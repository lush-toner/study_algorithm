/*
2021-02-08 예제 3-2 큰 수의 법칙 문제 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
iostream을 제외한 STL을 사용하지 않고 코드 구성
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
    
    int n, m, k, d; // n : 총 개수, m : 총 연산, k : 최대 연속 사용, d : 받을 숫자자
    int max, smax;
    int result = 0;

    scanf("%d%d%d", &n, &m, &k);

    // k는 m보다 작거나 same이어야 한다.
    if (k > m)
    {
        cout << "k가 m보다 크거나 같아야 합니다" << endl;
        return 0; // 종료
    }

    /*배열 동적 할당*/
    int *arr = new int[n];
    int temp = 0;

    /* value 받기 */
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* 정렬 */
    for (int i = 0; i < (n - 1); i++) // rotation 4번
    {
        for (int j = 0; j < (n - 1); j++) // n-1인 이유는 굳이 끝의 요소를 바꿔줄 필요가 없기 때문에
        {
            if (arr[j] > arr[j + 1])
            {
                /*swap*/
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else
            {
                continue;
            }
        }
    }
    max = arr[n-1];
    smax = arr[n-2];

    result = max * k * (m / k) + smax * (m % k);

    cout << result << endl;

    /*배열 메모리 해제*/
    delete[] arr;
}
