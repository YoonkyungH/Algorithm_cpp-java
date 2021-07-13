#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자놀이

string str = "";

string Num(int n) {
  switch(n) {
    case 1:
      str = "one";
      break;
    case 2:
      str = "two";
      break;
    case 3:
      str = "three";
      break;
    case 4:
      str = "four";
      break;
    case 5:
      str = "five";
      break;
    case 6:
      str = "six";
      break;
    case 7:
      str = "seven";
      break;
    case 8:
      str = "eight";
      break;
    case 9:
      str = "nine";
      break;
    case 0:
      str = "zero";
      break;
  }

  return str;

}

int main() {
  ios::sync_with_stdio(0);

  int M, N;
  cin >> M >> N;

  // int arr[10] = {8, 5, 4, 9, 1, 7, 6, 3, 2, 0};
  vector<pair<string, int>> v;

  for(int i=M; i<=N; i++) {
    string str = "";
    if(i < 10) {
      str = Num(i);
      v.push_back({str, i});
    }
    else {
      str = Num(i/10) + " " + Num(i%10);
      v.push_back({str, i});
    }
  }

  sort(v.begin(), v.end());         // str을 기준으로 정렬

  int cnt = 1;
  for(int i=0; i<v.size(); i++) {
    if(cnt == 11) {                // 한 줄에 10개씩 출력
      cout << '\n'; cnt = 1;
    }
    cout << v[i].second << " ";
    cnt++;
  }

  return 0;
}
