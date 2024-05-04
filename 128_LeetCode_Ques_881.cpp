// Leet-Code : Q.No => 881 => Boats to Save People => 4th May


    //  sorting + 2 pointer + array


    // 1.******* Using C++ *******  


    int numRescueBoats(vector<int>& people, int limit) 
    {
        // Sort the array in non-decreasing order
        sort(people.begin(), people.end());

        // Initialize two pointers
        int start = 0; // Pointer for the lightest person
        int end = people.size() - 1; // Pointer for the heaviest person
        int boats = 0; // Counter to count the number of boats needed

        // Loop until the pointers meet or cross each other
        while (start <= end) 
        {
            // Check if the weight of the lightest and heaviest person can fit in one boat
            if (people[start] + people[end] <= limit) 
            {
                start++; // Move the pointer for the lightest person to the next person
            }

            end--; // Move the pointer for the heaviest person to the previous person
            boats++; // Increment the number of boats needed
        }

        return boats; // Return the total number of boats needed
    }






    // 2.******* Using Java *******  

    public int numRescueBoats(int[] people, int limit) 
    {
        // sort
        Arrays.sort(people);

        // create 2 pointer 
        int start = 0;
        int end = people.length - 1;
        int noOfBoats = 0;

        // traverse the array 
        while(start <= end)
        {
            if(people[start] + people[end] <= limit)
            {
                start++;
            }

            end--;
            noOfBoats++;
        }

        return noOfBoats;   
    }
