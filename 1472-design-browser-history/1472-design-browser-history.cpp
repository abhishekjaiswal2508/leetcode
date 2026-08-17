class BrowserHistory {
public:
    stack<string>browser,fwd;
    BrowserHistory(string homepage) {
        browser.push(homepage);
        
    }
    
    void visit(string url) {
        //visit kiya mtb fwd history end;
        while(!fwd.empty()){
            fwd.pop();
        }
        browser.push(url);
        

        
    }
    
    string back(int steps) {
        while(steps--){
            if(browser.size()>1){
                fwd.push(browser.top());
                browser.pop();
                
            }
            else{
                break;
            }
        }
        return browser.top();
        
    }
    
    string forward(int steps) {
        while(steps-- && !fwd.empty()){
            browser.push(fwd.top());
            fwd.pop();
        }
        return browser.top();
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */