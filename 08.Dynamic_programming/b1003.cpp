#include <iostream>
using namespace std;

// 피보나치 함수

// 시간초과
// int zero, one;
// int fibonacci(int n) {
//   if(n==0) {
//     zero++;
//     return 0;
//   } else if(n==1) {
//     one++;
//     return 1;
//   } else {
//     return fibonacci(n-1) + fibonacci(n-2);
//   }
// }

int main() {
  ios::sync_with_stdio(0);
  int T, c;
  // 다이나믹 프로그래밍은 배열에 이전 값을 저장해둬야 한다고 해서 배열을 선언
  // arr[0][n]은 0의 개수 arr[1][n]은 1의 개수
  int arr[2][41]={0,};

  // 호출을 (n-1) (n-2)이렇게 하니까 arr[0][0]~arr[1][1]까지 미리 수를 넣어둠
  arr[0][0] = 1;
  arr[1][0] = 0;
  arr[0][1] = 0;
  arr[1][1] = 1;

  // 범위 내 숫자들의 0, 1 개수들을 미리 계산
  for(int i=2; i<41; i++) {
    arr[0][i] = arr[0][i-1] + arr[0][i-2];
    arr[1][i] = arr[1][i-1] + arr[1][i-2];
  }

  cin >> T;
  for(int i=0; i<T; i++) {
    cin >> c;
    // 받은 수의 0과 1의 개수를 출력
    cout << arr[0][c] << " " << arr[1][c] << '\n';
  }

  return 0;
}
