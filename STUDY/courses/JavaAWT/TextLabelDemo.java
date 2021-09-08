import java.awt.*;

class TextLabelDemo extends Frame {
    TextField txtName = new TextField(20);
    Label lblName = new Label("Name: ");

    public TextLabelDemo(String title) {
        super(title);
        setLayout(new FlowLayout());
        add(lblName);
        add(txtName);
    }

    public static void main(String[] args) {
        TextLabelDemo t = new TextLabelDemo("Testing!");
        t.setSize(500, 500);
        t.setVisible(true);
        //t.show(); was removed
    }
}
