// [1차] 비밀지도

// 메모리 한도 초과 코드
// #include <string>
// #include <vector>
//
// using namespace std;
//
// vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//     vector<string> answer;
//     vector<int> v;
//     vector<int> v2;
//     string str = "";
//
//     for(int i=0; i<n; i++) { // 배열 안 수를 모두 2진수로 바꾸어야 함
//         while(arr1[i] != 0) {
//             v.push_back(arr1[i] % 2);
//             arr1[i] /= 2;
//         }   // 여기까지 arr1의 원소 하나를 2진수로 바꾼 것이 v 벡터에 들어가 있음
//         while(arr2[i] != 0) {
//             v2.push_back(arr2[i] % 2);
//             arr2[i] /= 2;
//         }   // 여기까지 arr2의 원소 하나를 2진수로 바꾼 것이 v 벡터에 들어가 있음
//         // reverse(v.begin(), v.end());
//         // reverse(v2.begin(), v2.end());
//
//         for(int j=0; j<n; i++) {
//             if(v[j]==1 || v2[j]==1) {
//                 str += '#';
//             }
//         } answer.push_back(str);
//     }
//
//
//     return answer;
// }
