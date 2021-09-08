import java.awt.*;

public class PanelTest extends Panel {
    public static void main(String[] args) {
        PanelTest p = new PanelTest();
        Frame f = new Frame("Testing a Panel!");
        f.add(p);
        f.setSize(400, 400);
        f.setVisible(true);
    }
}
