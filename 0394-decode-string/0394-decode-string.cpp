class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<string>st;
        for(char ch:s){
            if(ch ==']'){
                string top="";
        
                string SubString="";
                while(!st.empty() && st.top()!="["){
                    SubString+=st.top();
                    st.pop();


                }
                st.pop();// ] yh bch gya hoga 
                string number="";
                while(!st.empty() && isdigit(st.top()[0])){// yha pr hm bhot bari mistake kiye h, like digit ke bdle 
                // pura no chekc ho rha tha :-123 ko kese chekck kro ge digit me not a single no 
                    number+=st.top();
                    st.pop();
                    // aak or cheese st.top()[0] dekho na ki stoi use kro 


                }
                reverse(number.begin(), number.end());
                int no=stoi(number);
                string sub="";
                for(int i =0;i<no;i++){
                    sub+=SubString;

                }
                st.push(sub);
            }
            else {
                string str="";
                str+=ch;
                
                st.push(str);
            }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;



        
    }
};