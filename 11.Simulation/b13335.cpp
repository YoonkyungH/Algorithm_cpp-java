#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 트럭

int main() {
  ios::sync_with_stdio(0);
  int n, W, L;  // n: 트럭 수, W: 다리의 길이, L: 다리 최대 하중
  int sum = 0;  // 걸리는 시간의 합
  vector<int> v;  // 트럭 무게를 저장
  queue<int> q; // 도로 위 트럭

  cin >> n >> W >> L;

  int w;  // 트럭의 무게
  for(int i=0; i<n; i++) {
    cin >> w;
    v.push_back(w);
  }

  w = 0;  // 도로 위 트럭의 총 무게를 잴 것
  for(int i=0; i<n; i++) {  // 트럭들이 도로에 다 오를 때까지
    while(1) {
      if(q.size() == W) { // 다리가 꽉 찼으면
        // 가장 먼저 들어온 트럭이 나가므로 전체 무게에서 빼주고 삭제
        w -= q.front();
        q.pop();
      }
      if(w+v[i] <= L) break;
      // 최대하중에 도달했다면 더 못 들어오게 큐를 0으로 메우고 시간을 증가
      q.push(0);
      sum++;
    }
    // 아직 최대 하중에 도달하지 않았다면 큐에 트럭 올리고
    // 무게를 더하고 시간 증가
    q.push(v[i]);
    w += v[i];
    sum++;
  }

  // for문에서 마지막 트럭이 다리에 오르는 것까지 계산했으므로
  // 마지막 트럭이 나가는 시간 w(다리길이)를 더해줌
  cout << sum + W << '\n';

  return 0;
}
