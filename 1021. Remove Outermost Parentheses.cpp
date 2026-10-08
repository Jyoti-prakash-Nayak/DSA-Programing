class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string str;
        int count1=0;
        int count2=0;

        for(auto ch:s){
            if(ch=='('){
                count1++;
                if(count1>1){
                    str+=ch;
                }
            }else if(ch==')'){
                count2++;
                if(count2<count1){
                    str+=ch;
                }
            }

            if(count1==count2){
                count1=0;
                count2=0;
            }
        }
        return str;
    }
};