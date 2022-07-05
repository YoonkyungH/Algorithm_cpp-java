// 암호 만들기
#include <iostream>
#include <vector>
using namespace std;

int L, C;
vector<char> v;
vector<char> ans;

void dfs(int cnt, int idx, int mo, int ja) {
    if(cnt == L) {
        if(mo >= 1 && ja >= 2) {
            for(int i=0; i<ans.size(); i++) {
                cout << ans[i];
            } cout << '\n';
        }

        return;
    }

    for(int i=idx; i<C; i++) {
        ans.push_back(v[i]);
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] =='o' || v[i] == 'u') {
            dfs(cnt+1, i+1, mo+1, ja);
        } else {
            dfs(cnt+1, i+1, mo, ja+1);
        }

        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i=0; i<C; i++) {
        char c;
        cin >> c;

        v.push_back(c);


    }

    sort(v.begin(), v.end());
    dfs(0, 0, 0, 0);


    return 0;
}