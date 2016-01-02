package ChatSocketMulti.src.stream;

import java.io.Serializable;
import java.util.Date;

public class Request implements Serializable {

	private static final long serialVersionUID = 1L;
	public static final int CONNECT = 0;
	public static final int DISCONNECT = 1;
	public static final int MESSAGE_ALL = 2;
	public static final int MESSAGE_PRIVATE = 3;
	public static final int ERROR = 4;
	public static final int SUCCESS = 5;
	public static final int EMPTY = 6;
	public static final int USERS = 7;
	
	private String username;
	private Date date;
	private int type;
	private String content;
	private String option;
	
	//Getters
	public int getType(){return type;}
	public String getUserName(){return username;}
	public Date getDate(){return date;}
	public String getContent(){return content;}
	public String getOption(){return option;}
	
	//Setters
	public void setUsername(String username){this.username = username;}
	public void setDate(Date date){this.date = date;}
	public void setType(int type){this.type = type;}
	public void setContent(String content){this.content = content;}
	public void setOption(String option){this.option = option;}
	
	public String toString() {
		String s = "";
		@SuppressWarnings("deprecation")
		String time = date.getHours() + ":" + date.getMinutes() + ":" + date.getSeconds();
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
	
	public Request(int type, String content, String option)
	{
		this.type = type;
		this.content = content;
		this.option = option;
	}
	
	public Request()
	{
		this.type = ERROR;
		this.content = "";
		this.option = "";
	}
}
