#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// N번째 큰 수

int main() {
  ios::sync_with_stdio(0);
  // 오름차순 우선순위 큐
  priority_queue<int, vector<int>, greater<int>> pq;

  int N, n;
  cin >> N;

  // 자꾸 틀리고 메모리 초과가 나서 N번째로 큰 수가 아니면
  // 나머지 수는 필요가 없기 때문에 버리기로 함
  for(int i=0; i<N*N; i++){
    cin >> n;
    if(pq.size() < N) pq.push(n);
    else { // N크기만큼 큐가 찼다면
      // 출력할 결과와 비교해 그 수보다 크다면 이미 있던 수를 꺼내고 새 수를 넣음
      if(pq.top() < n) { pq.pop(); pq.push(n); }
    }
  }

  cout << pq.top() << '\n';

  return 0;
}
