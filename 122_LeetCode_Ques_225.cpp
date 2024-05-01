// Leet-Code : Q.No => 225 => Implement STack Using Queue => 1st May


    //  stack + queue stl 


    // 1.******* Using C++ *******  
    class MyStack {
public:
    queue<int> q; // Using a queue to implement the stack

    MyStack() {
        
    }
    
    void push(int x) 
    {
        q.push(x); // Push the element onto the queue
        
        // Reorder the queue so that the newly added element becomes the front
        for(int i = 0; i < q.size() - 1; i++) 
        {
            int front = q.front();  // Store the front element
            q.pop();    // Remove the front element
            q.push(front);  // Push the front element to the back
        }    
    }
    
    int pop() 
    {
        int top = q.front();    // Get the top element of the stack
        q.pop();     // Remove the top element
        return top;     // Return the top element    
    }
    
    int top() 
    {
        return q.front(); // Get the top element of the stack without removing it    
    }
    
    bool empty() 
    {
        return q.empty(); // Check if the stack is empty    
    }
};

     





    // 2.******* Using Java *******  

    class MyStack {

    Queue<Integer> q;    

    public MyStack() 
    {
        q = new LinkedList<>();    
    }
    
    public void push(int x) 
    {
        q.add(x);

        for(int i=0;i<q.size()-1;i++)
        {
            int front = q.poll();
            q.add(front);   
        }

    }
    
    public int pop() 
    {
        return q.poll();    
    }
    
    public int top() 
    {
        return q.peek();    
    }
    
    public boolean empty() 
    {
        return q.isEmpty();        
    }
}


