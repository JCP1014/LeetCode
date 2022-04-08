#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *swapPairs(ListNode *head)
    {
        /********** Approach 1: Recursive **********/
        if (!head || !head->next)
            return head;
        ListNode *r = head->next;
        head->next = swapPairs(head->next->next);
        r->next = head;
        return r;

        /********** Approach 2: Iterative **********
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *l, *r;

        while ((l = pre->next) && (r = pre->next->next))
        {
            l->next = r->next;
            r->next = l;
            pre->next = r;
            pre = l;
        }
        return dummy->next;
        ********************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode *res = s.swapPairs(head);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}