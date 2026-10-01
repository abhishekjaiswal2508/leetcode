class Solution {
public:
    queue<int>q;
    vector<int> deckRevealedIncreasing(vector<int>& deck) {  
        //first : array create kro 
        vector<int>ans(deck.size());
        //second : deck ko sort kro 
        sort(deck.begin(), deck.end());

        //third : algo lgaao 
        for(int i = 0;i<deck.size();i++){
            q.push(i);
        }
        for(int i =0;i<deck.size();i++){
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;

        
    }
};