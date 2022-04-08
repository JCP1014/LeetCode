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
    /********** Approach 1: Two pointers **********
    void reorderList(ListNode *head)
    {
        vector<ListNode *> nodes;
        while (head)
        {
            nodes.push_back(head);
            head = head->next;
        }

        ListNode *curr = nodes[0];
        head = curr;
        int l = 1, r = nodes.size() - 1;
        while (l <= r)
        {
            curr->next = nodes[r];
            curr = curr->next;
            if (--r < l)
                break;
            curr->next = nodes[l++];
            curr = curr->next;
        }
        curr->next = NULL;
    }
    ***********************************************/

    /*********** Approach 2: Recursive ************/
    void reorderList(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ++len;
            curr = curr->next;
        }
        helper(head, len);
    }
    ListNode *helper(ListNode *head, int len)
    {
        if (len == 1)
            return head;
        if (len == 2)
            return head->next;
        ListNode *tail = helper(head->next, len - 2);
        ListNode *tmp = tail->next;
        tail->next = tail->next->next;
        tmp->next = head->next;
        head->next = tmp;
        return tail;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    s.reorderList(n1);

    return 0;
}