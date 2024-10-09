class Solution {
public:
    string longestPalindrome(string s) {
      int n=s.length();
      
      if(n==0) return "";
      
      int start=0;
      int maxLen=1;
      for(int i=0;i<n;i++){
        //Odd length palindrome
        int right=i,left=i;
        while(left>=0 && right<n && s[right]==s[left]){
            if(right-left+1>maxLen){
                start=left;
                maxLen=right-left+1;
            }

            left--;
            right++;
        }

        //even length palindrome
        left=i,right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxLen){
                start=left;
                maxLen=right-left+1;
            }
            left--;
            right++;
        }
      }  


      return s.substr(start,maxLen);
    }
};