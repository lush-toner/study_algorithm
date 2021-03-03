#include <iostream>
using namespace std;

/*
구현해야할 기능들
top
full
empty
push
pull
*/


class Stack
{
private:
	int s_size;
	int top;
	int* pstack;

public:
	Stack(int size);
	int full();
	int empty();
	void push(int value);
	int pop();
	void print_stack();
};

Stack::Stack(int size)
{
	s_size = size;
	pstack = new int[s_size];
	top = -1;
}

int Stack::full()
{
	if (top == s_size - 1)
		return 1;
	else
		return 0;
}

int Stack::empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void Stack::push(int value)
{
	if (full() == 1)
		cout << "stack is full" << endl;
	else
		pstack[++top] = value;
}

int Stack::pop()
{
	if (empty() == 1)
		cout << "Stack is empty" << endl;
	else
		return pstack[top--];
}

void Stack::print_stack()
{
	for (int i = 0; i < top + 1; i++)
		cout << pstack[i] << endl;
}


int main(void)
{
	Stack stack(5); // 생성자
	stack.push(3);
	stack.push(5);
	stack.push(5);
	stack.push(5);
	stack.push(5);
	stack.pop();

	stack.print_stack();

}