// Leet-Code : Q.No => 155 => Min Stack => 14th April 2024 


    //  Pair craetion + its insertation  + vector


    // 1.******* Using C++ *******

    vector<pair<int,int>> st;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(st.empty())
        {
            pair<int,int> p;
            p.first = val;
            p.second = val;

            st.push_back(p);
        }    
        else 
        {
            pair<int,int> p;
            p.first = val;

            int puranaMin = st.back().second;
            p.second = min(puranaMin,val);
            st.push_back(p);
        }
    }
    
    void pop() 
    {
        st.pop_back();    
    }
    
    int top() 
    {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first;    
    }
    
    int getMin() 
    {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second;      
    }






    // 2.******* Using Java *******


    List<Pair<Integer,Integer>> st;

    public MinStack() 
    {
        st = new ArrayList<>();    
    }
    
    public void push(int val) 
    {
        if(st.isEmpty())
        {
            st.add(new Pair<>(val,val));
        }    
        else 
        {
            int prevMin = st.get(st.size() - 1).getValue();
            st.add(new Pair<>(val,Math.min(prevMin,val)));
        }
    }
    
    public void pop() 
    {
        st.remove(st.size() - 1);    
    }
    
    public int top() 
    {
        return st.get(st.size() - 1).getKey();    
    }
    
    public int getMin() 
    {
        return st.get(st.size() - 1).getValue();    
    }