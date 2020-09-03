/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-03
    Description:给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素
     a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
    Agorithm:
        Solution 先将数组排序，遍历 a ，在 a 之后的数中用双指针遍历
        Solution1 暴力算法
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> out;
        if (nums.size() == 0)
        {
            return out;
        }
        sort(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> array;
                        array.push_back(nums[i]);
                        array.push_back(nums[j]);
                        array.push_back(nums[k]);
                        sort(array);
                        if (check(array, out) && i != k && j != i && k != j)
                            out.push_back(array);
                    }
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

    bool check(vector<int> &array, vector<vector<int>> out)
    {
        auto it = out.begin();
        for (; it < out.end(); it++)
        {
            if ((*it)[0] == array[0] && (*it)[1] == array[1] && (*it)[2] == array[2])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> out = {};
        if (nums.size() < 3)
        {
            return out;
        }

        sort(nums);
        int pre_i = 0;
        int pre_j = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i != 0)
            {
                if (nums[i] == nums[pre_i])
                {
                    continue;
                }
            }

            int j = i + 1;
            int k = nums.size() - 1;
            bool symbol=false;
            while (j < k)
            {
                if (j != i+1)
                {
                    while (nums[j] == nums[pre_j] && j < k)
                    {
                        j++;
                        if(j>=k){
                            symbol=true;
                        }
                    }
                    if(symbol){
                        symbol=false;
                        break;
                    }
                }
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> arr = {};
                    arr.push_back(nums[i]);
                    arr.push_back(nums[j]);
                    arr.push_back(nums[k]);
                    out.push_back(arr);
                    pre_j = j;
                    j++;
                }
                while (nums[i] + nums[j] + nums[k] < 0 && j < k)
                {
                    pre_j = j;
                    j++;
                }
                while (nums[i] + nums[j] + nums[k] > 0 && j < k)
                {
                    k--;
                }
            }
            pre_i = i;
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