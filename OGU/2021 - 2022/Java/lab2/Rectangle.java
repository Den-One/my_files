import static java.lang.Math.max;
import static java.lang.Math.min;
import java.awt.*;

public class Rectangle {
    private int x1 = 0;
    private int y1 = 0;
    private int x2 = 0;
    private int y2 = 0;

    public Rectangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public Rectangle(int x2, int y2) {
        this.x1 = x2;
        this.y1 = y2;
    }

    public Rectangle() {
    }

    public void printToConsole() {
        System.out.println("Rectangle points position:");
        System.out.println("x1: " + x1 + "\ny1: " + y1);
        System.out.println("x2: " + x2 + "\ny2: " + y2);
        System.out.println();
    }

    public void move(int dx, int dy) {
        x1 += dx;
        x2 += dx;
        y1 += dy;
        y2 += dy;
    }

    public Rectangle unionWith(Rectangle rec) {
        Rectangle newRec = new Rectangle();
        // Check top rectangle points
        newRec.x1 = max(this.x1, rec.x1);
        newRec.y1 = min(this.y1, rec.y1);
        // Check button rectangle points
        newRec.x2 = min(this.x2, rec.x2);
        newRec.y2 = max(this.y2, rec.y2);
        return newRec;
    }
}
