/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-13
    Description:请你来实现一个 atoi 函数，使其能将字符串转换成整数。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int begin = 0;
        bool positive = true;
        for (begin = 0; begin < str.length(); ++begin)
        {
            if (str[begin] != ' ')
            {
                if (str[begin] == '-')
                {
                    positive = false;
                    if (begin + 1 < str.length())
                    {
                        begin++;
                        if (str[begin] < '0' || str[begin] > '9')
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                if (str[begin] == '+')
                {
                    positive = true;
                    if (begin + 1 < str.length())
                    {
                        begin++;
                        if (str[begin] < '0' || str[begin] > '9')
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                break;
            }
        }
        if (begin == str.length())
        {
            return 0;
        }

        if (str[begin] < '0' || str[begin] > '9')
        {
            return 0;
        }

        int res = 0;
        for (int i = begin; i < str.length(); ++i)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                break;
            }
            int pop = (int)str[i] - (int)'0';
            if (positive == true)
            {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
                    return INT_MAX;
            }
            if (positive == false)
            {
                if (res > -(INT_MIN / 10) || (-res == INT_MIN / 10 && pop > 7))
                    return INT_MIN;
            }
            res = res * 10 + pop;
        }
        if (positive == false)
        {
            return -res;
        }
        else
        {
            return res;
        }
    }
};