// 제곱수의 합
// 다이나믹 프로그래밍

#include <iostream>
using namespace std;

int d[100001];

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {
        d[i] = i;   // i = (1^2) * i
        
        for(int j=1; j*j <= i; j++) {
            if(d[i] > d[i - (j*j)] + 1) { 
                // 항의 최소 개수를 구해야 하므로 개수가 더 적으면 갱신
                d[i] = d[i - (j*j)] + 1;
            }
        }
    }

    cout << d[N] << '\n';

    return 0;
}