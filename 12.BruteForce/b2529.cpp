#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 부등호
// 순열조합

int pArr[10] = { 0, };
bool check[10] = { false, }; // 중복체크를 위한 배열 depth 하나씩 늘리며 배열에 하나씩 채우는 방법으로 재귀 수행

char arr[9];  //부등호 넣을 배열
int k;

string MAX = "-1";
string MIN = "9999999999";

bool CHECK(int idx) {
    if(arr[idx]=='<' && pArr[idx]>pArr[idx+1]) return false;
    if(arr[idx]=='>' && pArr[idx]<pArr[idx+1]) return false;
  return true;
}

void permutation(int depth){
    if(depth == k+1){ // 부등호 개수보다 숫자가 하나 더 많아야 하므로 K+1
      for(int i=0; i<depth-1; i++) {
        if(CHECK(i) == false) return;
      }

      string str;

      for(int i=0; i<depth; i++) {
        str += to_string(pArr[i]);
      }
      if(str > MAX) MAX = str;
      if(str < MIN) MIN = str;
      return;
    }

    for(int i = 0; i <= 9; i++){
        if(!check[i]){
            // 방문하지 않았다면 true로 바꾸고 그 수를 pArr에 넣음. 그리고 순열함수 재귀 후 false로 다시 바꿔놓음.
            check[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main() {
  // ios::sync_with_stdio(0);

  cin >> k;
  for(int i=0; i<k; i++) {
    scanf(" %c", &arr[i]);
  }

  permutation(0);

  cout << MAX << '\n';
  cout << MIN << '\n';

  return 0;
}
