/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-01
    Description:给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新
        数组，要求也按非递减顺序排序。
    Algorithm:二双指针
**************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        while(i<nums.size() && nums[i]<0 ){
            i++;
        }
        int j=i-1;

        vector<int> res;
        while(i<nums.size() && j>=0){
            if(abs(nums[j])<nums[i]){
                res.push_back(nums[j]*nums[j]);
                j--;
            }else{
                res.push_back(nums[i]*nums[i]);
                i++;
            }
        }
        while(j>=0){
            res.push_back(nums[j]*nums[j]);
            j--;
        }
        while(i<nums.size()){
            res.push_back(nums[i]*nums[i]);
            i++;
        }
        return res;
    }
};