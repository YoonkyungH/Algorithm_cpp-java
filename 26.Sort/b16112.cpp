#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5차 전직

int main() {
    ios::sync_with_stdio(0);

    int n, k;       // n: 퀘스트 k: 최대 활성 스톤 개수
    int sum = 0;    // 경험치 합
    cin >> n >> k;

    if(n == 1) {
        cout << "0\n"; return 0;
    }

    vector<int> v;
    for(int i=0; i<n; i++) {
        int q;
        cin >> q;

        v.push_back(q);
    }

    sort(v.begin(), v.end());

    sum = v[1];
    int kNum;   // 지금 활성화 되어있는 스톤의 개수
    if(k == 1) { kNum = 1; }
    else { kNum = 2; }
    for(int i=2; i<n; i++) {
        sum += v[i] * kNum;
        // for(int j=0; j<kNum; j++) {
        //     sum += v[i];
        // }
    
        if(kNum < k) { kNum++; }

    }

    cout << sum << '\n';


    return 0;
}