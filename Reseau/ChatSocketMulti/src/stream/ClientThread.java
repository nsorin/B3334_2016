package ChatSocketMulti.src.stream;

import java.io.*;
import java.net.*;
import java.util.Date;

public class ClientThread extends Thread 
{
	
	private Socket clientSocket;
	private String username;
	private ObjectOutputStream oos;
	
	public Socket getClientSocket(){return clientSocket;}
	public String getUsername(){return username;}
	
	ClientThread(Socket s) 
	{
		this.clientSocket = s;
		username = null;
	}
	
	/**
	* receives a request from client then sends an echo to the client
	* @param clientSocket the client socket
	**/
	public void run() 
	{
		OutputStream os = null;
		ObjectOutputStream oos = null;
		InputStream is = null;
		ObjectInputStream ois = null;
		try 
		{		  
			os = clientSocket.getOutputStream();
			oos = new ObjectOutputStream(os);
			this.oos = oos;
			is = clientSocket.getInputStream();
			ois = new ObjectInputStream(is);
			while(true) 
			{
				Request request = (Request)ois.readObject();
				Request response = requestProcess(request);
				oos.writeObject(response); 
			}
	  	}
		catch (Exception e)
		{
	  		System.err.println("Error in ClientThread:" + e); 
	  	}
	}
	
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
					EchoServerMultiThreaded.listUsernames.addFirst(username);
					EchoServerMultiThreaded.listClients.addFirst(this.oos);
					this.username = username;
					System.out.println(this.username + " connected.");
					response = new Request(Request.SUCCESS,"Connection successful.","");
					message = new Request(Request.CONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					String list = "";
					for(String s : EchoServerMultiThreaded.listUsernames) {
						list += '\n' + s;
					}
					Request users = new Request(Request.USERS, list, "");
					oos.writeObject(users);
					for(ObjectOutputStream oos : EchoServerMultiThreaded.listClients) 
					{
						try 
						{
							oos.writeObject(message);
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
					EchoServerMultiThreaded.listClients.remove(this.oos);
					System.out.println(this.username + " disconnected.");
					response = new Request(Request.SUCCESS,"Disconnection successful.","");
					message = new Request(Request.DISCONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					for(ObjectOutputStream oos : EchoServerMultiThreaded.listClients) 
					{
						try 
						{
							oos.writeObject(message);
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
				for(ObjectOutputStream oos : EchoServerMultiThreaded.listClients) 
				{
					try 
					{
						oos.writeObject(request);
					} 
					catch (IOException e) 
					{
						e.printStackTrace();
					}						
				}
				response = new Request(Request.EMPTY,"","");
				break;
			case Request.MESSAGE_PRIVATE :
				response = new Request(Request.EMPTY,"","");
				break;
			case Request.USERS :
				String list = "";
				for(String s : EchoServerMultiThreaded.listUsernames) {
					list += '\n' + s;
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
 }

  
