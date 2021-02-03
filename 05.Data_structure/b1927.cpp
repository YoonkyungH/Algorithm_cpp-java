#include <iostream>
#include <queue>
using namespace std;

// 최소 힙

int main() {
  ios::sync_with_stdio(0);
  // cin을 cout으로부터 untie 시킴.(묶여있는 것을 풀어줘 cout 다음 cin인 경우 입력부터 받도록)
  // endl 대신 '\n'을 쓰는 이유도 속도 때문.
  cin.tie(0);
  // priority_queue는 stl 제공.
  // priority_queue<int> minHeap이 default로 내림차순. 오름차순은 greater<int>
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int N;
  int op;

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> op;
    if(op == 0) {
      if(minHeap.empty()) {             // 비었다면 0을 출력
        cout << "0" << '\n';
      } else {                          // 오름차순 정렬이 되어있기 때문에 가장 작은 원소는 root. 즉, top()함수로 출력
        cout << minHeap.top() << '\n';  // 출력 후 pop()으로 원소 삭제
        minHeap.pop();
      }
    } else {                            // 0이 아닌 수가 입력 되었을 때 minHeap에 push()로 원소 삽입
      minHeap.push(op);
    }
  }

  return 0;
}
