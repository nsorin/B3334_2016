package ChatSocketMulti.src.stream;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.net.*;

import javax.swing.*;

public class EchoClient 
{
	static final int FRAME_WIDTH = 800;
	static final int FRAME_HEIGHT = 600;
	
	static JTextField text;
	static Socket echoSocket = null;
    static ObjectOutputStream socOut = null;
    static BufferedReader stdIn = null;
    static ObjectInputStream socIn = null;
	
  /**
  *  main method
  *  accepts a connection, receives a message from client then sends an echo to the client
  **/
    public static void main(String[] args) throws IOException 
    {
    	JFrame frame = new JFrame("B3334Chat");
        text = new JTextField();
        text.setPreferredSize(new Dimension(7*FRAME_WIDTH/10, FRAME_HEIGHT/20));
        JButton send = new JButton("SEND");
        send.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMaximumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMinimumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.addActionListener(new EchoClient().new InputListener());
        JPanel controlPanel = new JPanel();
		controlPanel.add(text, BorderLayout.WEST);
		controlPanel.add(send, BorderLayout.EAST);
		controlPanel.setMaximumSize(new Dimension(FRAME_WIDTH, FRAME_HEIGHT/20));
		
		JTextArea messages = new JTextArea("Welcome to B3334Chat. Type /connect <username> to connect to the chat server.");
		messages.setBackground(Color.WHITE);
		messages.setEditable(false);
		JScrollPane msgScroll = new JScrollPane(messages);
		msgScroll.getVerticalScrollBar().addAdjustmentListener(new AdjustmentListener() {  
	        public void adjustmentValueChanged(AdjustmentEvent e) {  
	            e.getAdjustable().setValue(e.getAdjustable().getMaximum());  
	        }
	    });
		
		frame.add(msgScroll);
		frame.add(controlPanel, BorderLayout.SOUTH);
		frame.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		text.addKeyListener(new EchoClient().new KeyAdapter());
		frame.setVisible(true);
        
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
        	sendMessage(line);
        }
      socOut.close();
      socIn.close();
      stdIn.close();
      echoSocket.close();
    }
    
    public static void sendMessage(String line) {
    	if(line != "") {
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
			try {
				socOut.writeObject(req);
			} catch (IOException e1) {
			// 	TODO Auto-generated catch block
				e1.printStackTrace();
			}
			text.setText("");
	
		}
    }
    
    public class InputListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			String line = text.getText();
			sendMessage(line);
		}
    }
    
    public class KeyAdapter implements KeyListener {

		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
		}

		@Override
		public void keyReleased(KeyEvent e) {
			// TODO Auto-generated method stub
			if(e.getKeyCode() == KeyEvent.VK_ENTER) {
				String line = text.getText();
				sendMessage(line);
			}
		}

		@Override
		public void keyTyped(KeyEvent e) {
			// TODO Auto-generated method stub
			if(e.getKeyCode() == KeyEvent.VK_ENTER) {
				String line = text.getText();
				sendMessage(line);
			}
		}
    	
    }
}


