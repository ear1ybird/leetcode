/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-30
    Description:给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均
    出现两次。找出那个只出现了一次的元素。
    Algorithm:
        Solution: 哈希表
        Solution1: 所有数异或运算
**************************************************************************/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]==1){
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res ^=nums[i];
        }
        return res;
    }
};