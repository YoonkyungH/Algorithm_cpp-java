#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 로또의 최고 순위와 최저 순위

int result(int n) {
    if(n == 6) {
        return 1;
    } else if(n == 5) {
        return 2;
    } else if(n == 4) {
        return 3;
    } else if(n == 3) {
        return 4;
    } else if(n == 2) {
        return 5;
    } else { return 6; }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 오름차순 정렬
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int collect = 0;
    int ze = 0;
    for(int i=0; i<6; i++) {
        if(lottos[i] == 0) { ze++; }
        else { break; }
    }

    int temp = ze;
    for(int i=0; i<6; i++) {
        if(temp == 6) { break; }
        for(int j=temp; j<6; j++) {
            if(win_nums[i] == lottos[j]) { collect++; temp = ++j; break; }
        }
    }
    answer.push_back(result(collect+ze));
    answer.push_back(result(collect));

    // cout << answer[0] << ' ' << answer[1];
    return answer;
}

int main() {
  vector<int> lottos;
  vector<int> win_nums;

  lottos.push_back(44);
  lottos.push_back(1);
  lottos.push_back(0);
  lottos.push_back(0);
  lottos.push_back(31);
  lottos.push_back(25);

  win_nums.push_back(31);
  win_nums.push_back(10);
  win_nums.push_back(45);
  win_nums.push_back(1);
  win_nums.push_back(6);
  win_nums.push_back(19);

  solution(lottos, win_nums);

  return 0;
}
