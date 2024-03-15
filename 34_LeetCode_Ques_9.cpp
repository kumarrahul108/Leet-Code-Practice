// Leet-Code : Q.No => 9 => Palindrome Number =>  -> 15th March 2024 


    // 1.******* Using C++ *******

    bool isPalindrome(int x) 
    {
        // base case -> -ve no 
        if(x < 0)
        {
            return false;
        }

        // Store the original number before reversing
        long num = x;  // to store original no bxc after loop x != original value given -> valuye is lost
        long ans = 0;
        while(x)
        {
            int digit = x % 10;  // Extract the last digit of x
            ans = ans * 10 + digit;  // Build the reversed number
            x = x / 10;   // Move to the next digit
        }

        // Check if the reversed number equals the original number
        return (ans == num);
    }


    // 2. **** Using Java **** 

    public boolean isPalindrome(int x) 
    {
        if(x < 0)
        {
            return false;
        }

        long num = x;
        long ans = 0;

        while(x != 0)
        {
            int digit = x % 10;
            ans = ans * 10 + digit;
            x = x/ 10;
        }

        return (num == ans);
    }
