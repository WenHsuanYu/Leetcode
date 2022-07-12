// Using linked list node with smart pointer method
// TC: O(1)
// SC: O(n)
struct Element {
    int val;
    int minimum;
    shared_ptr<Element> next;
    Element(int value, int mini, shared_ptr<Element> next): val(value), minimum(mini), next(next) 
    {
        
    }
    ~Element() {
        
    }
        
};


class MinStack {
public:
    shared_ptr<Element> head = nullptr;
    MinStack() {
        
    }
    
    void push(int val) {
        if (!head) {
            head = make_shared<Element>(val, val, nullptr);
        } else {
            head = make_shared<Element>(val, min(val, head->minimum), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */