/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-16
    Description:判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从
    右向左）读都是一样的整数。
    Agorithm:
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
        }else if(x==0){
            return true;
        }

        vector<int> s;

        while (x != 0)
        {
            int pop = x % 10;
            s.push_back(pop);
            x /= 10;
        }

        auto left = s.begin();
        auto right = s.end() - 1;
        while (left < right)
        {
            if ((*left) != (*right))
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};