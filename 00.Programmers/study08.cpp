// 실패율
// 통과

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,double>& a, const pair<int,double>& b) {    // 내림차순
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > rate;

    int tmp = stages.size();                            // 도전한 사람의 수
    for(int i=1; i<=N; i++) {
        int n = count(stages.begin(), stages.end(), i); // 그 레벨에 몇명?
        
        if(n == 0) { rate.push_back(make_pair(i, 0)); } // 와 대박 컴퓨터가 가끔 0으로 나눌 때 0을 안 뱉음
        else {
            double d = (double)n / tmp;                 // 실패율 공식

            rate.push_back(make_pair(i, d));            // 레벨, 실패율
        }
        

        tmp -= n;   // 그 인원수를 제외해줘야 하므로
    }

    sort(rate.begin(), rate.end(), cmp);    // 내림차순 정렬

    for(int i=0; i<rate.size(); i++) {
        answer.push_back(rate[i].first);
    }

    return answer;
}
