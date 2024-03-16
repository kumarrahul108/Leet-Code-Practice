// Leet-Code : Q.No => 1910 => Remove All Occurrences of a Substring  -> 16th March 2024 


    // string stl functions 


    // 1.******* Using C++ ******* 

    string removeOccurrences(string s, string part) 
    {
        while(s.find(part) != string :: npos)
        {
            // if inside this loop , part exist in loop
            s.erase(s.find(part),part.length());
        } 
        return s;   
    }


    // 2. **** Using Java ******* 

    public String removeOccurrences(String s, String part) 
    {
        StringBuilder sb = new StringBuilder(s);
        while(sb.indexOf(part) != -1)
        {
            int idx = sb.indexOf(part);
            sb.delete(idx,idx+part.length());  
        }    

        return sb.toString();  // conver string builder into string
    }