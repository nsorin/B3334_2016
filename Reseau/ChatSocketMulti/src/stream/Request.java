package ChatSocketMulti.src.stream;

import java.util.Date;

public class Request {
	
	public static final int CONNECT = 0;
	public static final int DISCONNECT = 1;
	public static final int MESSAGE_ALL = 2;
	public static final int MESSAGE_PRIVATE = 3;
	
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
		return "[" + date + "] " + username + " : " + content;
	}
	
	public Request(int type, String content, String option)
	{
		this.type = type;
		this.content = content;
		this.option = option;
	}
}
