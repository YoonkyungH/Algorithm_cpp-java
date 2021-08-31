#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 메뉴 리뉴얼
// 주어진 메뉴 개수만큼 가장 많이 선택된 메뉴 조합을 고름
// 사전순으로 정렬해 반환

map<string, int> m;

// vector가 pair이므로 second를 기준으로 정렬되도록 함수 구현
bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

// 주문(order) 중 찾는 길이(size)만큼 조합(s) 찾기
void findAllCourse(string order, int size, string s, int idx) {
    // 종료조건
    // 지금 만들어진 코스가 찾는 코스 길이와 같으면
    if(s.length() == size) { 
        map<string, int>::iterator iter;
        
        iter = m.find(s);   // map m에서 s 조합 찾기
        
        // 맵에 s(찾는 코스 조합)가 이미 존재하는 경우 = 반복자가 "맨 끝+1 쓸데없는 값"을 가리키지 않으면
        // 개수((m에서)해당 코스의 second)++
        if(iter != m.end()) { iter->second++; }
        // 존재하지 않으면 map m에 새로 넣어줌
        else { m.insert(pair<string, int>(s, 1)); }
        
        return;
    }
    
    // findAllCourse를 반복하며 모든 코스 조합을 찾아 map에 저장
    for(int i=idx; i<order.length(); i++) {
        findAllCourse(order, size, s+order[i], i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 코스 크기만큼 모든 조합을 찾을 것이므로
    for(int i=0; i<course.size(); i++) {
        m.clear();  // map m 초기화
        
        for(int j=0; j<orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());   // 주문 정렬

            // 주문한 조합에서 코스 개수만큼 골라 모든 조합 만들어 맵에 저장(개수 추가)
            if(course[i] <= orders[j].length()) {  
                findAllCourse(orders[j], course[i], "", 0);
            }
        }
        
        // map을 vector v 에 옮기기 (정렬하기 위함)
        vector<pair<string, int>> v(m.begin(), m.end());
        
        // 만들어진 조합 개수로 내림차순 정렬
        sort(v.begin(), v.end(), compare);
        
        if(!v.empty()) {    // 아무 조합이 없는 것이 아니라면
            int max = v[0].second;
            
            // 최소 두명 이상 주문된 코스 조합인가 검사
            if(max >= 2) {
                for(int i=0; i<v.size(); i++) {
                    if(v[i].second == max) {
                        // 여러개 있으면 여러개 반환하라고 했으므로 answer에 추가해줌
                        answer.push_back(v[i].first);
                    }
                    else { break; }
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}