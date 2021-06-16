#include <iostream>
#include <algorithm>
// #include <vector>
// #include <stdlib.h>
using namespace std;

// 통나무 건너뛰기

int main() {
  ios::sync_with_stdio(0);

  int arr[10000] = {0,};
  int T, N;
  int level = 0;

  cin >> T;
  for(int i=0; i<T; i++) {
    level = 0;
    cin >> N;
    for(int j=0; j<N; j++) {
      cin >> arr[j];
    }
    sort(arr, arr+N);
    // 가운데 수가 가장 크도록 (/\) 정렬하면 인덱스가 2씩 차이남
    // for(int j=0; j<N-2; j+=2) {
    for(int j=2; j<N; j++) {
      // 처음에 t를 구하기 위한 for문이 잘못되어 틀림
      int t = arr[j]-arr[j-2];
      level = max(level, t);
    }
    cout << level << '\n';
  }

  return 0;
}
