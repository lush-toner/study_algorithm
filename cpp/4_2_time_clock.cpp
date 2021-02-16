/*
2021-02-16 예제 4-2 시각 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
cpp로 계산
*/

#include <iostream>

using namespace std;

int main(void)
{
    int n; // 시
    int count = 0;
    cin >> n;

    // 시 계산
    for (int h = 0; h <= n; h++)
        for (int m = 0; m < 60; m++)
            for (int s = 0; s < 60; s++)
            {
                // 3이 하나라도 포함되는 경우
                if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3) count++;
            }

    cout << count << endl;
}