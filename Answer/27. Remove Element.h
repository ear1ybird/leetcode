/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 
    val 的元素，并返回移除后数组的新长度。不要使用额外的数组空间，你必须仅使用 
    O(1) 额外空间并 原地 修改输入数组。元素的顺序可以改变。你不需要考虑数组中超
    出新长度后面的元素。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }

        int i=0;
        while(i<len){
            if(nums[i]==val){
                nums[i]=nums[len-1];
                len--;
            }else{
                i++;
            }
        }
        return len;
    }
};