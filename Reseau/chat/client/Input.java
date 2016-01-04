package chat.client; 

import java.rmi.RemoteException;

import chat.server.protocol.SessionItf;
import chat.client.protocol.OutputItf;

/**
 * The Class Input is a class treat all the command of the user
 * to send it properly to the server depending on the type of the command.
 */
public class Input 
{
	
	/** The command flag. */
	final char CMD_FLAG = '/';
	
	/** The command connect. */
	final String CMD_CONNECT = "connect";
	
	/** The command disconnect. */
	final String CMD_DISCONNECT = "disconnect";
	
	/** The command private message. */
	final String CMD_PRIVATE_MESSAGE = "private";

	/** The session. */
	SessionItf session;
	
	/** The output object. */
	OutputItf output;
	
	/** The current login of the user. */
	String currentLogin;

	/**
	 * Instantiates a new input.
	 *
	 * @param s the current session of the chat(server)
	 * @param o the output object of the current user
	 */
	public Input(SessionItf s, OutputItf o) 
	{
		session = s;
		currentLogin = null;
		output = o;
	}

	/**
	 * Method that treat the input of the user to send it 
	 * correctly to the server.
	 *
	 * @param cmd the command
	 * @throws RemoteException the remote exception
	 */
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
							output.display("Connection failed.");
						}
					}
					else
					{
						output.display("You are already connected.");
					}
					break;
				case (CMD_FLAG + CMD_DISCONNECT):
					if(currentLogin!=null)
					{
						if(session.disconnect(currentLogin)) 
						{
							currentLogin = null;
							output.display("Disconnection successful.");
							Client.users.setText("CONNECTED USERS :\n");
						}
						else
						{
							output.display("Disconnection failed.");
						}
					}
					else
					{
						output.display("You can't disconnect, you are not connected!");
					}		
					break;
				case (CMD_FLAG + CMD_PRIVATE_MESSAGE):
					if(currentLogin!=null)
					{
						if(session.receivePrivate(parts[2],parts[1],currentLogin))
						{
							
						}
						else
						{
							output.display("Sending a private message failed.");
						}
					}
					else
					{
						output.display("You can't send a message, you are not connected!");
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
				session.receiveAll(cmd,currentLogin);
			}
			else
			{
				output.display("You can't send a message, you are not connected!");
			}
		}
		Client.text.setText("");
	}

}