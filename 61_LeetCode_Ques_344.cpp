// Leet-Code : Q.No => 344 => Reverse STring => 28th March 2024 


    //  using stack + 2 pointer approach  


    // 1.******* Using C++ *******


    // A. ******* 2 pointer approach ************
    void reverseString(vector<char>& s) 
    {
        // Initialize start index to the beginning of the vector.
        int start = 0;

        // Initialize end index to the last element of the vector.
        int end = s.size() - 1;

        // Loop until start index is less than end index.
        while (start < end)
        {
            // Swap characters at start and end indices.
            swap(s[start], s[end]);
            // Move start index to the right.
            start++;
            // Move end index to the left.
            end--;
        }    
    }



    // B. ************** using stack approach ************ 
    void reverseString(vector<char>& s) 
    {
        // Create a stack to store characters
        stack<char> charStack;

        // Push each character of the vector onto the stack
        for (char c : s) 
        {
            charStack.push(c);
        }

        // Pop characters from the stack and update the vector
        for (int i = 0; i < s.size(); i++) 
        {
            s[i] = charStack.top(); // Assign the top element of the stack to the vector
            charStack.pop(); // Pop the top element from the stack
        }
    }





     // 2.******* Using Java *******


    // A. ******* 2 pointer approach ************

    void reverseString(vector<char>& s) 
    {
        // Create a stack to store characters
        stack<char> charStack;

        // Push each character of the vector onto the stack
        for (char c : s) 
        {
            charStack.push(c);
        }

        // Pop characters from the stack and update the vector
        for (int i = 0; i < s.size(); i++) 
        {
            s[i] = charStack.top(); // Assign the top element of the stack to the vector
            charStack.pop(); // Pop the top element from the stack
        }
    }



    // B. ************** using stack approach ************ 

    public void reverseString(char[] s) 
    {
        Stack<Character> st = new Stack<>();

        for(char ch : s)
        {
            st.push(ch);
        }

        for(int i=0;i<s.length;i++)
        {
            s[i] = st.peek();
            st.pop();
        }

    }