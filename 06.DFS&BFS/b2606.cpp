#include <iostream>
#include <vector>
using namespace std;

// 바이러스
// DFS: 깊이 우선 탐색(끝까지 탐색 후 다시 가장 가까운 갈림길 ...)
// BFS: 너비 우선 탐색(시작 정점에서 가장 가까운 정점부터 탐색)

int n, m, cnt=0;
vector<vector<int>> v;      // 양방향, 무방향 2차원 벡터
bool arr[101] = {false, };  // 방문 여부

void dfs(int c) {
  arr[c] = true;                          // 호출된 정점 true

  // 처음에 여기서 2차원을 생각하지 못해서 애씀
  for(int i=0; i<v[c].size(); i++) {      // 호출된 정점으로부터 끝까지
    if(arr[v[c][i]] == false) {           // 방문하지 않았다면
      dfs(v[c][i]);                       // 다시 그 정점으로부터 dfs 함수 호출
      cnt++;                              // 감염된 컴퓨터의 개수++
    }
  }
  return;
}
int main() {
  int a, b;

  // n: 컴퓨터 수, m: 컴퓨터 쌍의 수
  cin >> n >> m;
  // 벡터 사이즈를 컴퓨터 개수+1로 설정(v[0]은 버릴 것이므로)
  v.resize(n+1);

  for(int i=0; i<m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  cout << cnt;

  return 0;
}
