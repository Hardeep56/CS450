// C++ Concurrency Application
// Demonstrates two threads: one counting up to 20 and another counting down to 0

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool firstThreadComplete = false;

// Function for the first thread: counts up to 20
void countUp() {
    for (int i = 1; i <= 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Thread 1 (Counting Up): " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
    std::unique_lock<std::mutex> lock(mtx);
    firstThreadComplete = true;
    cv.notify_one(); // Notify the second thread
}

// Function for the second thread: counts down from 20 to 0
void countDown() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return firstThreadComplete; }); // Wait until the first thread completes

    for (int i = 20; i >= 0; --i) {
        std::cout << "Thread 2 (Counting Down): " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

int main() {
    // Create two threads
    std::thread t1(countUp);
    std::thread t2(countDown);

    // Join threads to ensure they complete before the program exits
    t1.join();
    t2.join();

    std::cout << "Both threads have completed their execution." << std::endl;
    return 0;
}
