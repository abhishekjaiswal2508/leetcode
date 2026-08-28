class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            //coll poss h 
            if(!st.empty() && st.top()>0 && ast<0){
                // -ast h  
                bool check=false;
                while(!st.empty() && st.top()>0 ){
                    
                    if(st.top()< abs(ast)){
                        st.pop();
                    }
                    else if(st.top()> abs(ast)){
                        //stack ke top me bda pra hua h too mt push kro 
                        check=true;
                        break;
                    }
                    else{
                        // hme aak check lgaana prega ki jo loop break hua h wh equal ele 
                        // ki wjh se hua h ki saara delete stack me kr chuka h aab naa bcha h uske liye 
                        st.pop();
                        check=true;
                        break;
                    }
                    
                }
                if(check==false){
                    st.push(ast);
                }
                
            }
           //coll naa hoga 
            else{
                st.push(ast);


            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};