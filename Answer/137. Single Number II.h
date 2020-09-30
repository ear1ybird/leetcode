/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-30
    Description:给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均
    出现了三次。找出那个只出现了一次的元素。
    Algorithm:
        Solution: 两步按位异或
        Solution1: 哈希表
**************************************************************************/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once=0;
        int seen_twice=0;

        for(auto i:nums){
            seen_once=~seen_twice&(seen_once^i);
            seen_twice=~seen_once&(seen_twice^i);
        }
        return seen_once;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i:nums){
            map[i]++;
        }

        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]==1){
                return nums[i];
            }
        }
        return 0;
    }
};