/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2021-03-19
    Link:https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
    Description:在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列
    都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，
    判断数组中是否含有该整数。
    Algorithm:哈希表
**************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;

        for(int i=0;i<matrix.size();i++){
            if(matrix[i].size()>0){
                if (rangeCheck(matrix[i][0], matrix[i].back(), target))
                {
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                        if (matrix[i][j] == target)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool rangeCheck(int a,int b,int target){
        return a<=target && b>=target;
    }
};