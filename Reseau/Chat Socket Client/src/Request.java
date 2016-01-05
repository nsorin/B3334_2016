

import java.io.Serializable;
import java.util.Date;

/**
 * The Class Request is a class that characterize a request send by a server to a client or 
 * send by a client to a server through a stream (Serializable).
 */
public class Request implements Serializable 
{

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;
	
	/** The Constant CONNECT. */
	public static final int CONNECT = 0;
	
	/** The Constant DISCONNECT. */
	public static final int DISCONNECT = 1;
	
	/** The Constant MESSAGE_ALL. */
	public static final int MESSAGE_ALL = 2;
	
	/** The Constant MESSAGE_PRIVATE. */
	public static final int MESSAGE_PRIVATE = 3;
	
	/** The Constant ERROR. */
	public static final int ERROR = 4;
	
	/** The Constant SUCCESS. */
	public static final int SUCCESS = 5;
	
	/** The Constant EMPTY. */
	public static final int EMPTY = 6;
	
	/** The Constant USERS. */
	public static final int USERS = 7;
	
	/** The name of the user that send the request. */
	private String username;
	
	/** The date when the request is send. */
	private Date date;
	
	/** The type of the request. */
	private int type;
	
	/** The content of the request. */
	private String content;
	
	/** The option of the request. */
	private String option;
	
	/**
	 * Gets the type.
	 *
	 * @return the type
	 */
	public int getType(){return type;}
	
	/**
	 * Gets the user name.
	 *
	 * @return the user name
	 */
	public String getUserName(){return username;}
	
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
	 * Gets the option.
	 *
	 * @return the option
	 */
	public String getOption(){return option;}
	
	/**
	 * Sets the username.
	 *
	 * @param username the new username
	 */
	public void setUsername(String username){this.username = username;}
	
	/**
	 * Sets the date.
	 *
	 * @param date the new date
	 */
	public void setDate(Date date){this.date = date;}
	
	/**
	 * Sets the type.
	 *
	 * @param type the new type
	 */
	public void setType(int type){this.type = type;}
	
	/**
	 * Sets the content.
	 *
	 * @param content the new content
	 */
	public void setContent(String content){this.content = content;}
	
	/**
	 * Sets the option.
	 *
	 * @param option the new option
	 */
	public void setOption(String option){this.option = option;}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString() 
	{
		String s = "";
		String time = date.toString().substring(11, 19);
		switch(type) {
			case CONNECT:
				s = "[" + time + "] " + username + " connected.";
				break;
			case DISCONNECT:
				s = "[" + time + "] " + username + " disconnected.";
				break;
			case MESSAGE_ALL:
				s = "[" + time + "] " + username + " : " + content;
				break;
			case MESSAGE_PRIVATE:
				s = "[" + time + "] " + "(private : " + option + ") " + username + " : " + content;
				break;
			case ERROR:
				s = "[" + time + "] ERROR : " + content;
				break;
			case SUCCESS:
				s = "[" + time + "] SUCCESS : " + content;
				break;
			default:
				break;
		}
		return s;
	}
	
	/**
	 * Instantiates a new request.
	 *
	 * @param type the type of the request
	 * @param content the content of the request
	 * @param option the option of the request
	 */
	public Request(int type, String content, String option)
	{
		this.type = type;
		this.content = content;
		this.option = option;
	}
	
	/**
	 * Instantiates a new request.
	 */
	public Request()
	{
		this.type = ERROR;
		this.content = "";
		this.option = "";
	}
}
