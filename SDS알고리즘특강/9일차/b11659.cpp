// 구간 합 구하기 4
// DP

#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int dp[100001];
int num, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        // cin >> num;
        // arr[i] = arr[i-1] + num;
    }

    
    dp[1] = arr[1];
    for(int i=2; i<=N; i++) {
        dp[i] = arr[i] + dp[i-1];
    }

    for(int i=0; i<M; i++) {
        cin >> a >> b;
        cout << dp[b]-dp[a-1] << '\n';
    }

    return 0;
}