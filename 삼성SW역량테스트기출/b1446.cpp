// 지름길
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, D;
vector<pair<int, int> > v[10000];
int ans = INF;

void sol(int cur, int start) {
    if(start == D) {
        ans = min(cur, ans);
    }

    for(int i=0; i<v[start].size(); i++) {
        if(v[start][i].second <= D) {
            if(cur + (v[start][i].second - start) > v[start][i].first + cur) {
                sol(v[start][i].first + cur, v[start][i].second);
            } else {
                sol(cur + (v[start][i].second - start), v[start][i].second);
            }
        } 
    }
    
    if(start+1 <= D) 
        sol(cur + 1, start + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;
    for(int i=0; i<N; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        v[s].push_back(make_pair(l, e));    // (길이, 도착지점)
    }

    sol(0, 0);

    cout << ans << '\n';

    return 0;
}