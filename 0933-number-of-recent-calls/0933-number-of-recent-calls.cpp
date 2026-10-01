class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        int left = t - 3000;
        int right = t;
        if(left > q.front()){
            while(left > q.front()){
                q.pop();
            }
           
        }
       return q.size();


        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */