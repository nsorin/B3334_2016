/***
 * ClientThread
 * Example of a TCP server
 * Date: 14/12/08
 * Authors:
 */

package ChatSocketMulti.src.stream;

import java.io.*;
import java.net.*;
import java.util.Date;

public class ClientThread extends Thread {
	
	private Socket clientSocket;
	private String username;
	
	ClientThread(Socket s) {
		this.clientSocket = s;
		username = null;
	}
	
	/**
	* receives a request from client then sends an echo to the client
	* @param clientSocket the client socket
	**/
	public void run() {
	  try {
		/*BufferedReader socIn = null;
		socIn = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));    
		PrintStream socOut = new PrintStream(clientSocket.getOutputStream());*/
		  
		  OutputStream os = clientSocket.getOutputStream();
		  ObjectOutputStream oos = new ObjectOutputStream(os);
		  InputStream is = clientSocket.getInputStream();
		  ObjectInputStream ois = new ObjectInputStream(is);
		  
		  while (true) {
			  Request request = (Request)ois.readObject();
			  Request response = requestProcess(request);
			  oos.writeObject(response); 
		  }
	  	} catch (Exception e) {
		  System.err.println("Error in EchoServer:" + e); 
		  }
	  	}
  
	
	public Request requestProcess(Request request)
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
				else
				{
					EchoServerMultiThreaded.listUsernames.addFirst(username);
					this.username = username;
					System.out.println(this.username + " connected.");
					response = new Request(Request.SUCCESS,"Connection successful.","");
					message = new Request(Request.CONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					for(Socket s : EchoServerMultiThreaded.listClients) {
						ObjectOutputStream oos;
						try {
							oos = new ObjectOutputStream(s.getOutputStream());
							oos.writeObject(message);
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}						
					}
				}
				break;
			case Request.DISCONNECT :
				if(EchoServerMultiThreaded.listUsernames.contains(this.username))
				{
					EchoServerMultiThreaded.listUsernames.remove(this.username);
					System.out.println(this.username + " disconnected.");
					response = new Request(Request.SUCCESS,"Disconnection successful.","");
					message = new Request(Request.DISCONNECT,"","");
					message.setUsername(this.username);
					message.setDate(date);
					//EchoServerMultiThreaded.listMessages.addFirst(message);
					for(Socket s : EchoServerMultiThreaded.listClients) {
						ObjectOutputStream oos;
						try {
							oos = new ObjectOutputStream(s.getOutputStream());
							oos.writeObject(message);
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}						
					}
					this.username = "";
				}
				break;
			case Request.MESSAGE_ALL :
				request.setDate(date);
				request.setUsername(this.username);
				//EchoServerMultiThreaded.listMessages.addFirst(request);
				for(Socket s : EchoServerMultiThreaded.listClients) {
					ObjectOutputStream oos;
					try {
						oos = new ObjectOutputStream(s.getOutputStream());
						oos.writeObject(request);
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}						
				}
				response = new Request(Request.EMPTY,"","");
				break;
			case Request.MESSAGE_PRIVATE :
				response = new Request(Request.EMPTY,"","");
				break;
			default :
				response = new Request(Request.EMPTY,"","");
				break;
		}
		response.setDate(date);
		return response;
	}
 }

  
