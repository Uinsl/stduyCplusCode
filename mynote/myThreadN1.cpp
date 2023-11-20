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



// ��֧��ʱ���ӳٲ���
mutex mtx;

timed_mutex tmtx;

int b = 0;

int main()
{
    std::cout << "���߳�Start\n";
    //thTest1();
    tlb2();

    std::cout << "���߳�end\n";
    return 0;
}

//----------unique_lock ����

// ʹ��lg
void tlb2() {
    thread t1(lockBa);
    thread t2(lockBa);
    t1.join();
    t2.join();

    cout << "�߳��� ��int b =" << b << endl;

}

void lockBa2() {
    //mtx.lock();
    for (int i = 0; i < 1000; i++)
    {
        unique_lock<timed_mutex>lg(tmtx,defer_lock); // ֻ�ڵ�ǰ������
        // defer_lock ����,��������������ʵ���ӳټ�������
        // lg.lock();// �ֶ�����

        lg.try_lock_for(chrono::seconds(1));
        // �������� ��Ȼ���߳�tִ�е�����ȴ�ִ�� b+=1 ��ʱ��tֻ���1��
        // �����ʱ������ɱ��t������������������

        this_thread::sleep_for(chrono::seconds(3));
        // ���磬��ǰ lg û�� mtx ����Ȩ���͵�5�룬���˾ͳ�ʱ����
        b += 1;
    }
    //mtx.unlock();
}

//-------------


// ʹ��lg
void tlb() {
    thread t1(lockBa);
    thread t2(lockBa);
    t1.join();
    t2.join();

    cout << "�߳��� ��int b =" << b << endl;

}

// lock_guard
// ���캯�� �Զ����� �����캯��?  �Զ�������
void lockBa() {
    //mtx.lock();
    for (int i = 0; i < 1000; i++) 
    {
        lock_guard<mutex>lg(mtx); // ֻ�ڵ�ǰ������
        b += 1;
    }
    //mtx.unlock();
}


// �߳���
void thMtx() {

    thread t1(addNum);
    thread t2(addNum);
    t1.join();
    t2.join();

    cout << "�߳��� ��int b =" << b << endl;
}



//�߳�����
void thTest1() {

    // �����̣߳����ã�thread_1()
    thread first(thread_1); 
    // �����̣߳����ã�thread_2(100)
    thread second(thread_2, 100); 
    //thread third(thread_2,3);//������3���̣߳�����thread_2������

    first.join(); //join ������        �߳� 1��2 ͬʱ����     
    second.join();

    //detach() ���룬������
    // first.detach();          
    // second.detach();

    //bool isJoin = first.joinable();
    // ��ʹ��join(); �������򶼻��ڵ���ִ�����
    // foo(1); 1=��ʱ����������ͷ��ڴ�
    // foo(std::ref(1)); ref �������ͣ� ����
    // foo(std::ref(a)); int a = 0;
    std::cout << "���߳̽���.\n";//����join���
}

// �������ͣ�
void foo(int& x) {
    x += 1;
}



// mtx ������
void addNum()
{
    mtx.lock();
    for (int i = 0; i < 1000; i++) {
        b += 1;
    }
    mtx.unlock();
}










