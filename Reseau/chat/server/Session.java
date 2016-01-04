package chat.server;

import chat.client.protocol.OutputItf;
import chat.server.protocol.SessionItf;
import chat.server.User;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.rmi.RemoteException;
import java.util.Date;
import java.util.LinkedList;


public class Session implements SessionItf, Serializable
{
	private static final long serialVersionUID = -1618331548764071912L;
	private LinkedList<String> listMessages;
    private LinkedList<User> listUsers;

    public boolean connect(String login, OutputItf output) throws RemoteException
    {
        boolean status = false;
        Date date = new Date();
        User user = new User(login,date,output);
        if(!listUsers.contains(user))
        {
        	String msg = "[" + date.toString().substring(11, 19) + "] " + login + " connected.";
            listUsers.addFirst(user);
            restoreSession(output);
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
    	String msg = "[" + date.toString().substring(11, 19) + "] " + login + " : " + content;
    	for(User u : listUsers)
        {
            try 
            {
				u.getOutput().display(msg);
			} 
            catch (RemoteException e) 
            {
				e.printStackTrace();
			}
        }
    	listMessages.addLast(msg);
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
    
    public void writeLog(String filename) throws IOException {
		FileOutputStream fos = new FileOutputStream(filename, false);
		ObjectOutputStream out = new ObjectOutputStream(fos);
		out.writeObject(this);
		out.close();
		fos.close();
		System.exit(0);
    }
    
    public static Session readLog(String filename) {
    	Session session = null;
    	FileInputStream fis;
		try {
			fis = new FileInputStream(filename);
			ObjectInputStream in = new ObjectInputStream(fis);
	    	session = (Session) in.readObject();	    	
	    	session.listUsers.clear();
	    	in.close();
	    	fis.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			session = new Session();
			System.out.println("No log to read");
		}
    	return session;
    }

    public void restoreSession(OutputItf output) {
    	for(String msg : listMessages) {
    		try {
				output.display(msg);
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
    	}
    }
    
    public void checkMessageList() {
    	System.out.println("Restored messages :");
    	for(String msg : listMessages) {
    		System.out.println(msg);
    	}
    }
    
    public Session()
    {
        listMessages = new LinkedList<String>();
        listUsers = new LinkedList<User>();
    }
}
