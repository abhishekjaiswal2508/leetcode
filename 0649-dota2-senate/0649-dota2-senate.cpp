class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;
        int i=0;
        for(;i<senate.size();i++){
            if(senate[i]=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }

        }
        while(!r.empty() && !d.empty()){
            int rIndex=r.front();
            int dIndex=d.front();
            r.pop();
            d.pop();
            if(rIndex < dIndex){// yha doo bar pop kr diye the hm 
                r.push(i++);
            }
            else{
                d.push(i++);
            }
        }
        

        return !r.empty()?"Radiant":"Dire";


        
    }
};