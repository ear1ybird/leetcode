/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单
    词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        int res = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                res++;
            }

            if(s[i]==' ' && res>0){
                break;
            }
        }
        return res;
    }
};