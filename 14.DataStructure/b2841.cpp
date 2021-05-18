#include <iostream>
#include <stack>
using namespace std;

// 외계인의 기타 연주
// 원래는 line별로 stack을 선언해야 하는 줄 알았으나 배열처럼 사용하면 된다는 것을 알았음

int main() {
  ios::sync_with_stdio(0);
  stack<int> g[7];  // idx0은 쓰지 않기 때문에 6+1

  int N, P;
  cin >> N >> P;

  int cnt=0;
  for(int i=0; i<N; i++) {
    int line, p;
    cin >> line >> p;

    while(!(g[line].empty()) && g[line].top() > p) {  // 줄이 비어있지 않고 손을 떼야 할 상황(칠 프렛이 잡은 프렛보다 낮다면)이라면
      g[line].pop(); cnt++; // 손을 뗴고(pop) cnt 증가
    }

    if(g[line].empty() || g[line].top() < p) {  // 비어있거나 손을 떼지 않아도 되는 상황(칠 프렛이 잡은 프렛보다 높다면)이라면
      g[line].push(p); cnt++; // 프렛 누르고(push) cnt 증가
    }
  }

  cout << cnt;

  return 0;
}
