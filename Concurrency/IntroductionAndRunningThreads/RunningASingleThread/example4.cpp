#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finished work 1 in thread \n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread \n";

}

int main() {
    std::thread thread(threadFunction);
    thread.join();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main\n";

    return 0;
}