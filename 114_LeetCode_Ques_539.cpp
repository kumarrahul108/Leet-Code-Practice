// Leet-Code : Q.No => 539 => Minimum Time Difference => 26th April


    // string + array + sorting


    // 1.******* Using C++ *******   

    // Function to convert time in the format "hh:mm" to minutes
    int convertToMin(string &time)
    {
        // Extract hours and minutes from the time string
        int hr = stoi(time.substr(0,2));   // Extracting hours
        int min = stoi(time.substr(3,2));  // Extracting minutes

        // Calculate total minutes
        int totalMinutes = (60 * hr) + min;
        return totalMinutes;
    }


    // Function to find the minimum time difference among time points
    int findMinDifference(vector<string>& timePoints) 
    {
        // Vector to store converted times in minutes
        vector<int> mins;
        
        // Convert each time point to minutes and store in 'mins'
        for(auto time : timePoints)
        {
            mins.push_back(convertToMin(time));
        }

        // Sort the times in ascending order
        sort(mins.begin(),mins.end());
        
        // Initialize the minimum difference to maximum integer value
        int ans = INT_MAX;

        // Calculate the difference between consecutive times and find the minimum difference
        // Iterate through the sorted times to find the minimum difference
            // between consecutive times
            for(int i = 0; i < mins.size() - 1; i++)
            {
                ans = min(ans, mins[i + 1] - mins[i]);
            }

            // Calculate the difference between the last and first times to handle circular time
            // (e.g., difference between 23:59 and 00:00)
            int lastdiff = mins[0] + 1440 - mins[mins.size() - 1]; // 1440 minutes = 24 hours
            ans = min(ans, lastdiff);

            return ans;
        }



/*
This calculation ensures that we handle cases where the time difference spans midnight correctly. 
For example, if the earliest time is 23:50 and the latest time is 00:10, the difference should be 20 minutes, not -1430 minutes. 
Adding 1440 minutes accounts for this and provides the correct difference.   */







    // 2.******* Using Java *******   

    public int convertToMin(String time)
    {
        int hr = Integer.parseInt(time.substring(0,2));
        int min = Integer.parseInt(time.substring(3,5));

        int totalMinutes = (60 * hr) + min;
        return totalMinutes;
    }    

    public int findMinDifference(List<String> timePoints) 
    {
        List<Integer> mins = new ArrayList<>();

        for(String time : timePoints)
        {
            mins.add(convertToMin(time));
        }

        Collections.sort(mins);
        int ans = Integer.MAX_VALUE;

        for(int i=0;i<mins.size()-1;i++)
        {
            ans = Math.min(ans,mins.get(i+1) - mins.get(i));
        }

        int lastdiff = mins.get(0) + 1440 - mins.get(mins.size() - 1);
        ans = Math.min(ans,lastdiff);

        return ans;
    }
