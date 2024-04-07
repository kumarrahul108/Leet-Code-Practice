// Leet-Code : Q.No => 678 => Valid Parenthesis String => 7th April 2024 


    //   stack + string stl 


    // 1.******* Using C++ *******

    bool checkValidString(string s) 
    {
        // Initialize counters for the minimum and maximum number of unpaired '('
        int leftMin = 0, leftMax = 0;

        // Iterate through each character of the string
        for(char c : s)
        {
            if(c == '(')
            {
                // If '(' is encountered, increment both leftMin and leftMax
                leftMin++;
                leftMax++;
            }
            else if(c == ')')
            {
                // If ')' is encountered, decrement both leftMin and leftMax
                leftMin--;
                leftMax--;
            }
            else 
            {
                // If '*' is encountered, it can act as '(' or ')', so update leftMin and leftMax accordingly
                leftMin--;
                leftMax++;
            }

            // If at any point leftMax becomes negative, it indicates excess ')' without matching '('
            // Hence, the string is invalid, so return false
            if(leftMax < 0)
            {
                return false;
            }

            // If leftMin becomes negative, reset it to 0 as '*' can be treated as an empty string
            if(leftMin < 0)
            {
                leftMin = 0;
            }
        }  

        // After processing the entire string, if leftMin is 0, it means all '(' are matched with ')'
        // Otherwise, there are unmatched '(' left, making the string invalid
        return (leftMin == 0);              
    }






    // 2.******* Using Java *******


    public boolean checkValidString(String s) 
    {
        // Initialize two stacks to keep track of indices of '(' and '*' characters
        Stack<Integer> starIndex = new Stack<>();
        Stack<Integer> stackIndex = new Stack<>();

        // Iterate through each character of the string
        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(')
            {
                // If '(' is encountered, push its index onto the stackIndex stack
                stackIndex.push(i);
            }
            else if(s.charAt(i) == '*')
            {
                // If '*' is encountered, push its index onto the starIndex stack
                starIndex.push(i);
            }
            else if(s.charAt(i) == ')')
            {
                // If ')' is encountered
                if(stackIndex.empty() && starIndex.empty())
                {
                    // If both stacks are empty, there's no matching '(' or '*', so return false
                    return false;
                }
                else if(!stackIndex.empty())
                {
                    // If stackIndex is not empty, pop an index from stackIndex as it matches the current ')'
                    stackIndex.pop();
                }
                else 
                {
                    // If stackIndex is empty, pop an index from starIndex as '*' is used to match the current ')'
                    starIndex.pop();
                }
            }   
        }

        // After processing the string, check if there are any remaining unmatched '('
        while(!stackIndex.empty())
        {
            // If starIndex is empty, there's no '*' to match the remaining '('
            // So, return false
            if(starIndex.empty())
            {
                return false;
            }

            // If the index of '(' is greater than the index of '*', it cannot be matched
            // So, return false
            if(stackIndex.peek() > starIndex.peek())
            {
                return false;
            } 

            // Pop indices of both '(' and '*' as they are matched
            stackIndex.pop();
            starIndex.pop();
        }   

        // If all '(' are matched, return true
        return true; 
    }