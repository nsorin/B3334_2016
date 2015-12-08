package chat.server.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface SessionItf extends Remote
{
    boolean connect(String login, OutputItf output) throws RemoteException;
    boolean disconnect(String login, OutputItf output) throws RemoteException;
    void receive(String content) throws RemoteException;
}
