#include <vector>
#include <algorithm>

using namespace std;

// 폰켓몬

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size()/2;
    int po = 1;

    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++) {
        if(nums[i-1] != nums[i]) { po++; }
    }

    if(n < po) { answer = n; }
    else { answer = po; }

    return answer;
}
