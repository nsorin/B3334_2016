package chat.server

import chat.server.User;

import java.util.Date;

public class Message
{
    User user;
    Date date;
    String hour;
    String content;

    public Message(User user, Date date, String hour, String content)
    {
        this.date = date;
        this.hour = hour;
        this.content = content;
    }
}
