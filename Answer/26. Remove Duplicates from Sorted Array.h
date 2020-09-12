/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素
    只出现一次，返回移除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修
    改输入数组 并在使用 O(1) 额外空间的条件下完成。
    Agorithm:快慢指针
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }

        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};