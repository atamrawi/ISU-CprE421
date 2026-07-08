import java.util.HashMap;

public class HashMapTimeComplexityAttack {

    // Custom class with a deliberately poor hashCode method that forces collisions
    static class CollidingKey {
        private String value;

        public CollidingKey(String value) {
            this.value = value;
        }

        @Override
        public int hashCode() {
            // All instances of this class will have the same hash code, forcing collision
            return 1;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            CollidingKey other = (CollidingKey) obj;
            return value.equals(other.value);
        }

        @Override
        public String toString() {
            return value;
        }
    }

    public static void main(String[] args) {
        // Create a HashMap
        HashMap<CollidingKey, Integer> map = new HashMap<>();

        // Insert a large number of keys that will collide in the same hash bucket
        int numKeys = 10000;
        long startTime = System.currentTimeMillis();

        for (int i = 0; i < numKeys; i++) {
            map.put(new CollidingKey("Key" + i), i);
        }

        long endTime = System.currentTimeMillis();
        System.out.println("Time taken to insert " + numKeys + " colliding keys: " + (endTime - startTime) + " ms");

        // Perform lookups to demonstrate how the attack slows down operations
        startTime = System.currentTimeMillis();
        for (int i = 0; i < numKeys; i++) {
            map.get(new CollidingKey("Key" + i));
        }
        endTime = System.currentTimeMillis();
        System.out.println("Time taken to lookup " + numKeys + " colliding keys: " + (endTime - startTime) + " ms");
    }
}
