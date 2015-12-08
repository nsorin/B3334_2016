package chat.client; 

import chat.client.protocol.OutputItf;

public class Output implements OutputItf {

	public Output() {}

	public void display(String notif) {
		System.out.println(notif);
	}

}