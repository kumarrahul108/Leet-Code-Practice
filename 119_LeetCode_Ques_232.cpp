// Leet-Code : Q.No => 232 => Implement Queue using Stacks => 30th April


    //  using stacks implemeny queue + stl function of stacks 


    // 1.******* Using C++ *******   

    
class MyQueue {
public:
    stack<int> s1, s2; // Two stacks for implementing the queue

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x); // Push element into stack s1
    }
    
    int pop() 
    {
        int pop = -1;

        if (!s2.empty()) 
        {
            pop = s2.top(); // If stack s2 is not empty, pop from it
            s2.pop();
        } 
        else 
        {
            // If stack s2 is empty, transfer elements from s1 to s2
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top(); // Pop from stack s2
            s2.pop();
        }
        return pop; // Return the popped element
    }
    
    int peek() 
    {
        int front = -1;

        if (!s2.empty()) 
        {
            front = s2.top(); // If stack s2 is not empty, peek from it
        } 
        else 
        {
            // If stack s2 is empty, transfer elements from s1 to s2
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top(); // Peek from stack s2
        }
        return front; // Return the front element
    }
    
    bool empty() 
    {
        return (s1.empty() && s2.empty()); // Check if both stacks are empty
    }
};




    // 2.******* Using Java *******  


class MyQueue 
{
    // Two stacks for implementing the queue
    private Stack<Integer> s1;
    private Stack<Integer> s2;

    public MyQueue() 
    {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    public void push(int x) 
    {
        s1.push(x); // Push element into stack s1
    }
    
    public int pop() 
    {
        int pop = -1;
        if (!s2.isEmpty()) 
        {
            pop = s2.pop(); // If stack s2 is not empty, pop from it
        } 
        else 
        {
            // If stack s2 is empty, transfer elements from s1 to s2
            while (!s1.isEmpty()) 
            {
                s2.push(s1.pop());
            }

            if (!s2.isEmpty()) 
            {
                pop = s2.pop(); // Pop from stack s2
            }
        }
        return pop; // Return the popped element
    }
    
    public int peek() 
    {
        int front = -1;
        if (!s2.isEmpty()) 
        {
            front = s2.peek(); // If stack s2 is not empty, peek from it
        } 
        else 
        {
            // If stack s2 is empty, transfer elements from s1 to s2
            while (!s1.isEmpty()) 
            {
                s2.push(s1.pop());
            }

            if (!s2.isEmpty()) 
            {
                front = s2.peek(); // Peek from stack s2
            }
        }
        return front; // Return the front element
    }
    
    public boolean empty() 
    {
        return (s1.isEmpty() && s2.isEmpty()); // Check if both stacks are empty
    }
}
