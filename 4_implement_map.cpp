/*
2021-01-21 예제 4-1 상화좌우 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
*/




/* 아직 완성 안됨됨 */
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int x = 1, y = 1;
    int tx, ty;
    char command[100];

    scanf("%d", &n);
    
    cout << n << endl;

    int arr[n][n] = {};

    for (int i = 0; i < n; i++)
    {
        scanf("%c", &command[i]);
    }


    for (int i = 0; i < n; i++)
    {
        cout << command[i] << endl;
        if (command[i] == 'R') 
        {
            ty = y + 1;
        }
        else if (command[i] == 'D')
        {
            tx = x + 1;
        }
            
        else if(command[i] == 'U')
        {
            tx = x - 1;
        }   
        else if(command[i] == 'L')
        {
            tx = y - 1;
        }
            

        if (x < 0 || x > n || y < 0 || y > n) continue;

        x = tx;
        y = ty;

    }
}