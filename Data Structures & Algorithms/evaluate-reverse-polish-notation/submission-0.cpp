class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto token : tokens){
            if (token == "+"){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();                
                int sum = num2 + num1;
                s.push(sum);
            } 
            else if (token == "-"){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();            
                int res = num2 - num1;
                s.push(res);
            }
            else if (token == "*"){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                int res = num2 * num1;
                s.push(res);
            }
            else if (token == "/"){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                int res = num2/num1;
                s.push(res);
            }
            else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
