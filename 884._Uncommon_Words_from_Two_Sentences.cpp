class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string temp = "";
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                m[temp]++;
                temp = "";
            } else {
                temp += s1[i];
            }
        }

        m[temp]++;
        temp = "";

        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                m[temp]++;
                temp = "";
            } else {
                temp += s2[i];
            }
        }

        m[temp]++;
        temp = "";

        vector<string> ans;
        for (auto i : m) {
            if (i.second == 1)
                ans.push_back(i.first);
        }

        return ans;
    }
};