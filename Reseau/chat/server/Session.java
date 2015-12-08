package chat.server

import chat.server.protocol.SessionItf;
import chat.server.User;
import chat.server.Message;

import java.rmi.RemoteException;
import java.util.Date;

public class Session implements SessionItf
{
    LinkedList<Message> listMessages;
    LinkedList<User> listUsers;

    public boolean connect(String login, OutputItf output) throws RemoteException
    {
        boolean status = false;
        Date date = new Date();
        User user = new User(login,date,output);
        if(!listUsers.contains(user))
        {
            listUsers.addFirst(user);
            status = true;
        }
        return status;
    }

    public boolean disconnect(String login, OutputItf output) throws RemoteException
    {
        /*boolean status = false;
        int index;
        index = listUsers.indexOf(user);
        listUsers.remove(index);
        status = true;
        return status;*/
    }

    public void receive(String content) throws RemoteException
    {

    }

    public void send(String notification)
    {
        User current = listUsers.getFirst();
        if(current!=null)
        {
            do
            {
                current.getOutput().display(notification);
                current = listUsers.get(listUsers.indexOf(current)+1);
            }while(current!=null);
        }
    }

    public Session()
    {
        listMessages = new LinkedList<Message>;
        listUsers = new LinkedList<User>;
    }
}
