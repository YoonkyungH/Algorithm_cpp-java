// 수 이어 쓰기 1

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string N;
    cin >> N;

    int len = N.length();
    int ans = 0;
    int tmp = 1;

    if(len == 1) { cout << N << '\n'; return 0; }

    for(int i=1; i<len; i++) {
        ans += i * (9 * pow(10, i-1));
    }

    ans += len*(stoi(N) - pow(10, len-1) + 1);

    cout << ans << '\n';

    return 0;
}