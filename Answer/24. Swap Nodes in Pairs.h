/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-14
    Description:给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能
    只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    Agorithm:增加头节点，快指针
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p = new ListNode(0);
        p->next = head;
        ListNode *ans = p;
        while (p->next && p->next->next)
        {
            ListNode *a = p->next;
            ListNode *b = p->next->next;
            ListNode *tail = NULL;

            if (p->next->next->next != NULL)
            {
                tail = p->next->next->next;
            }

            p->next = b;
            p->next->next = a;

            if (tail != NULL)
            {
                a->next = tail;
                p=a;
            }
            else
            {
                a->next = NULL;
                break;
            }
        }
        return ans->next;
    }
};