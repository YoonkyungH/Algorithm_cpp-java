// 계단 오르기
// Dynamic Programming 동적 계획법
// : 한 가지 문제에 대해 단 한 번만 풀도록

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 301

int N;
int stairs[MAX];
int dp[MAX];

int main() {
    ios::sync_with_stdio(0);

    cin >> N;   // 전체 계단 수

    for(int i=0; i<N; i++) {
        cin >> stairs[i];
    }

    dp[0] = stairs[0];
    dp[1] = max(stairs[1], stairs[0]+stairs[1]);
    dp[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2]);

    for(int i=3; i<N; i++) {
        dp[i] = max(stairs[i] + dp[i-2], stairs[i] + stairs[i-1] + dp[i-3]);
    }

    cout << dp[N-1] << '\n';

    return 0;
}