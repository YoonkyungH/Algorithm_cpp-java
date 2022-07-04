// 순열장난

/**
 * 순열은 1~N까지의 수로 이루어져 있음
 * 
 * 문자열의 길이가 13이라면 1~9까지인 13-9를 빼면 4가 남고 10, 11 이렇게 네 자리를 차지하므로
 * 이의 N은 11이 된다.
 */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string str;
int strSize;
bool ch[51] = {false, };

bool isValid(int x) {   // 유효하는 숫자인지
    return 1<=x && x<=strSize;
}

void backtracking(int idx, string s) {
    if(idx == str.size()) {
        cout << s << '\n';
        // return; 
        // exit(0) 대신 return;를 사용하면 렁타임 에러(out of range) 발생
        exit(0);
    }

    s += ' ';
    string tmp = "";

    for(int i=idx; i<str.size(); i++) {
        tmp += str[i];
        
        if(!isValid(stoi(tmp))){
            return;
        }
        if(!ch[stoi(tmp)] ) {   // 아직 체크하지 않은 자리라면
            ch[stoi(tmp)] = true;

            backtracking(i+1, s+tmp);

            ch[stoi(tmp)] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    if(str.size() <= 9) strSize = str.size();
    else {
        strSize = 9 + ( (str.size()-9) / 2);
    }

    string tmp = "";
    for(int i=0; i<str.size(); i++) {
        tmp += str[i];

        if( isValid(stoi(tmp)) && !ch[stoi(tmp)] ) {
            ch[stoi(tmp)] = true;

            backtracking(i+1, tmp);

            ch[stoi(tmp)] = false;
        }
    }

    return 0;
}
