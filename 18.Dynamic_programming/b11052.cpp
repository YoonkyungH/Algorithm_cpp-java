#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 카드 구매하기

int arr[1001];
int card[1001];
int dp(int v[], int n) {
  // 구해야하는 n번째 값이 될 때까지
  // 그 카드만 사는 비용과 그 전 카드들을 더해서 사는 값의 최대를 비교해 저장
  // 결국 구해야하는 n번째 비용을 반환
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      arr[i] = max(arr[i], v[j] + arr[i-j]);
    }
  }
  return arr[n];
}

int main() {
  ios::sync_with_stdio(0);

  int N;  // 카드의 수
  cin >> N;

  for(int i=1; i<=N; i++) {
    cin >> card[i];
  }

  cout << dp(card, N) << '\n';


  return 0;
}
