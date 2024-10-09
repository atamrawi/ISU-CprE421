import java.lang.ref.PhantomReference;
import java.lang.ref.ReferenceQueue;

public class GarbageCollectionExample {
    public static void main(String[] args) throws InterruptedException {
        ReferenceQueue<Object> referenceQueue = new ReferenceQueue<Object>();
        Object myObject = new Object();

        // Create a PhantomReference to the myObject with the referenceQueue
        PhantomReference<Object> phantomRef = new PhantomReference<>(myObject, referenceQueue);

        // Create a second reference to the same object
        Object secondReference = myObject;

        System.out.println("Setting the first reference (myObject) to null...");
        // Set the first reference to null, but secondReference still holds the object
        myObject = null;

        // Request garbage collection (it won't collect yet because secondReference still holds the object)
        System.gc();

        // Wait for the object to be enqueued in the ReferenceQueue
        if (referenceQueue.remove(2000) != null) {
            System.out.println("Garbage collector has started cleaning up MyObject.");
        } else {
            System.out.println("MyObject was not garbage collected yet. A reference still exists.");
        }

        System.out.println("Now setting the second reference (secondReference) to null...");
        // Set the second reference to null
        secondReference = null;

        // Request garbage collection again
        System.gc();

        // Wait for the object to be enqueued in the ReferenceQueue
        if (referenceQueue.remove(5000) != null) {
            System.out.println("Garbage collector has started cleaning up MyObject after both references were null.");
        } else {
            System.out.println("MyObject was not garbage collected within the timeout.");
        }
    }
}

