// 오픈채팅방

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> // map보다 빠른 탐색, 중복 데이터 허용 x
using namespace std;

unordered_map<string, string> user;    // uid, name

vector<pair<int, string> > state;         // 상태, uid
// 1: enter 2: leave

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        
        if(record[i][0]=='E') { 
            int j=9;
            string tmpId = "";
            string tmpName = "";

            while(record[i][j]!=' ') {
                tmpId += record[i][j++];
            }
            j++;
            while(record[i][j]!='\0') {
                tmpName += record[i][j++];
            } 
            
            // cout << "ENTER: " << tmpId << ' ' << tmpName << '\n';

            user[tmpId] = tmpName;
            state.push_back(make_pair(1, tmpId));
        }

        else if(record[i][0] == 'L') {
            int j=9;
            string tmpId = "";

            while(record[i][j]!='\0') {
                tmpId += record[i][j++];
            }
            
            // cout << "LEAVE: " << tmpId << '\n';

            state.push_back(make_pair(2, tmpId));
        }

        else if(record[i][0] == 'C') {
            int j=10;
            string tmpId = "";
            string tmpChangeName = "";

            while(record[i][j]!=' ') {
                tmpId += record[i][j++];
            } j++;
            while(record[i][j]!='\0') {
                tmpChangeName += record[i][j++];
            }
            // cout << "CHANGE: " << tmpId << ' ' << tmpChangeName << '\n';

            // state.push_back(make_pair(3, tmpId));

            // 바뀌기 전 닉네임은 몰라도 되니까 그냥 바로 바꿔버리기
            user[tmpId] = tmpChangeName;    
        }

    }

    for(int i=0; i<state.size(); i++) {
        if(state[i].first == 1) {
            answer.push_back(user[state[i].second] + "님이 들어왔습니다.");
        } else if(state[i].first == 2) {
            answer.push_back(user[state[i].second] + "님이 나갔습니다.");
        }
    }


    return answer;
}




