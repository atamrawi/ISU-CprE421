import java.util.HashMap;

public class HashCollisionExample {
    
    public static void main(String[] args) {
        // Create a HashMap
        HashMap<String, Integer> map = new HashMap<>();
        
        // These are three different strings that generate the same hashCode
        // Using known strings that produce the same hashcode by coincidence or design
        String key1 = "FB";  // hashCode = 2236
        String key2 = "Ea";  // hashCode = 2236
        
        // Insert the colliding keys into the HashMap
        map.put(key1, 1);
        map.put(key2, 2);
        
        // Display the map size (should be 2, as keys are considered unique)
        System.out.println("HashMap Size: " + map.size());
        
        // Demonstrate that all keys are present and their corresponding values
        System.out.println("Value for key1 (FB): " + map.get(key1));
        System.out.println("Value for key2 (Ea): " + map.get(key2));
        
        // Display the hash codes for each key to confirm collision
        System.out.println("HashCode of key1 (FB): " + key1.hashCode());
        System.out.println("HashCode of key2 (Ea): " + key2.hashCode());
    }
}
