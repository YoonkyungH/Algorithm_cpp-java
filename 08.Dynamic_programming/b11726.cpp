#include <iostream>
using namespace std;

// 2*n 타일링

int main() {
  ios::sync_with_stdio(0);
  int n;
  long long arr[1001];
  cin >> n;

  arr[1] = 1;
  arr[2] = 2;
  for(int i=3; i<=n; i++) {
    arr[i] = (arr[i-1] + arr[i-2])%10007;
  }

  cout << arr[n] << '\n';

  return 0;
}
