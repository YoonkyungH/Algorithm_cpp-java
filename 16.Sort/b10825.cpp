#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 국영수

struct Student {
  string name;
  int korean;
  int english;
  int math;
};

bool cmp(Student a, Student b) {
  // 비교하는 순서 중요
  if(a.korean==b.korean && a.english==b.english && a.math==b.math) {
    return a.name < b.name;
  }
  else if(a.korean==b.korean && a.english==b.english) {
    return a.math > b.math;
  }
  else if(a.korean==b.korean) {
    return a.english < b.english;
  }
  // if(a.korean==b.korean && a.english==b.english) {
  //   return a.math > b.math;
  // }
  // if(a.korean==b.korean && a.english==b.english && a.math==b.math) {
  //   return a.name < b.name;
  // }
  return a.korean > b.korean;
}

int main() {
  ios::sync_with_stdio(0);

  int N;
  cin >> N;
  vector<Student> s(N); // 이렇게 벡터의 크기를 지정해주지 않으니까 입력을 한 줄밖에 못 받음

  for(int i=0; i<N; i++) {
    cin >> s[i].name >> s[i].korean >> s[i].english >> s[i].math;
  }
  sort(s.begin(), s.end(), cmp);

  for(int i=0; i<N; i++) {
    cout << s[i].name << '\n';
  }

  return 0;
}
