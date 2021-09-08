import java.awt.*;

public class ButtonTest extends Frame {
    Button btnBread = new Button("Bread");
    Button btnButter = new Button("Butter");
    Button btnJam = new Button("Jam");

    public ButtonTest(String title) {
        super(title);
        setLayout(new FlowLayout());
        add(btnBread);
        add(btnButter);
        add(btnJam);
    }

    public static void main(String[] args) {
        ButtonTest b = new ButtonTest("The three little buttons");
        b.setSize(300, 300);
        b.setVisible(true);
    }
}
