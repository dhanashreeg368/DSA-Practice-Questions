class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;                            // created the stack for stroing the Folder names
        string ans ="";                              // it will store the final ans
        
        for(int i=0;i<path.size();i++)               // iterate over the whole given string
        {
            // if it is a backslash then just ignore it because it is not the Folder name
            if(path[i]=='/')
                continue;
            
            // if it is not / then try to store our Folder name till we do not find next /
            // store the Folder name in temp string
            string temp = "";
            while(i<path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            
            // after storing the Folder
            // just check the symbols 
            
            // ignoring .
            if(temp==".")
                continue;
            
            // if it is '..' move to previous Folder 
            else if(temp=="..")
            {
                // according to our given condition 
                // if it is '..' move to previous Folder
                if(!st.empty())
                    st.pop();
            }
            
            else
            {
                // else store our all Folder names into the stack
                st.push(temp);
            }
        }
        
        // store the Folder names from stack to the ans string 
        // in given firmat "/Folder_name"
        while(!st.empty())
        {
            ans = "/" + st.top() + ans;            // just following the format
            st.pop();
        }
        
        // if there is empty string 
        if(ans.size() == 0)
            return "/";
        
        return ans;
    }
};