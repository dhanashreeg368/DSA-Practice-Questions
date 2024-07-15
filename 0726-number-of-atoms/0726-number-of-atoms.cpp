class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();

        // initiate stack
        // stack of pair of (element, atom count)
        stack<pair<string,int>> st;

        int i = 0;
        while(i < n){
            // push open bracket '(' into  stack
            // Reason: in order to check when a particular paranthesis is closed
            // while popping off elements from the stack
            if(s[i] == '('){
                i++;
                st.push({"(", 1});
                // store and move ahead in the string
            } else if(s[i] == ')'){
                // move ahead in the string for the calculation of factor
                i++;

                // calculate factor to be multiplied with elements within paranthesis
                int factor = 0;
                while(i < n and isdigit(s[i])) {
                    // keep counting until you run out of digits in continuation
                    factor = factor * 10 + (s[i++] - '0');
                }
                factor = factor == 0 ? 1 : factor;

                // make a new map to calculate for current paranthesis calculation
                map<string,int> new_map;

                // pop strings out from stack and multiply with factor until you encounter '('
                while(st.top().first != "(") {
                    // calculate the atom counts for each element present in the paranthesis with factor multiplied
                    new_map[st.top().first] += st.top().second * factor;
                    st.pop();
                }
                // pop out '(' from stack
                st.pop();

                // store the elements and their new atoms count into the stack (from the new map)
                for(auto& [str, atoms] : new_map) {
                    st.push({ str, atoms });
                }
            } else {
                // check for individual elements
                // find their uppercase letters, lowercase letters and their count

                // initialize a empty string to contain periodic elements
                string temp;
                
                // we definitely encounter an uppercase at first
                // so store the character into the string 'temp' and move ahead
                temp += s[i++];

                // there is a possibility for a element to contain a lowercase letter
                // so if lower then store in temp and iterate ahead
                if(i < n and islower(s[i])){
                    temp += s[i++];
                }
                // our element is ready now

                // now count the number of atoms it has
                int atoms = 0;
                while(i < n and isdigit(s[i])) {
                    // keep counting until you run out of digits in continuation
                    atoms = atoms * 10 + (s[i++] - '0');
                }

                // push string (periodic element) into stack with its atom count
                st.push({ temp, atoms == 0 ? 1 : atoms });
                // this will be used in factor multiplication if we encounter a closing bracket ')'
            }
        }
        
        // map to store strings in a sorted order
        map<string,int> mp;
        // pop out everything from the stack and start storing the atom counts
        while(!st.empty()) {
            // there can be multiple same elements with their atom counts
            // so make sure to use +=
            mp[st.top().first] += st.top().second;
            st.pop();
        }

        string ans;
        // since we used map in this so elements are already sorted
        // so simply run the loop in the map and store each element with their atom counts
        for(auto& [str, atoms] : mp) {
            ans += str;
            // if atom count is 1 then we don't need to store the count of that element
            // just the element only
            if(atoms != 1) ans += to_string(atoms);
        }

        return ans;
    }
};