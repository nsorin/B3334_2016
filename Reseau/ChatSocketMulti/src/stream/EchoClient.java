package ChatSocketMulti.src.stream;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.io.*;
import java.net.*;

import javax.swing.*;

public class EchoClient 
{
	static final int FRAME_WIDTH = 800;
	static final int FRAME_HEIGHT = 600;
	
  /**
  *  main method
  *  accepts a connection, receives a message from client then sends an echo to the client
  **/
    public static void main(String[] args) throws IOException 
    {
    	JFrame frame = new JFrame("B3334Chat");
        JTextField text = new JTextField();
        text.setPreferredSize(new Dimension(7*FRAME_WIDTH/10, FRAME_HEIGHT/20));
        JButton send = new JButton("SEND");
        send.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMaximumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMinimumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        JPanel controlPanel = new JPanel();
		controlPanel.add(text, BorderLayout.WEST);
		controlPanel.add(send, BorderLayout.EAST);
		controlPanel.setMaximumSize(new Dimension(FRAME_WIDTH, FRAME_HEIGHT/20));
		JTextArea messages = new JTextArea("Welcome to the chat");
		messages.setBackground(Color.WHITE);
		messages.setEditable(false);
		frame.add(messages);
		frame.add(controlPanel, BorderLayout.SOUTH);
		frame.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		frame.setVisible(true);
    	
    	Socket echoSocket = null;
        ObjectOutputStream socOut = null;
        BufferedReader stdIn = null;
        ObjectInputStream socIn = null;
        
        if (args.length != 2) 
        {
          System.out.println("Usage: java EchoClient <EchoServer host> <EchoServer port>");
          System.exit(1);
        }

        try 
        {
      	    // creation socket ==> connexion
      	    echoSocket = new Socket(args[0],new Integer(args[1]).intValue());
		    socIn = new ObjectInputStream(echoSocket.getInputStream());
		    MessageClientThread messageThread = new MessageClientThread(echoSocket, socIn, messages);
	        messageThread.start();     
	      	socOut = new ObjectOutputStream(echoSocket.getOutputStream());
		    stdIn = new BufferedReader(new InputStreamReader(System.in));
        } 
        catch (UnknownHostException e) 
        {
            System.err.println("Don't know about host:" + args[0]);
            System.exit(1);
        } 
        catch (IOException e) 
        {
            System.err.println("Couldn't get I/O for "
                               + "the connection to:"+ args[0]);
            System.exit(1);
        }                
        String line;
        while (true) 
        {
        	line=stdIn.readLine();
        	if (line.equals(".")) break;
        	Request req = null;
        	if(line.charAt(0) != '/') 
        	{
        		req = new Request(Request.MESSAGE_ALL, line, "");
        	} 
        	else 
        	{
        		String[] parts = line.split(" ");
        		switch(parts[0]) 
        		{
        			case "/connect":
        				req = new Request(Request.CONNECT, parts[1], "");
        				break;
        			case "/disconnect":
        				req = new Request(Request.DISCONNECT, "", "");
        				break;
        			case "/private": 
        				req = new Request(Request.MESSAGE_PRIVATE, parts[2], parts[1]);
        				break;
        			default:
        				break;
        		}
        	}	
        	socOut.writeObject(req);
        }
      socOut.close();
      socIn.close();
      stdIn.close();
      echoSocket.close();
    }
}


