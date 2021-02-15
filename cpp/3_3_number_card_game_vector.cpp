#define _CRT_SECURE_NO_WARNINGs
#include <stdio.h>
#include <iostream>
using namespace std;


/*
2차원 배열 선언은 단순히 한줄 코드로 선언할 수 있는 것이 아닌 for 반복문으로 설정
mat[0] --> a[0][0], a[0][1], a[0][2], a[0][3] ....
mat[1] --> a[1][0], a[1][1], a[1][2], a[1][3] ....
mat[2] --> a[2][0], a[2][1], a[2][2], a[2][3] ....
mat[3] --> a[3][0], a[3][1], a[3][2], a[3][3] ....

*/
int main(void)
{
    int n, m; // n은 행, m은 열
    scanf("%d %d", &n, &m);
    int **mat = new int* [n]; // 이중포인터 배열 선언
    
    for(int i = 0; i < n; i++)
    {   
        mat[i] = new int[m]; // 행에 열을 집어 넣는다
    }

    /* value 넣기 */
    for (int i =0; i < n; i++)
        for (int j=0; j<m; j++)
            // mat[i][j] = i*m + j;
            scanf("%d", &mat[i][j]);

    /* Matrix 출력 */
    printf("========================\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    printf("========================\n");

    /* 게임 실행 */
    int compare = 0; // 큰 수 비교를 위해 설정

    for (int i = 0; i < n; i++)
    {
        int min_value = 10001; // 비교 대상
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] < min_value) // min_value 찾기
            {
                min_value = mat[i][j];
            }
        }
        if (min_value > compare)
        {
            compare = min_value;
        }
    }
    printf("Max value는 %d\n", compare);


    // 메모리 해제
    for (int i = 0; i < n; i++)
		delete [] mat[i];
	delete [] mat;

    return 0;
}
