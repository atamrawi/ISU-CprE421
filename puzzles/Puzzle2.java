import java.util.Random;

public class Puzzle2 {

	public static void main(String[] args) {
		Random rnd = new Random();
		int odds = 0;
		int runs = 1000;
		for(int i=0; i<runs; i++) {
			int num = rnd.nextInt();
			if(isOdd(num)) {
				odds++;
			}
		}
		double oddPercentage = ((double) odds / (double) runs) * 100.0;
		System.out.println("Odd: " + String.format("%.2f", oddPercentage) + "%");
	}
	
	private static boolean isOdd(int num) {
		return num % 2 == 1;
	}
	
}