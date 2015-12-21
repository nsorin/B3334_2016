package ChatSocketMulti.src.stream;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

import javax.swing.JTextArea;

public class MessageClientThread extends Thread
{
	Socket clientServerSocket;
	ObjectInputStream ois;
	JTextArea msg;
	
	MessageClientThread(Socket s, ObjectInputStream ois, JTextArea msg)
	{
		clientServerSocket = s;
		this.ois = ois;
		this.msg = msg;
	}
	
	public void run()
	{
		try 
		{	
			while(true) 
			{
				Request message = (Request)ois.readObject();
				if (message.getType()!=Request.EMPTY)
				{
					//System.out.println(message.toString());
					msg.setText(msg.getText() + '\n' + message.toString());
				}		
			}
	  	}
		catch (Exception e)
		{
	  		System.err.println("Error in MessageClientThread:" + e); 
	  	}
		try 
		{
			ois.close();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
}
