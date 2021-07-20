#include <iostream>
#include <vector>
using namespace std;

// 연산자 끼워넣기 (2)

int N;
vector<int> v;

int Plus, Minus, Multiple, Divide;
int MaxValue=-1000000000, MinValue=1000000000;

void BruteForce(int p, int mi, int mul, int d, int sum, int idx) {
  if(idx == N) {
    if(sum < MinValue) { MinValue = sum; }
    if(sum > MaxValue) { MaxValue = sum; }

    return;
  }

  if(p < Plus) BruteForce(p+1, mi, mul, d, sum+v[idx], idx+1);
  if(mi < Minus) BruteForce(p, mi+1, mul, d, sum-v[idx], idx+1);
  if(mul < Multiple) BruteForce(p, mi, mul+1, d, sum*v[idx], idx+1);
  if(d < Divide) BruteForce(p, mi, mul, d+1, sum/v[idx], idx+1);
}

int main() {
  ios::sync_with_stdio(0);

  cin >> N;

  int n;

  for(int i=0; i<N; i++) {
      cin >> n;
      v.push_back(n);
  }

  cin >> Plus >> Minus >> Multiple >> Divide;


  BruteForce(0, 0, 0, 0, v[0], 1);

  cout << MaxValue << '\n';
  cout << MinValue << '\n';

  return 0;
}
