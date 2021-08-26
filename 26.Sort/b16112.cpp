#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5차 전직

int main() {
    ios::sync_with_stdio(0);

    long long n, k;       // n: 퀘스트 k: 최대 활성 스톤 개수
    long long sum = 0;    // 경험치 합
    cin >> n >> k;

    if(n == 1) {
        cout << "0\n"; return 0;
    }

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        // int q;
        cin >> v[i];

        // v.push_back(q);
    }

    sort(v.begin(), v.end());

    for(long long i=1; i<n; i++) {
        // k가 최대 활성 스톤이므로 min
        sum += v[i] * min(i, k);
    }

    cout << sum << '\n';


    return 0;
}