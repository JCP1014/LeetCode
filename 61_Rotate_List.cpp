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
    ListNode *rotateRight(ListNode *head, int k)
    {
        /*************** Appraoch 1 ***************/
        if (!head || !head->next || !k)
            return head;
        ListNode *p1 = head, *p2 = head;
        int cnt = 0;
        while (k && p2)
        {
            ++cnt;
            p2 = p2->next;
            --k;
        }
        if (k)
        {
            k %= cnt;
            p2 = head;
            while (k--)
                p2 = p2->next;
        }
        if (!p2)
            return head;
        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;

        /*************** Appraoch 2 ***************
        if (!head || !head->next || !k)
            return head;
        ListNode *p = head;
        int cnt = 1;
        while (p->next)
        {
            ++cnt;
            p = p->next;
        }
        k %= cnt;
        if (!k)
            return head;
        p->next = head;
        k = cnt - k;
        while (k)
        {
            p = p->next;
            --k;
        }
        head = p->next;
        p->next = NULL;
        return head;
        *******************************************/

    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *p1 = new ListNode(1, p2);
    int k = 2;

    ListNode *res = s.rotateRight(p1, k);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}