// 녹색 옷 입은 애가 젤다지?
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int N, tc;
int map[125][125];
int dist[125][125];
bool visited[125][125];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }
}

void input() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tc = 1;
    while(1) {
        int ans = 0;

        cin >> N;
        if(N == 0) break;

        init();
        input();
        
        priority_queue<pair<int, pair<int, int> > > pq;
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

                if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    int nCost = cost + map[nx][ny];
                    if(dist[nx][ny] > nCost) {
                        dist[nx][ny] = nCost;
                        pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }

        ans = dist[N-1][N-1];
        cout << "Problem " << tc++ << ": " << ans << '\n';

    }

    return 0;
}