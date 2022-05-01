class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stack1=[]
        stack2=[]
        for i in range(len(s)):
            try:
                if s[i]=='#': #if hash remove letter else push
                    stack1.pop()
                else:
                    stack1.append(s[i])
            except:
                continue
        for i in range(len(t)):
            try:
                if t[i]=='#':
                    stack2.pop()
                else:
                    stack2.append(t[i])
            except:
                continue
        if stack1==stack2:
            return True
        else:
            return False
        