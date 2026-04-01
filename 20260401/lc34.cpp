#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans = {-1, -1};
    if (nums.empty()) {
      return ans;
    }

    int tmp = -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == target) {
        tmp = mid;
        break;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (tmp == -1) {
      return ans;
    }

    int i = tmp;
    while (i >= 0 && nums[i] == target) {
      i--;
    }
    ans[0] = i + 1;

    int j = tmp;
    while (j < nums.size() && nums[j] == target) {
      j++;
    }
    ans[1] = j - 1;
    return ans;
  }
};