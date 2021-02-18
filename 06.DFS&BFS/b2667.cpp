#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX 25

using namespace std;

// 단지번호붙이기

int n;                        // 지도의 크기
int num[MAX*MAX] = {0, };     // 단지 안 집의 개수
int house = 0;                // 단지의 개수
int map[MAX][MAX];            // 입력받은 지도
bool visited[MAX][MAX];

// 우,하,좌,상
// (0, 1), (1, 0), (0, -1), (-1, 0) 이렇게 생각
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
  queue<pair<int, int>> q; // (x,y) = (행, 열)
  q.push(make_pair(y, x)); // pair로 queue에 넣음

  // 처음 x,y를 방문 했기때문에
  visited[y][x] = true;
  num[house]++;           //단지 안 집의 개수++

  while (!q.empty()) {    // 큐가 빌 때까지
    // 큐의 현재 원소를 꺼내기 (queue: FIFO)
    // queue의 push는 원소를 !뒤에! 추가
    // queue의 pop은 원소를 !앞에서! 삭제
    y = q.front().first;
    x = q.front().second;
    q.pop();

    // 해당 위치의 상하좌우를 확인
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 지도를 벗어나지 않고
      if (0 <= nx && nx < n && 0 <= ny && ny < n) {
        // 방문하지 않은 집이라면
        if (map[ny][nx] == 1 && visited[ny][nx] == false) {
          visited[ny][nx] = true;
          // 해당 단지의 집의 수 증가
          num[house]++;
          // 큐에 현재 nx,ny를 추가
          q.push(make_pair(ny, nx));
        }
      }
    }
  }
}

int main() {
    scanf("%d", &n);

    // 지도 데이터 입력
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%1d", &map[i][j]);
      }
    }

    // 전체의 지도 데이터를 하나하나 체크
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // 방문하지 않은 집이 있을 경우
        if (map[i][j] == 1 && visited[i][j] == false) {
          // bfs탐색
          bfs(i, j);
          house++;
        }
      }
    }

    // 오름차순으로 정렬
    sort(num, num + house);

    // 출력
    printf("%d\n", house);
    for (int i = 0; i < house; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}
