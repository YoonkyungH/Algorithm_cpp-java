// 오픈 채팅방

#include <string>
#include <vector>
#include <sstream>  // stringstream
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<string> uid; // uid만 따로 저장
    map<string, string> m;  // id, name

    stringstream ss;    // : 주어진 문자열에서 필요한 정보를 빼냄

    string action;
    string id, nickname;

    for(int i=0; i<record.size(); i++) {
        ss.str(record[i]);
        
        ss >> action;   // Enter, Leave, Change 중 하나가 담기게 됨

        if(action == "Enter") {
            ss >> id;
            ss >> nickname;

            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);  // id만 따로 저장

            m[id] = nickname;   // key-value 저장
        }
        else if(action == "Leave") {
            ss >> id;

            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }
        else if(action == "Change") {
            ss >> id;
            ss >> nickname;

            m[id] = nickname; // 닉네임 교체
        }

        ss.clear(); // 저장된 문자열을 clear 하진 않음. 다만 새로운 문자열을 받았을 때 첫 위치부터 추출 가능하게 함.
    }

    for(int i=0; i<answer.size(); i++) {
        answer[i] = m[uid[i]] + answer[i];  // 반환해야 할 벡터를 완성시켜 줌(최종적인 닉네임 붙여주기 + 행위)
    }

    return answer;
}