#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        /********** Approach 1 **********
        if (x < 0)
            return false;
        string str = to_string(x);
        int l = 0, r = str.length()-1;
        while(l <= r)
        {
            if (str[l++] != str[r--])
                return false;
        }
        return true;
        ********************************/

        /********** Approach 2 (Fast and Simple) **********/
        if (x < 0)
            return false;    
        int arr[10];
        int cnt = 0;
        while (x > 0)
        {
            arr[cnt++] = x % 10; 
            x /= 10;
        }
        int l = 0;
        int r = cnt - 1;
        while (l < r)
        {
            if(arr[l++] != arr[r--])
                return false;
        }
        return true;


        /********** Approach 3 **********
        if (x == 0)
            return true;
        if (x < 0 || x % 10 == 0)
            return false;
        int reversed_right = 0;
        while (reversed_right < x)
        {
            reversed_right = reversed_right * 10 + x % 10;
            x /= 10;
        }
        if (reversed_right == x)
            return true;
        if (reversed_right / 10 == x) // Odd digits
            return true;
        return false;
        ********************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    int x = atoi(argv[1]);
    cout << s.isPalindrome(x) << endl;

    return 0;
}