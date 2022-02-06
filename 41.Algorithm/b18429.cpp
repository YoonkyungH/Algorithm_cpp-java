// 근손실
// 백트래킹: 해가 될 것 같지 않으면 더 이상 진행하지 않는 것

#include <iostream>

using namespace std;

int N, K;
int arr[8];
bool check[8];
int kg, ans;


void weight(int kg, int day) {
    if(day == N-1) {
        if(kg >= 500) {
            ans++;
        }
        return;
    }

    for(int i=0; i<N; i++) {
        if(check[i]==false && kg-K+arr[i]>=500) {
            check[i] = true;
            weight(kg-K+arr[i], day+1);
            check[i] = false;
        }
    }
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    // cout << weight(0, 500, 1) << '\n';
    weight(500, 0);
    cout << ans << '\n';

    return 0;
}