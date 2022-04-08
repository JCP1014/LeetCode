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
    int getDecimalValue(ListNode *head)
    {
        int ans = head->val;
        head = head->next;
        while (head)
        {
            ans <<= 1;
            ans += head->val;
            head = head->next;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(0);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(1);
    ListNode *n5 = new ListNode(0);
    ListNode *n6 = new ListNode(0);
    ListNode *n7 = new ListNode(1);
    ListNode *n8 = new ListNode(1);
    ListNode *n9 = new ListNode(1);
    ListNode *n10 = new ListNode(0);
    ListNode *n11 = new ListNode(0);
    ListNode *n12 = new ListNode(0);
    ListNode *n13 = new ListNode(0);
    ListNode *n14 = new ListNode(0);
    ListNode *n15 = new ListNode(0);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;

    cout << s.getDecimalValue(n1) << endl;

    return 0;
}