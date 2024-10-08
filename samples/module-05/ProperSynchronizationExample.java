public class ProperSynchronizationExample {
    private long someLongValue;
    public synchronized long getLongValue() {
        return someLongValue;
    }
    public synchronized void setLongValue(long l) {
        someLongValue = l;
    }

    public static void main(String[] args) {
        ProperSynchronizationExample example = new ProperSynchronizationExample();
        // Thread 1: Continuously setting a value
        Thread writerThread = new Thread(() -> {
            for (long i = 0; i < 1000000000L; i++) {
                example.setLongValue(i);
            }
        });
        // Thread 2: Continuously reading a value
        Thread readerThread = new Thread(() -> {
            for (long i = 0; i < 10000000000L; i++) {
                if (example.getLongValue() % 2 != 0) {  // Check for odd numbers
                    long value = example.getLongValue();
                    if(value % 2 == 0) {
                        System.out.println("Inconsistent value read: " + value);
                    }
                }
            }
        });

        // Start both threads
        writerThread.start();
        readerThread.start();

        try {
            writerThread.join();
            readerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
