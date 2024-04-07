// Leet-Code : Q.No => 1249 => Minimum Remove to Make Valid Parentheses => 6th April 2024 


    //   stack + string stl 


    // 1.******* Using C++ *******


    // ** approach - 1  ** 
    string minRemoveToMakeValid(string s) 
    {
        int leftCount = 0;
        int rightCount = 0;
        stack<char> stack;

        // Pass 1
        for (char ch : s) 
        {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                stack.push(ch);
            }
        }

        string result = "";
        
        // Pass 2
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }

        // Reverse the result string
        reverse(result.begin(), result.end());
        return result;   
    }


    // ** approach - 2 **

    string minRemoveToMakeValid(string s) 
    {
        // Initialize counters for open and close parentheses, and a flag to track valid pairs
        int open = 0, close = 0, flag = 0;

        // First pass: Count the number of open and close parentheses and check for valid pairs
        for(char c : s)
        {
            if(c == '(')
            {
                open++;  // Increment open counter
                flag++;  // Increment flag for valid pair
            }
            else if(c == ')' && flag > 0)  // If it's a close parenthesis and there's a valid pair
            {
                close++;  // Increment close counter
                flag--;   // Decrement flag as pair is consumed
            }
        }  

        // Calculate the number of parentheses to keep (minimum of open and close)
        int k = min(open, close);

        // Initialize an empty string to store the result
        string ans = "";

        // Reset open and close counters to the calculated minimum value
        open = k;
        close = k;

        // Second pass: Reconstruct the string with only the necessary parentheses
        for(char c : s)
        {
            if(c == '(')
            {
                if(open > 0)  // If there are remaining open parentheses to keep
                {
                    ans += '(';  // Add '(' to the result
                    open--;     // Decrement open counter
                }
                continue;  // Move to the next character
            }

            if(c == ')')
            {
                if(close > 0 && close > open)  // If there are remaining close parentheses to keep
                {
                    ans += ')';  // Add ')' to the result
                    close--;     // Decrement close counter
                }
                continue;  // Move to the next character
            }
            else 
            {
                ans += c;  // Add non-parentheses characters to the result
            }
        }

        return ans;  // Return the final result
    } 






    // 2.******* Using Java *******

    public String minRemoveToMakeValid(String s) 
    {
        // Initialize a stack to keep track of the indices of '(' characters
        Stack<Integer> st = new Stack<>();

        // First pass: Iterate through the string to find valid pairs of parentheses
        for (int i = 0; i < s.length(); i++) 
        {
            if (s.charAt(i) == '(') 
            {
                // If '(' is encountered, push its index onto the stack
                st.push(i);
            }
            else if (s.charAt(i) == ')') 
            {
                // If ')' is encountered
                if (!st.isEmpty() && s.charAt(st.peek()) == '(') 
                {
                    // If the stack is not empty and the top of the stack corresponds to '('
                    // Pop the '(' index from the stack as it forms a valid pair with the current ')'
                    st.pop();
                } 
                else 
                {
                    // Otherwise, push the index of the current ')' onto the stack
                    st.push(i);
                }
            } 
            else 
            {
                // Ignore characters other than '(' and ')'
                continue;
            }
        }

        // Initialize a StringBuilder to construct the result string
        StringBuilder sb = new StringBuilder();

        // Second pass: Reconstruct the string by removing invalid parentheses
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            if (!st.isEmpty() && st.peek() == i) 
            {
                // If the current index corresponds to an invalid '(' or ')', skip it
                // by popping it from the stack and continue to the next character
                st.pop();
                continue;
            } 
            else 
            {
                // Otherwise, append the character at index 'i' to the result StringBuilder
                sb.append(s.charAt(i));
            }
        }

        // Reverse the result StringBuilder and convert it to a string before returning
        return sb.reverse().toString();
    }

    