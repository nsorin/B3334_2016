package ChatSocketMulti.src.stream;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

/**
 * The Class MessageClientThread is a thread launch in the client side to treat
 * the request sending by the server and update the UI.
 */
public class MessageClientThread extends Thread
{
	
	/** The client side server socket. */
	Socket clientServerSocket;
	
	/** The input stream linked to the client socket in the server side. */
	ObjectInputStream ois;
	
	/**
	 * Instantiates a new message client thread.
	 *
	 * @param s the client side server socket
	 * @param ois the input stream
	 */
	MessageClientThread(Socket s, ObjectInputStream ois)
	{
		clientServerSocket = s;
		this.ois = ois;
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 */
	public void run()
	{
		try 
		{	
			while(true) 
			{
				Request message = (Request)ois.readObject();
				if(message.getType() == Request.USERS) 
				{
					EchoClient.users.setText(EchoClient.users.getText() + message.getContent());
				} 
				else if (message.getType()!=Request.EMPTY)
				{
					//System.out.println(message.toString());
					EchoClient.messages.setText(EchoClient.messages.getText() + '\n' + message.toString());
					EchoClient.messages.setCaretPosition(EchoClient.messages.getText().length());
					if(message.getType() == Request.CONNECT && EchoClient.users.getText().indexOf("\n" + message.getUserName() + "\n") == -1) 
					{
						EchoClient.users.setText(EchoClient.users.getText() + '\n' + message.getUserName());
					} 
					else if(message.getType() == Request.DISCONNECT) 
					{
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
