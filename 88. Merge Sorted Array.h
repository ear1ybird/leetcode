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