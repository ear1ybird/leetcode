/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-17
    Description:给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
    Agorithm:前一个罗马字母比后一个罗马字母小则为负数
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        int pre_num = getValue(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            int num = getValue(s[i]);
            if (num > pre_num)
            {
                sum -= pre_num;
            }
            else
            {
                sum += pre_num;
            }
            pre_num = num;
        }
        sum += pre_num;
        return sum;
    }

    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};