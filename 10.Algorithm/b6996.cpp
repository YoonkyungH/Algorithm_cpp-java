#include <iostream>
#include <string>
using namespace std;

// 애너그램

int main() {
  int T;
  string s, s2;
  bool flag = false;

  // 알파벳의 각 개수 0으로 설정, [0]은 사용 X
  int alphabet[27] = {0, };
  cin >> T;

  for(int q=0; q<T; q++) {
    // 배열 초기화 시켜야됨
    for(int a=0; a<27; a++) {
      alphabet[a] = 0;
    }
    // flag 초기화
    flag = false;

    cin >> s >> s2;

    if(s.length() != s2.length()) { // 우선 두 문자열의 길이가 다르면 애너그램 X
      cout << s << " & " << s2 << " are NOT anagrams." << '\n';
    }
    else {                          // 두 문자열의 길이가 같다면
      for(int i=0; i<s.length(); i++) {
        // 문자를 하나씩 돌면서 (아스키코드 'a'가 97) 해당 알파벳 배열 원소 증가
        alphabet[s.at(i)-96]++;
      }

      for(int j=0; j<s2.length(); j++) {
        if(alphabet[s2.at(j)-96] <= 0) {        // 배열에서 뺄 원소가 없다면 애너그램 실패
          cout << s << " & " << s2 << " are NOT anagrams." << '\n';
          flag = false;
          break;
        } else if(alphabet[s2.at(j)-96] > 0) {  // 해당 알파벳 자리의 원소 감소
          alphabet[s2.at(j)-96]--;
        }
        flag = true;
      }
      if(flag == true) cout << s << " & " << s2 << " are anagrams." << '\n';
    }

  }

  return 0;
}
