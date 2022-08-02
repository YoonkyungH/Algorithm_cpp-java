// 서로 다른 부분 문자열 개수
#include <iostream>
#include <string>
#include <set>
using namespace std;

string str;
set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for(int i=0; i<str.size(); i++) {
        string tmp = "";
        for(int j=i; j<str.size(); j++) {
            tmp += str[j];
            s.insert(tmp);
        }
    }

    cout << s.size() << '\n';

    return 0;
}