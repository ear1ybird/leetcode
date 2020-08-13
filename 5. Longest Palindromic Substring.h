/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-12
    Description:给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大
    长度为 1000。
    Agorithm:   
    Solution 中心扩散
    Solution1 暴力算法
    Solution2 动态规划
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int palindromicLen = 0;
        int maxLen = 0;
        int begin = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            palindromicLen = max(expendAroundCenter(s, i, i), expendAroundCenter(s, i, i + 1));
            if (palindromicLen > maxLen)
            {
                maxLen = palindromicLen;
                begin = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(begin, maxLen);
    }

    int expendAroundCenter(string s, int left, int right)
    {
        int len = s.length();

        int i = left;
        int j = right;
        while (i >= 0 && j < len)
        {
            if (s[i] == s[j])
            {
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        return j - i - 1;
    }
};

class Solution1
{
public:
    string longestPalindrome(string s)
    {
        vector<string> subString;
        if (s.length() < 2)
        {
            return s;
        }

        for (int i = 0; i < s.length() - 1; i++)
        {
            for (int j = 1; j <= s.length() - i; j++)
            {
                subString.push_back(s.substr(i, j));
            }
        }

        vector<char> stack;
        vector<string> palindromic;

        for (auto it = subString.begin(); it != subString.end(); ++it)
        {
            auto left = (*it).begin();
            auto right = (*it).end() - 1;
            while (left < right)
            {
                if (*left != *right)
                {
                    break;
                }
                left++;
                right--;
            }
            if (left >= right)
            {
                palindromic.push_back(*it);
            }
        }
        int maxLen = 0;
        string *res;
        for (auto it = palindromic.begin(); it != palindromic.end(); ++it)
        {
            if ((*it).size() > maxLen)
            {
                maxLen = (*it).size();
                res = &(*it);
            }
        }
        return *res;
    }
};

class Solution2
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len < 2)
        {
            return s;
        }

        int maxLen = 1;
        int begin = 0;

        bool **dp = new bool *[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = new bool[len];
            for (int m = 0; m < len; m++)
            {
                if (i == m)
                {
                    dp[i][m] = true;
                }
                else
                {
                    dp[i][m] = false;
                }
            }
        }

        for (int j = 1; j < len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if(s[i]!=s[j]){
                    dp[i][j]=false;
                }else{
                    if(j-i<3){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && j-i+1>maxLen){
                    maxLen=j-i+1;
                    begin=i;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};