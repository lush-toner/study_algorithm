#include <iostream>
#include <stack>
 using namespace std;

int main(void)
{
    stack<int> s; // 스택 생성

    // 삽입(1) - 삽입(2) - 삽입(3) - 삭제() - 삽입(4) - 삽입(5) - 삭제()
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();

    // 스택의 최상단 원소부터 출력

    while(!s.empty()) // empty : 요소가 없으면 true, 있으면 false
    {
        cout << s.top() << ' '; // top은 맨 위에 있는 요소를 반환한다.
        s.pop(); // 요소 삭제
    }

}