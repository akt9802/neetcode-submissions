class Solution {
public:
    bool isValid(string s) {
        // stack question 
        stack<char>st;
        for(auto ch:s){
            if(ch == '(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                char temp = st.top();
                if((temp=='(' && ch!=')') || (temp=='{' && ch!='}') || (temp=='[' && ch!=']')){
                    return false;
                }
                st.pop();
            }
        }
        // edge case
        if(st.size() > 0){
            return false;
        }
        return true;
    }
};
