struct Node {
    int val;
    Node *previous;
    int minVal;
};

class MinStack {

private:
    Node *currentNode = nullptr;
    
public:

    MinStack() {}
    
    void push(int val) {
        Node *newNode = new Node();
        newNode->val = val;
        newNode->previous = currentNode;
        newNode->minVal = (currentNode == nullptr) ? val : min(val, currentNode->minVal);
        currentNode = newNode;
    }
    
    void pop() {
        if (currentNode == nullptr) return;
        Node *currentNodeAddr = currentNode;
        currentNode = currentNode->previous;
        delete currentNodeAddr;
    }
    
    int top() {
        if (currentNode != nullptr) {
            return currentNode->val;
        }
        return -1;
    }
    
    int getMin() {
        if (currentNode != nullptr) {
            return currentNode->minVal;
        }
        return -1;
    }
};
