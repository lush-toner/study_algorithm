#include <iostream>

template<class T>
class Queue {
private:
	T* queue;
	int maxsize;
	int datasize;
	int frontindex;
	int rearindex;

public:
	Queue(const int size);
	~Queue();
	bool empty() const; // �Լ��� ��� ������ ���� �������� �ʴ�.
	bool full() const;
	int size() const;
	int front() const;
	void pushback(const int data);
	int popfront();
	void display() const;

};

template<class T>
Queue<T>::Queue(const int size)
{
	queue = new T[size]; // �Է� ���� ������ �ʱ�ȭ
	maxsize = size; //queue �� �ִ� ��
	datasize = 0;
	frontindex = 0;
	rearindex = 0;
}

template<class T>
Queue<T>::~Queue()
{
	delete[] queue;
}

template<class T>
bool Queue<T>::empty() const
{
	return datasize == 0; // ������ ����� 0�̸� �� ����
}

template<class T>
bool Queue<T>::full() const
{
	return datasize == maxsize; // ������ ����� max size�� ������ �� ����
}

template<class T>
int Queue<T>::size() const
{
	return datasize;
}

template<class T>
int Queue<T>::front() const
{
	if (empty()){
		puts("Queue is empty"); // ���ڿ� ���
		exit(EXIT_FAILURE);
	}
	return queue[frontindex];
}

template<class T>
void Queue<T>::pushback(const int data)
{
	if (full()) {
		puts("Queue is full!");
		exit(EXIT_FAILURE);
	}
		
	queue[rearindex] = data;
	rearindex = (rearindex + 1) % maxsize; // ����ť
	datasize++;
}

template<class T>
int Queue<T>::popfront()
{
	int frontdata = front(); // front�� �ִ� ���� �����´�.
	frontindex = (frontindex + 1) % maxsize; // circular way
	datasize--;
	return frontdata;
}

template<class T>
void Queue<T>::display() const {
	puts("====================================================================================================");
	if (empty()) {
		puts("Queue is empty!");
		puts("====================================================================================================");
		return;
	}
	printf("%-5s : %s\n", "full", full() ? "true" : "false");
	printf("%-5s : %d\n", "size", size());
	printf("%-5s : %d\n", "front", front());
	printf("(FRONT) ");
	for (int i = 0; i < datasize; i++) {
		int tempIndex = (frontindex + i) % maxsize;
		printf("[%d] ", queue[tempIndex]);
	}
	puts("(BACK)");
	puts("====================================================================================================");
}

int main(void)
{
	Queue<int> q(3);
	q.pushback(3);
	q.popfront();
	q.display();
	q.pushback(3);
	q.display();
	q.pushback(3);
	q.display();
	q.pushback(3);
	q.display();
}
