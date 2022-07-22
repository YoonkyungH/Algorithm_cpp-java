// N과 M(2)
#include <iostream>
using namespace std;

int N, M;
int arr[8];

void backtracking(int idx) {
    if(idx == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        } cout << '\n';
        return;
    }

    int start = 1;
    if(idx != 0) {
        start = arr[idx-1] + 1;
    }
    for(int i=start; i<=N; i++) {
        arr[idx] = i;
        backtracking(idx+1);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backtracking(0);

    return 0;
}