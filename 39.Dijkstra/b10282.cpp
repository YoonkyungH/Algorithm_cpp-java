// 해킹
// 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>    // swap

#define INF 987654321

using namespace std;

struct Data {
    int node, second;
    Data() {};
    Data(int second, int node) : second(second), node(node) {};

    bool operator<(const Data d) const {
        return second > d.second;   // 부등호 주의 
        // '<'는 시간초과
        // priority_queue는 시간 효율을 위해 사용하는데 "우선순위"를 지키지 못하면 의미가 없음
    }
};

int T;
int n, d, c;    // 컴터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호
int a, b, s;    // a -> b 의존, b 감염 s초 후 a도 감염
vector<Data> v[10001];
priority_queue<Data> pq;
int dp[10001];
int cp, tm; // 감염되는 컴퓨터 수, 걸리는 시간

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> n >> d >> c;
        cp = 0, tm = 0;
        for(int i=1; i<=n; i++) {
            v[i].clear();
            dp[i] = INF;
        }
        priority_queue<Data> newPq;
        swap(newPq, pq);

        for(int i=0; i<d; i++) {
            cin >> a >> b >> s;
            v[b].push_back(Data(s, a));  // a->b 의존, s초
        }

        dp[c] = 0;
        pq.push((Data(0, c)));
        while(!pq.empty()) {
            Data now = pq.top();
            pq.pop();
            if(dp[now.node] < now.second) continue;

            for(int i=0; i<v[now.node].size(); i++) {
                Data next = v[now.node].at(i);
                if((now.second+next.second) < dp[next.node]) {
                    dp[next.node] = next.second + now.second;
                    pq.push(Data(next.second + now.second, next.node));
                }
            }            
        }

        cp = 0, tm = 0;
        for(int i=1; i<=n; i++) {
            if(dp[i] != INF) {
                cp++;
                tm = max(tm, dp[i]);
            }
        }

        cout << cp << " " << tm << '\n';
    }

    return 0;
}