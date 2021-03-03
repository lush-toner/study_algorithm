/*
Stack은 기본적으로 Last in First out의 구조를 띄고 있음
나중에 들어온 것이 먼저 나간다.
가장 마지막에 들어온 자료가 먼저 빠져야 다음 자료가 빠질 수 있다.
DFS 깊이 우선 탐색에 쓰인다.
스택은 Top이라는 포인터로 가장 상단의 데이터를 알 수 있다.
참고 사이트 : http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221212462913&categoryNo=88&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Stack
{
private:
    unsigned short m_count; // 스택에 저장된 데이터의 개수
    unsigned short m_size;  // 스택의 크기
    short *mp_data;         // 스택으로 사용할 메모리 주소를 가리킬 포인터

public:
    Stack() // 생성자 및 멤버 변수 초기화
    {
        m_size = 0;
        m_count = 0;
        mp_data = NULL;
    }
    ~Stack() // 객체 소멸자 - 사용하던 스택 메모리를 제거
    {
        if (mp_data != NULL) delete[] mp_data;
    }

    // 스택으로 사용할 메모리를 a_size 크기로 생성

    void create(unsigned short a_size)
    {
        // 크기의 유효성 체크
        if (a_size > 0 && a_size != m_size)
        {
            // 이전에 사용하던 메모리가 있으면 해당 메모리 제거
            if (mp_data != NULL) delete[] mp_data;
            // 새로운 크기를 저장하고 메모리를 할당
            m_size = a_size;
            mp_data = new short[m_size];
        }
    }

    // 스택에 정수 value를 하나 추가할 때 사용하는 함수
    void push(short a_num)
    {
        // 스택에 빈 공간이 있는 경우에만 입력을 받는다.
        if (m_count < m_size)
        {
            // 스택에 새로운 value를 저장한다.
            *(mp_data + m_count) = a_num;
            m_count++; // 저장된 갯수를 증가시킨다.
        }
        else cout << "Stack이 가득차서 value를 더 이상 넣을 수 없다." << endl;
    }

    // 스택에서 마지막에 입력된 정수 값을 하나 가져오는 함수
    // 스택에서 정수 value를 성공적으로 가져오면 1을 반환 실패하면 0을 반환
    short pop(short *ap_num)
    {
        if (m_count == 0) // 스택에 저장된 value가 없는 경우
        {
            cout << "Stack에 저장된 value가 없다." << endl;
            return 0;
        }

        m_count--; // 스택에 저장된 정수의 갯수를 줄임
        *ap_num = *(mp_data + m_count); // 마지막에 저장된 정수 값을 복사 (포인터 주소에 m_count만큼 더해서 value를 가져온다음 이를 ap_num에 대입)
        return 1;
    }

    // 스택에 있는 값들을 출력하는 함수
    void showstack()
    {
        if (m_count == 0) cout << "Stack에 저장된 value가 없습니다." << endl;
        else{
            cout << "Stack에 저장된 value 목록" << endl;
            for (int i = 0; i < m_count; i++)
            {
                cout << i +1 << " : " << *(mp_data + i) << endl;
            }
            cout << "총 " << m_count << "개의 value가 저장되어 있습니다." << endl;
        }
    }
};

int main()
{
    Stack stack;  // 스택으로 사용할 변수
    // 메뉴 항목을 선택할 때 사용할 변수와 value를 입력받을 때 사용할 변수
    short select_index = 0, temp  = 0;

    cout << "Stack의 크기를 입력하세요 : " ;
    cin >> temp;
    stack.create(temp);

    while (select_index !=9)
    {
        // 사용자에게 선택할 수 있는 기능
        cout << "\n\n1. Stack에 값 넣기" << endl;
        cout << "2. Stack에서 값 꺼내기" << endl;
        cout << "3. Stack에 저장된 값 확인" << endl;
        cout << "9. 프로그램 종료" << endl;
        cout << "선택 : ";
        scanf("%hd", &select_index); // 사용자가 선택한 메뉴값을 얻는다

        switch (select_index)
        {
        case 1: // 사용자가 입력한 값 stack에 저장
            cout << "저장할 값을 입력 : ";
            scanf("%hd", &temp);
            stack.push(temp);
            break;
        case 2: // 스택에 저장된 정수값을 가져온다.
            if (stack.pop(&temp)) cout << "가져온 값 -> " << temp << endl;
            break;
        case 3: // 스택에 저장된 값들을 보여준다.
            stack.showstack();
            break;
        }
    }
    return 0;
}