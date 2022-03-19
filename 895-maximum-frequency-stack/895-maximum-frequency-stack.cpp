class FreqStack {
public:
    stack<int> freqStack;
    map<int,int> m;
    int i = 0;
    priority_queue<pair<pair<int,int>,int>> pq;
    FreqStack() {
        stack<int> freqStack;
    }
    
    void push(int val) {
        freqStack.push(val);
        m[val]++;
        i++;
        pq.push({{m[val], i},val});
    }
    
    int pop() {
        auto it = pq.top();
        pq.pop();
        m[it.second]--;
        return it.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */