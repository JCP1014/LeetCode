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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *res = new ListNode();
        ListNode *curr, *tmp;
        while (head)
        {
            tmp = head;
            head = head->next;
            curr = res;
            while (curr->next && curr->next->val < tmp->val)
                curr = curr->next;
            tmp->next = curr->next;
            curr->next = tmp;
        }
        return res->next;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *n1 = new ListNode(-1);
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(0);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode *res = s.insertionSortList(n1);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}