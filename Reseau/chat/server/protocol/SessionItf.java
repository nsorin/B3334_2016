package chat.server.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;
import chat.client.protocol.OutputItf;

public interface SessionItf extends Remote
{
    boolean connect(String login, OutputItf output) throws RemoteException;
    boolean disconnect(String login) throws RemoteException;
    boolean receiveAll(String content,String login) throws RemoteException;
    boolean receivePrivate(String content,String loginRec, String loginExp) throws RemoteException;
}
