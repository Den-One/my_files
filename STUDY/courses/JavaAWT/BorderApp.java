import java.awt.*;

public class BorderApp extends Frame {
    public BorderApp(String s) {
        super(s);
        setLayout(new BorderLayout());
        Button btnEast = new Button("EAST");
        Button btnWest = new Button("WEST");
        Button btnNorth = new Button("NORTH");
        Button btnSouth = new Button("SOUTH");
        Button btnCenter = new Button("CENTER");
        add("East",btnEast);
        add("West", btnWest);
        add("North",btnNorth);
        add("South", btnSouth);
        add("Center",btnCenter);
    }

    public static void main(String[] args) {
        BorderApp ba = new BorderApp("Border Layout Demo!");
        ba.setSize(400, 400);
        ba.setVisible(true);
    }
}
