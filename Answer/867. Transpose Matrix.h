/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-01
    Description:矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
    Algorithm:二维数组vector
**************************************************************************/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res(A[0].size(),vector<int>(A.size(),0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                res[j][i]=A[i][j];
            }
        }
        return res;
    }
};