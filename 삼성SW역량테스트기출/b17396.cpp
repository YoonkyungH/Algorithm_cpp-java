// 백도어
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, M;
int sight[100001];  // 시야
bool visited[100001] = {false, };
vector<pair<int, int> > v[300001];
int ans = INF;

void sol(int start, int t) {
    if(start == N-1) {
        ans = min(ans, t);
    }

    for(int i=0; i<v[start].size(); i++) {
        if(!visited[v[start][i].first]) {
            if (v[start][i].first == N-1 || sight[v[start][i].first] == 0) {
                visited[v[start][i].first] = true;
                sol(v[start][i].first, v[start][i].second + t);
                visited[v[start][i].first] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> sight[i];
    }

    for(int i=0; i<M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        v[a].push_back(make_pair(b, t));
        v[b].push_back(make_pair(a, t));
    }


    visited[0] = true;
    sol(0, 0);

    if(ans == INF) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}