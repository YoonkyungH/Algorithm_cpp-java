// 통계학
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> v;

int arithmeticMean() {  // 산술평균: N개의 수들의 합을 N으로 나눈 값
    double sum = 0;
    for(int i=0; i<N; i++) {
        sum += v[i];
    }

    return round(sum / N);   
}

int median() {    // 중앙값: N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
    int mid = N/2;

    return v[mid];
}

int mode() {    // 최빈값: N개의 수들 중 가장 많이 나타나는 값
    int cnt = 0;
    int ans = 0;
    int tmp = v[0];
    int result = v[0];
    bool flag = false;

    for(int i=0; i<N; i++) {
        if(tmp == v[i]) cnt++;
        else {
            if(ans < cnt) {
                // 갱신
                ans = cnt; 
                result = v[i-1]; 
                flag = false;
            } else if(ans == cnt && !flag) {
                result = v[i-1];
                flag = true;
            }
            cnt = 1;    // 카운트와 값 초기화
            tmp = v[i];
        }
    }

    if(ans < cnt) {
        result = v[N-1];
    } else if(ans == cnt && !flag) {
        result = v[N-1];
    }

    return result;
} 

int range() {
    return v[N-1] - v[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cout << arithmeticMean() << '\n';
    cout << median() << '\n';
    cout << mode() << '\n';
    cout << range() << '\n';

    return 0;
}