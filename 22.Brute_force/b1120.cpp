#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 문자열

int main() {

  string A, B;

  cin >> A >> B;

  int min_value = 51;

  for(int i=0; i<B.length()-A.length()+1; i++) {
    int k = i;
    int cnt = 0;

    for(int j=0; j<A.length(); j++) {
      if(A[j]!=B[k]) { cnt++; k++; }
      else { k++; continue; }
    }

    min_value = min(min_value, cnt);
  }

  cout << min_value << '\n';

  return 0;
}
