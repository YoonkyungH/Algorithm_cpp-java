// 시험 감독
#include <iostream>
#include <vector>
using namespace std;

int N, A, B, C;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    cin >> B >> C;

    long long cnt = 0;
    for(int i=0; i<N; i++) {
        cnt++;
        if(v[i] > B) {
            int tmp = v[i] - B;
            if(tmp % C == 0) cnt += tmp/C;
            else cnt += tmp/C + 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}