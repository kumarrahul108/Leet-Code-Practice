// Leet-Code : Q.No => 134 => Gas Station => 30th April


    //  Greedy Approach 


    // 1.******* Using C++ *******   


    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int deficit = 0; // Total deficit encountered so far
        int balance = 0; // Current balance of gas
        int start = 0; // Starting index of the potential starting point

        // Traverse through the gas stations
        for (int i = 0; i < gas.size(); i++) 
        {
            // Update the balance by adding gas and subtracting cost
            balance = balance + (gas[i] - cost[i]);

            // If the balance becomes negative, update the deficit and reset the starting point
            if (balance < 0) 
            {
                deficit += abs(balance); // Accumulate the deficit
                start = i + 1; // Update the starting point to the next station
                balance = 0; // Reset the balance
            }
        }

        // Check if the remaining balance after traversing all stations is sufficient to cover the deficit
        if ((balance - deficit) >= 0) 
        {
            return start; // If yes, return the starting point
        }
        else 
        {
            return -1; // If no, return -1 indicating it's impossible to complete the circuit
        }
    }






    // 2.******* Using Java *******  


    public int canCompleteCircuit(int[] gas, int[] cost) 
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for(int i=0;i<gas.length;i++)
        {
            balance += (gas[i] - cost[i]);  

            if(balance < 0)
            {
                deficit += Math.abs(balance);
                start = i + 1;
                balance = 0;
            }
        }

        if(balance - deficit >= 0)
        {
            return start;
        }    
        else 
        {
            return -1;
        }
    }
