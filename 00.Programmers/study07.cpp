// 캐시 (40)
// 통과 코드

// 원래 FIFO queue로 하려다가 find 함수를 못써서 deque 사용

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    deque<string> dq;

    // 캐시 사이즈가 0일 때
    if(cacheSize == 0) {    
        return cities.size() * 5;
    }

    for(int i=0; i<cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);    // transform 함수: 모두 대문자로 바꿔줌 (필요헤더: algorithm)
        auto it = find(dq.begin(), dq.end(), cities[i]);                                // find 함수로 캐시가 저장된 dq를 돌며 cities[i]가 있는지 검사

        if(it == dq.end()) {                // 없음
            if(dq.size() == cacheSize) {    // 캐시가 다 차있으면 앞에 하나 빼고
                dq.pop_front();           
            }
            answer += 5;
        } else {                            // 있음
            answer += 1;
            dq.erase(it);                   // 해당 위치 캐시 지워주고
        }
        
        dq.push_back(cities[i]);            // 맨 뒤에 캐시 채움
    }

    return answer;
}
