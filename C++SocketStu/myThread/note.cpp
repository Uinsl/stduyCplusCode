/*
C++11 Thread
���߳�
�߳� && ���̣�ͨ��
------------------
void funca() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);

        // �ж�������������
        bool isEmpty = tasks.empty();
        condition.wait(lock, !tasks.empty() || stop  );
        // [this] { return stop || !tasks.empty(); } ����ʵ��һ��������ô��
        // 1�� [this]
        // ��5��[this] ��ʾֵ���ݷ�ʽ��׽��ǰ��thisָ�롣
        //
        // 2��wait(&lock ) //&ʲô��˼��ȡlock���ڴ��ַ����lock����ȥ�������޸�lcok��ֵ
        // https://blog.csdn.net/qq_45487715/article/details/108796609
        //
        // wair param2  ,true ������ ��false �ȴ�
        // condition.wait(lock, [this] { return stop || !tasks.empty(); });

        // ȡ����
        // move �ƶ�����
        // ȡ���б�����ߵ�����
        std::function<void()> task(std::move(tasks.front()));

    }
}
*/