/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可
    能的并且 有效的 括号组合。
    Agorithm:回溯
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string s;
        vector<string> res;
        backtrack(res, s, 0, 0, n);
        return res;
    }

    void backtrack(vector<string> &res, string &s, int open, int close, int n)
    {
        if (s.size() == n * 2)
        {
            res.push_back(s);
            return;
        }

        if (open < n)
        {
            s.push_back('(');
            backtrack(res, s, open + 1, close, n);
            s.pop_back();
        }
        //重点
        if (close < open)
        {
            s.push_back(')');
            backtrack(res, s, open, close + 1, n);
            s.pop_back();
        }
    }
};
