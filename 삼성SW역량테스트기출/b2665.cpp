// 미로 만들기
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N;
int map[51][51];
int visited[51][51] = {false, };
int ans[51][51] = {0, };

struct node {
    int x, y;
    int dark;
} n;
queue<node> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    
    n.y = 1; n.x = 1; n.dark = 0;
    q.push(n);
    visited[1][1] = true;
    ans[1][1] = 0;

    while(!q.empty()) {
        node now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int tmp = now.dark;

            int nextX = now.x + dx[i];
            int nextY = now.y + dy[i];

            if(nextX < 1 || nextY < 1 || nextX > N || nextY > N) continue;

            if(!map[nextY][nextX]) tmp++;

            if(visited[nextY][nextX]) { // 방문 했다면 더 작은 값을 택해야 하므로
                if(ans[nextY][nextX] > tmp) {
                    ans[nextY][nextX] = tmp;

                    n.y = nextY; n.x = nextX; n.dark = tmp;
                    q.push(n);
                    visited[nextY][nextX] = true;
                } else {
                    continue;
                }
            } else {
                ans[nextY][nextX] = tmp;
                visited[nextY][nextX] = true;
                n.y = nextY; n.x = nextX; n.dark = tmp;
                q.push(n);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        string str = "";
        cin >> str;
            for(int j=0; j<N; j++) {
                map[i][j+1] = str[j]-48;
            }
    }

    bfs();
    cout << ans[N][N] << '\n';

    return 0;
}