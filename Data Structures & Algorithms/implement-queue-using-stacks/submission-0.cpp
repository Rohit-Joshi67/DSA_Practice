class MyQueue {

    private :

    stack<int>input;
    stack<int>output;

    void transfer(){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
        
    }
    
    int pop() {
        if(output.empty())
        transfer();

        int ans= output.top();
        output.pop();
        return ans;
        
    }
    
    int peek() {
        if(output.empty()) {
            transfer();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */