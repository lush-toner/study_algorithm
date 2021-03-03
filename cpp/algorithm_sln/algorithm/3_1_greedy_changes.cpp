/*
2021-02-28 greedy algorithm
1260원을 500원 100원 50원 10원으로 거스름돈으로 나눠 줄 때
거슬러줘야할 동전의 최소 개수를 구하라
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
