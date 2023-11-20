#include <iostream>
#include <thread>
#include <mutex>  // std::mutex
using namespace std;

void foo(int& x);
void thread_1();
void thread_2(int x);
void addNum();
void thTest1();
void thMtx();
void tlb();
void lockBa();
void tlb2();
void lockBa2();



// 不支持时间延迟操作
mutex mtx;

timed_mutex tmtx;

int b = 0;

int main()
{
    std::cout << "主线程Start\n";
    //thTest1();
    tlb2();

    std::cout << "主线程end\n";
    return 0;
}

//----------unique_lock 常用

// 使用lg
void tlb2() {
    thread t1(lockBa);
    thread t2(lockBa);
    t1.join();
    t2.join();

    cout << "线程锁 ，int b =" << b << endl;

}

void lockBa2() {
    //mtx.lock();
    for (int i = 0; i < 1000; i++)
    {
        unique_lock<timed_mutex>lg(tmtx,defer_lock); // 只在当前作用域
        // defer_lock 就是,不开启锁，用来实现延迟加锁操作
        // lg.lock();// 手动上锁

        lg.try_lock_for(chrono::seconds(1));
        // 开启上锁 ，然后当线程t执行到这里，等待执行 b+=1 的时候，t只会等1秒
        // 如果超时，就是杀死t？？？？？？？？？

        this_thread::sleep_for(chrono::seconds(3));
        // 比如，当前 lg 没有 mtx 所有权，就等5秒，过了就超时操作
        b += 1;
    }
    //mtx.unlock();
}

//-------------


// 使用lg
void tlb() {
    thread t1(lockBa);
    thread t2(lockBa);
    t1.join();
    t2.join();

    cout << "线程锁 ，int b =" << b << endl;

}

// lock_guard
// 构造函数 自动加锁 ；析造函数?  自动解锁；
void lockBa() {
    //mtx.lock();
    for (int i = 0; i < 1000; i++) 
    {
        lock_guard<mutex>lg(mtx); // 只在当前作用域
        b += 1;
    }
    //mtx.unlock();
}


// 线程锁
void thMtx() {

    thread t1(addNum);
    thread t2(addNum);
    t1.join();
    t2.join();

    cout << "线程锁 ，int b =" << b << endl;
}



//线程例子
void thTest1() {

    // 开启线程，调用：thread_1()
    thread first(thread_1); 
    // 开启线程，调用：thread_2(100)
    thread second(thread_2, 100); 
    //thread third(thread_2,3);//开启第3个线程，共享thread_2函数。

    first.join(); //join 是阻塞        线程 1、2 同时运行     
    second.join();

    //detach() 分离，非阻塞
    // first.detach();          
    // second.detach();

    //bool isJoin = first.joinable();
    // 当使用join(); 整个程序都会在等其执行完毕
    // foo(1); 1=临时变量用完就释放内存
    // foo(std::ref(1)); ref 引用类型？ 不懂
    // foo(std::ref(a)); int a = 0;
    std::cout << "子线程结束.\n";//必须join完成
}

// 引用类型？
void foo(int& x) {
    x += 1;
}



// mtx 互斥量
void addNum()
{
    mtx.lock();
    for (int i = 0; i < 1000; i++) {
        b += 1;
    }
    mtx.unlock();
}










