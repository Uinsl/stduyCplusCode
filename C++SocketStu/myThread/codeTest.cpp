#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

std::vector<std::thread> threads;
std::queue<std::function<void()>> tasks;
std::mutex mutex;
std::condition_variable condition;
bool stop;

void func() {

    std::cout << "nothig \n";
}




int main() {

    /*
    std::thread t99([]
        {
            while (true) {
                std::unique_lock<std::mutex> lock(mutex);
                condition.wait(lock, [] { return stop || !tasks.empty(); });
                if (stop && tasks.empty()) {
                    return;
                }
                std::function<void()> task(std::move(tasks.front()));
                tasks.pop();
                lock.unlock();
                task();
            }
        });
    */


    threads.emplace_back(std::thread(func)); //这个是可以的。
    return 0;
}
/*
https://blog.csdn.net/unonoi/article/details/114680819
emplace_back 回调用一次，“ threads ” 这个东西的类型，的构造函数.
你用线程d的代码，
不也是，thread t1 ( func );
emplace_back 就是实现上面的效果。
emplace_back（thread(func)）;
*/


#endif
