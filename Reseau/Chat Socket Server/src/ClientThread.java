

import java.io.*;
import java.net.*;
import java.util.Date;

/**
 * The Class ClientThread is a thread linked to a specific client where
 * all the request sending by this client are treated.
 */
public class ClientThread extends Thread 
{
	
	/** The server side client socket. */
	private Socket clientSocket;
	
	/** The name of the user. */
	private String username;
	
	/** The output stream linked to the client side socket. */
	private ObjectOutputStream oos;
	
	/** The input stream linked to the client side socket. */
	private ObjectInputStream ois;
	
	///** The output stream linked to the log File. */
	//private ObjectOutputStream logOut;
	
	///** The input stream linked to the log File. */
	//private ObjectInputStream logIn;
	
	/**
	 * Gets the client socket.
	 *
	 * @return the client socket
	 */
	public Socket getClientSocket(){return clientSocket;}
	
	/**
	 * Gets the username.
	 *
	 * @return the username
	 */
	public String getUsername(){return username;}
	
	/**
	 * Gets the object output stream.
	 *
	 * @return the object output stream
	 */
	public ObjectOutputStream getObjectOutputStream(){return oos;}
	
	/**
	 * Method that test if the current ClientThread is equal to a ClientThread put in argument.
	 *
	 * @param client the client that will be compared
	 * @return true, if the current ClientThread is equal to the ClientThread in argument.
	 */
	public boolean equals(ClientThread client){return client.getUsername().equals(username);}
	
	/**
	 * Instantiates a new client thread.
	 *
	 * @param s the server side client socket
	 */
	ClientThread(Socket s) 
	{
		this.clientSocket = s;
		username = null;
		try {
			this.oos = new ObjectOutputStream(clientSocket.getOutputStream());
			this.ois = new ObjectInputStream(clientSocket.getInputStream());
			//this.logOut = new ObjectOutputStream(EchoServerMultiThreaded.fos);
			//this.logIn = new ObjectInputStream(EchoServerMultiThreaded.fis);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Instantiates a new client thread.
	 *
	 * @param username the name of the user
	 */
	ClientThread(String username) 
	{
		this.username = username;
		this.clientSocket = null;
		this.oos = null;
		this.ois = null;
	}
	
	/**
	 * Method run of the thread that receives a request from client then sends an echo to the client.
	 */
	public void run() 
	{
		try
		{		  
			while(true) 
			{
				Request request = (Request)ois.readObject();
				Request response = requestProcess(request);
				oos.writeObject(response);
				//logOut.writeObject(request);
			}
	  	}
		catch (Exception e)
		{
	  		System.err.println("Error in ClientThread:" + e); 
	  	}
	}
	
	/**
	 * Method that treat the request depending on its type.
	 *
	 * @param request the request
	 * @return the response request
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public Request requestProcess(Request request) throws IOException
	{
		Request response = new Request();
		Request message = new Request();
		Date date = new Date();
		int typeReq = request.getType();
		switch(typeReq)
		{
			case Request.CONNECT :
				String username = request.getContent();
				if(EchoServerMultiThreaded.listUsernames.contains(username))
				{
					response = new Request(Request.ERROR,"Username already used.","");
				}
				else if(this.username!=null)
				{
					response = new Request(Request.ERROR,"You are already connected.","");
				}
				else
				{
					//restoreLog();
					EchoServerMultiThreaded.listUsernames.addFirst(username);
					EchoServerMultiThreaded.listClients.addFirst(this);
					this.username = username;
					System.out.println(this.username + " connected.");
					response = new Request(Request.SUCCESS,"Connection successful.","");
					message = new Request(Request.CONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					String list = "";
					for(String s : EchoServerMultiThreaded.listUsernames) 
					{
						list += s + '\n';					
					}
					Request users = new Request(Request.USERS, list, "");
					oos.writeObject(users);
					for(ClientThread c : EchoServerMultiThreaded.listClients) 
					{
						try 
						{
							c.getObjectOutputStream().writeObject(message);
						} 
						catch (IOException e) 
						{
							e.printStackTrace();
						}						
					}
				}
				break;
			case Request.DISCONNECT :
				if(this.username==null)
				{
					response = new Request(Request.ERROR,"You are not connected.","");
				}
				else if(EchoServerMultiThreaded.listUsernames.contains(this.username))
				{
					EchoServerMultiThreaded.listUsernames.remove(this.username);
					EchoServerMultiThreaded.listClients.remove(this);
					System.out.println(this.username + " disconnected.");
					response = new Request(Request.SUCCESS,"Disconnection successful.","");
					message = new Request(Request.DISCONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					for(ClientThread c : EchoServerMultiThreaded.listClients) 
					{
						try 
						{
							c.getObjectOutputStream().writeObject(message);
						} 
						catch (IOException e) 
						{
							e.printStackTrace();
						}						
					}
					this.username = null;
				}
				break;
			case Request.MESSAGE_ALL :
				request.setDate(date);
				request.setUsername(this.username);
				if(this.username==null)
				{
					response = new Request(Request.ERROR,"You are not connected.","");
				}
				else
				{
					for(ClientThread c : EchoServerMultiThreaded.listClients) 
					{
						try 
						{
							c.getObjectOutputStream().writeObject(request);
						} 
						catch (IOException e) 
						{
							e.printStackTrace();
						}						
					}
					response = new Request(Request.EMPTY,"","");
				}
				break;
			case Request.MESSAGE_PRIVATE :
				request.setDate(date);
				request.setUsername(this.username);
				ClientThread clientRec = new ClientThread(request.getOption());
				ClientThread clientExp = new ClientThread(this.username);
				if(this.username==null)
				{
					response = new Request(Request.ERROR,"You are not connected.","");
				}
				else
				{
					for(ClientThread c : EchoServerMultiThreaded.listClients) 
					{
						if(c.equals(clientRec) || c.equals(clientExp))
						{
							try 
							{
								c.getObjectOutputStream().writeObject(request);
							} 
							catch (IOException e) 
							{
								e.printStackTrace();
							}
						}						
					}
					response = new Request(Request.EMPTY,"","");
				}
				break;
			case Request.USERS :
				String list = "";
				for(String s : EchoServerMultiThreaded.listUsernames) 
				{
					list += s + '\n';
				}
				response = new Request(Request.USERS, list, "");
				break;
			default :
				response = new Request(Request.EMPTY,"","");
				break;
		}
		response.setDate(date);
		return response;
	}
	
	/*Method used to save logs
	public void restoreLog() 
	{
		Request request = null;
		while(true) 
		{
			try 
			{
				request = (Request) logIn.readObject();
				if(request == null) break;
			} 
			catch (ClassNotFoundException | IOException e) 
			{
				e.printStackTrace();
			}
			System.out.println(request.toString());
			try 
			{
				getObjectOutputStream().writeObject(request);
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
		}
	}*/
 }

  
