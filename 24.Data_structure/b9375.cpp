#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;   // 의상 종류

        string s;
        vector<pair<string, string> > v;

        if (n == 0) { cout << "0\n"; }
        else if (n == 1) {
            cout << "1\n";
        }
        else {

            for (int j = 0; j <= n; j++) {
                // cin은 공백 문자에서 입력을 끊어버림
                getline(cin, s);
                int point = s.find(' ');
                string tmp1 = s.substr(0, point);
                string tmp2 = s.substr(point + 1, (s.size()-1) - point);
                v.push_back(pair<string, string>(tmp2, tmp1));
            }

            // 종류별로 모으기 위해 오름차순 정렬
            sort(v.begin(), v.end());

            // cout << "\nTEST1\n";
            // for(int i=0; i<v.size(); i++) {
            //     cout << i << ": " << v[i].first << ' ' << v[i].second << '\n';
            // }

            int ans = 1;
            int cnt = 2;    // 입거나 안 입거나

            // 벡터를 출력해보니 인덱스 1부터 시작
            for (int j = 1; j < n; j++) {
                if (v[j].first == v[j + 1].first) { cnt++; }
                else {
                    ans *= cnt;
                    cnt = 2;
                }
            }

            ans *= cnt;
            // 모두 벗는 경우를 제외해줌
            ans--;

            cout << ans << '\n';
            
            v.clear();
        }
    }
    return 0;
}