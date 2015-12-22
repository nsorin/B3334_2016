package chat.client;

import chat.client.Output;
import chat.client.Input;
import chat.client.protocol.OutputItf;
import chat.server.protocol.SessionItf;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class Client 
{
    public static void main(String[] args) 
    {
        String host = (args.length < 1) ? null : args[0];
        try 
        {
            Registry registry = LocateRegistry.getRegistry(host);
            SessionItf session = (SessionItf) registry.lookup("Session");
            Output output = new Output();
            OutputItf oItf = (OutputItf) UnicastRemoteObject.exportObject(output, 0);
            Input input = new Input(session, oItf);
            // Message de bienvenue si tout a réussi
            output.display("Bienvenue. Vous pouvez vous connecter au chat.");
            while(true) 
            {
            	Scanner sc = new Scanner(System.in);
     			String cmd = sc.nextLine();
     			sc.reset();
     			input.command(cmd); 
            }
        }
        catch (Exception e) 
        {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
