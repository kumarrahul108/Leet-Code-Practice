// Leet-Code : Q.No => 8 => String to Integer (atoi)  =>  -> 17th March 2024 


    // string + int ka range 


    // 1.******* Using C++ *******

    int myAtoi(string s) 
    {
        int num  = 0 , i = 0 , sign = 1;

        // space condition 
        while(s[i] == ' ')
        {
            i++;
        }       

        // sign -> condition 
        if(i < s.size()  &&  (s[i] == '-' || s[i] == '+'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }  

        // non-digit -> condition 
        while(i < s.size()  &&  isdigit(s[i]))
        {
            // INT_MAX  &  INT_MIN -> condition 
            if(num > INT_MAX/10  ||  (num == INT_MAX/10  &&  s[i] > '7'))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            // create number
            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num*sign;
    }






    // 2.******* Using Java *******


    public int myAtoi(String s) 
    {
        int num  = 0;
        int i = 0;
        int sign = 1;

        // space -> condition 
        while(i < s.length()  &&  s.charAt(i) == ' ')
        {
            i++;
        }

        // sign -> condition 
        if(i < s.length()  &&  (s.charAt(i) == '-'  ||  s.charAt(i) == '+'))
        {
            sign = s.charAt(i) == '+' ? 1 : -1;
            i++;
        }

        // non-digit -> condition 
        while(i < s.length()  &&  Character.isDigit(s.charAt(i)))
        {
            // Check for overflow
            if (num > Integer.MAX_VALUE / 10 || (num == Integer.MAX_VALUE / 10 && s.charAt(i) - '0' > 7)) 
            {
                return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }

            // Create number
            num = num * 10 + (s.charAt(i) - '0');
            i++;
        }

        return num * sign;
    }