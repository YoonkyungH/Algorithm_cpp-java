// 돌 게임
// 다이나믹 프로그래밍 (DP)

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    /**
     * 굳이 DP로 풀었을 경우 
     */
    // dp[1] = 1;
    // dp[2] = 2;
    // dp[3] = 1;

    // for(int i=4; i<=N; i++) {
    //     dp[i] = min(dp[i-3] + 1, dp[i-1] + 1);
    // }
    // if(dp[N] % 2) { cout << "SK\n"; }
    // else { cout << "CY\n"; }

    /**
     * 짝수일 때 CY, 홀수일 때 SK
     */
    if(N%2 == 0) { cout << "CY\n"; }
    else { cout << "SK\n"; }

    return 0;
}