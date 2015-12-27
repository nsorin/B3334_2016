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

public class Client 
{
	static final int FRAME_WIDTH = 800;
	static final int FRAME_HEIGHT = 600;
	
	static JFrame frame;
	static JTextField text;
	static JTextArea messages;
	static JTextArea users;
	static JScrollPane msgScroll;
	static JScrollPane usrScroll;
	
	static Input input;
	
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
		users = new JTextArea("CONNECTED USERS :");
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
            // Message de bienvenue si tout a réussi
            //output.display("Bienvenue. Vous pouvez vous connecter au chat.");       
        }
        catch (Exception e) 
        {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

	 public class InputListener implements ActionListener {

			@Override
			public void actionPerformed(ActionEvent e) {
				String line = text.getText();
				try {
					input.command(line);
				} catch (RemoteException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
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
					try {
						input.command(line);
					} catch (RemoteException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}

			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
				if(e.getKeyCode() == KeyEvent.VK_ENTER) {
					String line = text.getText();
					try {
						input.command(line);
					} catch (RemoteException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}
	    	
	    }
	}
