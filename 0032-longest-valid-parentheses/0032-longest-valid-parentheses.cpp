class Solution {
public:
    int longestValidParentheses(string s) {
        // simple sa logic h :-- stack me -1 push kro , aagr ) aaya too pop kro or dekho ki empty h ki nhi 
        // agr empty  h mtlb invalid h just uska index push kr do , wrna leng nikalo or max update kro , 
        // baki normal waale ko sidha index push kro 
        stack<int>st;
        int maxi=INT_MIN;
        st.push(-1);
        for(int i =0;i<s.size();i++){
            if(s[i]==')' && !st.empty() ){
                st.pop();
                if(!st.empty()){ 
                    int len=i-st.top();
                    maxi=max(len,maxi);

                }
                else{
                    
                    st.push(i);

                }
                
            }
            else{
                st.push(i);
            }

            

        }
        return maxi==INT_MIN?0:maxi;

        
    }
};