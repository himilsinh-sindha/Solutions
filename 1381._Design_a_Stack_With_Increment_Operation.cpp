class CustomStack {
public:
    vector<int> st;     // Stack storage
    vector<int> inc;    // Increment storage
    int top;            // Stack top pointer

    CustomStack(int maxSize) {
        st.resize(maxSize);        // Resize to maxSize
        inc.resize(maxSize, 0);    // Initialize increments array
        top = -1;                  // Initialize top pointer to -1
    }
    
    void push(int x) {
        if (top < (int)st.size() - 1) { // If stack is not full
            top++;
            st[top] = x;           // Push the element onto the stack
        }
    }
    

    int pop() {
        if (top == -1) return -1;  // If stack is empty, return -1
        
        int res = st[top] + inc[top];  // Add the increment to the element
        if (top > 0) {
            inc[top - 1] += inc[top];  // Pass the increment down to the next element
        } 

        inc[top] = 0;   // Reset the increment for the popped element
        top--;          // Decrease the top pointer
        return res;
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);  // We can only increment up to the current number of elements
        if (limit > 0) {
            inc[limit - 1] += val;    // Add the increment value to the k-th element (zero-indexed)
        }
    }
};
