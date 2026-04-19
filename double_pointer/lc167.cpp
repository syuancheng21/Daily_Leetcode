#include <cstddef>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < numbers.size(); i++) {
      int n = numbers[i];
      if (const auto &iter = map.find(target - n); iter != map.end()) {
        return {map[target - n], i + 1};
      }
      map[n] = i + 1;
    }
    return {};
  }
};