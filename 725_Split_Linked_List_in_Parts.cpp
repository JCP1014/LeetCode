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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0;
        while (curr)
        {
            ++len;
            curr = curr->next;
        }
        int avg = len / k;
        int large = len % k;
        vector<ListNode *> res(k);
        curr = head;
        for (int i = 0; i < k; ++i)
        {
            int part_len = avg;
            if (large)
            {
                part_len += 1;
                --large;
            }
            res[i] = curr;
            ListNode *prev = NULL;
            while (part_len)
            {
                prev = curr;
                curr = curr->next;
                --part_len;
            }
            if (prev)
                prev->next = NULL;
        }
        return res;
        
        /********** My Approach **********
        ListNode *curr = head;
        int len = 0;
        while (curr)
        {
            ++len;
            curr = curr->next;
        }
        int avg = len / k;
        int large = len % k;
        int small = k - large;
        vector<ListNode *> res;
        curr = head;
        for (int i = 0; i < large; ++i)
        {
            ListNode *partHead = curr;
            ListNode *partCurr = partHead;
            curr = curr->next;
            for (int j = 1; j < avg + 1; ++j)
            {
                partCurr->next = curr;
                partCurr = partCurr->next;
                curr = curr->next;
            }
            partCurr->next = NULL;
            res.push_back(partHead);
        }
        if (!avg)
        {
            for (int i = 0; i < small; ++i)
            {
                res.push_back(NULL);
            }
        }
        else
        {
            for (int i = 0; i < small; ++i)
            {
                ListNode *partHead = curr;
                ListNode *partCurr = partHead;
                curr = curr->next;
                for (int j = 1; j < avg; ++j)
                {
                    partCurr->next = curr;
                    partCurr = partCurr->next;
                    curr = curr->next;
                }
                partCurr->next = NULL;
                res.push_back(partHead);
            }
        }
        return res;
        *********************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(2, l1);
    ListNode *l3 = new ListNode(1, l2);

    Solution s;
    vector<ListNode *> v;
    v = s.splitListToParts(l3, 5);
    for (int i = 0; i < v.size(); ++i)
    {
        ListNode *curr = v[i];
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    return 0;
}
