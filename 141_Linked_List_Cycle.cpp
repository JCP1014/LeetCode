#include <bits/stdc++.h>
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
    bool hasCycle(ListNode *head)
    {
        /********** Approach 1: Replace value **********
        int min_val = -100001;
        while(head)
        {
            if (head->val > min_val)
            {
                head->val = min_val;
                head = head->next;
            }
            else
                return true;
        }
        return false;
        ************************************************/

        /********** Approach 2: Two Pointers (Floyd’s Cycle-Finding Algorithm) **********/
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    cout << s.hasCycle(n1) << endl;

    return 0;
}