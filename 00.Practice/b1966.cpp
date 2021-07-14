#include <iostream>
#include <queue>
using namespace std;


int main() {
  ios::sync_with_stdio(0);

  int T;
  int a, b;

  cin >> T;

  while(T--) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    cin >> a >> b;

    int n;
    for(int i=0; i<a; i++) {
      cin >> n;
      q.push({i, n});
      pq.push(n);
    }

    int cnt = 0;
    while(!q.empty()) {
      int idx = q.front().first;
      int value = q.front().second;
      q.pop();
      if(pq.top() == value) {
        pq.pop();
        cnt++;
        if(idx == b) { cout << cnt << '\n'; break; }
      } else { q.push({idx, value}); }
    }
  }

  return 0;
}
