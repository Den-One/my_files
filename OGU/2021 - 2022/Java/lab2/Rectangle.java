public class Rectangle {
    private int x1;
    private int y1;
    private int x2;
    private int y2;

    public Rectangle(int x1, int y1,
                     int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public Rectangle(int x2, int y2) {
        x1 = 0;
        y1 = 0;
        this.x2 = x2;
        this.y2 = y2;
    }

    public Rectangle() {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }

    public void rect_print() {
        System.out.println("x1: " + x1);
        System.out.println("y1: " + y1);
        System.out.println("x2: " + x2);
        System.out.println("y2: " + y2);
    }

    public void move(int dx, int dy) {
        x1 += dx;
        x2 += dx;
        y1 += dy;
        y2 += dy;
    }

    public void union(int x1s, int y1s, int x2s, int y2s) {
        // x, y - height and width
        // 1, 2 - two points of rectangle
        // f, s - first and second rectangles
        int[] arrayResult = new int[4];
        // checking top points
        if (this.x1 <= x1s && x1s <= this.x2) {
            arrayResult[0] = x1s;
        }
        else if (this.x1 > x1s && x1s <= this.x2) {
            arrayResult[0] = this.x1;
        }
        if (this.y1 >= y1s && y1s >= this.y2) {
            arrayResult[1] = y1s;
        }
        else if (this.y1 < y1s && y1s >= this.y2) {
            arrayResult[1] = this.y1;
        }

        // checking button points
        if (x1s <= this.x2 && this.x2 <= x2s) {
            arrayResult[2] = this.x2;
        }
        else if (x1s <= this.x2 && this.x2 > x2s) {
            arrayResult[2] = x2s;
        }
        if (y1s >= this.y2 && this.y2 >= y2s) {
            arrayResult[3] = this.y2;
        }
        else if (y1s >= y2 && this.y2 < y2s) {
            arrayResult[3] = y2s;
        }

        for (int i = 0; i < 4; i++) {
            System.out.println(arrayResult[i]);
        }
    }
}
