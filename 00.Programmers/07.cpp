// 숫자 문자열과 영단어 

#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    string tmp = "";

    for(int i=0; i<s.length(); i++) {
        
        if(97<=s[i] && s[i]<=122) { // 문자라면
            if(s[i] == 'z') { ans += '0'; i += 3; }
            else if(s[i] == 'o') { ans += '1'; i += 2; }
            else if(s[i] == 't') {
                if(s[i+1] == 'w') { ans += '2'; i += 2;}
                else if(s[i+1] == 'h') { ans += '3'; i+= 4; }
            }
            else if(s[i] == 'f') {
                if(s[i+1] == 'o') { ans += '4'; i += 3; }
                else if(s[i+1] == 'i') { ans += '5'; i += 3; }
            }
            else if(s[i] == 's') {
                if(s[i+1] == 'i') { ans += '6'; i += 2; }
                else if(s[i+1] == 'e') { ans += '7'; i += 4;}
            }
            else if(s[i] == 'e') { ans += '8'; i += 4; }
            else if(s[i] == 'n') { ans += '9'; i += 3;}

        } else {
            ans += s[i];
        }
    }

    answer = stoi(ans);

    return answer;
}