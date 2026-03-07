#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

int main() {
  std::vector<int> tmp = {2, 7, 11, 15};
  auto res = twoSum(tmp, 9);

  std::cout << "1st:" << res[0] << ", 2nd: " << res[1] << std::endl;
  return 0; }