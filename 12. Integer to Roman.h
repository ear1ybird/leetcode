/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-17
    Description:给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
    Agorithm:找零钱问题，贪心算法
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;

        for (int i = 0; i < values.size(); i++)
        {
            while(num>=values[i]){
                res+=reps[i];
                num-=values[i];
            }
        }
        return res;
    }
};