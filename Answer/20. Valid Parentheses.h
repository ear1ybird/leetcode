/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-05
    Description:给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符
    串是否有效。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> paris = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (stack.empty())
            {
                stack.push(s[i]);
            }
            else if (stack.top()==paris[s[i]])
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
        }
        if (stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};