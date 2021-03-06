#include <iostream>

class Queue {

public:
	Queue(const int size);
	~Queue();

	bool empty() const;
	bool full() const;
	int size() const;
	int front() const;
	void pushBack(const int data);
	int popFront();

	void display() const;

private:
	int* queue;
	int maxSize;
	int dataSize;
	int frontIndex;
	int rearIndex;

};

inline void error(const char* message) {
	puts(message);
	exit(EXIT_FAILURE);
}

Queue::Queue(const int size) {
	queue = new int[size];
	maxSize = size;
	dataSize = 0;
	frontIndex = 0;
	rearIndex = 0;
}

Queue::~Queue() {
	delete[] queue;
}

bool Queue::empty() const {
	return dataSize == 0;
}

bool Queue::full() const {
	return dataSize == maxSize;
}

int Queue::size() const {
	return dataSize;
}

int Queue::front() const {
	if (empty()) {
		error("Queue is empty!");
	}
	return queue[frontIndex];
}

void Queue::pushBack(const int data) {
	if (full()) {
		error("Queue is full!");
	}
	queue[rearIndex] = data;
	rearIndex = (rearIndex + 1) % maxSize;// circular array
	dataSize++;
}

int Queue::popFront() {
	int frontData = front();// if empty, error occurred
	frontIndex = (frontIndex + 1) % maxSize;// circular array
	dataSize--;
	return frontData;
}

void Queue::display() const {
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
	for (int i = 0; i < dataSize; i++) {
		int tempIndex = (frontIndex + i) % maxSize;
		printf("[%d] ", queue[tempIndex]);
	}
	puts("(BACK)");
	puts("====================================================================================================");
}

int main(void)
{
	Queue q(3);
	q.pushBack(3);
	q.display();
	q.pushBack(3);
	q.display();
	q.pushBack(3);
	q.display();
	q.pushBack(3);
	q.display();
}