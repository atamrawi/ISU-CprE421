import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class IntensiveHashCollisionExample {

    public static void main(String[] args) {

        int blocks = 10;   // 2^10 = 1024 colliding strings

        List<String> keys = generateCollisions(blocks);

        HashMap<String, Integer> map = new HashMap<>();

        // Insert all colliding strings
        for (int i = 0; i < keys.size(); i++) {
            map.put(keys.get(i), i);
        }

        System.out.println("Number of generated keys: " + keys.size());
        System.out.println("HashMap size:            " + map.size());

        // Every generated string should have exactly the same hashCode
        int commonHash = keys.get(0).hashCode();

        System.out.println("Common hashCode:         " + commonHash);

        System.out.println("\nFirst 10 colliding strings:");

        for (int i = 0; i < Math.min(10, keys.size()); i++) {
            String key = keys.get(i);

            System.out.println(
                key + "  -> hashCode = " + key.hashCode()
            );
        }

        // Verify that every key has the same hashCode
        boolean allCollide = true;

        for (String key : keys) {
            if (key.hashCode() != commonHash) {
                allCollide = false;
                break;
            }
        }

        System.out.println("\nAll keys have the same hashCode: " + allCollide);

        // Demonstrate that HashMap still distinguishes the keys
        System.out.println("\nExample lookups:");

        for (int i = 0; i < Math.min(5, keys.size()); i++) {
            String key = keys.get(i);

            System.out.println(
                "map.get(\"" + key + "\") = " + map.get(key)
            );
        }
    }


    /*
     * Generate 2^blocks different strings.
     *
     * Each block is either:
     *
     *     "Aa"
     *
     * or
     *
     *     "BB"
     *
     * Because:
     *
     *     "Aa".hashCode() == "BB".hashCode()
     *
     * every generated string has the same hashCode.
     */
    static List<String> generateCollisions(int blocks) {

        List<String> result = new ArrayList<>();

        int count = 1 << blocks;

        for (int i = 0; i < count; i++) {

            StringBuilder s = new StringBuilder();

            for (int bit = 0; bit < blocks; bit++) {

                if ((i & (1 << bit)) == 0) {
                    s.append("Aa");
                } else {
                    s.append("BB");
                }
            }

            result.add(s.toString());
        }

        return result;
    }
}