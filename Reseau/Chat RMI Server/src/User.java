import java.io.Serializable;
import java.util.Date;

/**
 * The Class User is the class that characterize a user entity.
 */
public class User implements Serializable
{
    
    /** The Constant serialVersionUID. */
	private static final long serialVersionUID = 7681488508531964229L;
	
	/** The login of the user. */
	String login;
    
    /** The time connection. */
    Date timeConnexion;
    
    /** The output object linked to the UI of the user. */
    OutputItf output;

    /**
     * Method that test if the current user is equal to a user put in argument
     *
     * @param user the user that will be compared with the current user
     * @return true, if the current user is equal to the user in argument
     */
    public boolean equals(User user){return user.getLogin().equals(login);}

    /**
     * Gets the login.
     *
     * @return the login
     */
    public String getLogin(){return login;}
    
    /**
     * Gets the time connexion.
     *
     * @return the time connexion
     */
    public Date getTimeConnexion(){return timeConnexion;}
    
    /**
     * Gets the output.
     *
     * @return the output
     */
    public OutputItf getOutput(){return output;}

    /**
     * Instantiates a new user.
     *
     * @param login the login of the new user
     * @param date the date when the new user is created(connected)
     * @param output the output linked to the UI of the new user
     */
    public User(String login, Date date, OutputItf output)
    {
        this.login = login;
        this.timeConnexion = date;
        this.output = output;
    }
    
    /**
     * Instantiates a new user that will be used to make comparisons.
     *
     * @param login the login
     */
    public User(String login)
    {
        this.login = login;
        this.timeConnexion = null;
        this.output = null;
    }
}
