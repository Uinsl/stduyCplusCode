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


    threads.emplace_back(std::thread(func)); //����ǿ��Եġ�
    return 0;
}
/*
https://blog.csdn.net/unonoi/article/details/114680819
emplace_back �ص���һ�Σ��� threads �� ������������ͣ��Ĺ��캯��.
�����߳�d�Ĵ��룬
��Ҳ�ǣ�thread t1 ( func );
emplace_back ����ʵ�������Ч����
emplace_back��thread(func)��;
*/


#endif
