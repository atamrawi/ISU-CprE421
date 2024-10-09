public class TrickyNullPointerExample {
    public static void main(String[] args) {
        // Create an array of Person objects with size 5
        Person[] people = new Person[5];

        // Initialize some elements of the array, but not all
        people[0] = new Person("Alice");
        people[2] = new Person("Bob");

        // Loop through the array and attempt to print each person's name
        for (int i = 0; i < people.length; i++) {
            // This line will throw a NullPointerException for uninitialized elements
            System.out.println(people[i].getName());
        }
    }
}

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
