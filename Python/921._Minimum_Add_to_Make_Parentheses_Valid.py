class Solution(object):
    def minAddToMakeValid(self, s):
        stack = [] 
        count = 0 

        for ch in s : 
            if ch == '(' : 
                stack.append('(')
            else : 
                if stack : 
                    stack.pop()
                else : 
                    count += 1
        
        count += len(stack)
        return count 


        