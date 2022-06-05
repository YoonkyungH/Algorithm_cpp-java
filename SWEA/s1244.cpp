#include <iostream>
#include <algorithm>    // swap()
using namespace std;

int ch, res;
string num;
void dfs(int idx, int cur) {
    if(cur == ch) { // 교환 횟수 도달
        res = max(res, stoi(num));
        return;
    }

    for(int i=idx; i<num.size()-1; i++) {
        for(int j=i+1; j<num.size(); j++) {
            swap(num[i], num[j]);
            dfs(i, cur+1);
            swap(num[i], num[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=1; i<=t; i++) {
        res = 0;
        cin >> num >> ch;

        if(ch > num.size()) {
            ch = num.size() - 1;
        }

        dfs(0, 0);

        cout << "#" << i << " " << res << '\n';
    }

    return 0;
}