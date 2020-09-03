/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-11
    Description:给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 
    nums1 中，使 nums1 成为一个有序数组。
    Algorithm:双指针。
**************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0;
        vector<int> nums1_copy = nums1;
        int c=0;

        while (i < m && j < n)
        {
            if (nums1_copy[i] < nums2[j])
            {
                nums1[c++]=nums1_copy[i++];
            }
            else
            {
                nums1[c++]=nums2[j++];
            }
        }
        while(i<m){
            nums1[c++]=nums1_copy[i++];
        }
        while(j<n){
            nums1[c++]=nums2[j++];
        }
    }
};