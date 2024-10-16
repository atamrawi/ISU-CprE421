public class InsecureStringCompare {
    public static void main(String[] args) {
        String str1 = "SuperSecretPassword";
        String str2 = "SuperSecretPassworx"; // Intentional mismatch at the end

        // Measure start time
        long startTime = System.nanoTime();

        // Call the insecure string compare function
        boolean result = insecureStringCompare(str1, str2);

        // Measure end time
        long endTime = System.nanoTime();

        // Calculate the time taken in nanoseconds
        long duration = endTime - startTime;

        System.out.println("Strings are equal: " + result);
        System.out.println("Time taken (nanoseconds): " + duration);
    }

    // Insecure string comparison function (vulnerable to timing attacks)
    public static boolean insecureStringCompare(String a, String b) {
        // Convert strings to char arrays for byte-by-byte comparison
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();

        // Ensure both strings are of the same length
        if (ca.length != cb.length) {
            return false;
        }

        // Compare character by character
        for (int i = 0; i < ca.length; i++) {
            if (ca[i] != cb[i]) {
                return false; // Return as soon as a mismatch is found (timing vulnerability)
            }
        }

        return true; // Strings are equal
    }
}
