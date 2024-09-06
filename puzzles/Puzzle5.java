public class Puzzle5 {
    public static void main(String[] args) {
        int x = 900;
        int y = -100;
        System.out.println("x = " + Integer.toBinaryString(x));
        System.out.println("y = " + Integer.toBinaryString(y));
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        System.out.println("x = " + x);
        System.out.println("y = " + y);
    }
}