// Leet-Code : Q.No => 1209 => Remove All Adjacent Duplicates in String II => 29th April


    // 2 pointer approach + stacks


    // 1.******* Using C++ *******   


    // ** 2 pointer ****

    string removeDuplicates(string s, int k) 
    {
        int i = 0, j = 0;
        vector<int> count(s.size()); // Vector to store the count of consecutive characters
        
        while (j < s.size()) 
        {
            s[i] = s[j]; // Copy character at position j to position i
            count[i] = 1; // Initialize count at position i to 1
            
            if (i > 0 && s[i] == s[i - 1]) 
            {
                count[i] += count[i - 1]; // If the current character is the same as the previous one, update count
            }

            if (count[i] == k) 
            {
                i = i - k; // If count reaches k, move i back by k positions to effectively remove duplicates
            }

            i++; // Move to the next position
            j++; // Move to the next character
        }

        return s.substr(0, i); // Return the substring from s[0] to s[i-1]
    }




    // *** stack *** 

    string removeDuplicates(string s, int k) 
    {
        int n = s.size();

        if(n < k)
        {
            return s;
        }                   

        stack<pair<char,int>> st;

        for(int i=0;i<n;i++)
        {
            if(st.empty() || st.top().first !=  s[i])
            {
                st.push({s[i],1});
            }
            else 
            {
                auto prev = st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }

            if(st.top().second == k)
            {
                st.pop();
            }
        }


        string ans = "";
        while(!st.empty())
        {
            auto curr = st.top();
            st.pop();
            while(curr.second--)
            {
                ans.push_back(curr.first);
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }





    // 2.******* Using Java ******* 


    public String removeDuplicates(String s, int k) 
    {
        int i =0 , j = 0;
        int count[] = new int[s.length()];

        char chars[] = s.toCharArray();

        while(j < s.length())
        {
            chars[i] = chars[j];
            count[i] = 1;

            if(i > 0 && chars[i] == chars[i-1])
            {
                count[i] += count[i-1];
            }

            if(count[i] == k)
            {
                i = i- k;
            }

            i++;
            j++;
        }  

        return new String(Arrays.copyOf(chars,i));      
    }   