#include <iostream>
#include <queue>
#include <tuple> // 3쌍의 값을 묶기 위해
using namespace std;

#define MAX 100

// 토마토

int M, N, H;
int map[MAX][MAX][MAX] = {-1, };
queue<tuple<int, int, int> > q;
bool visited[MAX][MAX][MAX] = {false, };
int day = 1;

// 동 서 남 북 위 아래
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

// void bfs(int x, int y, int h) {
void bfs() {

    // day++;
    // q.push(make_tuple(x, y, h));

    // visited[x][y][h] = true;
    int x, y, h;

    while(!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        h = get<2>(q.front());

        q.pop();
    
        visited[h][y][x] = true;

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h + dh[i];

            if(0<=nx && nx<N && 0<=ny && ny<M && 0<=nh && nh<h) {
                if(visited[nh][ny][nx]==false && map[nh][nx][nx]==0) {
                    q.push(make_tuple(nh, ny, nx));
                    visited[nh][ny][nx] = true;
                    map[nh][ny][nx] = 1;
                    // map[nh][ny][nx] = map[h][y][x] + 1;
                    // day = map[nh][ny][nx];
                }
            }
        }
        day++;
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> M >> N >> H;

    bool flag = false;
    int cnt = 0;


    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) { 
                    // 익은 토마토가 하나라도 있음
                    flag = true; 
                    // bfs(j, k, i);
                    // 모두 익어있는 경우를 판별하기 위함
                    cnt++; 
                    q.push(make_tuple(i, j, k));
                    // visited[j][k][i] = true;
                }
                else if(map[i][j][k] == -1) { cnt++; }
            }
        }
    }
    bfs();


    // 테스트
    // for(int i=0; i<H; i++) {
    //     for(int j=0; j<N; j++) {
    //         for(int k=0; k<M; k++) {
    //             cout << map[k][j][i] << ' ';
    //         } cout << '\n';
    //     } cout << '\n';
    // }

    // for(int i=0; i<H; i++) {
    //     for(int j=0; j<N; j++) {
    //         for(int k=0; k<M; k++) {
    //             if(map[j][k][i] > day) { day = map[j][k][i]; }
    //         }
    //     }
    // }

    if(flag == false) { cout << "-1\n"; }       // 모두 익지 못함
    else if(H*N*M == cnt) { cout << "0\n"; }    // 모두 익어있음
    else { cout << day << '\n'; }

    return 0;
}

