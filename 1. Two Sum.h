/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-11
    Description:给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出
    和为目标值的那 两个 整数，并返回他们的数组下标。
**************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;

        for(int i=0;i<nums.size();++i){
            m[nums[i]]=i;
        }

        for(int i=0;i<nums.size();++i){
            int t=target-nums[i];
            if(m.count(t) && m[t]!=i){
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};