import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * The Interface SessionItf is the interface used by the class Session.
 */
public interface SessionItf extends Remote
{
    
    /**
     * Method used by a client to connect to the Session as a user.
     *
     * @param login the login of the user
     * @param output the output of the user
     * @return true, if the connection is successful
     * @throws RemoteException the remote exception
     */
    boolean connect(String login, OutputItf output) throws RemoteException;
    
    /**
     * Method used by a client to disconnect from the Session.
     *
     * @param login the login of the user
     * @return true, if the disconnection is successful
     * @throws RemoteException the remote exception
     */
    boolean disconnect(String login) throws RemoteException;
    
    /**
     * Method used by client when he send a message to all users of the chat.
     *
     * @param content the content of the message
     * @param login the login of the user that send the message
     * @return true, if the message have been correctly sent
     * @throws RemoteException the remote exception
     */
    boolean receiveAll(String content,String login) throws RemoteException;
    
    /**
     * Method used by client when he send a private message to one of a connected user.
     *
     * @param content the content of the message
     * @param loginRec the login of the receiver of the message
     * @param loginExp the login of the user that send the private message
     * @return true, if the message have been correctly sent
     * @throws RemoteException the remote exception
     */
    boolean receivePrivate(String content,String loginRec, String loginExp) throws RemoteException;
}
