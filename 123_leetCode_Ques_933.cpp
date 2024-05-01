// Leet-Code : Q.No => 933 => Number of Recent Calls  => 1st May


    //  queue stl 


    // 1.******* Using C++ *******  


// *** approach - 1  ****  
    class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) 
    {
        int lower = t - 3000;

        while(!q.empty() && lower > q.front())
        {
            q.pop();
        }   

        q.push(t); 

        return q.size();
    }
};
     


// *** approach - 2 *** 
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }
    
    int ping(int t) 
    {
        // 1. 
        q.push(t);

        // 2. 
        while(!q.empty() && q.front() < (t - 3000))
        {
            q.pop();
        }       

        return q.size();
    }
};



    // 2.******* Using Java *******  

    class RecentCounter {
    Queue<Integer> q;

    public RecentCounter() 
    {
        q = new LinkedList<>();    
    }
    
    public int ping(int t) 
    {
        int lower = t - 3000;    

        while(!q.isEmpty() && lower > q.peek())
        {
            q.remove();
        }

        q.add(t);

        return q.size();
    }
}


