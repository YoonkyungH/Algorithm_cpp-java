#include <iostream>
#include <string.h>
using namespace std;

// 다이얼

// 처음엔 if문으로 다 해결하려고 했는데 원하는 결과가 나오지 않음
// 처음에 한번 틀렸는데 그건 d배열에 숫자를 잘못 적어넣음^^;
int main() {
  char s[16];
  int d[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
  // d[0]=A - d[25]=Z 숫자와 알파벳 매치
  int sum = 0;

  scanf("%s", s);
  for(int i=0; i<strlen(s); i++) { // 입력한 문자열을 돌면서
    sum += d[s[i]-'A'];            // s[i]에 해당하는 알파벳에서 A를 빼면 해당 알파벳에 해당하는 수 d배열과 매치 가능
  }
  printf("%d", sum);
  return 0;
}
