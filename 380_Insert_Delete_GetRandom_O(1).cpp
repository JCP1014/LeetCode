#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        rs.push_back(val);
        m[val] = rs.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;
        m[rs[rs.size() - 1]] = m[val];
        swap(rs[m[val]], rs[rs.size() - 1]);
        rs.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        // return rs[uniform_int_distribution<int>(0, rs.size() - 1)(generator)];
        return rs[rand() % rs.size()];
    }

private:
    unordered_map<int, int> m;
    vector<int> rs;
    // default_random_engine generator;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int param_4 = obj->getRandom();
    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    int param_7 = obj->getRandom();
    cout << param_1 << " " << param_2 << " " << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << " " << param_6 << endl;
    cout << param_7 << endl;

    return 0;
}