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
	bool empty() const; // 함수는 멤버 변수의 값을 수정하지 않다.
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
	queue = new T[size]; // 입력 받은 값으로 초기화
	maxsize = size; //queue 의 최대 값
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
	return datasize == 0; // 데이터 사이즈가 0이면 빈 거임
}

template<class T>
bool Queue<T>::full() const
{
	return datasize == maxsize; // 데이터 사이즈가 max size와 같으면 찬 것임
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
		puts("Queue is empty"); // 문자열 출력
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
	rearindex = (rearindex + 1) % maxsize; // 원형큐
	datasize++;
}

template<class T>
int Queue<T>::popfront()
{
	int frontdata = front(); // front에 있는 값을 가져온다.
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
