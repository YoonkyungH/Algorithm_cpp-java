// 소수의 연속합

#include <iostream>
#include <cmath> // sqrt()
#include <vector>

using namespace std;

vector<int> primeNum;
int primeArr[4000001];
int N, cnt;

void primeNumber(int n) {
    for(int i=2; i<=n; i++) { primeArr[i] = i; }

    for(int i=2; i<=sqrt(n); i++) {
        if(primeArr[i] == 0) { continue; }
        for(int j=i*i; j<=n; j+=i) {
            primeArr[j] = 0;
        }
    }

    for(int i=2; i<=n; i++) {
        if(primeArr[i] != 0) {
            primeNum.push_back(primeArr[i]);
        }
    }   // 소수만 들어있는 벡터 생성
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    primeNumber(N);

    int l=0, r=0, cnt=0, sum=0;
    while(1) {
        if(sum >= N) { sum -= primeNum[l++]; }
        else if(r == primeNum.size()) { break; }
        else { sum += primeNum[r++]; }

        if(sum == N) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}