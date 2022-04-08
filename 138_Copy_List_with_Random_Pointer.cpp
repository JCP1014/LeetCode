#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        /*************** Approach 1: O(1) Space ***************
        Node *curr = head;
        while (curr)
        {
            Node *copied = new Node(curr->val);
            copied->next = curr->next;
            curr->next = copied;
            curr = copied->next;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node *dummy= new Node(0);
        dummy->next = head;
        curr = dummy;
        while(head)
        {
            curr->next = head->next;
            head->next = head->next->next;
            curr = curr->next;
            head = head->next;
        }

        return dummy->next;
        *******************************************************/

        /********** Approach 2: Map & Iterative **********/
        unordered_map<Node*, Node*> m;
        Node *curr = head;
        while(curr)
        {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr)
        {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];

        /********** Approach 3: Map & Recursive **********
        if (!head)
            return NULL;
        if (m[head])
            return m[head];
        m[head] = new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
        **************************************************/
    }
// For Approach 3
// private:
//     unordered_map<Node *, Node *> m;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    Node *n0 = new Node(7);
    Node *n1 = new Node(13);
    Node *n2 = new Node(11);
    Node *n3 = new Node(10);
    Node *n4 = new Node(1);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->random = n0;
    n2->random = n4;
    n3->random = n3;
    n4->random = n0;

    Node *res = s.copyRandomList(n0);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}