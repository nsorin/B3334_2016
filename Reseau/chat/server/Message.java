package chat.server;

import chat.server.User;

import java.util.Date;

public class Message
{
    User user;
    Date date;
    String content;

	public User getUser(){return user;}
	public Date getDate(){return date;}
	public String getContent(){return content;}
	public void setUser(User user){this.user = user;}
	public void setDate(Date date){this.date = date;}
	public void setContent(String content){this.content = content;}
	
    public Message(User user, Date date, String content)
    {
        this.date = date;
        this.content = content;
    }

}
