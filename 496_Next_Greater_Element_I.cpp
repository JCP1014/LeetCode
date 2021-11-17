#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        unordered_map<int, int> m;
        s.push(nums2[0]);
        for (int j = 1; j < nums2.size(); ++j)
        {
            while (!s.empty() && nums2[j] > s.top())
            {
                m[s.top()] = nums2[j];
                s.pop();
            }
            s.push(nums2[j]);
        }
        while(!s.empty())
        {
            m[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for (auto &num : nums1)
        {
            ans.push_back(m[num]);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums1 = {2,4}, nums2 = {1,2,3,4};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for(auto &a:ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}