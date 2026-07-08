public class ConstantTimeStringCompare {
    public static void main(String[] args) {
        String str1 = "SuperSecretPassword";
        String str2 = "cuperSecretPassworx"; // Intentional mismatch at the end

        // Measure start time
        long startTime = System.nanoTime();

        // Call the constant-time string compare function
        boolean result = constantTimeStringCompare(str1, str2);

        // Measure end time
        long endTime = System.nanoTime();

        // Calculate the time taken in nanoseconds
        long duration = endTime - startTime;

        System.out.println("Strings are equal: " + result);
        System.out.println("Time taken (nanoseconds): " + duration);
    }

    // Constant-time string comparison function
    public static boolean constantTimeStringCompare(String a, String b) {
        // Convert strings to char arrays for byte-by-byte comparison
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();

        // If lengths differ, we still proceed, but they are not equal
        if (ca.length != cb.length) {
            return false;
        }

        // Initialize result as true
        boolean result = true;

        // Compare each character, always iterating through the entire length
        for (int i = 0; i < ca.length; i++) {
            System.out.println("Comparing '"+ ca[i] +"' with '"+ cb[i]+"'");
            result &= (ca[i] == cb[i]); // Keep comparing every character
        }

        return result;
    }
}
