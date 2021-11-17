#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (ms.empty())
            ms.push_back({val, val});
        else
            ms.push_back({val, min(val, ms.back().second)});
    }

    void pop()
    {
        ms.pop_back();
    }

    int top()
    {
        return ms.back().first;
    }

    int getMin()
    {
        return ms.back().second;
    }

private:
    vector<pair<int, int>> ms;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    return 0;
}