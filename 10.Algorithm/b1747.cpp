#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// 소수&팰린드롬

bool prime_number(int n) {  // 소수 판별
  // 2부터 그 수의 제곱근까지의 수로 나뉘는지 확인하면 소수인지 아닌지 판별 가능
  if (n < 2)
    return false;
    
  int n_sqrt = (int)sqrt(n);

  for(int i=2; i<=n_sqrt; i++) {
    if(n%i == 0) return false;
  }

  return true;
}

bool palindrome(int n) {
  vector<int> v;  // 뒤집어진 벡터(뒷자리 수부터 들어가기 때문)
  vector<int> v2;

  while(n != 0) { // 숫자열 하나씩 분리, 뒷자리 수부터 들어감
    v.push_back(n%10);
    v2.push_back(n%10);
    n /= 10;
  }

  reverse(v2.begin(), v2.end());  // v2벡터 뒤집기

  for(int i=0; i<v.size(); i++) {
    if(v[i] != v2[i]) {
      return false; break;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  int N;
  cin >> N;

  int i=N;
  while(1) {
    // n부터 무한루프를 돌면서 함수 2개로 소수, 팰린드롬 여부를 판별
    if(prime_number(i) && palindrome(i)) {
      cout << i << '\n';
      break;
    }
    i++;
  }

  return 0;
}
