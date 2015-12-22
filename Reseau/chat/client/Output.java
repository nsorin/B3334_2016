package chat.client; 

import chat.client.protocol.OutputItf;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Output extends JFrame implements OutputItf
{
	private JButton sendButton;
	private JTextField textField;
	private JPanel controlPanel;
	private JLabel msgLabel;
	private GridLayout layout;

	public Output() 
	{
		super();
		this.setTitle("34Chat");
		sendButton = new JButton("Send");
		textField = new JTextField();
		controlPanel = new JPanel();
		controlPanel.setLayout(new GridLayout(1, 2));
		controlPanel.add(textField);
		controlPanel.add(sendButton);
		msgLabel = new JLabel();
		this.setLayout(new GridLayout(2, 1));
		this.add(msgLabel);
		this.add(controlPanel);
	}

	public void display(String notif) 
	{
		System.out.println(notif);
	}

}