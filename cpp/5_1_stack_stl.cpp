#include <iostream>
#include <stack>

// using namespace std;

int main(void)
{
    // 스택 생성
    std::stack<int> s;

    // 삽입(1) - 삽입(2) - 삽입(3) - 삭제() - 삽입(4) - 삽입(5) - 삭제()
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();

    // 스택의 최상단 원소부터 출력

    while(!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }
}