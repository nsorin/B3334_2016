package ChatSocketMulti.src.stream;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.net.*;

import javax.swing.*;

/**
 * The Class EchoClient is a class that create the interface for the client side of the 
 * Chat application. This class also creates a socket and streams(input/output) linked to the server 
 * that will be used to communicate with it.
 */
public class EchoClient 
{
	
	/** The Constant FRAME_WIDTH. */
	static final int FRAME_WIDTH = 800;
	
	/** The Constant FRAME_HEIGHT. */
	static final int FRAME_HEIGHT = 600;
	
	/** The frame. */
	static JFrame frame;
	
	/** The field where the user can write. */
	static JTextField text;
	
	/** The area where are displayed messages. */
	static JTextArea messages;
	
	/** The area that display the list of connected users. */
	static JTextArea users;
	
	/** The scroll panel of the chat. */
	static JScrollPane msgScroll;
	
	/** The scroll panel of the list of connected users. */
	static JScrollPane usrScroll;
	
	/** The client side socket. */
	static Socket echoSocket = null;
    
    /** The output stream linked to the server. */
    static ObjectOutputStream socOut = null;
    
    /** The bufferedReader. */
    static BufferedReader stdIn = null;
    
    /** The input stream linked to the server. */
    static ObjectInputStream socIn = null;
	
  /**
   *  main method
   *  accepts a connection, receives a message from client then sends an echo to the client.
   *
   * @param args the arguments
   * @throws IOException Signals that an I/O exception has occurred.
   */
    public static void main(String[] args) throws IOException 
    {
    	frame = new JFrame("B3334Chat");
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
		
		messages = new JTextArea("Welcome to B3334Chat. Type /connect <username> to connect to the chat server.");
		messages.setBackground(Color.WHITE);
		messages.setEditable(false);
		msgScroll = new JScrollPane(messages);
		msgScroll.setPreferredSize(new Dimension(7*FRAME_WIDTH/10, 17*FRAME_HEIGHT/20));
		users = new JTextArea("CONNECTED USERS :\n");
		users.setEditable(false);
		usrScroll = new JScrollPane(users);
		usrScroll.setPreferredSize(new Dimension(FRAME_WIDTH/5, 17*FRAME_HEIGHT/20));
		JPanel displayPanel = new JPanel();
		displayPanel.add(msgScroll, BorderLayout.WEST);
		displayPanel.add(usrScroll, BorderLayout.EAST);
		
		frame.add(displayPanel);
		frame.add(controlPanel, BorderLayout.SOUTH);
		frame.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		text.addKeyListener(new EchoClient().new KeyAdapter());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
		    MessageClientThread messageThread = new MessageClientThread(echoSocket, socIn);
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
    
    /**
     * Method that send a request to the server depending on the command written by the user.
     *
     * @param line the line written by the user
     */
    public static void sendMessage(String line) 
    {
    	if(line != "") 
    	{
			boolean msgOk = true;
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
    					users.setText("CONNECTED USERS :");
    					break;
    				case "/private": 
    					String contentMsgPrivate = "";
    					for(int compt = 2;compt<parts.length;compt++)
    					{
    						contentMsgPrivate += parts[compt] + " ";
    					}
    					req = new Request(Request.MESSAGE_PRIVATE, contentMsgPrivate, parts[1]);
    					break;
    				default:
    					msgOk = false;
    					break;
				}
			}
			if(msgOk) 
			{
				try 
				{
					socOut.writeObject(req);
				} 
				catch (IOException e1) 
				{
					e1.printStackTrace();
				}
			}
			text.setText("");
    	}
    }
    
    /**
     * The listener interface for receiving input events.
     * The class that is interested in processing a input
     * event implements this interface, and the object created
     * with that class is registered with a component using the
     * component's <code>addInputListener<code> method. When
     * the input event occurs, that object's appropriate
     * method is invoked.
     *
     * @see InputEvent
     */
    public class InputListener implements ActionListener 
    {

		/* (non-Javadoc)
		 * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
		 */
		@Override
		public void actionPerformed(ActionEvent e) 
		{
			String line = text.getText();
			sendMessage(line);
		}
    }
    
    /**
     * The Class KeyAdapter.
     */
    public class KeyAdapter implements KeyListener 
    {

		/* (non-Javadoc)
		 * @see java.awt.event.KeyListener#keyPressed(java.awt.event.KeyEvent)
		 */
		@Override
		public void keyPressed(KeyEvent e) 
		{
		}

		/* (non-Javadoc)
		 * @see java.awt.event.KeyListener#keyReleased(java.awt.event.KeyEvent)
		 */
		@Override
		public void keyReleased(KeyEvent e) 
		{
			// TODO Auto-generated method stub
			if(e.getKeyCode() == KeyEvent.VK_ENTER) 
			{
				String line = text.getText();
				sendMessage(line);
			}
		}

		/* (non-Javadoc)
		 * @see java.awt.event.KeyListener#keyTyped(java.awt.event.KeyEvent)
		 */
		@Override
		public void keyTyped(KeyEvent e) 
		{
			if(e.getKeyCode() == KeyEvent.VK_ENTER)
			{
				String line = text.getText();
				sendMessage(line);
			}
		}
    	
    }
}


