class Solution {
public:
    bool isValid(string s) {
        std::stack<char> checked;
        for ( char c : s){
            if( c == '(' || c == '{' || c == '['){
                checked.push(c);
                continue;
            }
            if(c == ')' || c == '}' || c == ']'){
                if(checked.empty()) return false;
                if(c == ')' && checked.top() == '('){
                    checked.pop();
                    continue;
                }
                if(c == '}' && checked.top() == '{'){
                    checked.pop();
                    continue;
                }
                if(c == ']' && checked.top() == '['){
                    checked.pop();
                    continue;
                }
                return false;
            }

        }
        return checked.empty();

    }
};
