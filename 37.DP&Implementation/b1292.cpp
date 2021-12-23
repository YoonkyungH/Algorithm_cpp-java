// 쉽게 푸는 문제
// 구현

#include <iostream>

using namespace std;

int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    int k=1;
    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=i; j++) {
            arr[k] = i;

            if(k > 1000) { break; }
            
            k++;
        }
    }

    int sum = 0;
    for(int i=A; i<=B; i++) {
        sum += arr[i];
    }

    cout << sum << '\n';

    return 0;
}