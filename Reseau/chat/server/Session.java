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
        	String msg = "[" + date.toString().substring(11, 19) + "] " + login + " connected.";
            listUsers.addFirst(user);
            this.send(msg);
            for(User u : listUsers)
            {
                try 
                {
    				u.getOutput().addUser(login);
    				if(u.getLogin() != login)
    				{
    					output.addUser(u.getLogin());
    				}
    			} 
                catch (RemoteException e) 
                {
    				e.printStackTrace();
    			}
            }
            //System.out.println(msg);
            status = true;
        }
        return status;
    }

    public boolean disconnect(String login) throws RemoteException
    {
        boolean status = false;
        Date date = new Date();
        User user = new User(login);
        for(User u : listUsers)
        {
    		u.getOutput().removeUser(login);
        	if(u.equals(user))
    		{
    			listUsers.remove(u);
				String msg = "[" + date.toString().substring(11, 19) + "] " + login + " disconnected.";
				this.send(msg);
				//System.out.println(msg);
				status = true;
    		}   
        }
        return status;
    }

    public boolean receiveAll(String content, String login) throws RemoteException
    {
    	boolean status = false;
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
    	status = true;
    	return status;
    }
    
    public boolean receivePrivate(String content, String loginRec, String loginExp) throws RemoteException
    {
    	boolean status = false;
    	Date date = new Date();
    	User userRec = new User(loginRec);
    	User userExp = new User(loginExp);
    	for(User u : listUsers)
        {
    		if(u.equals(userRec))
    		{
    			try 
	            {
					u.getOutput().display("[" + date.toString().substring(11, 19) + "] (private) " + loginExp + " : " + content);
					status = true;
				} 
	            catch (RemoteException e) 
	            {
					e.printStackTrace();
				}
    		}  
    		else if(u.equals(userExp))
    		{
    			try 
	            {
					u.getOutput().display("[" + date.toString().substring(11, 19) + "] (private : " + loginRec +") " + loginExp + " : " + content);
					status = true;
				} 
	            catch (RemoteException e) 
	            {
					e.printStackTrace();
				}
    		}
        }
    	return status;
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
