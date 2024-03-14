// Leet-Code : Q.No => 1047 => Remove All Adjacent Duplicates In String =>  -> 14th March 2024 


    //  using new string 


    // 1.******* Using C++ *******

    // 2 pontier type 
    string removeDuplicates(string s) 
    {
        string ans = "";
        int index = 0;

        while(index < s.length())
        {
            // same 
            // ans ka rightmost charcter & string ka curent char compare
            if(ans.length() > 0  && s[index] == ans[ans.length()-1])
            {
                // pop from ans string 
                ans.pop_back();
            }
            else 
            {
                // push 
                ans.push_back(s[index]);
            }
            index++;
        } 
        return ans;   
    }



    // *** using stack **** 

    string removeDuplicates(string s) 
    {
        int n = s.size();
        stack<char> st;

        /*
        for(int i=0;i<n;i++)
        {
            if(st.empty()) 
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.top() == s[i])
                {
                    st.pop();
                }
                else 
                {
                    st.push(s[i]);
                }
            }   
        }  
        */

        // more optimised way 
        for(char ch : s)
        {
            if(!st.empty()  &&  st.top() == ch)
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }

        string ans = "";
        while(!st.empty()) 
        {
            ans = st.top() + ans;  // reverse order  me store 
            st.pop();
        } 

        return ans;
    }

 


    // 2.******* Using Java *******

    public String removeDuplicates(String s) 
    {
        StringBuilder ans = new StringBuilder();
        int index = 0;

        while (index < s.length()) 
        {
            // Check if ans is not empty and the current character equals the last character in ans
            if (ans.length() > 0 && s.charAt(index) == ans.charAt(ans.length() - 1)) 
            {
                // Remove the last character from ans
                ans.deleteCharAt(ans.length() - 1);
            } 
            else 
            {
                // Append the current character to ans
                ans.append(s.charAt(index));
            }
            index++;
        }
        return ans.toString();    
    }


