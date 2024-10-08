public class ImproperSynchronizationExample {
    private long someLongValue;
    public long getLongValue() {
        return someLongValue;
    }
    public void setLongValue(long l) {
        someLongValue = l;
    }

    public static void main(String[] args) {
        ImproperSynchronizationExample example = new ImproperSynchronizationExample();
        // Thread 1: Continuously setting a value
        Thread writerThread = new Thread(() -> {
            for (long i = Long.MAX_VALUE; i > 0; i--) {
                example.setLongValue(i);
            }
        });
        // Thread 2: Continuously reading a value
        Thread readerThread = new Thread(() -> {
            for (long i = 0; i < 10000000000L; i++) {
                long value = example.getLongValue();
                if (value % 2 != 0) {  // Check for odd numbers
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
