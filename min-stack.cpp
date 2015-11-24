class MinStack {
public:
    void push(int x) {
        data.push(x);
        if(min.size()==0)
            min.push(x);
        else
        {
            if(x<min.top())
            {
                min.push(x);
            }
            else if(x>=min.top())
                min.push(min.top());
        }
    }

    void pop() {
        data.pop();
        min.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min; 
};