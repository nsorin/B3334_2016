package chat.client; 

import chat.server.protocol.SessionItf;

public class Input {

	final char CMD_FLAG = '/';
	final String CMD_CONNECT = "connect";
	final String CMD_DISCONNECT = "quit";

	SessionItf session;
	OutputItf output;
	String currentLogin;

	public Input(SessionItf s, int t) {
		session = s;
		token = t;
		currentLogin = "";
	}

	public void command(String cmd) {
		if(cmd.charAt(0) == CMD_FLAG {
			String[] parts = cmd.split(" ");
			switch(parts[0]) {
				case (CMD_FLAG + CMD_CONNECT):
					if(session.connect(parts[1], output)) {
						currentLogin = parts[1];
					}
					break;
				case (CMD_FLAG + CMD_DISCONNECT):
					if(session.disconnect(currentLogin)) {
						currentLogin = "";
					}
					break;
				default:
					break;
			}	
		} else {
			session.receive(cmd, token);
		}
	}

}