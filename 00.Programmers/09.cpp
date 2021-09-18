// 신규 아이디 추천

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // transform

using namespace std;

/**
 * 3<= 아이디 길이 <=15
 * 소문자, 숫자, -, _, . 만 사용 가능
 * .는 처음과 끝에 사용 불가.
 * . 연속 사용 불가
 **/

string solution(string new_id) {
    // string answer = "";

    // 1단계 모두 소문자로 바꾸기 ok
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); // transform 함수: 모두 대문자로 바꿔줌 (필요헤더: algorithm)

    // 2단계
    string tmp = "";
    for(int i=0; i<new_id.length(); i++) {
        if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' || ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122)))
        { tmp += new_id[i]; }
        else {
            continue;
        }
    }

    // 3단계

    string tmp2 = "";
    bool flag = false;
    for(int i=0; i<tmp.length(); i++) {
        if(tmp[i] == '.' && flag == false) { flag = true; tmp2 += tmp[i]; }
        else if(tmp[i] == '.' && flag == true) { continue; }
        else { flag = false; tmp2 += tmp[i]; }
    }

    tmp = tmp2;


    // 4단계 처음과 끝 마침표 지우기
    if(tmp[0] == '.') { tmp.erase(0, 1); }
    else if(tmp[tmp.length()-1] == '.') { tmp.erase(tmp.length()); }


    // 5단계 빈 문자열이라면 a 대입
    if(tmp.empty()) { tmp = 'a'; }    

    // 6단계 16자 이상이라면 15개 이후 문자 지우기
    if(tmp.length() > 15) {
        tmp.erase(15);
    }
    if(tmp[tmp.length()-1] == '.') { tmp.erase(tmp.length()-1); }

    // 7단계 길이 2 이하 3까지 늘리기
    if(tmp.length() <= 2) {
        char c = tmp[tmp.length()-1];
        while(tmp.length() < 3) {
            tmp += c;
        }
    }

    return tmp;
}