class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stack2.empty()){
            stack2.pop();
        }
        else{
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            stack2.pop();
        }
        
    }

    // Get the front element.
    int peek(void) {
         if(!stack2.empty()){
            return stack2.top();
        }
        else{
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            return stack2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty()&&stack2.empty();
    }
};