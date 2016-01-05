package chat.server;

import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

import chat.server.protocol.SessionItf;

/**
 * The Class Server is the class that initiate the Registry and the Session of the chat.
 */
public class Server 
{
	/** The path of the log File */
	public static final String LOG_PATH = "chat/chat.log";
    
    /**
     * The main method that create the registry and the restore the session saved on a log file and bind it to the registry.
     *
     * @param args the arguments
     */
    public static void main(String args[]) 
    {
        try 
        {
            LocateRegistry.createRegistry(1099);
            Session obj = Session.readLog(LOG_PATH);
            SessionItf stub = (SessionItf) UnicastRemoteObject.exportObject(obj, 0);
            obj.checkMessageList();
            // Bind the remote object's stub in the registry
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Session", stub);

            System.err.println("Server ready");
            boolean close = false;
            while(!close) 
            {            	
            	Scanner sc = new Scanner(System.in);
            	String cmd = sc.nextLine();
            	if(cmd.equals("close")) 
            	{
            		close = true;
            		break;
            	}
            	sc.close();
            }
            System.out.println("Server closed");
            obj.writeLog(LOG_PATH);
        } 
        catch (Exception e) 
        {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
