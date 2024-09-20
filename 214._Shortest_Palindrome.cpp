class Solution {
public:
    string shortestPalindrome(string s) {
        // i have used KMP algorithm for string matching (Prefix-suffix method)
        // logic : just find the longest prefix which is also a suffix and then just add the remaining characters at the start of original string.

        string original = s; 
        string t = s;
        reverse(s.begin(),s.end());
        t += "#" + s;  // new string = original + # + reversed_original

        vector<int> lps(t.size(),0); // lps array to track the longest lenght of prefix found

        for(int i=1;i<t.size();i++){
            int j = lps[i-1];

            while(j>0 && t[i]!=t[j]){
                j = lps[j-1];
            }

            if(t[i]==t[j]) j++;
            lps[i]=j;
        }

        int len = lps.back(); // last index will have the largest length of prefix found;

        string remain = s.substr(0,s.size()-len);

        return remain+original;
    }
};