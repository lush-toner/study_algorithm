/*
2021-01-24 예제 4-1 상화좌우 cpp 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
2중 for문을 하나의 for문으로 즐임
*/

// #include <bits/stdc++.h> // pre-compiled header,

#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    // N을 입력받기
    int x;
    int n = 1, m = 1;
    string plans;

    cin >> x;
    cin.ignore(); // 버퍼 비우기
    getline(cin, plans);

    // 이동 계획을 하나씩 확인
    int tn = 1, tm = 1;
    for (int i = 0; i < plans.size(); i++)
    {
        if (plans[i] == 'R')
        {
            tm = m + 1;
        }
        else if (plans[i] == 'L')
        {
            tm = m - 1;
        }
        else if (plans[i] == 'U')
        {
            tn = n - 1;
        }
        else if (plans[i] == 'D')
        {
            tn = n + 1;
        }
        
        if (tm < 1 || tn < 1 || tn > x || tm > x) continue;
        
        n = tn;
        m = tm;

    }
    cout << n << ' ' << m << '\n';
    return 0;
}