// 수 찾기
// 이분탐색

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);   // 오름차순 정렬

    cin >> M;
    for(int j=0; j<M; j++) {
        long long n;
        cin >> n;
        
        bool flag = false; 
        long long left=0, right=N-1;
        while(left <= right) {
            long long mid = (left+right) / 2;
            if(arr[mid] == n) { flag = true; cout << "1\n"; break; }    // 값 비교시 arr[mid] 대신 mid를 넣지 않기

            if(arr[mid] < n) { left = mid + 1; }
            else { right = mid - 1; }
        }
        if(flag == false) { cout << "0\n"; }
    }


    return 0;
}