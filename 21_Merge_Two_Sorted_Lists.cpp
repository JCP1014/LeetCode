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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        /********** Approach 1: Iterative **********
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = (list1) ? list1 : list2;
        return dummy->next;
        ********************************************/
       
        /********** Approach 2: Recursive **********/
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode *res = s.mergeTwoLists(list1, list2);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}