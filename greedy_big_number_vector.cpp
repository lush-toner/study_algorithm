/*
2021-01-20 예제 3-1 거스름돈 문제 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
*/

/*
Vector를 이용한 풀이
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    vector <int> v;
    int n, m, k, d;
    int arr[5];
    int max, smax;
    

    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        v.push_back(d);
    }
    
    sort(v.begin(), v.end());

    max = v[n-1];
    smax = v[n-2];

    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }


}
