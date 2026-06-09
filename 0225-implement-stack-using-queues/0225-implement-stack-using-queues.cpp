class MyStack {
public:
    queue<int>q;
    int s=q.size();
    MyStack() {
       
    }
    
    void push(int x) {
  
        q.push(x);
        for(int i=0;i<s;i++){
           q.push(q.front());
           q.pop(); 
        }
        s++;
    }
    
    int pop() {
       int r=q.front();
       q.pop();
       s--;
       return r; 
    }
    
    int top() {
       return q.front(); 
    }
    
    bool empty() {
       bool ok=false;
       if(s==0){
         ok=true;
       } 
       return ok;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */