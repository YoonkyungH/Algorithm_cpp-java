// 다리 놓기
// 다이나믹 프로그래밍
#include <iostream>
using namespace std;

int N, M;
int dp[30][30];

int sol(int m, int n) {
    if(dp[m][n] != 0) { // 없으면 시간초과
        return dp[m][n];
    }

    if(n == 0 || m == n) {
        return 1;
    } else {
        dp[m][n] = sol(m-1, n-1) + sol(m-1, n);

        return dp[m][n];
    }
}

 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        cin >> N >> M;

        cout << sol(M, N) << '\n';
    }

    return 0;
}