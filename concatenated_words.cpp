class Solution
{
public:
    bool isConcatenated(string word, unordered_set<string> &st)
    {
        int size = word.size();

        for (int i = 0; i < size; i++)
        {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if ((st.find(prefix) != st.end() && isConcatenated(suffix, st)) ||
                (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
            {
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> st(begin(words), end(words));

        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            if (isConcatenated(word, st))
                ans.push_back(word);
        }
        return ans;
    }
};