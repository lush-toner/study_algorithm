/*
2021-02-16 예제 4-3 왕실의 나이트 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
cpp로 계산
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    int n = input[1] - '0';     // 문자 형태로 받기 때문에 아스키코드에서 숫자 형태를 찾아야 함
    int m = input[0] - 'a' + 1; // 문자를 int 형태로 바꿔 a에서 얼마나 멀어져 있는지 확인

    int arr_m[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int arr_n[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    int tn;
    int tm;

    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        tn = n + arr_m[i];
        tm = m + arr_n[i];

        if(tn < 1 || tn > 8 || tm < 1 || tm > 8) continue;
        count++;
    }
    cout << count << endl;
}