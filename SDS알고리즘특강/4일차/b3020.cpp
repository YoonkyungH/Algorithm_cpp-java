// 개똥벌레
// 누적합

#include <iostream>
#include <algorithm>

using namespace std;

int top[500001];
int bottom[500001];

// 아래에서 자라는 석순, 위에서 자라는 종유석, 석순 ,,,
int N, H; // 길이(짝수), 높이
int left = 1, right = H;

int main() {
    ios::sync_with_stdio(0);


    cin >> N >> H;

    for(int i=0; i<N; i++) {
        int size; 
        cin >> size;
        if(i%2 == 0) {
            bottom[size]++;
        } else {
            top[size]++;
        }
    }

    // 누적합
    for(int i=H; i>1; i--) {
        bottom[i-1] += bottom[i];
        top[i-1] += top[i];
    }

    int total = 0;
    int minVal = 987654321;
    int cnt = 0;
    // 그림을 그려보면 이해가 쉬움
    for(int i=1; i<=H; i++) {
        total = bottom[i] + top[H+1 - i];

        if(total < minVal) {
            minVal = total;
            cnt = 1;
        } else if(total == minVal) {
            cnt++;
        }
    }

    cout << minVal << " " << cnt << '\n';

    return 0;
}