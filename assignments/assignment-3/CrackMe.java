import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class CrackMe {
	
	public static void main(String[] args) throws Exception {
		long sleepy = 1;
		while (true) {
			Thread.sleep(sleepy++);
			long seed = new Random().nextLong();
			Random rnd = new Random(seed);
			final int range = 26;
			String prefix = "";
			for (int i = 0; i < 80; i++) {
				int v = rnd.nextInt(range) + 1;
				char c = (char) ('`' + v);
				prefix += c;
			}
			prefix = prefix.replace("s", "-");
			String[] preconditions = prefix.split("-");
			if (preconditions.length != 3) {
				continue;
			}
			if (!preconditions[0].equals("xgjv")) {
				continue;
			}
			if (!preconditions[1].equals("xceg")) {
				continue;
			}
			if (!preconditions[2].equals("rtakdmavlctjtnfdwicmliizylrfqynpbolgexazdutylgzrbyrcybzgdmjydylzhrbiml")) {
				continue;
			}
			String suffix = "";
			for (int i = 0; i < 20; i++) {
				int v = rnd.nextInt(range) + 1;
				char c = (char) ('`' + v);
				suffix += c;
			}
			suffix = suffix.replace("s", "-");
			if (SHA256(suffix).startsWith("e9")) {
				System.out.println("You unlocked the challenge - This is your key [" + suffix.substring(0, 15) + "]");
				System.out.println("Your job now is to write a solution summary");
				break;
			}
		}
	}

	private static String SHA256(String input) throws NoSuchAlgorithmException {
		MessageDigest digest = MessageDigest.getInstance("SHA-256");
		byte[] hash = digest.digest(input.getBytes(StandardCharsets.UTF_8));
		StringBuffer hexString = new StringBuffer();
		for (int i = 0; i < hash.length; i++) {
			String hex = Integer.toHexString(0xff & hash[i]);
			if (hex.length() == 1) {
				hexString.append('0');
			}
			hexString.append(hex);
		}
		return hexString.toString();
	}

}