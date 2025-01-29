//simple MinStack implementation using two trackers currentMin and prevMin to track status of stack.

class MinStack {
public:
    std::unique_ptr<int[]> arr; //dynamically allocated array
    int current; // current size of the stack
    int capacity; //capacity of the stakc
    int currentMin;
    int prevMin;
    MinStack() : arr(std::make_unique<int[]>(10)), current(0),capacity(10),prevMin(0),currentMin(0){
    }
    
    void push(int val) {
        prevMin = currentMin;
        if(current == 0){
            arr[current] = val;
            currentMin = arr[current];
        }
        else{
        currentMin = arr[current-1] > val ? val : arr[current-1];
        arr[current] = val;
        }
        ++current;
    }
    
    void pop() {
        if(currentMin == arr[current])
        {
            currentMin = prevMin;
        }
        arr[current] = 0;
        current--;
    }
    
    int top() {
        return current;
    }
    
    int getMin() {
        return currentMin;
    }

};
