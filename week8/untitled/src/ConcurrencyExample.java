// Java Concurrency Application
// Demonstrates two threads: one counting up to 20 and another counting down to 0

class CounterApp {
    private boolean firstThreadComplete = false;

    // Synchronized method to ensure proper thread communication
    public synchronized void countUp() {
        for (int i = 1; i <= 20; i++) {
            System.out.println("Thread 1 (Counting Up): " + i);
            try {
                Thread.sleep(100); // Simulate work with a delay
            } catch (InterruptedException e) {
                System.out.println("Thread 1 interrupted.");
            }
        }
        firstThreadComplete = true;
        notify(); // Notify the second thread
    }

    public synchronized void countDown() {
        while (!firstThreadComplete) {
            try {
                wait(); // Wait for the first thread to complete
            } catch (InterruptedException e) {
                System.out.println("Thread 2 interrupted.");
            }
        }
        for (int i = 20; i >= 0; i--) {
            System.out.println("Thread 2 (Counting Down): " + i);
            try {
                Thread.sleep(100); // Simulate work with a delay
            } catch (InterruptedException e) {
                System.out.println("Thread 2 interrupted.");
            }
        }
    }
}

public class ConcurrencyExample {
    public static void main(String[] args) {
        CounterApp counterApp = new CounterApp();

        // Create two threads for counting
        Thread thread1 = new Thread(counterApp::countUp);
        Thread thread2 = new Thread(counterApp::countDown);

        // Start both threads
        thread1.start();
        thread2.start();

        try {
            // Ensure both threads complete before exiting
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Both threads have completed their execution.");
    }
}
