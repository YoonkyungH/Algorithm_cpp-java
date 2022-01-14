// Dance Dance Revolution (DDR)
// DP + DFS 적용

// 어려운 문제
// (~했을 때 최솟값을 구하여라 -> dp문제일 수 있음)

// 강사님 코드 참고

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;
int dp[100001][5][5];
int arr[100001];

int move(int from, int to) {
    if(from == 0) return 2;     // 중앙에서 다른 자리 비용 2
    if(from == to) return 1;    // 제자리 비용 1

    // 중앙이 아닌 다른데서 인접한 곳 갈때 3, 다른데서 반대 지점으로 갈 때 4
    return (4 - (abs(from-to) % 2));    
}

int dfs(int n, int x, int y) {
    if(n == N) return 0;

    if(dp[n][x][y] > 0) return dp[n][x][y];
    
    // 왼발을 움직이는 경우, 오른발을 움직이는 경우
    // 파라미터는 (n+1번째 발판을 때, 왼발, 오른발)
    int left = dfs(n+1, arr[n], y) + move(x, arr[n]);   
    int right = dfs(n+1, x, arr[n]) + move(y, arr[n]);  

    return dp[n][x][y] = min(left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    N = 0;
    while(1) {
        cin >> arr[N];
        if(arr[N] == 0) break;

        N++;
    }

    cout << dfs(0, 0, 0) << '\n';

    return 0;
}