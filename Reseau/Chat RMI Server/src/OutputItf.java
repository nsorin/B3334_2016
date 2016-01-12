 

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * The Interface OutputItf is the interface related to the object Output.
 */
public interface OutputItf extends Remote 
{
	
	/**
	 * Method that display a text in the User Interface.
	 *
	 * @param notif the notification that will be displayed
	 * @throws RemoteException the remote exception
	 */
	void display(String notif) throws RemoteException;
	
	/**
	 * Method to add a User to the list of connected users.
	 *
	 * @param name the name of the user added
	 * @throws RemoteException the remote exception
	 */
	void addUser(String name) throws RemoteException;
	
	/**
	 * Method to remove a User to the list of connected user.
	 *
	 * @param name the name of the user removed
	 * @throws RemoteException the remote exception
	 */
	void removeUser(String name) throws RemoteException;
}