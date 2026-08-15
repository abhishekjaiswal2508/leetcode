class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        
        for(int i=0;i<path.size();i++){
            int s=i;
            int e=s+1;
            // end ko bdaate jaao jb tk / naa mill jaye 
            while(e<path.size() && path[e]!='/'){
                e++;
            }
            string subs=path.substr(s,e-s);
            i=e-1;
            if(subs=="/" || subs=="/."){
                continue;
            }
            else if(subs=="/.."){
                if(!st.empty()){
                    st.pop();

                } 
            }
            else{
                cout<<subs<<" ";
                reverse(subs.begin(),subs.end());

                st.push(subs);
            }
        }
        string ans=st.empty() ? "/": "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};