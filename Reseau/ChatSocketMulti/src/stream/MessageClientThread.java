package ChatSocketMulti.src.stream;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

public class MessageClientThread extends Thread
{
	Socket clientServerSocket;
	ObjectInputStream ois;
	
	MessageClientThread(Socket s, ObjectInputStream ois)
	{
		clientServerSocket = s;
		this.ois = ois;
	}
	
	public void run()
	{
		try 
		{	
			while(true) 
			{
				Request message = (Request)ois.readObject();
				if(message.getType() == Request.USERS) {
					EchoClient.users.setText(EchoClient.users.getText() + message.getContent());
				} else if (message.getType()!=Request.EMPTY)
				{
					//System.out.println(message.toString());
					EchoClient.messages.setText(EchoClient.messages.getText() + '\n' + message.toString());
					EchoClient.messages.setCaretPosition(EchoClient.messages.getText().length());
					if(message.getType() == Request.CONNECT && EchoClient.users.getText().indexOf("\n" + message.getUserName() + "\n") == -1) {
						EchoClient.users.setText(EchoClient.users.getText() + '\n' + message.getUserName());
					} else if(message.getType() == Request.DISCONNECT) {
						EchoClient.users.setText(EchoClient.users.getText().replaceAll("\n" + message.getUserName() + "\n", "\n"));
					}
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
