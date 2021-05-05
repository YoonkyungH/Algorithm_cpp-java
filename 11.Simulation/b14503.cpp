#include <iostream>
using namespace std;
#define MAX 51

// 로봇 청소기

int N, M;   // 가로, 세로
int r, c, d; // 로봇이 있는 칸의 좌표(r, c), 방향 d
int map[MAX][MAX];
int result;

int main() {
  ios::sync_with_stdio(0);

  cin >> N >> M;
  cin >> r >> c >> d;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> map[i][j];
    }
  }

  while(1) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    if(map[r][c] == 0) {  // 현재 위치 청소
      map[r][c] = 2;
      result++;
    }

    int check = 0;
    for(int i=0; i<4; i++) {
      // 2.a
      d--;  // 왼쪽 방향
      if(d < 0) { // 0:북 1:동 2:남 3:서
        d = 3;
      }
      // 왼쪽 방향으로 한칸 전진
      int temp_x = r+dx[d];
      int temp_y = c+dy[d];
      if(map[temp_x][temp_y] == 0) {
        // 청소하지 않은 공간이라면 현재 위치를 그 공간으로 갱신
        r = temp_x;
        c = temp_y;
        check = 1;
        break;
      }
    }
    // 2.a를 수행하고 다시 1부터 진행하기 위함
    if(check == 1)  continue;

    // 2.c 청소 되어있거나 벽인 경우(check=0인 경우에만 이 코드가 실행 되므로) 후진
    int temp_d = d-2;
    if(temp_d == -2) temp_d = 2;
    if(temp_d == -1) temp_d = 3;

    r += dx[temp_d];
    c += dy[temp_d];

    // 후진도 못 하는 경우 작동 끝
    if(map[r][c] == 1) break;
  }

  cout << result;
  return 0;
}
