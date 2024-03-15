// Leet-Code : Q.No => 1209 => Remove All Adjacent Duplicates In String =>  -> 14th March 2024 


    //   Using stack 


    // 1.******* Using C++ *******

    // Shows-> T.L.E -> correct solution 
    string removeDuplicates(string s, int k) 
    {
        int count = 1;   // Initialize count of consecutive occurrences of a character
        int index = 1;  // Initialize index to iterate through the string
        
        // Iterate through the string
        for(int i=1;i<s.length();i++)
        {
            char curr = s[index];   // Current character being considered
            
            // Check if the current character is the same as the previous character
            if(curr == s[index-1])
            {
                count++;
            }
            else 
            {
                count = 1;  // Reset count if characters are different
            }

            // If the count reaches 'k', remove the 'k' adjacent duplicates
            if(count == k)
            {
                // Construct the modified string by removing 'k' adjacent duplicates
                string str = s.substr(0,i-k+1) + s.substr(i+1);
                
                // Recursively call removeDuplicates with the modified string
                return removeDuplicates(str,k);      
            }
            index++;   // Move to the next character
        } 
        return s;   // If no adjacent duplicates occur 'k' times, return the original string
    }



    // *** using Stack *** 

    string removeDuplicates(string s, int k) 
    {
        int n = s.size();

        // If the length of the string is less than k, no duplicates to remove    
        if(n < k)
        {
            return s;
        }

        // Stack to keep track of characters and their frequencies
        stack<pair<char,int>> st;

        // Iterate through the string
        for(int i=0;i<n;i++)
        {
            // If the stack is empty or the current character is different from the top of the stack
            if(st.empty() || st.top().first !=  s[i])
            {
                // Push the current character with frequency 1 onto the stack
                st.push({s[i],1});
            }
            else 
            {
                // Increment the frequency of the top character in the stack
                auto prev = st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }

            // If the frequency of the top character in the stack becomes k, pop it
            if(st.top().second == k)
            {
                st.pop();
            }
        }

        // Reconstruct the string from the characters remaining in the stack
        string ans = "";
        while(!st.empty())
        {
            auto curr = st.top();
            st.pop();
            // Append the character to the answer string 'curr.second' times
            // This loop repeats the process of appending the character 'curr.first'
            // to the answer string, 'curr.second' times.
            while(curr.second--)
            {
                ans.push_back(curr.first);
            }
        }

        // Reverse the answer string and return
        reverse(ans.begin(),ans.end());

        cout << ans;

        return ans;
    }



    // ***** 2. Using Java *****

    


