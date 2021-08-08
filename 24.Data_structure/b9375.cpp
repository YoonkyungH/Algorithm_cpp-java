#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 패션왕 신해빈

int main() {
    int T, N;
    cin >> T;

    while(T--) {
        vector<pair<string, int> > v;

        cin >> N;

        string s1, s2;
        for(int n=0; n<N; n++) {
            cin >> s1 >> s2;

            // 옷이 하나도 없다면 일단 추가
            if(v.size() == 0) { v.push_back(pair<string, int>(s2, 1)); continue; }

            for(int i=0; i<v.size(); i++) {
                // 벡터를 돌면서 같은 종류의 옷이라면 second에 옷 개수를 추가
                if(s2 == v[i].first) {
                    v[i].second++;
                    break;
                }
                // 끝까지 돌았는데 없다면 새로운 종류의 옷이므로 추가
                if(i == v.size()-1) { v.push_back(pair<string, int>(s2, 0)); }
            }

        }

        int ans = 1;
        for(int j=0; j<v.size(); j++) {
            // +1은 그 종류의 옷을 걸치지 않는 경우
            ans *= (v[j].second+1);
        }

        // -1은 모두 벗는 경우
        cout << ans-1 << '\n';
    }

    return 0;
}