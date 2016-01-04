package chat.server;

import java.io.Serializable;
import java.util.Date;
import chat.client.protocol.OutputItf;

public class User implements Serializable
{
    /**
	 * 
	 */
	private static final long serialVersionUID = 7681488508531964229L;
	String login;
    Date timeConnexion;
    OutputItf output;

    public boolean equals(User user){return user.getLogin().equals(login);}

    public String getLogin(){return login;}
    public Date getTimeConnexion(){return timeConnexion;}
    public OutputItf getOutput(){return output;}

    public User(String login, Date date, OutputItf output)
    {
        this.login = login;
        this.timeConnexion = date;
        this.output = output;
    }
    
    public User(String login)
    {
        this.login = login;
        this.timeConnexion = null;
        this.output = null;
    }
}
