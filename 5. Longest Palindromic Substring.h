/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-12
    Description:给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大
    长度为 1000。
    Agorithm:中心扩散。
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int palindromicLen=0;
        int maxLen=0;
        int begin=0;

        for(int i=0;i<s.length();++i){
            palindromicLen=max(expendAroundCenter(s,i,i),expendAroundCenter(s,i,i+1));
            if(palindromicLen>maxLen){
                maxLen=palindromicLen;
                begin=i-(maxLen-1)/2;
            }
        }
        return s.substr(begin,maxLen);
    }


    int expendAroundCenter(string s,int left ,int right){
        int len=s.length();

        int i=left;
        int j=right;
        while (i>=0 && j<len)
        {
            if(s[i]==s[j]){
                i--;
                j++;
            }else{
                break;
            }
        }
        return j-i-1;    
    }
};