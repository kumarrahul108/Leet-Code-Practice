// Leet-Code : Q.No => 20 => Valid Parenthesis => 29th March 2024 


    //  using stacks    


    // 1.******* Using C++ *******


    // ***** approaxh - 1 ********
    bool isValid(string s) 
    {
        // Initialize a stack to store opening brackets
        stack<char> st;

        // Iterate through each character in the string
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];   // Get the current character

            // If the character is an opening bracket, push it onto the stack
            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            // If the character is a closing bracket
            else 
            {
                // Check if the stack is not empty
                if(!st.empty())
                {
                    // Compare the current closing bracket with the top of the stack
                    if(ch == ')' && st.top() == '(')
                    {
                        st.pop();   // If they match, pop the corresponding opening bracket
                    }
                    else if(ch == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else 
                    {
                        return false;   // If there is no matching opening bracket in the stack, return false
                    }
                }
                else 
                {
                    return false;
                }
            }
        }  

        // If the stack is empty, all brackets are matched and valid
        if(st.empty())
        {
            return true;
        }      

        return false;   // If stack is not empty, return false
    }



    // ***** approaxh - 2 ********

    bool isValid(string s) 
    {
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else 
            {
                if(!st.empty())
                {
                    if( (ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '['))
                    {
                        st.pop();
                    }
                    else 
                    {
                        return false;
                    }
                }
                else 
                {
                    return false;
                }
            }
        } 

        if(!st.empty())
        {
            return false;
        }   

        return true;
    }




    // 2.******* Using Java *******


    public boolean isValid(String s) 
    {
        Stack<Character> st = new Stack<>();

        for(int i=0;i<s.length();i++)
        {
            char ch = s.charAt(i);

            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.add(ch);
            }
            else 
            {
                if(!st.isEmpty())
                {
                    if( (ch == ')' && st.peek() == '(') || (ch == '}' && st.peek() == '{') || (ch == ']' && st.peek() == '['))
                    {
                        st.pop();
                    }
                    else 
                    {
                        return false;
                    }
                }
                else 
                {
                    return false;
                }
            }
        }

        if(st.isEmpty())
        {
            return true;
        }

        return false;
    }


