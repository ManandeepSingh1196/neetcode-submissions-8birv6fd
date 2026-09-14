class MinStack {
private: 
    stack<int> stck;
    vector<int> m;
public:
    MinStack() {}
    
    void push(int val) 
    {       
        if      (m.empty())             m.emplace_back(val);
        else if (val <= m[m.size() - 1]) m.emplace_back(val);

        stck.emplace(val);
    }
    
    void pop() 
    {
        if (stck.top() == m[m.size() - 1]) m.pop_back();
        stck.pop();
    }
    
    int top() 
    {
        return stck.top();    
    }
    
    int getMin() 
    {
        return m[m.size() - 1];    
    }
};
