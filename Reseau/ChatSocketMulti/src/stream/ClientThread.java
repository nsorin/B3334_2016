/***
 * ClientThread
 * Example of a TCP server
 * Date: 14/12/08
 * Authors:
 */

package ChatSocketMulti.src.stream;

import java.io.*;
import java.net.*;
import java.util.LinkedList;

public class ClientThread
	extends Thread {
	
	private Socket clientSocket;
	private static LinkedList<String> listUsernames;
	private static LinkedList<Request> listMessages;
	private String username;
	
	ClientThread(Socket s, LinkedList<String> listUsernames, LinkedList<Request> listMessages) {
		this.clientSocket = s;
		ClientThread.listUsernames = listUsernames;
		ClientThread.listMessages = listMessages;
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
			/*String line = socIn.readLine();
			socOut.println(line);*/
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
		Request response;
		int typeReq = request.getType();
		switch(typeReq)
		{
			case Request.CONNECT :
				String username = request.getContent();
				if(listUsernames.contains(username))
				{
					response = new Request(Request.ERROR,"Username already used.","");
				}
				else
				{
					listUsernames.addFirst(username);
					response = new Request(Request.SUCCESS,"Connection successful.","");
				}
				break;
			case Request.DISCONNECT :
				listUsernames.remove(this.username);
				response = new Request(Request.SUCCESS,"Disconnection successful.","");
				break;
			case Request.MESSAGE_ALL :
				response = new Request(Request.SUCCESS,"successful.","");
				break;
			case Request.MESSAGE_PRIVATE :
				response = new Request(Request.SUCCESS,"successful.","");
				break;
			default :
				response = new Request(Request.SUCCESS,"successful.","");
				break;
		}
		return response;
	}
 }

  
