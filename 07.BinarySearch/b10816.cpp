#include <iostream>
#include <unordered_map>
// #include <hash_map>
// using namespace stdext;
using namespace std;

// 숫자 카드 2
// 원래 hash_map을 이용하려고 했는데 c++ STL 비표준이라 unordered_map 사용을 권장
// unordered_map: hash_table 기반 hash container
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, c;
  unordered_map<int, int> card;

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> c;
    // 나온 횟수만큼 ++될 수 있음
    card[c]++;
  }
  // 예제상 6 3 2 10 10 10 -10 -10 7 3 => card[6][1], card[3][2], card[2][1], card[10][3]

  cin >> M;
  for(int i=0; i<M; i++) {
    cin >> c;
    // 입력을 받아서 입력받은 수에 해당하는 수를 출력 = 나온 횟수
    cout << card[c] << ' ';
  }

  return 0;
}
