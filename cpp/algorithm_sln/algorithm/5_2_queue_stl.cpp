/*
먼저 들어 온 데이터가 먼저 나가는 형식(선입선출)
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop(); // 왼쪽 원소 제거
	q.pop(); // 왼쪽 원소 제거

	// 먼저 들어온 원소부터 추출

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}