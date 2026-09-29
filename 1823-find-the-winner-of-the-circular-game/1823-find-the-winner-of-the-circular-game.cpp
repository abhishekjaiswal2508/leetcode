class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int count = 0;
        for(int i = 1;i <= n;i++){
            q.push(i);
        }
        while(q.size() != 1){
            count++;
            if(count == k){
                q.pop();
                count = 0;
            }
            else{
                int x = q.front();
                q.push(x);
                q.pop();
            }
            

        }
        return q.front();

        
    }
};