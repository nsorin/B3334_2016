/***
 * EchoServer
 * Example of a TCP server
 * Date: 10/01/04
 * Authors:
 */

package ChatSocketMulti.src.stream;

import java.net.*;
import java.util.LinkedList;

public class EchoServerMultiThreaded  {
	
	static LinkedList<String> listUsernames;
	static LinkedList<Socket> listClients;
  
 	/**
  	* main method
	* @param EchoServer port
  	* 
  	**/
       public static void main(String args[]){ 
        ServerSocket listenSocket;
        
  	if (args.length != 1) {
          System.out.println("Usage: java EchoServer <EchoServer port>");
          System.exit(1);
  	}
	try {
		listenSocket = new ServerSocket(Integer.parseInt(args[0])); //port
		System.out.println("Server ready..."); 
		listUsernames = new LinkedList<String>();
		listClients = new LinkedList<Socket>();
		while (true) {
			Socket clientSocket = listenSocket.accept();
			listClients.addFirst(clientSocket);
			System.out.println("Connexion from:" + clientSocket.getInetAddress());
			ClientThread ct = new ClientThread(clientSocket);
			ct.start();
		}
        } catch (Exception e) {
            System.err.println("Error in EchoServer:" + e);
        }
      }
  }

  
