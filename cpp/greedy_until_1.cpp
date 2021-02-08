/*
2021-01-21 예제 3-4 1이 될 때까지 cpp 구현
참고: 이것이 취업을 위한 코딩 테스트다 with 파이썬 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main(void)
{
    int n, k; // n 25, k 5
    int count = 0;

    scanf("%d %d", &n, &k);

    while (true)
    {
        if (n == 0)
            break;

        else if (n % k == 0)
        {
            count++;
            n /= k;
            if (n == 1) // 마지막 몫이 1이 나오면 1을 빼준다.
            {
                n--;
            }
        }
        else if (n % k != 0)
        {
            n--;
            count++;
        }
    }
    cout << count << endl;
}