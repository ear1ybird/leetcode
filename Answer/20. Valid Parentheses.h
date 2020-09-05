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
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        string stack = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
            {
                stack.push_back(s[i]);
            }
            else if (check(getStackBack(stack), s[i]))
            {
                stack.pop_back();
            }else{
                stack.push_back(s[i]);
            }
        }
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }

    bool check(char a, char b)
    {
        if (a == '(' && b == ')')
        {
            return true;
        }
        else if (a == '{' && b == '}')
        {
            return true;
        }
        else if (a == '[' && b == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char getStackBack(string s){
        if(s.empty()){
            return 0;
        }else{
            return s.back();
        }
    }
};