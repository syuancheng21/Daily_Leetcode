#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int s = nums.size();
    if (s == 0) {
      return -1;
    }
    if (s == 1) {
      return nums[0] == target ? 0 : -1;
    }
    int l = 0, r = s - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target <= nums[mid]) {
          r = mid - 1;

        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] <= target && target <= nums[s - 1]) {
          l = mid + 1;
        } else {

          r = mid - 1;
        }
      }
    }
    return -1;
  }
};