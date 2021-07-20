#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 반복수열
// visited가 반복되지 않은 것만 세면 되므로 1인 것은 한 번만 나왔던 것이므로

int P;
// 9^5 = 295245
int visited[300001] = {0, };

void DFS(int a) {
  visited[a]++;
  // 3이 된 순간 계속 반복될 것을 의미하므로 종료
  if(visited[a] == 3) { return; }

  int sum = 0;
  while(a) {
    // P제곱한 값을 구하는 식
    sum += (int)pow((a % 10), P);
    a /= 10;
  }

  // 다음 값은 지금 값의 P제곱
  DFS(sum);
}

int main() {
  ios::sync_with_stdio(0);

  int A;
  cin >> A >> P;

  DFS(A);

  int result = 0;
  for(int i=0; i<300001; i++) {
    if(visited[i] == 1) { result++; }
  }

  cout << result << '\n';

  return 0;
}
