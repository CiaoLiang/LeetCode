class Stack {
private:
    queue<int>temp;
public:
    // Push element x onto stack.
    void push(int x) {
        temp.push(x);
    }

    // Removes the element on top of the stack.
    void pop(void) {
       int len = temp.size();
       while(len>1){
           int n = temp.front();
           temp.pop();
           temp.push(n);
           len -- ;
       }
       temp.pop();
    }

    // Get the top element.
    int top(void) {
        int len = temp.size();
        while(len>1){
            int n = temp.front();
            temp.pop();
            temp.push(n);
            len -- ;
        }
        int ret = temp.front();
        temp.pop();
        temp.push(ret);
        return ret;
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return temp.empty();
    }
};