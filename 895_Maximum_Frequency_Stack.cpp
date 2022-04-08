#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
public:
    FreqStack()
    {
        freq_stacks.push_back(vector<int>());
    }

    void push(int val)
    {
        ++freq[val];
        if (freq[val] == freq_stacks.size())
            freq_stacks.push_back(vector<int>());
        freq_stacks[freq[val]].push_back(val);
    }

    int pop()
    {
        int val = freq_stacks.back().back();
        --freq[val];
        freq_stacks.back().pop_back();
        if (freq_stacks.back().empty())
            freq_stacks.pop_back();
        return val;
    }

private:
    unordered_map<int, int> freq;
    vector<vector<int>> freq_stacks;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    FreqStack *obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;

    return 0;
}