/*
C++11 Thread
多线程
线程 && 进程，通信
------------------
void funca() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);

        // 判断任务有无任务
        bool isEmpty = tasks.empty();
        condition.wait(lock, !tasks.empty() || stop  );
        // [this] { return stop || !tasks.empty(); } 不是实现一个函数这么简单
        // 1、 [this]
        // （5）[this] 表示值传递方式捕捉当前的this指针。
        //
        // 2、wait(&lock ) //&什么意思，取lock的内存地址，当lock传进去，可以修改lcok的值
        // https://blog.csdn.net/qq_45487715/article/details/108796609
        //
        // wair param2  ,true 往下走 ，false 等待
        // condition.wait(lock, [this] { return stop || !tasks.empty(); });

        // 取任务
        // move 移动语义
        // 取到列表最左边的任务
        std::function<void()> task(std::move(tasks.front()));

    }
}
*/