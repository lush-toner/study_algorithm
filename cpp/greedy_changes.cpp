/*
2021-01-20 예제 3-1 거스름돈 문제 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
시간 복잡도 O(k)
*/

#include <iostream>

int main(void)
{
    int change = 1260; // 거스름돈 3450원
    int arr[5] = {500, 100, 50, 10}; // 거스름돈 단위
    int count = 0;

    for(int i = 0; i<4; i++)
    {
        count += change / arr[i]; // 몫을 계산하면 몇개의 동전을 써야하는지 알 수 있다.
        change = change % arr[i]; // 나머지 돈 계산
    }
    printf("%d\n", count);
}