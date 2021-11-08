#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums.at(i)) != map.end()) {
        return {map.at(nums.at(i)), i};
      }
      map[target - nums.at(i)] = i;
    }
    return {-1, -1};
  }
};