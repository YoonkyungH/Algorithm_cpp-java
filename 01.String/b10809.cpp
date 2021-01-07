#include <iostream>
#include <string>
using namespace std;

int main() {
  int a[26];                // 출력할 배열
  char s[101] = {0, };      // 입력될 문자열(0으로 채우지 않으면 이상한 값이 출력)
  int j = 0;
  for(int q=0; q<26; q++) { // 알파벳이 포함되지 않은 부분은 -1로 채우기 위함
    a[q] = -1;
  }
  scanf("%s", s);
  for(int j='a'; j<='z'; j++) { // 알파벳을 기준으로
    for(int i=0; i<101; i++){   // 입력된 문자열을 돌면서
      if(s[i] == j){            // 알파벳이 가장 처음 등장한 위치를 저장
        a[j-97] = i;            // 'a'가 아스키코드 97이므로 97을 빼주면 a 배열에서의 해당 알파벳 위치를 알 수 있음
        break;                  // break는 가장 처음 등장한 위치를 저장해야 하므로 for문 빠져나오기 위함
      }
    }
  }
  for(int k=0; k<26; k++) {
    printf("%d ", a[k]);
  }
}
