public class Test {
    public static void main(String[] args) {

        Rectangle[] rectangles = new Rectangle[3];
        rectangles[0] = new Rectangle(0, 10,8, 2);
        rectangles[1] = new Rectangle(3, 4);
        rectangles[2] = new Rectangle();

        System.out.println("Rectangles before moving:");
        printRectanglesToConsole(rectangles);

        rectangles[0].move(2, 1);
        rectangles[1].move(3, 0);
        rectangles[2].move(5, 9);

        System.out.println("Rectangles after moving:");
        printRectanglesToConsole(rectangles);

        Rectangle unionRec = rectangles[0].unionWith(rectangles[1]);

        System.out.println("New rectangle after union:");
        unionRec.printToConsole();
    }

    public static void printRectanglesToConsole(Rectangle[] rectangles) {
        for (Rectangle rec : rectangles) {
            rec.printToConsole();
        }
    }
}
