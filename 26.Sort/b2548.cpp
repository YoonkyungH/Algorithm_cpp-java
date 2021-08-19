#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 대표 자연수

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    
    vector<int> v;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    // 짝수면 가운데 - 1, 홀수면 정가운데
    if(v.size() % 2 == 0) {
        cout << v[(N/2)-1] << '\n';
    } else {
        cout << v[N/2] << '\n';
    }

    return 0;
}