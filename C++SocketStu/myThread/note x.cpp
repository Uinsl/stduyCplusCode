//-------�̳߳�
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
    //��stopĬ��Ϊf
    threadPool(int numThread) :stop(false) {
        for (int i = 0; i < numThread; i++) {
            // threads.emplace_back([this] {});
            // lamdba���ʽ ʵ��һ������
            //threads.emplace_back(func1); //func1 ���Եİ�



        }

    }


    void func1() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);

            // �ж�������������
            bool isEmpty = tasks.empty();
            condition.wait(lock, !isEmpty || stop);
            // wair param2  ,true ������ ��false �ȴ�
            if (stop && tasks.empty()) {
                return;
            }

            // ȡ����
            // move �ƶ�����
            // ȡ���б�����ߵ����� 
            std::function<void()> task(std::move(tasks.front()));

            tasks.pop();
            lock.unlock();
            task();
        }
    }

    // ��������
    ~threadPool() {
        {
            std::unique_lock<std::mutex> lock(mutex);

            stop = true;
        }
        //֪ͨ�����߳�ȥȡ����
        condition.notify_all();
        //�Զ������Ƶ� auto
        for (auto& t : threads) {
            t.join();
        }
    }


    //������
    // ����ģ��
    // &&f��ֵӦ�� ����Ӧ�� &f��ֵ����
    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        //����������bind forword����ת��
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            // ������
            std::unique_lock<std::mutex> lock(mutex);
            tasks.emplace(std::move(task));
        }
        //֪ͨ�߳�
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
    threadPool pool(4); //4��

    //������м�����
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