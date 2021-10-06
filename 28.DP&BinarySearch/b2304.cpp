// 창고 다각형

#include <iostream>
#include <algorithm>

using namespace std;

int map[1000];

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int maxH = 0, maxX = 0;
    int answer = 0;

    for(int i=0; i<N; i++) {
        int L, H;
        cin >> L >> H;

        map[L] = H; // 위치에 높이 저장

        if(H > maxH) {
            maxH = H;   // 최대 높이
            maxX = L;   // 최대 높이의 좌표
        }
    }

    int m = 0;
    
    for(int i=0; i<maxX; i++) { // 최대 높이가 있는 좌표까지
        m = max(m, map[i]);

        answer += m;
    }

    m = 0;
    for(int i=1000; i>=maxX; i--) { // 맨 끝부터 최대 높이가 있는 좌표까지
        m = max(m, map[i]);

        answer += m;
    }

    cout << answer << '\n';

    return 0;
}