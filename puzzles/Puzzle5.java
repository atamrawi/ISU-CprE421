public class Puzzle5 {
    public static void main(String[] args) {
        int x = 900;
        int y = -100;
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        System.out.println("x = " + x);
        System.out.println("y = " + y);
    }
}