/*
2021-01-20 시간복잡도 cpp 계산 
O(N)
10개의 데이터를 받아 차례로 10회 더하는 과정
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
*/

#include <iostream>

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for(int i = 0; i<10; i++)
    {
        sum+=arr[i];
    }
    printf("%d\n", sum);
}