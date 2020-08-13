/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-11
    Description:给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
    请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    Algorithm:二分查找法。
**************************************************************************/

#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        //使用二分查找在第一个数组确定分割线 i，再通过totalLeft - i 确定第二个数组的分割线
        //避免访问越界，确保第二个数组的分割线两边都应元素，故使第一个数组短于第二个数组
        if (nums1.size() > nums2.size())
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.size();
        int n = nums2.size();

        //不论元素为偶数个还是奇数个，都满足左边元素个数为(m+n+1)/2
        int totalLeft = (m + n + 1) / 2;

        //定义分割线右边的元素下标为 i j
        //查找 i j，使得分割线左边元素全部小于右边元素
        int left = 0;
        int right = m;
        while (left < right)
        {
            //当区间仅剩两个元素时，区间不会再缩小，将进入死循环
            //+1,使得这种情况下 left > right ，从而退出循环 
            //同时，不会执行 i = 0 的情况，下标 i - 1不会越界
            int i = (left + right + 1) / 2;

            //分割线右边第一个元素的下标 = 分割线左边元素的个数
            int j = totalLeft - i;

            if (nums1[i - 1] > nums2[j])
            {
                //重新设置搜索区间
                right = i - 1;
            }
            else
            {
                left = i;
            }
        }

        int i = left;
        int j = totalLeft - i;

        int num1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
        int num1RightMin = (i == m) ? INT_MAX : nums1[i];
        int num2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
        int num2RightMin = (j == n) ? INT_MAX : nums2[j];

        if ((m + n) % 2 == 1)
        {
            return max(num1LeftMax, num2LeftMax);
        }
        else
        {
            return (double)(max(num1LeftMax, num2LeftMax) + min(num1RightMin, num2RightMin)) / 2;
        }
    }
};