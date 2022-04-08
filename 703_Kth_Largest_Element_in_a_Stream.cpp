#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        kk = k;
        for (auto n : nums)
        {
            q.push(n);
            if (q.size() > k)
                q.pop();
        }
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > kk)
            q.pop();
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int kk;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest *obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl;  // return 4
    cout << obj->add(5) << endl;  // return 5
    cout << obj->add(10) << endl; // return 5
    cout << obj->add(9) << endl;  // return 8
    cout << obj->add(4) << endl;  // return 8

    return 0;
}