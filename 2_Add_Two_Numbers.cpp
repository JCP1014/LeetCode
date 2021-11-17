#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *curr = ans;
        int carry = 0;
        int sum = 0;

        while (l1 != NULL || l2 != NULL)
        {
            sum = 0;
            sum += carry;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        return ans->next;
    }
};

void pushBack(ListNode *l, int x)
{
    ListNode *newNode = new ListNode(x);
    if (l == NULL)
    { // 若list沒有node, 令newNode為first
        l = newNode;
        return;
    }

    ListNode *current = l;
    while (current->next != NULL)
    { // Traversal
        current = current->next;
    }
    current->next = newNode;
}

void printList(ListNode *l)
{

    if (l == NULL)
    { // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = l; // 用pointer *current在list中移動
    while (current != 0)
    { // Traversal
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ListNode *l1 = new ListNode(9);
    pushBack(l1, 9);
    pushBack(l1, 9);
    pushBack(l1, 9);
    pushBack(l1, 9);
    pushBack(l1, 9);
    pushBack(l1, 9);

    ListNode *l2 = new ListNode(9);
    pushBack(l2, 9);
    pushBack(l2, 9);
    pushBack(l2, 9);

    Solution s;
    ListNode *ans;
    ans = s.addTwoNumbers(l1, l2);
    printList(ans);
}