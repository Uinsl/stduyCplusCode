/*
#if 1
#endif
*/

// void* func()
// 



// �ź��� C++ ��׼�� ���ź��� 
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//�����ź�������

sem_t sem;


#endif

#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

class ThreadPool {
public:
    ThreadPool(int numThreads) : stop(false) {
        for (int i = 0; i < numThreads; ++i) {

            std::thread t99([this]
                {
                    while (true) {
                        std::unique_lock<std::mutex> lock(mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        std::function<void()> task(std::move(tasks.front()));
                        tasks.pop();
                        lock.unlock();
                        task();
                    }
                });

            threads.emplace_back(t99);
         
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& thread : threads) {
            thread.join();
        }
    }

    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lock(mutex);
            tasks.emplace(std::move(task));
        }
        condition.notify_one();
    }

private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex mutex;
    std::condition_variable condition;
    bool stop;
};

int main() {
    ThreadPool pool(4);
    for (int i = 0; i < 8; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Task " << i << " is done" << std::endl;
            });
    }
    return 0;
}

#endif



// condition_variable 
// �²����������������
#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
std::mutex g_mutex;
std::condition_variable g_cv;
std::queue<int> g_queue;

// mark
bool shipment_available()
{
    return false;
}

void Producer() {
    for (int i = 0; i < 10; i++) {
        {
            std::unique_lock<std::mutex> lock(g_mutex);
            g_queue.push(i);
            std::cout << "Producer: produced " << i << std::endl;
        }
        g_cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


void Consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(g_mutex);
        bool isEmpty = g_queue.empty();
        // wait false ���� 
        // g_cv.wait(lock, []() { return !g_queue.empty(); });
        g_cv.wait(lock, shipment_available);
        int value = g_queue.front();
        g_queue.pop();
        std::cout << "Consumer: consumed " << value << std::endl;
    }
}
int main() {
    std::thread producer_thread(Producer);
    std::thread consumer_thread(Consumer);
    producer_thread.join();
    consumer_thread.join();
    return 0;
}



#endif



//����Ϊʲô����
#if 0 
#include <iostream>                // std::cout
#include <thread>                // std::thread, std::this_thread::yield
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available()
{
    return cargo != 0;
}

// �������߳�.
void consume(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::unique_lock <std::mutex> lck(mtx);
        cv.wait(lck, shipment_available);
        std::cout << cargo << '\n';
        cargo = 0;
    }
}

int main()
{
    std::thread consumer_thread(consume, 10); // �������߳�.

    // ���߳�Ϊ�������߳�, ���� 10 ����Ʒ.
    for (int i = 0; i < 10; ++i)
    {
        while (shipment_available())
        {
            std::this_thread::yield();
        }
        std::unique_lock <std::mutex> lck(mtx);
        cargo = i + 1;
        cv.notify_one();
    }

    consumer_thread.join();

    return 0;
}


#endif





// �߳���������
#if 0
#include <iostream>
#include <thread>
using namespace std;

void thread_1()
{
    // C++ �� cout ����ԭ��
    cout << "���߳�1" << endl;
}

void thread_2(int x)
{
    cout << "int x = " << x << endl;
    cout << "���߳�2" << endl;
}



int main() {
    std::cout << "���߳�Start.\n";
    thread t1(thread_1);
    thread t2(thread_2, 100);
 
    // join ������        
    // �߳� 1��2 ͬʱ����    
    t1.join();
    t2.join();

    // detach() ���룬������
    // t1.detach();          
    // t2.detach();

    // bool isJoin = t1.joinable();
    // ��ʹ��join(); �������򶼻��ڵ���ִ�����
    std::cout << "���߳̽���.\n";//����join���
    std::cout << "���߳�End.\n";//����join���
}

#endif