#include <string>
#include <vector>

using namespace std;

// 괄호 변환

// 올바른 문자열
bool correct(string s) {
    int flag = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') { flag++; }
        else { flag--; } 
        
        if(flag < 0) { return false; }  // )) 가 먼저 쌓여버린 상황이라 올바른 문자열이 될 수 없음.        
    }
    return true;
}

string solution(string p) {
    string answer = "";
    string u="", v="";
    
    if(p.length() == 0) { return answer; }  // 입력이 빈 문자열인 경우 그대로 반환
    
    int left=0, right=0;
    for(int i=0; i<p.length(); i++){
        if(p[i] == '(') { left++; }
        else { right++; }
        
        if(left == right) { // 균형잡힌 문자열
            u = p.substr(0, i+1);   // 균형잡힌 문자열(u)과
            v = p.substr(i+1);      // 그 나머지(v)로 자름
            break;
        }
    }
    
    // u가 올바른 문자열이다? -> u와 v에 대해서 다시 solution 반복한 뒤 반환
    if(correct(u)) { return u + solution(v); }
    else {
        // 4-1~3. 빈 문자열에 ( + 단계부터 수행한 문자열 + )
        string tmp = "(" + solution(v) + ")";

        // 4-4. 첫, 마지막 문자 제거 = for 범위
        // ( -> )로, ) -> (로 변환해 tmp에 저장
        for(int i=1; i<u.length()-1; i++) {
            if(u[i] == '(') { tmp += ')'; }
            else { tmp += '('; }
        }
        return tmp;
    }
}