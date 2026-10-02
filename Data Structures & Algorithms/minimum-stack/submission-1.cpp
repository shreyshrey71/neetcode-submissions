class MinStack {
    vector<int> minSt, st;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        minSt.push_back(min(val, (minSt.size() == 0) ? INT_MAX : minSt[minSt.size() - 1]));
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
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
