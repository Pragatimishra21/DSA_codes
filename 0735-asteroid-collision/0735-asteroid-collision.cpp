class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int> st;
     for(int i=0 ; i<asteroids.size() ; i++)
     {
         if(st.empty() || asteroids[i]>0)
         {
             st.push(asteroids[i]);
         }
         else
         {
             while(!st.empty())
             {
                 int top = st.top();
                 if(top<0)
                 {
                     st.push(asteroids[i]);
                     break;
                 }
                 else
                 {
                    int modVal = abs(asteroids[i]);
                    if(top == modVal)
                    {
                        st.pop();
                        break;
                    } 
                    else if(top > modVal)
                    {
                        break;
                    }
                    else {
                        st.pop();
                        if(st.empty())
                        {
                            st.push(asteroids[i]);
                            break;
                        }
                    }
                 }
             }
         }
     }
     int len = st.size();
     vector<int> ans(len);
     for(int i= len-1 ; i>=0 ; i--)
     {
         ans[i] = st.top();
         st.pop();
     }
     return ans;
    }
};