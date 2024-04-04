// Leet-Code : Q.No => 1614 => Maximum Nesting Depth of the Parentheses => 4th April 2024 


    //   string + stack 


    // 1.******* Using C++ *******


    // **** A. Using Stack ***** 
    int maxDepth(string s) 
    {
        stack<char> st;

        int depth = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                st.push(c);
                if(depth < st.size())
                {
                    depth = st.size();
                }
            }
            else if(c == ')')
            {
                st.pop();
            }
        }  

        return depth;  
    }



    // **** B. Using String *****

    int maxDepth(string s) 
    {
        // Initialize a counter to keep track of the current depth
        int count = 0;

        // Initialize a variable to store the maximum depth encountered
        int max_num = 0;

        // Iterate through each character in the string
        for (char c : s) 
        {
            // If the current character is an opening parenthesis '('
            if (c == '(') 
            {
                count++;

                // Update the maximum depth encountered if necessary
                if (max_num < count)
                {
                    max_num = count;
                }
            } 
            // If the current character is a closing parenthesis ')'
            else if (c == ')') 
            {
                // Decrement the counter to indicate exiting nesting
                count--;
            }
        }

        // Return the maximum depth encountered
        return max_num;    
    }





    // 2.******* Using Java *******

    public int maxDepth(String s) 
    {
        int count = 0;
        int maxi = 0;

        for(char c : s.toCharArray()) 
        {
            if(c == '(')
            {
                count++;

                if(count > maxi)
                {
                    maxi = count;
                }
            }
            else if(c == ')')
            {
                count--;
            }
        }   

        return maxi;
    }