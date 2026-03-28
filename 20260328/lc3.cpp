#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    string tmp;

    int ans = 0;
    for (const char x : s) {
      int pos = tmp.find(x);
      if (pos != string::npos) {
        if (tmp.size() > ans) {
          ans = tmp.size();
        }
        tmp.erase(0, pos+1);
      }
      tmp.push_back(x);
    }

    if (tmp.size() > ans) {
      ans = tmp.size();
    }
    return ans;
  }
};