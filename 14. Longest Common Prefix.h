/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-03
    Description:编写一个函数来查找字符串数组中的最长公共前缀。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string out = "";
        if(strs.size()==0){
            return out;
        }
        char c;
        int i = 0;
        while (true)
        {
            if (strs[0][i])
            {
                c = strs[0][i];
            }
            else{
                return out;
            }
            for (auto it = strs.begin(); it < strs.end(); it++)
            {
                if ((*it)[i])
                {
                    if ((*it)[i] != c)
                    {
                        return out;
                    }
                }else{
                    return out;
                }
            }
            out.push_back(c);
            i++;
        }
        return out;
    }
};