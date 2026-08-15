class Solution {
public:
    string removeKdigits(string num, int k) {
        // yha pr jo jo digit stack ke ander chota h wh usse pop krdo 
        stack<char>st;
        if(k==num.size()){
            return"0";
        }
        for(int i =0;i<num.size();i++){
            while(!st.empty() && (k>0) && (num[i]<st.top())){
                st.pop();
                k--;
                
            }
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(ans.back()=='0' && ans.size()!=1){//**** kyuki yh char h isspe dyaan do ki char se compare kr rhe h 
            ans.pop_back();
        }
    
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};