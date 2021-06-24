#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

// 3진법 뒤집기

int solution(int n) {
    int answer = 0;
    vector<int> v;

    while(n != 0) {
        v.push_back(n%3);
        n /= 3;
    }

    // for(int i=0; i<v.size(); i++) {
    //     cout << v[i] << ' ';
    // }

    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        answer += v[i] * pow(3, i);
    }

    return answer;
}
