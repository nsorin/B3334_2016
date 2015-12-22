package chat.client; 

import java.rmi.RemoteException;

import chat.server.protocol.SessionItf;
import chat.client.protocol.OutputItf;

public class Input 
{
	final char CMD_FLAG = '/';
	final String CMD_CONNECT = "connect";
	final String CMD_DISCONNECT = "quit";

	SessionItf session;
	OutputItf output;
	String currentLogin;

	public Input(SessionItf s, OutputItf o) 
	{
		session = s;
		currentLogin = null;
		output = o;
	}

	public void command(String cmd) throws RemoteException 
	{
		if(cmd.charAt(0) == CMD_FLAG) 
		{
			String[] parts = cmd.split(" ");
			switch(parts[0]) 
			{
				case (CMD_FLAG + CMD_CONNECT):
					if(currentLogin==null)
					{
						if(session.connect(parts[1], output)) 
						{
							currentLogin = parts[1];
						}
						else
						{
							output.display("Connection failed!");
						}
					}
					else
					{
						output.display("You are already connected!");
					}
					break;
				case (CMD_FLAG + CMD_DISCONNECT):
					if(currentLogin!=null)
					{
						if(session.disconnect(currentLogin)) 
						{
							currentLogin = null;
						}
						else
						{
							output.display("Disconnection failed!");
						}
					}
					else
					{
						output.display("You are not connected!");
					}		
					break;
				default:
					break;
			}	
		} 
		else 
		{
			if(currentLogin!=null)
			{
				session.receive(cmd,currentLogin);
			}
			else
			{
				output.display("You are not connected!");
			}
		}
	}

}