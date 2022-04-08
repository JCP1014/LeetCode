#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        /*************** Approach 1: Less memory ***************/
        stack<char> word;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
                word.push(s[i]);
            else
            {
                while (!word.empty())
                {
                    ans += word.top();
                    word.pop();
                }
                if (ans.back() != ' ')
                    ans += ' ';
            }
        }
        while (!word.empty())
        {
            ans += word.top();
            word.pop();
        }
        while (ans.front() == ' ')
            ans = ans.substr(1, ans.length());
        while (ans.back() == ' ')
            ans = ans.substr(0, ans.length() - 1);
        return ans;

        /*************** Approach 2: Clear but more memory ***************
        istringstream iss(s);
        string tmp;
        string ans = "";
        while(iss >> tmp)
        {
            ans = tmp + " " + ans;
        }
        return ans.substr(0, ans.length()-1);
        ******************************************/

    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = "Alice does not even like bob";
    cout << s.reverseWords(str) << endl;

    return 0;
}