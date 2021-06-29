#include <iostream>
#include <algorithm>
// #include <cstring>
using namespace std;

// 구간 합 구하기 5

// 참고한 코드
int main() {
  ios::sync_with_stdio(0);
  // 12, 13줄 코드를 안 넣으니 시간 초과로 틀림
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  int map[1025][1025];
  int dp[1025][1025];

  cin >> N >> M;

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin >> map[i][j];
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j];
    }
  }

  int x1, x2, y1, y2;
  int ans;
  for(int i=0; i<M; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
    // 구하고 싶은 영역 이외의 합?을 빼주는 과정
    // 여기서 dp[x1-1][y1-1]을 더해주는 이유는 중복해서 빠졌기 때문

    cout << ans << '\n';
  }

  return 0;
}

// 시간초과

// int map[1025][1025];  // [0][0] 사용 X
// int sum[1025][1025];
// int N, M; // N: 표의 크기, M: 구할 합의 수
//
//
// int dp(int x1, int x2, int y1, int y2) {
//
//   int j, tmp=0;
//   for(int i=y1; i<=y2; i++) {
//     for(j=x1; j<=x2; j++) {
//       if(j == x1) { sum[i][j] = sum[i][j-1] + map[i][j] + tmp; }
//       else { sum[i][j] = sum[i][j-1] + map[i][j]; }
//       // sum[i][j] = map[i][j];
//     } tmp = sum[i+1][y1] += sum[i][j-1];
//   }
//
//   return sum[y2][x2];
// }
//
// int main() {
//   ios::sync_with_stdio(0);
//
//   cin >> N >> M;
//
//   for(int i=1; i<=N; i++) {
//     for(int j=1; j<=N; j++) {
//       cin >> map[i][j];
//     }
//   }
//
//   int x1, x2, y1, y2;
//   for(int i=0; i<M; i++) {
//     memset(sum, 0, sizeof(sum));
//     cin >> x1 >> y1 >> x2 >> y2;
//     cout << dp(x1, x2, y1, y2) << '\n';
//   }
//
//   return 0;
// }
