class MinStack {
private:
    vector<int> s;
    stack<int> mins;
public:
    MinStack() {}
    
    void push(int val) {
        s.push_back(val);
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        } else {
            mins.push(mins.top());
        }
    }
    
    void pop() {
        s.pop_back();
        mins.pop();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return mins.top();
    }
};