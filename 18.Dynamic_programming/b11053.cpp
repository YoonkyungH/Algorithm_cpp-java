#include <iostream>
#include <algorithm>
using namespace std;

// 가장 긴 증가하는 부분 수열

int arr[1000];
int cnt[1000];
int sum = 0;

int dp(int arr[], int n) { 
  for(int i=0; i<n; i++) {
    cnt[i] = 1;               // 시작지점 count
    for(int j=0; j<i; j++) {
      // 증가하는 수열이라면
      if(arr[i] > arr[j]) { cnt[i] = max(cnt[i], cnt[j] + 1); }
    }
    // sum에 수열 중 가장 긴 것을 비교해 넣음
    sum = max(sum, cnt[i]);
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(0);

  int N;
  cin >> N;

  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }

  cout << dp(arr, N) << '\n';

  return 0;
}
