#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// 그룹 단어 체커

int main() {
  ios::sync_with_stdio(0);
  int n;
  int k;
  int sum = 0;
  string str;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int a[26] = {0, };
    bool isGroup = true;

    cin >> str;

    a[str[0]-'a']++;

    for(k = 1; k<str.size(); k++) {
         if (str[k] != str[k-1] && a[str[k]-'a'] >= 1){
           isGroup = false;
           break;
         }
         else a[str[k]-'a']++;
     }
     if (isGroup == true) {
         sum++;
     }
  }

  cout << sum;
  return 0;
}
