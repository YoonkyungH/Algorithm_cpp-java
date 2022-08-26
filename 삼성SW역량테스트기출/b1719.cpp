// 택배
// 플로이드워셜
#include <iostream>
using namespace std;

#define INF 987654321

int n, m;
int map[201][201];
int ans[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;

        ans[a][b] = b;
        ans[b][a] = a;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                    ans[j][k] = ans[j][i];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(ans[i][j] == 0) cout << "- ";
            else cout << ans[i][j] << " ";
        } cout << '\n';
    }

    return 0;
}