#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=1; i<=T; i++) {
        int t;
        cin >> t;

        int score[101] = {0, };

        int s;
        for(int j=0; j<1000; j++) {
            cin >> s;
            score[s]++;
        }

        int res = 0, m = 0;
        for(int j=100; j>-1; j--) {
            if(m < score[j]) {
                m = score[j];
                res = j;
            }
        }

        cout << "#" << i << " " << res << '\n';
    }

    return 0;
}