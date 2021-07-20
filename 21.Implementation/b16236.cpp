#include <iostream>
#include <queue>
using namespace std;

#define MAX 20

// 아기상어
// BFS: 모든 간선의 가중치가 1일 때 최단 경로 탐색

int N;
int shark_x, shark_y, eat_cnt, shark_size=2;
int min_dist, min_x, min_y, result;
int map[MAX][MAX], check[MAX][MAX];
// check 배열은 거리를 저장

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

// 물고기 좌표
struct info {
  int x, y;
};

void bfs(int x, int y) {
  queue<info> q;

  // 지금 위치의 시간 = 0
  check[x][y] = 0;
  q.push({x, y});

  while(!q.empty()) {
    // 가장 앞에 있는 객체의 네 방향을 탐색
    info cur = q.front();
    q.pop();

    int x = cur.x, y = cur.y;

    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위가 어긋난 경우 continue
      if(nx<0 || nx>=N || ny<0 || ny>=N) { continue; }

      // 이미 방문했거나 상어 크기보다 커도 continue
      if(check[nx][ny]!=-1 || map[nx][ny]>shark_size) { continue; }

      // (nx, ny)에 있는 물고기까지의 이동거리 갱신
      check[nx][ny] = check[x][y] + 1;

      // 먹을 수 있는 물고기라면
      if(map[nx][ny]!=0 && map[nx][ny]<shark_size) {
        // 이 과정은 맨 위, 맨 왼쪽 물고기부터 먹어야해서 검사하는 것
        if(min_dist > check[nx][ny]) {
          min_x = nx;
          min_y = ny;
          min_dist = check[nx][ny];
        } else if(min_dist == check[nx][ny]) {
          if(min_x == nx) {
            if(min_y > ny) {
              min_x = nx;
              min_y = ny;
            }
          } else if(min_x > nx) {
            min_x = nx;
            min_y = ny;
          }
        }
      }

      // 다시 물고기 위치를 push
      q.push({nx, ny});

    }
  }

}

int main() {
  ios::sync_with_stdio(0);

  int x, y;

  cin >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> map[i][j];
      // 아기 상어의 위치를 알아내야 하기 때문
      if(map[i][j] == 9) { shark_x=i; shark_y=j; map[i][j]=0; }
    }
  }

  // 물고기 개수만큼 수행
  while(1) {
    min_dist = 400;
    min_x = 20;
    min_y = 20;

    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        check[i][j] = -1;
      }
    }
    // 여기까지 BFS를 위한 정보 초기화 과정

    // 처음엔 아기상어 자리를 인자로 bfs 호출
    bfs(shark_x, shark_y);

    // 먹을 수 있는 물고기라면
    if(min_x != 20 && min_y != 20) {
      // 이동시간을 result에 더해주고
      result += check[min_x][min_y];

      // 얼마나 먹었는지 증가시켜주고
      eat_cnt++;

      // 아기상어가 성장할 수 있는 경우인지 검사
      if(eat_cnt == shark_size) {
        shark_size++;
        eat_cnt = 0;
      }

      // 물고기를 먹었으니까 0으로 초기화
      map[min_x][min_y] = 0;

      // 상어의 위치를 재조정
      shark_x = min_x;
      shark_y = min_y;
    } else {
      // 먹을 수 있는 물고기가 없는 경우라면 break
      break;
    }
  }
  cout << result << '\n';

  return 0;
}
