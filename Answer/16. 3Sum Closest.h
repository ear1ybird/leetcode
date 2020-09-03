/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-03
    Description:给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 
    nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每
    组输入只存在唯一答案。
    Agorithm:先将数组排序，遍历 a ，在 a 之后的数中用双指针遍历
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums);
        int out = 0;

        int temp = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target){
                    return sum;
                }
                if (abs(sum - target) < temp)
                {
                    out = sum;
                    temp = abs(sum - target);
                    continue;
                }
                if (sum < target)
                {
                    j++;
                }
                if (sum > target)
                {
                    k--;
                }
            }
        }
        return out;
    }

    vector<int> sort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < nums.size() - 1 - i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int a = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = a;
                }
            }
        }
        return nums;
    }
};