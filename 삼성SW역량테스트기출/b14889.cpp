// 스타크와 링크
// 조합이용
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define MAX 987654321

int N;
int map[21][21];
int arr[21][21];
int ans = MAX;

void combination(vector<int> comb, int r, int idx, int depth) {
    if(r == 0) {
 
        int s=0, l=0;
        bool visited[21] = {false, };

        for(int j=0; j<comb.size()-1; j++) {
            for(int k=j+1; k<comb.size(); k++) {
                s += map[comb[j]][comb[k]];
                s += map[comb[k]][comb[j]];
                visited[comb[j]] = true;
                visited[comb[k]] = true;
            }
        }

        vector<int> tmp;
        for(int j=0; j<N; j++) {
            if(!visited[j]) {
                tmp.push_back(j);
            } 
        }

        for(int j=0; j<tmp.size()-1; j++) {
            for(int k=j+1; k<tmp.size(); k++) {
                l += map[tmp[j]][tmp[k]];
                l += map[tmp[k]][tmp[j]];
            }
        }

        ans = min(ans, abs(s-l));
        
    } else if(depth == N) {
        return;
    } else {
        comb[idx] = depth;
        combination(comb, r-1, idx+1, depth+1);
        combination(comb, r, idx, depth+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    vector<int> comb(N/2);
    combination(comb, N/2, 0, 0);

    cout << ans << '\n';

    return 0;
}