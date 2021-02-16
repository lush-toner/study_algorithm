/*
2021-02-16 예제 4-4 게임 개발 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
cpp로 계산
*/

/*
맵 칸 :(A, B)
A : 북쪽으로부터 떨어진 칸의 개수
B : 서쪽으로부터 떨어진 칸의 개수
*/

#include <iostream>
using namespace std;


/*
   북(0)
서(3)  동(1)
   남(2)
*/
int main(void)
{
    int n, m; // 행, 렬
    int a, b, direct;
    cin >> n >> m;
    cin >> a >> b >> direct;

    int arr[50][50] = {};

    // 북, 동, 남, 서 direction 정의 
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    arr[a][b] = 1; // 시작하는 지점 1
    while (true)
    {
        // 반시계 방향 회전 -1 씩 빼주면 됨
        direct -= 1;
        if(direct == -1) direct = 3;

        // 이동 후 평가
        int tx = a + dx[direct];
        int ty = b + dy[direct];

        // 앞이 비어 있는 경우 이동
        if(arr[tx][ty] == 0)
        {
            arr[tx][ty] = 1;
            a = tx;
            b = ty;
            cnt++;
            continue;
        }
    }

    /* 출력 */
    cout << "=========================" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=========================" << endl;


}