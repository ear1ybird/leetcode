/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-03
    Description:给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素
     a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
    Agorithm:
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
        vector<vector<int>> out;

        if (nums.size() == 0)
        {
            return out;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int l = 0;
            int r = nums.size() - 1;
            sort(nums);
            while (l < r)
            {
                if (nums[l] + nums[r] + nums[i] == 0)
                {
                    vector<int> array;
                    if (i != l && i != r)
                    {
                        array.push_back(nums[l]);
                        array.push_back(nums[r]);
                        array.push_back(nums[i]);
                        sort(array);
                        //if (check(array, out))
                        ///{
                            out.push_back(array);
                        //}
                    }
                    l++;
                }
                else if (nums[l] + nums[r] + nums[i] < 0)
                {
                    l++;
                }
                else if (nums[l] + nums[r] + nums[i] > 0)
                {
                    r--;
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