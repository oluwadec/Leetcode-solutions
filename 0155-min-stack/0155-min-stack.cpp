class MinStack {
public:
    MinStack() {}

    void push(int val) {
        int curMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, curMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;  // {value, min so far}
};