class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>ans(cars.size(),-1);
        stack<int>st;
        for(int i=cars.size()-1;i>=0;i--){
            
            // removimg the idex of car which is faster then current car , 
            while(!st.empty() && cars[i][1]<=cars[st.top()][1]){
                st.pop();
            }
            // yha tk phoche mtlb ,stack ke top pr koi smaller speed waala car h 

            while(!st.empty()){// yha pr*******bhot bhar mistake kiye h 
                /// hm stack me see dekh rhe h ki wh uska col time se kyuki jo ans hoskta tha usse hi rkha h 
                double time= (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1 || ans[st.top()] >=  time ){
                    ans[i]=time;
                    break;

                }
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
        
        
        
    }
};