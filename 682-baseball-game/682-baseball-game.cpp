class Solution {
public:
    int calPoints(vector<string>& ops) {
        // a vector to store all integers
        vector<int> sol;
        int n = ops.size();

        // iterating through all operations
        for (int i = 0; i < n; i++)
        {
            if (ops[i] == "D")
                sol.push_back(2 * sol.back());
            else if (ops[i] == "C")
                sol.pop_back();
            else if (ops[i] == "+")
                sol.push_back(sol[sol.size() - 1] + sol[sol.size() - 2]);
            else
                sol.push_back(stoi(ops[i]));
        }
        // adding the remaining integers in vector
        //  after performing all the operations
        int sum = 0;
        for (int i : sol)
            sum += i;

        // returning answer as sum
        return sum;
    }
};