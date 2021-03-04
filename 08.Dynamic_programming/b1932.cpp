#include <iostream>
#include <algorithm>
using namespace std;

// 정수 삼각형

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, num;             // 테스트 케이스, 삼각형 속 수
  int M=0;                // 최댓값
  int arr[501][501];
  // int sum[501][501];

  cin >> T;
  // 피라미드 모양으로 숫자를 배열에 집어넣음
  for(int i=1; i<=T; i++) {
    for(int j=1; j<=i; j++) {
      cin >> num;
      arr[i][j] = num;
    }
  }

  // 둘째줄 첫번째 원소부터
  for(int i=2; i<=T; i++) {
    for(int j=1; j<=i; j++) {
      // 가장 첫, 끝 원소가 아닐 시,
      if(1<j<i) {
        // 윗줄 왼/오 대각선 두 개의 숫자 중 큰 수를 현 원소에 더함
        arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
      }
      // 그 줄의 첫번째 또는 마지막 원소라면 바로 위에 있는 수를 현 원소에 더함
      else if(j == 1) arr[i][1] += arr[i-1][1];
      else if(j == i) arr[i][j] += arr[i-1][j-1];
    }
  }

  // 제대로 더해졌는지 확인
  // for(int i=1; i<=T; i++) {
  //   for(int j=1; j<=i; j++) {
  //     cout << arr[i][j] << " ";
  //   } cout << '\n';
  // }

  // 가장 마지막 줄 원소 중 최댓값을 찾음
  M = arr[T][1];
  for(int i=2; i<=T; i++) {
    M = max(M, arr[T][i]);
  }

  cout << M << '\n';

  return 0;
}
