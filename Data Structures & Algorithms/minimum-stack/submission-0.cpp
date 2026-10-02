class MinStack {
    vector<int> minSt, st;
    int minElement;
public:
    MinStack() {
        minElement = INT_MAX;
    }
    
    void push(int val) {
        st.push_back(val);
        minElement = min(minElement, val);
        minSt.push_back(minElement);
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
        minElement = getMin();
    }
    
    int top() {
        if(st.size()==0)
            return INT_MAX;
        return st[st.size()-1];
    }
    
    int getMin() {
        if(st.size()==0)
            return INT_MAX;
        return minSt[st.size()-1];
    }
};
