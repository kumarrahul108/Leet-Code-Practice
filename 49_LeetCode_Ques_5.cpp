// Leet-Code : Q.No => 5 => Longest Palindromic Substring  =>  -> 17th March 2024 


    // string + 2-pointer 


    // 1.******* Using C++ *******


    bool isPalindrome(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }


    string longestPalindrome(string s) 
    {
        string ans = "";

        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPalindrome(s,i,j))
                {
                    string t = s.substr(i,j-i+1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }

        return ans;
    }





    // 2.******* Using Java *******

     public boolean isPalindrome(String s, int start , int end)
    {
        while(start < end)
        {
            if(s.charAt(start) != s.charAt(end))
            {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }


    public String longestPalindrome(String s) 
    {
        String ans = "";

        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(isPalindrome(s,i,j))
                {
                    String t = s.substring(i,j+1);
                    ans = t.length() > ans.length() ? t : ans;
                }
            }
        } 
        return ans;   
    }


