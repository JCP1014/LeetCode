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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *l = head, *r = head;
        int cnt = 1;
        while(curr)
        {
            if(cnt < k)
                l = l->next;
            else if (cnt > k)
                r = r->next;
            ++cnt;
            curr = curr->next;
        }
        swap(l->val, r->val);
        return head;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;

    head = s.swapNodes(head, k);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}