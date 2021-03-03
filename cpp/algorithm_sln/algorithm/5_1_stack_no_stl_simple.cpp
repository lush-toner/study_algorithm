/*
Stack은 기본적으로 Last in First out의 구조를 띄고 있음
나중에 들어온 것이 먼저 나간다.
가장 마지막에 들어온 자료가 먼저 빠져야 다음 자료가 빠질 수 있다.
DFS 깊이 우선 탐색에 쓰인다.
스택은 Top이라는 포인터로 가장 상단의 데이터를 알 수 있다.
참고 사이트 : https://popcorn16.tistory.com/52
*/

#include <iostream>
using namespace std;

class Stack
{
private:
    int top, Maxsize;
    char *stack;

public:
    Stack(int size); // 생성자
    bool isFull(), isEmpty(); // 찬 것과 빈 것 구분
    char pop();
    void push(char element);
    void print();
};

// 생성자
Stack::Stack(int size)
{
    Maxsize = size; // Maxsize 및 size는 stack 사이즈
    stack = new char[Maxsize]; // char를 담고있는 배열 생성
    top = -1; // index 역할
}

// return bool
bool Stack::isFull()
{
    if (top == Maxsize - 1) // Maxsize가 5일 때 top이 4가 되면 full
        return 1;
    else
        return 0;
}

// return bool
bool Stack::isEmpty()
{
    if (top == -1) // top이 -1이면 아무것도 없는 것임
        return 1;
    else
        return 0;
}

char Stack::pop()
{
    if (isEmpty() == 1)
        cout << "Empty!\n";
    else
    {
        return stack[top--];
    }
        
}

void Stack::push(char element)
{
    if (isFull() == 1)
        cout << "Full!\n";
    else
        stack[++top] = element;
}

void Stack::print()
{
    for (int i = 0; i < top + 1; ++i)
        cout << stack[i] << endl;
}

int main()
{
    Stack stack(5); // 생성자
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.push('e');
    stack.push('f'); // Full 

    stack.pop();
    // stack.push('f');
    // stack.print();


    return 0;
}