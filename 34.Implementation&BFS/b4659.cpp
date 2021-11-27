// 비밀번호 발음하기

#include <iostream>
#include <string>

using namespace std;

void accept(string str) {
    cout << '<' << str << '>' << " is acceptable.\n";
}

void notAccept(string str) {
    cout << '<' << str << '>' << " is not acceptable.\n";
}

int main() {
    ios::sync_with_stdio(0);

    char arr[5] = {'a', 'e', 'i', 'o', 'u'};    // 하나이상 포함해야 하는 모음

    while(1) {
        string str = "";

        cin >> str;
        if(str == "end") { break; }

        // false일 때 조건 불충분
        bool flagMo = false;    // 모음 반드시 하나 포함
        bool flagThr = false;   // 모/자음 3개 연속 불가
        bool flagCont = false;  // 같은 글자 연속 비허용


        for(int i=0; i<5; i++) {
            if (str.find(arr[i]) != string::npos) {
                // 모음이 하나라도 있으므로 true
                flagMo = true; break; 
            }    
        }
        

        if(flagMo == false) { notAccept(str); continue; }   // 이미 조건 불충분(모음이 하나도 없음)이므로 다음 문자열로 넘어감 

        // 같은 글자가 연속되는지 검사
        char pre = str[0];  // 이전 문자
        bool flag = false;  // true면 while문 continue할 것
        for(int i=1; i<str.length(); i++) {
            if(str[i] == pre) {     // 이전 문자와 겹치면
                if(pre == 'e' || pre == 'o') {
                    continue;       // ee, oo는 예외로 허용
                } else {
                    notAccept(str); flag = true; break; // 예외가 아니라면 문자열을 출력하고 다음 문자열을 받을 것
                }
            }
            pre = str[i];               // 문자 연속되지 않는다면 이전 문자 갱신
        }

        if(flag == true) { continue; }  // while문을 continue 시킴

        string tmp = str;               // 기존 문자열 복사(자음모음이 3개 이상 반복되는지 체크하기 위함)
        for(int i=0; i<str.length(); i++) {
            // 문자열을 돌면서 복사해놓은 문자열 tmp에 모음이면 M, 자음이면 J로 대체
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
                tmp[i] = 'M';
            } else {
                tmp[i] = 'J';
            }
        }

        // 모음 또는 자음이 3번이상 연속으로 오는지 검사
        if(tmp.find("JJJ") != string::npos || tmp.find("MMM") != string::npos) {   // 3개 이상 연속되는 것이 있다면
            notAccept(str); continue;
        }

        accept(str);    // 아무데도 해당되지 않고 다 통과했다면

    }

    return 0;
}