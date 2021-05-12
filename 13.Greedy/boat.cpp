#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 프로그래머스 구명보트

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());    // 내림차순 정렬

    // 확인
    // cout << "sort" << '\n';
    // for(int i=0; i<people.size(); i++) {
    //   cout << people[i] << ' ';
    // } cout << "\n";

    if(people.size() == 1) {  // 사람이 1명이면 보트도 1 필요
      answer = 1;
    }
    else {
      int check = limit - people[0];  // 한명(people[0])을 태우고 남은 무게를 check에 넣음

      for(int i=1; i<people.size(); i++) {
          if(check == 0) {  // 한명의 무게가 이미 limit면 더 태울 수 없어 answer++ 후 배열에서 삭제.
            answer++;
            people.erase(people.begin());
            // for문을 다시 앞에서부터 돌리기 위해 check값 갱신, i=0으로 초기화
            check = limit - people[0];
            i=0;
            continue;
          }
          if(check >= people[i]) {
              // 더 태울 수 있는 사람이면 answer++, 해당 사람 2명 삭제
              answer++;
              people.erase(people.begin()+i);
              people.erase(people.begin());
              // 삭제 후 사람이 한명 남았으면 더 볼 것도 없이 answer++, for문 탈출
              if(people.size() == 1) {
                answer++; break;
              }
              check = limit - people[0];
              i=0;
              continue;
          }
          if(i == people.size()-1) {
              // 끝까지 돌았음에도 태울 수 있는 사람이 없으면 answer++ 후 사람 1명 삭제.
              answer++;
              people.erase(people.begin());
              // 마찬가지로 남은 사람이 1명이면 answer++, for문 탈출
              if(people.size() == 1) {
                answer++; break;
              }
              check = limit - people[0];
              i=0;
          }
      }
    }

    return answer;
}

int main() {
  vector<int> v;
  v.push_back(70);
  v.push_back(50);
  v.push_back(80);
  // v.push_back(50);
  cout << solution(v, 100);

  return 0;
}
