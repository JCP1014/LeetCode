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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *odd_curr = head;
        ListNode *even_curr = head->next;
        ListNode *even_head = even_curr;

        while (odd_curr->next && even_curr->next)
        {
            odd_curr->next = odd_curr->next->next;
            even_curr->next = even_curr->next->next;
            odd_curr = odd_curr->next;
            even_curr = even_curr->next;
        }

        odd_curr->next = even_head;

        return head;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(5);
    ListNode *n5 = new ListNode(6);
    ListNode *n6 = new ListNode(4);
    ListNode *n7 = new ListNode(7);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Solution s;
    ListNode *curr = s.oddEvenList(n1);
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
