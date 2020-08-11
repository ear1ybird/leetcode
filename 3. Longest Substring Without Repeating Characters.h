/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-11
    Description:给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
**************************************************************************/

#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;   //窗口左
        int i = 0;
        int res = 0;
        unordered_set<int> set;

        for (i = 0; i < s.size(); ++i)
        {
            if (!set.count(s[i]))
            {
                set.insert(s[i]);
                res = max(res, static_cast<int>(set.size()));
            }
            else
            {
                while (set.count(s[i]))
                {
                    //因为子串要求连续，所以无论窗口最左边是否重复，都应删除
                    //直到子串中没有重复值
                    set.erase(s[left]);
                    left++;
                }
                set.insert(s[i]);
            }
        }

        return res;
    }
};