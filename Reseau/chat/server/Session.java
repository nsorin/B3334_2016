package chat.server;

import chat.client.protocol.OutputItf;
import chat.server.protocol.SessionItf;
import chat.server.User;
import chat.server.Message;

import java.rmi.RemoteException;
import java.util.Date;
import java.util.LinkedList;


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
            this.send("[" + date.toString().substring(11, 19) + "] " + login + " c'est connecté.");
            status = true;
        }
        return status;
    }

    public boolean disconnect(String login) throws RemoteException
    {
        boolean status = false;
        Date date = new Date();
        User user = new User(login);
        int index = listUsers.indexOf(user);
        if(index!=-1)
        {
        	listUsers.remove(index);
        	this.send("[" + date.toString().substring(11, 19) + "] " + login + " c'est connecté.");
        	status = true;
        }
        return status;
    }

    public void receive(String content, String login) throws RemoteException
    {
    	Date date = new Date();
    	for(User u : listUsers)
        {
            try 
            {
				u.getOutput().display("[" + date.toString().substring(11, 19) + "] " + login + " : " + content);
			} 
            catch (RemoteException e) 
            {
				e.printStackTrace();
			}
        }
    }

    public void send(String notification)
    {
        for(User u : listUsers)
        {
            try 
            {
				u.getOutput().display(notification);
			} 
            catch (RemoteException e) 
            {
				e.printStackTrace();
			}
        }
    }

    public Session()
    {
        listMessages = new LinkedList<Message>();
        listUsers = new LinkedList<User>();
    }
}
