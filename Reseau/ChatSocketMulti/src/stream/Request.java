package ChatSocketMulti.src.stream;

import java.util.Date;

public class Request {
	
	final int CONNECT = 0;
	final int DISCONNECT = 1;
	final int MESSAGE_ALL = 2;
	final int MESSAGE_PRIVATE = 3;
	
	private String username;
	private Date date;
	private int type;
	private String content;
	
	//Getters
	public int getType(){return type;}
	public String getUserName(){return username;}
	public Date getDate(){return date;}
	public String getContent(){return content;}
	
	//Setters
	public void setUsername(String username){this.username = username;}
	public void setDate(Date date){this.date = date;}
	public void setType(int type){this.type = type;}
	public void setContent(String content){this.content = content;}
	
	public Request(int type, String content)
	{
		this.type = type;
		this.content = content;
	}
}
