package chat.server;

import chat.server.User;

import java.util.Date;

/**
 * The Class Message is the class that characterize a message send by a user.
 */
public class Message
{
    
    /** The user that send the message. */
    User user;
    
    /** The date of the message. */
    Date date;
    
    /** The content of the message. */
    String content;

	/**
	 * Gets the user.
	 *
	 * @return the user
	 */
	public User getUser(){return user;}
	
	/**
	 * Gets the date.
	 *
	 * @return the date
	 */
	public Date getDate(){return date;}
	
	/**
	 * Gets the content.
	 *
	 * @return the content
	 */
	public String getContent(){return content;}
	
	/**
	 * Sets the user.
	 *
	 * @param user the new user
	 */
	public void setUser(User user){this.user = user;}
	
	/**
	 * Sets the date.
	 *
	 * @param date the new date
	 */
	public void setDate(Date date){this.date = date;}
	
	/**
	 * Sets the content.
	 *
	 * @param content the new content
	 */
	public void setContent(String content){this.content = content;}
	
    /**
     * Instantiates a new message.
     *
     * @param user the user that send the message
     * @param date the date of the message
     * @param content the content of the message
     */
    public Message(User user, Date date, String content)
    {
        this.date = date;
        this.content = content;
    }

}
