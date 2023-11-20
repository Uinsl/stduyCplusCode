//-------线程池
#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <vector>
#include <functional>

class threadPool {
public:
    //把stop默认为f
    threadPool(int numThread) :stop(false) {
        for (int i = 0; i < numThread; i++) {
            // threads.emplace_back([this] {});
            // lamdba表达式 实现一个函数
            //threads.emplace_back(func1); //func1 可以的吧



        }

    }


    void func1() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);

            // 判断任务有无任务
            bool isEmpty = tasks.empty();
            condition.wait(lock, !isEmpty || stop);
            // wair param2  ,true 往下走 ，false 等待
            if (stop && tasks.empty()) {
                return;
            }

            // 取任务
            // move 移动语义
            // 取到列表最左边的任务 
            std::function<void()> task(std::move(tasks.front()));

            tasks.pop();
            lock.unlock();
            task();
        }
    }

    // 析构函数
    ~threadPool() {
        {
            std::unique_lock<std::mutex> lock(mutex);

            stop = true;
        }
        //通知所有线程去取任务
        condition.notify_all();
        //自动类型推导 auto
        for (auto& t : threads) {
            t.join();
        }
    }


    //加任务
    // 函数模板
    // &&f右值应用 万能应用 &f左值引用
    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        //函数适配器bind forword完美转发
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            // 加任务
            std::unique_lock<std::mutex> lock(mutex);
            tasks.emplace(std::move(task));
        }
        //通知线程
        condition.notify_one();
    }


private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex mutex;
    std::condition_variable condition;
    bool stop;

};


void funcm(int i) {

    std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Task " << i << " is done" << std::endl;

}

int mainII() {
    threadPool pool(4); //4个

    //任务队列加任务
    for (int i = 0; i < 10; i++) {
        //pool.enqueue(funcm(i));

        pool.enqueue([i] {
            std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Task " << i << " is done" << std::endl;
            });

    }

    return 0;
}


void f1() {

}
#endif
//---------