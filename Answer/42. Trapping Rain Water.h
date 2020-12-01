/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-01
    Description:给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的
        柱子，下雨之后能接多少雨水。
    Agorithm:遍历，分别找左边和右边的最大值，其中较小的是水的高度
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;

        if(height.size()<3){
            return 0;
        }

        for(int i=1;i<height.size()-1;i++){
            int max_left=0,max_right=0;
            for(int j=i;j>=0;j--){
                max_left=max(max_left,height[j]);
            }
            for(int j=i;j<height.size();j++){
                max_right=max(max_right,height[j]);
            }

            int h=min(max_right,max_left);
            res+=h-height[i];
        }
        return res;
    }
};
