/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-04
    Description:给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    Agorithm:回溯算法
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
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations = {};
        string combination = "";

        if (digits.empty())
        {
            return combinations;
        }

        unordered_map<char, string> lettersMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        backtrack(combinations, lettersMap, combination, 0, digits);
        return combinations;
    }

    void backtrack(vector<string> &combinations, const unordered_map<char, string> &lettersMap, string combination, int index, const string &digits)
    {
        if (index == digits.length())
        {
            combinations.push_back(combination);
        }
        else
        {
            const char digit = digits[index];
            const string letters = lettersMap.at(digit);
            for (const char &letter : letters)
            {
                combination.push_back(letter);
                backtrack(combinations, lettersMap, combination, index + 1, digits);
                combination.pop_back();     //Focus
            }
        }
    }
};
