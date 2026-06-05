class MinStack {
public:
    MinStack() {
        v = vector<int>{};
        cacheMin = vector<int>{};
    }

    void push(int value) {
        if (cacheMin.empty() || value <= cacheMin[cacheMin.size() - 1]) {
            cacheMin.push_back(value);
        }

        v.push_back(value);
    }

    void pop() {
        if (v.back() == cacheMin[cacheMin.size() - 1]) {
            cacheMin.pop_back();
        }

        v.pop_back();
    }

    int top() { return v[v.size() - 1]; }

    int getMin() { return cacheMin[cacheMin.size() - 1]; }

    vector<int> v;
    vector<int> cacheMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */