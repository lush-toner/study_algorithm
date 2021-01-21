/*
2021-01-20 예제 3-2 큰 수의 법칙 문제 cpp 계산 
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
    vector<int> v;
    int n, m, k, d; // n : 총 개수, m : 총 연산, k : 최대 연속 사용, d : 받을 숫자자
    int arr[5];
    int max, smax;
    int result = 0;

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        v.push_back(d);
    }

    sort(v.begin(), v.end());

    max = v[n - 1];
    smax = v[n - 2];

    result = max * k * (m / k) + smax * (m % k);

    cout << result << endl;
}
