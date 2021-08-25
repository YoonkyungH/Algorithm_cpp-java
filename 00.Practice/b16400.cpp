#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 소수 화폐

int N;                  // 물건의 값
vector<int> pNumber;    // N까지 수 중 소수만 저장

void primeNumber(int num) {
    int number[40001];

    for(int i=2; i<=num; i++) {
        number[i] = i;
    }
    
    for(int i=2; i<=num; i++) {
        if(number[i] == 0) { continue; }
        
        for(int j=i+i; j<=num; j+=i) {  // 자기 자신을 제외하고 삭제
            number[j] = 0;
        }
    }

    for(int i=2; i<=num; i++) {
        if(number[i] != 0) { pNumber.push_back(number[i]); }
    }
}

int main() {
    ios::sync_with_stdio(0);


    int sum = 0;
    int DP[40001] = {0, };

    cin >> N;

    primeNumber(N);

    DP[0] = 1;

    for(int i=0; i<pNumber.size(); i++) {
        for(int j=pNumber[i]; j<=N; j++) {
            DP[j] = (DP[j] + DP[j - pNumber[i]]) % 123456789;
            DP[j] %= 123456789;
        }
    }


    cout << DP[N] << '\n';

    return 0;
}