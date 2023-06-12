class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0;
        int curr = 0;
        int last = -1;
        stack<int> st;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == '(')
            st.push(i);

            else
            {
                if(!st.empty()){
                st.pop();
                if(!st.empty())
                curr = i- st.top();
                else
                curr = i - last;

                maxi = max(maxi , curr);
                }
                else
                last = i;
            }
        }
        return maxi;
    }
};