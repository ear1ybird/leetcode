/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-11
    Description:给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出
    和为目标值的那 两个 整数，并返回他们的数组下标。
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
        vector<string> subString;
        if (s.length() < 2)
        {
            return s;
        }

        for (int i = 0; i < s.length() - 1; i++)
        {
            for (int j = 1; j <= s.length()-i; j++)
            {
                subString.push_back(s.substr(i, j));
            }
        }

        vector<char> stack;
        vector<string> palindromic;

        for (auto it = subString.begin(); it != subString.end(); ++it)
        {
            auto left=(*it).begin();
            auto right=(*it).end()-1;
            while(left<right){
                if(*left!=*right){
                    break;
                }
                left++;
                right--;
            }
            if(left>=right){
                palindromic.push_back(*it);
            }
        }
        int maxLen=0;
        string* res;
        for(auto it=palindromic.begin();it!=palindromic.end();++it){
            if((*it).size()>maxLen){
                maxLen=(*it).size();
                res=&(*it);
            }
        }
        return *res;
    }
};