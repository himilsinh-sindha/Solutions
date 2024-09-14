class Solution {
public:
    int myAtoi(string s) {
        int result=0;
        int sign=1;
        int i=0;

        while(i<s.size() && isspace(s[i])) i++;

        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            int digit = s[i]-'0';

            if(result>(INT_MAX-digit)/10){
                return sign==1?INT_MAX:INT_MIN;
            }
            i++;
            result = result * 10 + digit;
        }
    
        return (result*sign);
    }
};