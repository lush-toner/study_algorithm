/*
���� ��� �� �����Ͱ� ���� ������ ����(���Լ���)
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
	q.pop(); // ���� ���� ����
	q.pop(); // ���� ���� ����

	// ���� ���� ���Һ��� ����

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}