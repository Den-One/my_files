import java.awt.*;

public class TextComments extends Frame {
    TextArea txtComment=new TextArea();
    Label lblComment= new Label ( "Comments :" );

    public TextComments(String title) {
        super(title);
        setLayout(new FlowLayout());
        add(lblComment);
        add(txtComment);
    }

    public static void main(String[] args) {
        TextComments t = new TextComments("Testing components!");
        t.setSize(500, 500);
        t.setVisible(true);
    }
}
