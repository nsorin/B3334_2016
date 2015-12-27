package chat.client; 

import chat.client.protocol.OutputItf;

public class Output implements OutputItf
{
	public Output() 
	{
		super();
	}

	public void display(String notif) 
	{
		Client.messages.setText(Client.messages.getText() + '\n' + notif);
		Client.messages.setCaretPosition(Client.messages.getText().length());
	}
	
	public void addUser(String name) {
		Client.users.setText(Client.users.getText() + name + '\n');
	}
	
	public void removeUser(String name) {
		Client.users.setText(Client.users.getText().replace('\n' + name + '\n', "\n"));
	}

}