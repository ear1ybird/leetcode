/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2021-03-19
    Description:在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中
    某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中
    任意一个重复的数字。
    Algorithm:哈希表
**************************************************************************/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])){
                return nums[i];
            }
            map[nums[i]]++;
        }
    }
};