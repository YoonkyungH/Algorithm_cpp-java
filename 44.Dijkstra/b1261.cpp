// 알고스팟
#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define INF 987654321

int N, M;
int ans;
int map[100][100];
int dist[100][100];
bool visited[100][100];
priority_queue<pair<int, pair<int, int> > > pq;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init() {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    init();

    for(int i=0; i<M; i++) {
        string str;
        cin >> str;

        for(int j=0; j<N; j++) {
            map[i][j] = str[j] - 48;    // 아스키코드에서 0은 48
        }
    }

    pq.push(make_pair(-map[0][0], make_pair(0, 0)));
    dist[0][0] = map[0][0];

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx <= M && ny <= N) {
                int nCost = cost + map[nx][ny];
                if(dist[nx][ny] > nCost) {
                    dist[nx][ny] = nCost;
                    pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }

    cout << dist[M-1][N-1] << '\n';

    return 0;
}