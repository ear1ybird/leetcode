/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-02
    Description:在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
    每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数
    组和一个整数，判断数组中是否含有该整数。
    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool RangeCheck(int a,int b,int target){
        if(a<=target && b>=target){
            return true;
        }else
        {
            return false;
        }
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }

        for(int i=matrix.size()-1;i>=0;i--){
            if(matrix[i].size()==0){
                continue;
            }

            if(RangeCheck(matrix[i][0],matrix[i][matrix[i].size()-1],target)){
                for(int j=0;j<matrix[i].size();j++){
                    if(matrix[i][j]==target){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};