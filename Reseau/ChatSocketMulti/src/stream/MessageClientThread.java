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
				if (message.getType()!=Request.EMPTY)
				{
					System.out.println(message.toString());
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
