// 연산자 끼워넣기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX = 1000000001
#define MIN = -1000000001

int N;
int add, sub, mul, Div;
vector<int> v;
int minSum = 1000000001, maxSum = -1000000001;

// flag 1: add, 2: sub, 3: mul, 4:div
void calculator(int idx, int sum) {

    if(idx == N) {

        maxSum = max(maxSum, sum);
        minSum = min(minSum, sum); 

    } else {
        if(add > 0) {
            add--;
            calculator(idx + 1, sum + v[idx]);
            add++;
        }
        if(sub > 0) {
            sub--;
            calculator(idx + 1, sum - v[idx]);
            sub++;
        }
        if(mul > 0) {
            mul--;
            calculator(idx + 1, sum * v[idx]);
            mul++;
        }
        if(Div > 0) {
            Div--;
            calculator(idx + 1, sum / v[idx]);
            Div++;
        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    cin >> add >> sub >> mul >> Div;

    calculator(1, v[0]);

    cout << maxSum << '\n' << minSum << '\n';

    return 0;
}