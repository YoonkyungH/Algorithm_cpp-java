#include <iostream>
#include <deque>
#include <math.h>
using namespace std;

// 톱니바퀴

deque<bool> wheels[4];

// spread_dir: 0왼쪽, 1양방향, 2오른쪽
void Rotate(int num, int rotate_dir, int spread_dir) {
  // 왼쪽 검사
  if(spread_dir == 0 || spread_dir == 1) {
    if(num > 0) {
      // 왼쪽과 맞닿는 부분이 일치한지 검사
      if(wheels[num][6] != wheels[num-1][2]) {
        // 극이 다를 경우 회전
        Rotate(num-1, -1*rotate_dir, 0);
      }
    }
  }

  // 오른쪽 검사
  if(spread_dir == 1 || spread_dir == 2) {
    if(num < 3) {
      // 오른쪽과 맞닿는 부분이 일치한지 검사
      if(wheels[num][2] != wheels[num+1][6]) {
        // 극이 다를 경우 회전
        Rotate(num+1, -1*rotate_dir, 2);
      }
    }
  }

  // 반시계 회전
  if(rotate_dir == -1) {
  bool tmp = wheels[num].front();
    wheels[num].pop_front();
    wheels[num].push_back(tmp);
  }

  // 시계 회전
  if(rotate_dir == 1) {
    bool tmp = wheels[num].back();
    wheels[num].pop_back();
    wheels[num].push_front(tmp);
  }

}

int main() {
  ios::sync_with_stdio(0);

  for(int i=0; i<4; i++) {
    char c;
    for(int j=0; j<8; j++) {
      cin >> c;
      wheels[i].push_back(c-48);
    }
  }

  int K, N, D;
  cin >> K;

  for(int i=0; i<K; i++) {
    cin >> N >> D;
    // N-1은 인덱스가 0부터니까, 마지막 인자 1은 일단 처음이니까 양방향 다 검사
    Rotate(N-1, D, 1);
  }

  int ans = 0;
  for(int i=0; i<4; i++) {
    // N: 0(false), S: 1(true)인데 S극이면 점수
    if(wheels[i].front() == true) { ans += pow(2, i); }
  }

  cout << ans;


  return 0;
}
