#include <bits/stdc++.h>
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *tail = dummy;

        while (head && head->next)
        {
            if (head->val != head->next->val)
            {
                tail->next = head;
                tail = tail->next;
            }
            else
            {
                while (head->next && head->val == head->next->val)
                    head = head->next;
            }
            head = head->next;
        }
        tail->next = head;
        return dummy->next;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *n7 = new ListNode(3);
    ListNode *n6 = new ListNode(3, n7);
    ListNode *n5 = new ListNode(3, n6);
    // ListNode *n4 = new ListNode(2, n5);
    // ListNode *n3 = new ListNode(1, n4);
    // ListNode *n2 = new ListNode(2, n3);
    // ListNode *n1 = new ListNode(1, n2);
    
    ListNode *res = s.deleteDuplicates(n5);
    while(res)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}