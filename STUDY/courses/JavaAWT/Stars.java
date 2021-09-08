import java.awt.*;

public class Stars extends Frame {
    Choice movieStars = new Choice();
    Label lbl = new Label("Who is your favorite movie start?");

    public Stars(String s) {
        super(s);
        setLayout(new FlowLayout());
        movieStars.addItem( "Antonio Banderas" );
        movieStars.addItem( "Leonardo DiCaprio" );
        movieStars.addItem( "Sandra Bullock" );
        movieStars.addItem( "Hugh Grant" );
        movieStars.addItem( "Julia Roberts ");

        add(lbl);
        add(movieStars);
    }

    public static void main(String[] args) {
        Stars s = new Stars("A sky full of start!");
        s.setSize(400, 400);
        s.setVisible(true);
    }
}
