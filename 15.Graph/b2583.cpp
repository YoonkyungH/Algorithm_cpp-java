#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

// 영역 구하기
// bfs

int N, M, K;
int map[MAX][MAX];
bool visited[MAX][MAX] = {false, };
int area = 1; // 영역의 넓이
vector<int> num;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));

  visited[y][x] = true;

  while(!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0 <= nx && nx < N && 0 <= ny && ny < M) {
        if(map[ny][nx] == 0 && visited[ny][nx] == false) {
          // map 범위 안에 존재하며 빈 칸이고 방문하지 않았다면
          visited[ny][nx] = true;
          q.push(make_pair(ny, nx));
          area++;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);

  cin >> M >> N >> K;

  int x=0, y=0, x2=0, y2=0;

  for(int i=0; i<K; i++) {  // map 채우기
    cin >> x >> y >> x2 >> y2;
    for(int q=y2-1; q>=y; q--) {
      for(int j=x2-1; j>=x; j--) {
        map[q][j] = 1; // 직사각형 영역을 1로 표시
      }
    }
  }

  // map 확인용 출력
  // cout << "map test" << '\n';
  // for(int i=0; i<M; i++) {
  //   for(int j=0; j<N; j++) {
  //     cout << map[i][j] << ' ';
  //   } cout << '\n';
  // }

  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      if(map[i][j] == 0 && visited[i][j] == false) {
        bfs(i, j);
        num.push_back(area);
        area=1; // area를 초기화
      }
    }
  }

  sort(num.begin(), num.end());
  cout << num.size() << '\n';
  for(int i=0; i<num.size(); i++) {
    cout << num[i] << '\n';
  }

  return 0;
}
