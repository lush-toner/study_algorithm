/*
Stack은 기본적으로 Last in First out의 구조를 띄고 있음
나중에 들어온 것이 먼저 나간다.
가장 마지막에 들어온 자료가 먼저 빠져야 다음 자료가 빠질 수 있다.
DFS 깊이 우선 탐색에 쓰인다.
스택은 Top이라는 포인터로 가장 상단의 데이터를 알 수 있다.
*/

#include <iostream>

class Stack
{
private:
    int top, Maxsize;
    char *stack;
public:
    Stack(int size);
    bool isFull(), isEmpty();
    char pop();
    void push(char element);
    void print();
}

// 생성자
Stack::Stack(int size)
{
    Maxsize = size;
    stack = new char[Maxsize];
    top = -1;
}