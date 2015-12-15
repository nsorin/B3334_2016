package chat.server.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;
import chat.client.protocol.OutputItf;

public interface SessionItf extends Remote
{
    boolean connect(String login, OutputItf output) throws RemoteException;
    boolean disconnect(String login) throws RemoteException;
    void receive(String content) throws RemoteException;
}
