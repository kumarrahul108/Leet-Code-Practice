    // Leet-Code : Q.No => 7 => Reverse Integer  -> 28th Feb 2024 


    // 1. Using C++ 

    int reverse(int x) 
    {
        bool isNegative = false;   // flag 
        int reverse = 0;   // to store final answer

        // lower out of bound 
        if( x <= INT_MIN)
        {
            return 0;
        }

        // handling -ve numbers
        if(x < 0)
        {
            isNegative = true; 
            x = -x;
        }
        
        // reversing our number 
        while(x)
        {
            // upper out of bound
            if(reverse > INT_MAX/10)     // int max ke 2nd last digit pe rook jaoo
            {
                return 0;
            }

            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x/10;
        }

        return isNegative ? (-1)*reverse : reverse;
    }



    // 2. Using Java 

     public int reverse(int x) 
     {
        boolean isNegative = false;
        int reverse = 0;

        // lower out of bound
        if (x <= Integer.MIN_VALUE) 
        {
            return 0;
        }

        // handling negative numbers
        if (x < 0) 
        {
            isNegative = true;
            x = -x;
        }

        // reversing the number
        while (x > 0) 
        {
            // upper out of bound
            if (reverse > Integer.MAX_VALUE / 10) 
            {
                return 0;
            }

            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x / 10;
        }

        return isNegative ? (-1) * reverse : reverse;
    }


