public class NullPointerExample {
    public static void main(String[] args) {
        Person person = null;  // person is not initialized (points to null)
        
        // Attempt to call a method on the null object
        person.sayHello();
    }
}

class Person {
    public void sayHello() {
        System.out.println("Hello!");
    }
}
