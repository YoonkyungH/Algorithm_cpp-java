// 단어 뒤집기 2

#include <iostream>
#include <string>
#include <algorithm>    // reverse 함수

using namespace std;

char arr[100000];

int main() {
    // ios::sync_with_stdio(0);

    string str = "";
    string ans = "";
    getline(cin, str);

    string tmp = "";
    bool start = false;

    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' ') {
            
            reverse(tmp.begin(), tmp.end());
            ans += tmp;
            tmp = "";
            if(start == true) { ans += ' '; }

            start = true;
        }
        else if(str[i] == '<') {
            if(!tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                tmp = "";
            }              
            // start = true;

            while(str[i] != '>') {
                ans += str[i];
                i++;
            }
            ans += '>';
        } 
        else {
            tmp += str[i];
            
            start = true;
        }
    }
    // if(start == true) { ans += ' '; }

    reverse(tmp.begin(), tmp.end());
    ans += tmp;

    cout << ans << '\n';

    return 0;
}