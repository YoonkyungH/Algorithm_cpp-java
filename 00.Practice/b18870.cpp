#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0);

  int N;
  cin >> N;


  vector<pair<int, int>> v;

  int n;
  for(int i=1; i<=N; i++) {
      cin >> n;
      v.push_back({n, i});
  }

  sort(v.begin(), v.end());

  int j=0, tmp=v[0].first;
  v[0].first = 0;

  for(int i=1; i<N; i++) {
    if(v[i].first != tmp) { tmp = v[i].first; v[i].first = ++j; }
    else if(v[i].first == tmp) { v[i].first = j; }
  }

  sort(v.begin(), v.end(), cmp);

  for(int i=0; i<N; i++) {
    cout << v[i].first << ' ';
  }

  return 0;
}
