#include <iostream>
#include <string>
#include <vector>
using namespace std;

// IOIOI
// KMP 알고리즘

string ioi(int n) { // 찾을 문자열을 만드는 함수
  string ioi = "IOI";
  string oi = "OI";

  for(int i=0; i<n-1; i++) {
      ioi += oi;
  }

  return ioi;
}

vector<int> makeTable(string pattern) { // 접두사와 접미사의 최대 일치 길이를 구하는 함수
  // for문을 돌며 j==i일 때 i인덱스에 (j인덱스)+1을 넣어 테이블을 만듦
  // j!=i일 때 j의 위치를 뒤로 한칸
  int patternSize = pattern.size();
  vector<int> table(patternSize, 0);
  int j = 0;

  for(int i=1; i<patternSize; i++) {
    while(j>0 && pattern[i]!=pattern[j]) {
      j = table[j-1];
    }
    if(pattern[i] == pattern[j]) {
      table[i] = ++j;
    }
  }

  return table;
}

void KMP(string parent, string pattern) {
  int cnt = 0;

  vector<int> table = makeTable(pattern);
  int parentSize = parent.size();
  int patternSize = pattern.size();
  int j = 0;
  for(int i=0; i<parentSize; i++) {
    while(j>0 && parent[i]!=pattern[j]) {
      j = table[j-1];
    }
    if(parent[i] == pattern[j]) {
      if(j == patternSize-1) {
        cnt++;
        j = table[j];
      } else {
        j++;
      }
    }
  }
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  string s2;

  int cnt = 0;
  int N, M;

  cin >> N >> M;
  cin >> s; // 주어진 문자열


  string str = ioi(N);  // 찾아야 할 문자열

  KMP(s, str);

  return 0;
}
