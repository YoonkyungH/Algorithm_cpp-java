#include <iostream>
#include <string.h>     // strlen 함수를 위함
using namespace std;

int main() {
  int n = 0;            // 테스트 케이스 개수
  char s[81];           // OX 문자열

  scanf("%d\n", &n);
  for(int i=0; i<n; i++) {
    int sum = 0, count = 1;               // 점수 합산, 점수 계산 변수 초기화
    scanf("%s", s);
    for(int j=0; j<strlen(s)+1; j++) {    // char 배열이기 때문에 \0 문자까지 세어주기 위함(+1)
      if(s[j]=='O') {
        sum += count++;                   // 총점에 count를 더하고 다음 O를 위해 count를 증가시킴
      } else if(s[j]=='X') {
          count = 1;                      // 'X'일 경우 count를 1로 리셋
      } else printf("%d\n", sum);
    }
  }
  return 0;
}
