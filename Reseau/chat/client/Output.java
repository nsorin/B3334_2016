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

}