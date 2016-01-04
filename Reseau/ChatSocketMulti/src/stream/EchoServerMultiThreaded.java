package ChatSocketMulti.src.stream;

import java.io.FileOutputStream;
import java.io.IOException;
import java.net.*;
import java.util.LinkedList;

/**
 * The Class EchoServerMultiThreaded is the class that initiate the thread of each client when one of them try to connect to the server.
 */
public class EchoServerMultiThreaded 
{
	
	/** The list of the name of connected users. */
	static LinkedList<String> listUsernames;
	
	/** The list of the ClientThread of all connected clients. */
	static LinkedList<ClientThread> listClients;
	
	/** The file output stream linked to the log File */
	static FileOutputStream fos;
  
 	/**
	  * main method that create and launch a ClientSocket for each client that tries to connect to the server.
	  *
	  * @param args the arguments
	  */
    public static void main(String args[])
    { 
        ServerSocket listenSocket = null;
	  	if (args.length != 1) 
	  	{
	          System.out.println("Usage: java EchoServer <EchoServer port>");
	          System.exit(1);
	  	}
		try 
		{
			listenSocket = new ServerSocket(Integer.parseInt(args[0])); //port
			System.out.println("Server ready..."); 
			listUsernames = new LinkedList<String>();
			listClients = new LinkedList<ClientThread>();
			fos = new FileOutputStream("chat.log");
			while (true) 
			{
				Socket clientSocket = listenSocket.accept();
				System.out.println("Connexion from:" + clientSocket.getInetAddress());
				ClientThread ct = new ClientThread(clientSocket);
				ct.start();
			}
        }
		catch (Exception e) 
		{
            System.err.println("Error in EchoServerMultiThreaded:" + e);
        }
		try 
		{
			listenSocket.close();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		try 
		{
			fos.close();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
    }
  }

  
