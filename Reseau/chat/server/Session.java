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
        User current = listUsers.getFirst();
        if(current!=null)
        {
            boolean loginExist = false;
            do
            {
                if(current.getLogin()==login)
                {
                    test = true;
                    break;
                }
            }while(!current.equals(listUsers.getLast()));
        }
        if(test==false)
        {
            listUsers.addFirst(user);
            status = true;
        }
        return status;
    }

    public boolean disconnect(String login, OutputItf output) throws RemoteException
    {
        boolean status = false;
        int index;
        index = listUsers.indexOf(user);
        listUsers.remove(index);
        status = true;
        return status;
    }

    public String receive(String msg) throws RemoteException
    {
        return msg;
    }

    public void send(String notification)
    {

    }

    public Session()
    {
        listMessages = new LinkedList<Message>;
        listUsers = new LinkedList<User>;
    }
}
