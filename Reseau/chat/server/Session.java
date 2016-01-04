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

/**
 * The Class Session is the class that characterize the session entity which is symbolized the status of the chat.
 */
public class Session implements SessionItf, Serializable
{
	
	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -1618331548764071912L;
	
	/** The list of the messages. */
	private LinkedList<String> listMessages;
    
    /** The list of the connected users. */
    private LinkedList<User> listUsers;

    /* (non-Javadoc)
     * @see chat.server.protocol.SessionItf#connect(java.lang.String, chat.client.protocol.OutputItf)
     */
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

    /* (non-Javadoc)
     * @see chat.server.protocol.SessionItf#disconnect(java.lang.String)
     */
    public boolean disconnect(String login) throws RemoteException
    {
        boolean status = false;
        Date date = new Date();
        User user = new User(login);
        for(User u : listUsers)
        {
        	if(u.equals(user))
    		{
    			listUsers.remove(u);
				String msg = "[" + date.toString().substring(11, 19) + "] " + login + " disconnected.";
				this.send(msg);
				status = true;
    		}
        }
        if(status)
    	{
        	for(User u : listUsers)
            {
        		u.getOutput().removeUser(login);
            }
    	}
        return status;
    }

    /* (non-Javadoc)
     * @see chat.server.protocol.SessionItf#receiveAll(java.lang.String, java.lang.String)
     */
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
    
    /* (non-Javadoc)
     * @see chat.server.protocol.SessionItf#receivePrivate(java.lang.String, java.lang.String, java.lang.String)
     */
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

    /**
     * Method that display a notification to all connected users.
     *
     * @param notification the notification that will be sent to the user.
     */
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
    
    /**
     * Method that write a log in the log File
     *
     * @param filename the filename of the log File
     * @throws IOException Signals that an I/O exception has occurred.
     */
    public void writeLog(String filename) throws IOException 
    {
		FileOutputStream fos = new FileOutputStream(filename, false);
		ObjectOutputStream out = new ObjectOutputStream(fos);
		out.writeObject(this);
		out.close();
		fos.close();
		System.exit(0);
    }
    
    /**
     * Method that read a log from a log File
     *
     * @param filename the filename
     * @return the session
     */
    public static Session readLog(String filename) 
    {
    	Session session = null;
    	FileInputStream fis;
		try 
		{
			fis = new FileInputStream(filename);
			ObjectInputStream in = new ObjectInputStream(fis);
	    	session = (Session) in.readObject();	    	
	    	session.listUsers.clear();
	    	in.close();
	    	fis.close();
		} 
		catch (Exception e) 
		{
			session = new Session();
			System.out.println("No log to read");
		}
    	return session;
    }

    /**
     * Method that restore the session of the chat in the UI of a user.
     *
     * @param output the output linked to the UI of the user
     */
    public void restoreSession(OutputItf output) 
    {
    	for(String msg : listMessages) 
    	{
    		try 
    		{
				output.display(msg);
			} 
    		catch (RemoteException e) 
    		{
				e.printStackTrace();
			}
    	}
    }
    
    /**
     * Method that show in the console the messages restored
     */
    public void checkMessageList() 
    {
    	System.out.println("Restored messages :");
    	for(String msg : listMessages) 
    	{
    		System.out.println(msg);
    	}
    }
    
    /**
     * Instantiates a new session.
     */
    public Session()
    {
        listMessages = new LinkedList<String>();
        listUsers = new LinkedList<User>();
    }
}
