#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int cnt = 0;
  cin >> str;
  // scanf("%s", str);
  for(int i=0; i<str.length(); i++) {
    if(str[i] == 'c' && (str[i+1] == '=' || str[i+1] == '-')) {          // c 뒤에 = 또는 - 문자가 오면 하나의 문자로 봐야하기 때문에 i를 증가시켜
      i++;
    } else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') {
      i += 2;
    } else if(str[i] == 'd' && str[i+1] == '-') {
      i++;
    } else if((str[i] == 'l' || str[i] == 'n') && str[i+1] == 'j') {
      i++;
    } else if((str[i] == 's' || str[i] == 'z') && str[i+1] == '=') {
      i++;
    }

    cnt++;                                                               // 다음 문자로 넘어가기 전 count 증가
  }
  cout << cnt;
  // printf("%d", cnt);
  return 0;
}
