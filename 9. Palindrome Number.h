/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-16
    Description:判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从
    右向左）读都是一样的整数。
    Agorithm:整数反转一半
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x == 0)
        {
            return true;
        }

        if (x % 10 == 0)
        {
            return false;
        }

        int revertedNum = 0;
        while (x > revertedNum)
        {
            revertedNum *= 10;
            revertedNum += x % 10;

            x /= 10;
        }

        if (x == revertedNum || x == revertedNum / 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};