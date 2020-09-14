/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-14
    Description:给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到
    一个升序链表中，返回合并后的链表。
    Agorithm:两两合并链表
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        if (lists.size() == 0)
        {
            return ans;
        }
        for (int i = 0; i < lists.size(); i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }

    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if ((!a) || (!b))
        {
            return a ? a : b;
        }
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = aPtr ? aPtr : bPtr;
        return head.next;
    }
};