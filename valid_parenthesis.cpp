class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        char x;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
                continue;
            }
            // if current char not opening then stack cannot be empty
            if (st.empty())
            {
                return false;
            }
            if (st.top() == 0)
            {
                st.pop();
            }
            switch (s[i])
            {
            case ')':
                x = st.top();
                st.pop();
                if (x == '{' || x == '[')
                {
                    return false;
                }
                break;
            case ']':
                x = st.top();
                st.pop();
                if (x == '(' || x == '{')
                {
                    return false;
                }
                break;
            case '}':
                x = st.top();
                st.pop();
                if (x == '(' || x == '[')
                {
                    return false;
                }
                break;
            case '(':
                x = st.top();
                if (x == '}' || x == '[')
                {
                    return false;
                }
                break;
            }
        }
        return (st.empty());
    }
};
// Time complexity---O(N)
// Space complexity---O(N)