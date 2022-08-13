// 뱀
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, L, X;
char C;
int map[101][101] = {0, };
vector<pair<int, char> > v;
bool visited[101][101] = {false, };
int ans;

queue<pair<int, int> > q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;  // 보드의 크기, 사과의 개수
    for(int i=0; i<K; i++) {
        int y, x;
        cin >> x >> y;
        map[x][y] = 1;
    }


    cin >> L;
    for(int i=0; i<L; i++) {
        cin >> X >> C;

        v.push_back(make_pair(X, C));
    }


    int curY=1, curX=1;
    q.push(make_pair(1, 1));

    int dirIdx = 0; 
    int i = 0;  // vector(방향 전환)
    while(1) {
        ans++;

        int nx = curX + dx[dirIdx];
        int ny = curY + dy[dirIdx];
        if(visited[nx][ny] || ny>N || nx>N || nx<=0 || ny<=0) {

            break;
        }   // 벽이나 자신의 몸에 부딪혔을 때 break

        curX = nx;
        curY = ny;
        visited[curX][curY] = true;
        q.push(make_pair(nx, ny));

        // 사과가 없다면 pop으로 꼬리 빼주기
        // 사과가 있다면 앞으로 이동(꼬리 유지 -> queue에서 빼지 않기)
        if(map[nx][ny] == 0) {

            int tmpX = q.front().first;
            int tmpY = q.front().second;
            visited[tmpX][tmpY] = false;


            q.pop(); // 꼬리 빼주기
        } else {
            map[nx][ny] = 0;    // 먹은 사과 없애기
        }


        if(ans == v[i].first) {
            if(v[i].second == 'D') {
                dirIdx++;
                if(dirIdx > 3) { dirIdx = 0; }
            } else {
                dirIdx--;
                if(dirIdx < 0) { dirIdx = 3; }
            }

            i++;
        }   // 몸의 방향을 돌려야 할 시간이 되었을 때 머리 방향 바꾸기


    }
    
    cout << ans << '\n';

    return 0;
}