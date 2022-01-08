// 사전
// 파스칼의 삼각형

#include <iostream>

using namespace std;

#define MAXK 1000000000

int dp[201][201];

int main() {
    ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K; // a 개수, z 개수, k번째

    N += M;
    
    dp[0][0] = 1;   // 0개에서 0개를 고르는 경우
    for(int i=1; i<=N; i++) {
        dp[i][0] = 1;

        for(int j=1; j<=i && j<=M; j++) {   // j<=M조건은 M보다 작은 경우를 미리 계산해둘 필요가 없기 때문
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

            if(dp[i][j] > MAXK) { dp[i][j] = MAXK + 1; }    // overflow 방지 (최대값 고정)
        }
    }

    if(dp[N][M] < K) {  // N에서 C개 고르는 경우 < K => 불가능한 경우
        cout << "-1\n"; return 0;
    }

    while(N) {
        if(dp[N-1][M] >= K) { cout << "a"; }    // 경우의 수가 K보다 크면 그 자리에 a
        else {
            cout << "z";
            K -= dp[N-1][M--]; 
        }
        N--;
    } cout << '\n';

    return 0;
}