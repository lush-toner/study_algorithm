/*
Stack�� �⺻������ Last in First out�� ������ ��� ����
���߿� ���� ���� ���� ������.
���� �������� ���� �ڷᰡ ���� ������ ���� �ڷᰡ ���� �� �ִ�.
DFS ���� �켱 Ž���� ���δ�.
������ Top�̶�� �����ͷ� ���� ����� �����͸� �� �� �ִ�.
���� ����Ʈ : http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221212462913&categoryNo=88&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Stack
{
private:
    unsigned short m_count; // ���ÿ� ����� �������� ����
    unsigned short m_size;  // ������ ũ��
    short *mp_data;         // �������� ����� �޸� �ּҸ� ����ų ������

public:
    Stack() // ������ �� ��� ���� �ʱ�ȭ
    {
        m_size = 0;
        m_count = 0;
        mp_data = NULL;
    }
    ~Stack() // ��ü �Ҹ��� - ����ϴ� ���� �޸𸮸� ����
    {
        if (mp_data != NULL) delete[] mp_data;
    }

    // �������� ����� �޸𸮸� a_size ũ��� ����

    void create(unsigned short a_size)
    {
        // ũ���� ��ȿ�� üũ
        if (a_size > 0 && a_size != m_size)
        {
            // ������ ����ϴ� �޸𸮰� ������ �ش� �޸� ����
            if (mp_data != NULL) delete[] mp_data;
            // ���ο� ũ�⸦ �����ϰ� �޸𸮸� �Ҵ�
            m_size = a_size;
            mp_data = new short[m_size];
        }
    }

    // ���ÿ� ���� value�� �ϳ� �߰��� �� ����ϴ� �Լ�
    void push(short a_num)
    {
        // ���ÿ� �� ������ �ִ� ��쿡�� �Է��� �޴´�.
        if (m_count < m_size)
        {
            // ���ÿ� ���ο� value�� �����Ѵ�.
            *(mp_data + m_count) = a_num;
            m_count++; // ����� ������ ������Ų��.
        }
        else cout << "Stack�� �������� value�� �� �̻� ���� �� ����." << endl;
    }

    // ���ÿ��� �������� �Էµ� ���� ���� �ϳ� �������� �Լ�
    // ���ÿ��� ���� value�� ���������� �������� 1�� ��ȯ �����ϸ� 0�� ��ȯ
    short pop(short *ap_num)
    {
        if (m_count == 0) // ���ÿ� ����� value�� ���� ���
        {
            cout << "Stack�� ����� value�� ����." << endl;
            return 0;
        }

        m_count--; // ���ÿ� ����� ������ ������ ����
        *ap_num = *(mp_data + m_count); // �������� ����� ���� ���� ���� (������ �ּҿ� m_count��ŭ ���ؼ� value�� �����´��� �̸� ap_num�� ����)
        return 1;
    }

    // ���ÿ� �ִ� ������ ����ϴ� �Լ�
    void showstack()
    {
        if (m_count == 0) cout << "Stack�� ����� value�� �����ϴ�." << endl;
        else{
            cout << "Stack�� ����� value ���" << endl;
            for (int i = 0; i < m_count; i++)
            {
                cout << i +1 << " : " << *(mp_data + i) << endl;
            }
            cout << "�� " << m_count << "���� value�� ����Ǿ� �ֽ��ϴ�." << endl;
        }
    }
};

int main()
{
    Stack stack;  // �������� ����� ����
    // �޴� �׸��� ������ �� ����� ������ value�� �Է¹��� �� ����� ����
    short select_index = 0, temp  = 0;

    cout << "Stack�� ũ�⸦ �Է��ϼ��� : " ;
    cin >> temp;
    stack.create(temp);

    while (select_index !=9)
    {
        // ����ڿ��� ������ �� �ִ� ���
        cout << "\n\n1. Stack�� �� �ֱ�" << endl;
        cout << "2. Stack���� �� ������" << endl;
        cout << "3. Stack�� ����� �� Ȯ��" << endl;
        cout << "9. ���α׷� ����" << endl;
        cout << "���� : ";
        scanf("%hd", &select_index); // ����ڰ� ������ �޴����� ��´�

        switch (select_index)
        {
        case 1: // ����ڰ� �Է��� �� stack�� ����
            cout << "������ ���� �Է� : ";
            scanf("%hd", &temp);
            stack.push(temp);
            break;
        case 2: // ���ÿ� ����� �������� �����´�.
            if (stack.pop(&temp)) cout << "������ �� -> " << temp << endl;
            break;
        case 3: // ���ÿ� ����� ������ �����ش�.
            stack.showstack();
            break;
        }
    }
    return 0;
}