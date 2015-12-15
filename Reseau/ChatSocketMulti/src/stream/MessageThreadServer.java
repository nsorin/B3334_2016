package ChatSocketMulti.src.stream;

import java.io.ObjectOutputStream;
import java.util.Date;

public class MessageThreadServer extends Thread
{
	private Date lastDateMessage;
	private ObjectOutputStream oos;
	
	public MessageThreadServer(ObjectOutputStream oos)
	{
		this.oos = oos;
		lastDateMessage = new Date();
	}
	
	public void run() {
		  try {
			  while (true) {
				  if(!lastDateMessage.equals(EchoServerMultiThreaded.listMessages.getFirst().getDate()))
				  {
					  oos.writeObject(EchoServerMultiThreaded.listMessages.getFirst());
				  } 
			  }
		  } catch (Exception e) 
		  {
			  System.err.println("Error in EchoServer:" + e); 
		  }
	}
}
