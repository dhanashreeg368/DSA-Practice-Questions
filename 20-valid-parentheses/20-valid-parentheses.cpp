class Solution {
public:
    bool isValid(string s) {
      stack<char> st; //declare stack
      for (int i=0;i<s.size();i++)
      {
          if (s[i]=='(' || s[i]=='[' || s[i]=='{')
          {
              st.push(s[i]); //push
          }
          else if (s[i]==')')
          {
              if (st.empty()) 
              {
                  return false;
              }
              if (st.top()!='(')
              {
                  return false;
              }
              st.pop();
          }
          else if (s[i]==']')
          {
              if (st.empty())
              {
                  return false;
              }
              if (st.top()!='[')
              {
                  return false;
              }
              st.pop();
          }
          else
          {
              if (st.empty())
              {
                  return false;
              }
              if (st.top()!='{')
              {
                  return false;
              }
              st.pop();
          }
      }
      return st.empty();
    }
};