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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;  // 보드의 크기, 사과의 개수
    for(int i=0; i<K; i++) {
        int y, x;
        cin >> y >> x;
        map[x][y] = 1;
    }

    // for(int i=1; i<=N; i++) {
    //     for(int j=1; j<=N; j++) {
    //         cout << map[j][i] << ' ';
    //     }cout << '\n';
    // }

    cin >> L;
    for(int i=0; i<L; i++) {
        cin >> X >> C;

        v.push_back(make_pair(X, C));
    }


    int curY=1, curX=1;
    q.push(make_pair(curX, curY));

    int dir = 1;    // 1 동 2 서 3 남 4 북 (현재 바라보는 방향)
    int i = 0;  // vector(방향 전환)
    while(1) {
        ans++;
        if(visited[curX][curY] || curY>N || curX>N) {
            cout << "curX and curY: " << curX << " " << curY << '\n'; 
            break;
        }   // 벽이나 자신의 몸에 부딪혔을 때 break

        visited[curX][curY] = true;


        if(ans == v[i].first) {
            if(dir == 1) {
                if(v[i].second == 'L') dir = 4;
                else dir = 3;
            } else if(dir == 2) {
                if(v[i].second == 'L') dir = 3;
                else dir = 4;
            } else if(dir == 3) {
                if(v[i].second == 'L') dir = 1;
                else dir = 2;
            } else if(dir == 4) {
                if(v[i].second == 'L') dir = 2;
                else dir = 1;
            }
            i++;
        }   // 몸의 방향을 돌려야 할 시간이 되었을 때 머리 방향 바꾸기


        if(dir == 1) {  // 동쪽 바라보는 상황
            curX++;
        } else if(dir == 2) {
            curX--;
        } else if(dir == 3) {
            curY++;
        } else if(dir == 4) {
            curY--;
        }


        q.push(make_pair(curX, curY));

        // 사과가 없다면 pop으로 꼬리 빼주기
        // 사과가 있다면 앞으로 이동(꼬리 유지 -> queue에서 빼지 않기)
        if(map[curX][curY] == 0) {

            int tmpX = q.front().second;
            int tmpY = q.front().first;
            visited[tmpX][tmpY] = false;

            cout << "사과 없음 " << tmpX << " " << tmpY << '\n';

            q.pop(); // 꼬리 빼주기
        } 
    }
    
    cout << ans << '\n';

    return 0;
}