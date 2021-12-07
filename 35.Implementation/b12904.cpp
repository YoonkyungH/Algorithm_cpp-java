// A와 B
// 역으로 T에서 S 만들기

#include <iostream>
#include <string>
#include <algorithm>    // reverse

using namespace std;

string S, T;

void del(string str) {  // 마지막 문자 자르기
    T = T.substr(0, str.length()-1);
}

int main() {
    ios::sync_with_stdio(0);

    cin >> S;
    cin >> T;

    int i=1;
    while(1) {
        if(T == S) { cout << "1\n"; break; }
        if(T.empty()) { cout << "0\n"; break; }

        if(T[T.length()-1] == 'A') {        // 마지막 문자가 A라면
            del(T);
        } else if(T[T.length()-1] == 'B') { // 마지막 문자가 B라면
            del(T);
            reverse(T.begin(), T.end());
        }

    }

    return 0;
}