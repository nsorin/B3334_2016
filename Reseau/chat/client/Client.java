package chat.client;

import chat.client.Output;
import chat.client.Input;
import chat.client.protocol.OutputItf;
import chat.server.protocol.SessionItf;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

/**
 * The Class Client is a class that create the interface for the client side of the 
 * Chat application.
 */
public class Client 
{
	
	/** The Constant FRAME_WIDTH. */
	static final int FRAME_WIDTH = 800;
	
	/** The Constant FRAME_HEIGHT. */
	static final int FRAME_HEIGHT = 600;
	
	/** The frame. */
	static JFrame frame;
	
	/** The field where the user can write. */
	static JTextField text;
	
	/** The area where are displayed messages */
	static JTextArea messages;
	
	/** The area that display the list of connected users. */
	static JTextArea users;
	
	/** The scroll panel of the chat. */
	static JScrollPane msgScroll;
	
	/** The scroll panel of the list of connected users. */
	static JScrollPane usrScroll;
	
	/** The input object. */
	static Input input;
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) 
    {
        String host = (args.length < 1) ? null : args[0];
        
        frame = new JFrame("B3334Chat");
        text = new JTextField();
        text.setPreferredSize(new Dimension(7*FRAME_WIDTH/10, FRAME_HEIGHT/20));
        JButton send = new JButton("SEND");
        send.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMaximumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.setMinimumSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/20));
        send.addActionListener(new Client().new InputListener());
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
		text.addKeyListener(new Client().new KeyAdapter());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
        
        try 
        {
            Registry registry = LocateRegistry.getRegistry(host);
            SessionItf session = (SessionItf) registry.lookup("Session");
            Output output = new Output();
            OutputItf oItf = (OutputItf) UnicastRemoteObject.exportObject(output, 0);
            input = new Input(session, oItf);     
        }
        catch (Exception e) 
        {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
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
				try 
				{
					input.command(line);
				} 
				catch (RemoteException e1) 
				{
					e1.printStackTrace();
				}
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
				if(e.getKeyCode() == KeyEvent.VK_ENTER) 
				{
					String line = text.getText();
					try 
					{
						input.command(line);
					} 
					catch (RemoteException e1) 
					{
						e1.printStackTrace();
					}
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
					try 
					{
						input.command(line);
					} 
					catch (RemoteException e1) 
					{
						e1.printStackTrace();
					}
				}
			}
	    	
	    }
	}
