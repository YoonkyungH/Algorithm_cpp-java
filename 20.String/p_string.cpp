#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 압축

int solution(string s) {
    int answer = s.size();

    for(int i=1; i<=s.size()/2; i++) {
        string convert, tmp;

        int cnt = 1;
        tmp = s.substr(0, i);   // substr: 0부터 i까지 문자열을 리턴

        for(int j=i; j<s.size(); j+=i) {
            if(tmp == s.substr(j, i)) { cnt++; }
            else {
                if(cnt > 1) { convert += to_string(cnt); }
                convert += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }

        if(cnt > 1) { convert += to_string(cnt); }

        convert += tmp;
        answer = min(answer, (int)convert.size());
    }


    return answer;
}
