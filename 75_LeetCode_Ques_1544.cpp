// Leet-Code : Q.No => 1544 => Make The String Great => 5th April 2024 


    //    string stl + stack concept


    // 1.******* Using C++ *******

     string makeGood(string s) 
    {
        // Initialize a stack to store characters
        stack<char> st;
        
        // Iterate through each character in the string
        for(char c: s)
        {
            // If the stack is not empty and the current character and the top of the stack form a pair,
            // where one is uppercase and the other is lowercase of the same letter, remove the pair.
            if(!st.empty() && abs(c - st.top()) == 32)
            {
                st.pop();  // Remove the top character from the stack
            }
            else 
            {
                st.push(c);   // Otherwise, push the current character onto the stack
            }
        }

        // Construct the result string by popping characters from the stack
        string ans;

        /*
        while(!st.empty())
        {
            // Add the characters from the stack to the beginning of the result string
            ans = st.top() + ans;
            st.pop();
        }
        */

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }






    // 2.******* Using Java *******


    class Solution {
    public String makeGood(String s) 
    {
        Stack<Character> st = new Stack<>();

        for(char ch : s.toCharArray())
        {
            if(!st.isEmpty() && Math.abs(ch - st.peek()) == 32)
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }

        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty())
        {
            ans.insert(0,st.peek());
            st.pop();
        }

        return ans.toString();

    }
}

/*
== 32: This part checks if the absolute difference between the ASCII values of the characters is exactly 32. 
The value 32 represents the difference between uppercase and lowercase letters in ASCII encoding. 
For example, the ASCII value of 'A' is 65 and the ASCII value of 'a' is 97. 
The absolute difference between them is 32.
*/