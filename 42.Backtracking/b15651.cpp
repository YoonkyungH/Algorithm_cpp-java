// N과 M(3)
#include <iostream>
using namespace std;

int N, M;
int arr[7];

void backtracking(int idx) {
    if(idx == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        } cout << '\n';

        return;
    }

    for(int i=1; i<=N; i++) {
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