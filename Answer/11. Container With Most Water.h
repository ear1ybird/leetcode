/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-17
    Description:给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 
    (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 
    (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    Agorithm:双指针，根据面积特点减少计算次数
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        int area = 0;
        int m;


        while (i<j)
        {
            area = (j - i) * min(height[i], height[j]);

            if (area > res)
            {
                res = area;
            }

            if (height[i] > height[j])
            {
                m = j - 1;
                while (height[m] < height[j])
                {
                    m--;
                }
                j = m;
            }
            else
            {
                m = i + 1;
                while (height[m] < height[i])
                {
                    m++;
                }
                i = m;
            }
        }
        return res;
    }
};