// 로마 숫자
// 로미숫자로 바꾸는 인터넷 코드 참고함

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1 = "";
string s2 = "";
int s1Num = 0;
int s2Num = 0;

/**
 * IV = 4, IX = 9
 * XL = 40, XC = 90
 * CD = 400, CM = 900
 **/
vector<pair<string, int> > vStr;
void trans() {

    vStr.push_back(make_pair("IV", 4));
    vStr.push_back(make_pair("IX", 9));
    vStr.push_back(make_pair("XL", 40));
    vStr.push_back(make_pair("XC", 90));
    vStr.push_back(make_pair("CD", 400));
    vStr.push_back(make_pair("CM", 900));

    // vector를 반복문으로 한 번 돌기 때문에 중복 사용불가 조건에 만족함
    // s1
    for(int i=0; i<6; i++) {
        if (s1.find(vStr[i].first) != string::npos) {
            s1Num += vStr[i].second;

            int idx = s1.find(vStr[i].first);  // 인덱스 반환
            s1.erase(idx, 2);  // 삭제
        }
    }

    // s2
    for(int i=0; i<6; i++) {
        if (s2.find(vStr[i].first) != string::npos) {
            s2Num += vStr[i].second;

            int idx = s2.find(vStr[i].first);  // 인덱스 반환
            s2.erase(idx, 2);  // 삭제
        }
    }

}

/*
가져온 코드 (숫자 -> 로마)
*/
string NumToRom(int num) {
    string tmp;
    switch (num)
    {
    case 0: return "";
    case 1: return "I";
    case 5: return "V";
    case 10: return "X";
    case 50: return "L";
    case 100: return "C";
    case 500: return "D";
    case 1000: return "M";
    
    case 4: return "IV";
    case 9: return "IX";
    case 40: return "XL";
    case 90: return "XC";
    case 400: return "CD";
    case 900: return "CM";

    default:
        if(num / 10 == 0) { // num 한자리수
            if(num > 5) { num -= 5; tmp += NumToRom(5); }
            if(num % 3 == 1) { tmp += "I"; }
            if(num % 3 == 2) { tmp += "II"; }
            if(num % 3 == 0) { tmp += "III"; }
        } else if(num / 100 == 0) { // num 두자리수
            if(num > 50) { num -= 50; tmp += NumToRom(50); }
            if((num/10) % 3 == 1) tmp+= "X";
            if((num/10) % 3 == 2) tmp+= "XX";
            if((num/10) % 3 == 0) tmp+= "XXX";
        } else if(num/1000 == 0) { // num 세자리수
            if(num>500){ num -= 500; tmp += NumToRom(500); }
            if((num/100)%3==1) tmp+= "C";
            if((num/100)%3==2) tmp+= "CC";
            if((num/100)%3==0) tmp+= "CCC";
        } else if(num/10000 == 0) { // num 네자리수
            for(int i=1; i<=(num/1000); i++)
                tmp+="M";
        }

    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);

    int ans = 0;
    string ansString = "";

    cin >> s1;
    cin >> s2;

    trans();

    
    if(!s1.empty()) {
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] == 'I') { s1Num += 1; }
            else if(s1[i] == 'V') { s1Num += 5; }
            else if(s1[i] == 'X') { s1Num += 10; }
            else if(s1[i] == 'L') { s1Num += 50; }
            else if(s1[i] == 'C') { s1Num += 100; }
            else if(s1[i] == 'D') { s1Num += 500; }
            else if(s1[i] == 'M') { s1Num += 1000; }
        }
    }

    if(!s2.empty()) {
        for(int i=0; i<s2.length(); i++) {
            if(s2[i] == 'I') { s2Num += 1; }
            else if(s2[i] == 'V') { s2Num += 5; }
            else if(s2[i] == 'X') { s2Num += 10; }
            else if(s2[i] == 'L') { s2Num += 50; }
            else if(s2[i] == 'C') { s2Num += 100; }
            else if(s2[i] == 'D') { s2Num += 500; }
            else if(s2[i] == 'M') { s2Num += 1000; }
        }
    }

    ans = s1Num + s2Num;
    int tmp = ans;  // 숫자를 문자열로 바꾸기 위해 tmp에 담아둠


    string result = "";
    int ten = 10;
    while(tmp != 0) {
        result.insert(0, NumToRom(tmp % ten));
        tmp -= tmp % ten;
        ten *= 10;
    }

    cout << ans << '\n' << result << '\n';

    return 0;
}