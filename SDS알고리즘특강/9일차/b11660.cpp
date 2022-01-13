// 구간 합 구하기 5
// DP
// 아래의 주석처리한 코드가 시간, 메모리상 더 좋은 코드

#include <iostream>

using namespace std;

int N, M;
int arr[1025][1025];
int dp[1025][1025];
int x1, x2, y1, y2;
int sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        dp[i][1] = arr[i][1];
    }

    for(int i=1; i<=N; i++) {
        for(int j=2; j<=N; j++) {
            dp[i][j] = arr[i][j] + dp[i][j-1];
        }
    }

    for(int i=0; i<M; i++) {
        sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j=x2; j>=x1; j--) {
            sum += dp[j][y2] - dp[j][y1-1];
        }        
        cout << sum << '\n';
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// // 구간 합 구하기 5

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int N, M;
//   int map[1025][1025];
//   int dp[1025][1025];

//   cin >> N >> M;

//   for(int i=1; i<=N; i++) {
//     for(int j=1; j<=N; j++) {
//       cin >> map[i][j];
//       dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j];
//     }
//   }

//   int x1, x2, y1, y2;
//   int ans;
//   for(int i=0; i<M; i++) {
//     cin >> x1 >> y1 >> x2 >> y2;
//     ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
//     // 구하고 싶은 영역 이외의 합?을 빼주는 과정
//     // 여기서 dp[x1-1][y1-1]을 더해주는 이유는 중복해서 빠졌기 때문

//     cout << ans << '\n';
//   }

//   return 0;
// }