class Solution {
public:
    void next(vector<int>&arr, vector<int>&nxt){
        stack<int>st;
        st.push(0);
        for(int i=1;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nxt[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i =0;i<arr.size();i++){
            if(nxt[i]==-1){ //nxt se compare hoga naa ki arr se 
                nxt[i]=arr.size();
            }
        }
        return ;

    }
    void previ(vector<int>&arr, vector<int>&prev){
        stack<int>st;
        st.push(arr.size()-1); // yha pr bhi hm ** 0 push kiye the 
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                prev[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ;

    }
    int maxarea(vector<int>& arr){
        vector<int>nxt(arr.size(),-1);
        vector<int>prev(arr.size(),-1);
        next(arr,nxt);
        previ(arr,prev);
        int maxarea=INT_MIN;
        for(int i=0;i<arr.size();i++){
            int area=(nxt[i]-prev[i]-1)*arr[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>arr;
        
        for(int i=0;i<matrix.size();i++){
            vector<int>temp(matrix[0].size(),1);
            for(int j=0;j<matrix[0].size();j++){
                temp[j]=matrix[i][j]-'0';
            }
            arr.push_back(temp);
        }
        int maxi=maxarea(arr[0]);
        for(int i=1;i<matrix.size();i++){ //yha pr galti ki thi like matrix[0] lee rhe the ***bog mistake
            for(int j=0;j<matrix[0].size();j++){
                
                arr[i][j]=arr[i][j]==0?0:arr[i][j]+arr[i-1][j];
            }
            maxi=max(maxi,maxarea(arr[i]));
        }
        return maxi;
        
    }
};