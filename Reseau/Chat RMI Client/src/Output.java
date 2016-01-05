

/**
 * The Class Output is a class that extends Remote.
 * This class can be used by the server to interact with the view of a user.
 */
public class Output implements OutputItf
{
	
	/**
	 * Instantiates a new output.
	 */
	public Output() 
	{
		super();
	}

	/* (non-Javadoc)
	 * @see chat.client.protocol.OutputItf#display(java.lang.String)
	 */
	public void display(String notif) 
	{
		Client.messages.setText(Client.messages.getText() + '\n' + notif);
		Client.messages.setCaretPosition(Client.messages.getText().length());
	}
	
	/* (non-Javadoc)
	 * @see chat.client.protocol.OutputItf#addUser(java.lang.String)
	 */
	public void addUser(String name) 
	{
		Client.users.setText(Client.users.getText() + name + '\n');
	}
	
	/* (non-Javadoc)
	 * @see chat.client.protocol.OutputItf#removeUser(java.lang.String)
	 */
	public void removeUser(String name) 
	{
		Client.users.setText(Client.users.getText().replace('\n' + name + '\n', "\n"));
	}

}