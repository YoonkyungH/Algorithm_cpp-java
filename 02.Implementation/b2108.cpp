#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // accumulate()
#include <cstdlib>  // abs() 절대값 함수
#include <cmath>    // round()
using namespace std;

// 통계학

// long의 범위는 -2,147,483,648 ~ +(동일-1)
// double의 범위는 -1.7*10^308 ~ +동일
int main() {
  long N; // 입력할 수의 개수
  long n; // 입력한 수
  vector<long> v;
  int po[4001] = {0, };  // positive 양수, 0은 여기 포함
  int na[4001] = {0, }; // negative 음수, 숫자를 편하게 매치시키기 위해서 na[0]은 무시


  scanf("%ld", &N);
  for(long i=0; i<N; i++) { // N번 숫자 입력받아서 vector v에 저장
    scanf("%ld", &n);
    v.push_back(n);
    if(n < 0) {             // 동시에 그 숫자들이 몇번 나왔는지 양수, 음수배열로 나누어 체크
      na[abs(n)]++;         // abs()는 절대값 함수
    } else if (n >= 0) {
      po[n]++;
    }
  }

  sort(v.begin(), v.end()); // 원소들을 오름차순 정렬

  // 산술평균
  printf("%.lf\n", round(accumulate(v.begin(), v.end(), 0)/(double)N));
  // round()소수점 첫째 자리에서 반올림 해주는 함수
  // accumulate() 총합을 구해주는 함수
  // 산술평균 얘가 자꾸 결과가 다르게 나와서 엄청 고생했는데 (double)N이 문제였음

  // 중앙값
  printf("%ld\n", v[N/2]);

  // 최빈값
  long max_cnt = 0;                   // 가장 큰 횟수
  long fi_min = 4001, se_min = 4002;  // 첫번째로 작은 값, 두번째로 작은 값
  for(int i=1; i<4001; i++) {         // 음수배열을 도는 코드
    int tar = (i * -1);
    if(na[i] > max_cnt) {
      max_cnt = na[i];              // max_cnt 갱신
      fi_min = tar; se_min = 4002;
    } else if (na[i] == max_cnt) {  // max_cnt 갱신안됨
        if(fi_min > tar) {
        se_min = fi_min;            // fi_min 갱신
        fi_min = tar;
      } else if(fi_min < tar && se_min > tar) { // fi_min < tar < se_min일 때
        se_min = tar;               // se_min 갱신
      }
    }
  }

  for(int i=0; i<4001; i++) {      // 양수배열을 도는 코드
    if(po[i] > max_cnt) {
      max_cnt = po[i];
      fi_min = i; se_min = 4002;
    }
    else if (po[i] == max_cnt) {
      if(fi_min > i) {            // 기존 fi_min보다 작은 수일때
        se_min = fi_min;
        fi_min = i;               // fi_min갱신
      }
      else if (fi_min < i && se_min > i) {
        se_min = i;               // se_min 갱신
      }
    }
  }

  if(se_min == 4002) {        // se_min이 없다는 뜻이므로
    printf("%ld\n", fi_min);  // fi_min값 출력
  } else if(se_min!=4002)
      printf("%ld\n", se_min);

  // 범위
  // sort 되어있기 때문에 간단하게 맨 끝에서 맨 처음을 뺀 수의 절대값으로 나타냄
  printf("%ld\n", abs(v[N - 1] - v[0]));

  return 0;
}
