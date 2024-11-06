import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EmailValidator {
    private static final String EMAIL_PATTERN = "([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+)*";
    private static final Pattern pattern = Pattern.compile(EMAIL_PATTERN);

    public static boolean isValidEmail(String email) {
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }

    public static void main(String[] args) {
        String testEmail = "test@gmail.com";
        long startTime = System.nanoTime();
        boolean result = isValidEmail(testEmail);
        long endTime = System.nanoTime();

        System.out.println("Is valid: " + result);
        System.out.println("Time taken: " + (endTime - startTime) / 1e6 + " ms");
    }
}
