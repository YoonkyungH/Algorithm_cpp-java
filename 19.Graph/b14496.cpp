#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 그대, 그머가 되어
// BFS: 너비우선탐색. 최단경로를 검색할 때

int a, b;
int N, M;
vector<vector<int>> v;  // 양방향, 무방향
int visit[1001];
int cnt[1001];

int bfs(int start, int end) {
  queue<int> q;
  q.push(start);
  visit[start] = true;

  while(!q.empty()) {
    // 큐에 값이 있다는 것은 아직 방문하지 않은 노드가 있다는 것
    int x = q.front();
    q.pop();
    // cout << x << ' ';

    if(x == end) {
      return cnt[x];
    //   cout << cnt << '\n';
    }

    for(int i=0; i<v[x].size(); i++) {
      int y = v[x][i];
      if(!visit[y]) {
        q.push(y);
        visit[y] = true;

        cnt[y] = cnt[x]+1;

      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);

  cin >> a >> b >> N >> M;

  v.resize(N+1);

  int n1, n2;
  for(int i=0; i<M; i++) {
    cin >> n1 >> n2;
    v[n1].push_back(n2);
    v[n2].push_back(n1);
  }

  if(a == b) { cout << "0" << '\n'; }
  else { cout << bfs(a, b) << '\n'; }

  return 0;
}
