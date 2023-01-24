#include <bits/stdc++.h>

using namespace std;

string maxLengthPalindrome(string s)
{
    // using hash table to store the index of the last occurrence of each character
    unordered_map<char, int> last;
    for (int i = 0; i < s.length(); i++) last[s[i]] = i;
    // using a stack to store the characters that have not been paired
    stack<int> st;
    // using a vector to store the characters that have been paired
    vector<int> paired;
    for (int i = 0; i < s.length(); i++)
    {
        // if the character has not been paired
        if (find(paired.begin(), paired.end(), i) == paired.end())
        {
            // if the character has not been seen before
            if (st.empty()) st.push(i);
            // if the character has been seen before
            else
            {
                // if the character can be paired with the top of the stack
                if (s[st.top()] == s[i])
                {
                    paired.push_back(st.top());
                    paired.push_back(i);
                    st.pop();
                }
                // if the character cannot be paired with the top of the stack
                else st.push(i);
            }
        }
    }
    // using a vector to store the characters that have not been paired
    vector<int> unpaired;
    while (!st.empty())
    {
        unpaired.push_back(st.top());
        st.pop();
    }

    // return the longest palindrome
    string palindrome = "";
    for (int i = 0; i < paired.size(); i++) palindrome += s[paired[i]];
    if (unpaired.size() > 0)
    {
        int max = 0;
        for (int i = 0; i < unpaired.size(); i++)
        {
            int count = 1;
            for (int j = i+1; j < unpaired.size(); j++)
                if (s[unpaired[i]] == s[unpaired[j]]) count++;
            if (count > max) max = count;
        }
        for (int i = 0; i < max; i++) palindrome += s[unpaired[0]];
    }
    return palindrome;
}

int main()
{
    string s;
    cin >> s;
    cout << maxLengthPalindrome(s);
    return 0;
}