class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> st;
        
        function<set<string>(int&)> solve = [&](int &i) {
            set<string> result, current = {""};

            while (i < expression.size() && expression[i] != '}') {
                if (expression[i] == ',') {
                    result.insert(current.begin(), current.end());
                    current = {""};
                    i++;
                }
                else if (expression[i] == '{') {
                    i++;
                    set<string> inside = solve(i);
                    i++;

                    set<string> temp;

                    for (string a : current)
                        for (string b : inside)
                            temp.insert(a + b);

                    current = temp;
                }
                else {
                    char c = expression[i++];
                    set<string> temp;

                    for (string x : current)
                        temp.insert(x + c);

                    current = temp;
                }
            }

            result.insert(current.begin(), current.end());
            return result;
        };

        int i = 0;
        set<string> ans = solve(i);

        return vector<string>(ans.begin(), ans.end());
    }
};