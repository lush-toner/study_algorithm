/*
2021-03-03
���� ����Ʈ : http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221212462913&categoryNo=88&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
*/

#include <iostream>
using namespace std;

class Stack {
private:
	int stack_size;  // ���� ������
	int stack_count; // ���ÿ� ����� �������� ����
	int* p_stack;    // �������� ����� �޸� �ּҸ� ����ų ������

public:
	// �޼��� ����
	Stack(); 
	~Stack();
	void create_stack(int size);
	void push(int value);
	void pop();
	void show_stack();
};

Stack::Stack() // ������
{
	// Ŭ���� ���� �ʱ�ȭ
	stack_size = 0;
	stack_count = 0;
	p_stack = NULL;
}

Stack::~Stack() // �Ҹ���
{
	if (p_stack != NULL) delete[] p_stack; // p_stack�� �����ϸ� �Ҹ�
}

// ���� ���� -> ���ÿ� ����� size�� size ������ ����
void Stack::create_stack(int size)
{
	if (p_stack != NULL) delete[] p_stack; // ������ ����ϴ� �޸𸮰� ������ �ش� �޸𸮸� �����Ѵ�.
	stack_size = size; // �� �ڵ带 �������ִ� ������ class ������ ���� �־��ֱ� ����
	p_stack = new int[stack_size]; // ���� �޸𸮸� �Ҵ��Ѵ�.
}

// ���� Ǫ��
void Stack::push(int value)
{
	// ���ÿ� �� ������ ���� �� ���� �ִ´�.
	if (stack_count < stack_size)
	{
		*(p_stack + stack_count) = value; // ���� �޸� ������ stack_count index ��ŭ�� �ּҰ��� ���� �־� �ش�.
		stack_count++; // ������ �Ǿ� ���� count�� ������Ų��.
	}
	else
		cout << "Stack�� ���� á��" << endl;
}

// pop ����
void Stack::pop()
{
	if (stack_count == 0) // ����� stack�� ������
	{
		cout << "Stack�� ����� ������ ����." << endl;
	}
	else
	{
		cout << "Popped!!" << endl;
		p_stack[stack_count--] = 0; // ������ ���� 0���� ����� stack_count�� ���ҽ�Ų��.
	}
}


void Stack::show_stack()
{
	if (stack_count == 0) cout << "Stack�� ����� ������ �����ϴ�" << endl;

	else 
	{
		cout << "Stack�� ����� ���� �Ʒ��� �����ϴ�." << endl;
		for (int i = 0; i < stack_count; i++)
		{
			cout << i << " : " << p_stack[i] << endl;
		}
		cout << "�� " << stack_count << "���� value�� ����Ǿ� �ִ�." << endl;
	}
}


int main(void)
{
	Stack stack;
	int s_size = 0;
	int tmp = 0;
	int button = -1; // �ƹ� ���ڷ� �ʱ�ȭ
	int value = 0;
	cout << "Stack ����� �Է��ϼ��� : ";

	// �Էµ� stack ����� ������� üũ
	while (s_size <= 0)
	{
		scanf_s("%d", &tmp);
		if (tmp <= 0)
		{
			cout << "stack_size�� ����� �Է��ϼ���, ���� �Էµ� �� ->" << s_size << endl << endl;
			cout << "Stack ����� �Է��ϼ��� : ";
		}
		else s_size = tmp;
	}

	// ���� ����
	stack.create_stack(s_size);


	cout << endl;
	cout << "1. Stack Push" << endl;
	cout << "2. Stack Pop" << endl;
	cout << "3. Stack Print" << endl;
	cout << "0. Exit program" << endl;
	cout << endl << endl;

	while (button != 0)
	{
		cout << "��ư ���� : ";
		scanf_s("%d", &button);
		cout << endl << endl;
		switch (button)
		{
		case 1: // �Է��� �� ����
			cout << "������ ���� ? : ";
			scanf_s("%d", &value);
			stack.push(value);
			break; // break �ʼ� �ȱ׷��� �Ʒ� �׸�鵵 ����

		case 2:
			stack.pop();
			break;

		case 3:
			stack.show_stack();
			break;

		}

	}
	return 0;

}