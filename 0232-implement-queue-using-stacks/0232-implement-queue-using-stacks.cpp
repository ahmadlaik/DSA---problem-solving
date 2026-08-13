class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
    }

    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Insert new element
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int value = s1.top();
        s1.pop();
        return value;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};