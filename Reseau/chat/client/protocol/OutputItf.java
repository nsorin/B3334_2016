package chat.client; 

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface OutputItf extends Remote {
	void display(String notif) throws RemoteException;
}