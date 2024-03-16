// Leet-Code : Q.No => 2391 =>  Minimum Amount of Time to Collect Garbage -> 16th March 2024 


    // array + string  


    // 1.******* Using C++ *******

    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        // pick time 
        int pickP = 0;       
        int pickM = 0;       
        int pickG = 0;

        // travel time 
        int travelG = 0;       
        int travelM = 0;       
        int travelP = 0;   

        // last index of each 
        int lastP = 0;    
        int lastG = 0;    
        int lastM = 0;


        // Calculate pick time for each type of garbage
        for(int i=0;i<garbage.size();i++)
        {
            string curr = garbage[i];

            for(int j=0;j<curr.length();j++)
            {
                char ch = curr[j];

                // Count occurrences and update the last index
                if(ch == 'P')
                {
                    pickP++;
                    lastP = i;
                }
                else if(ch == 'M')
                {
                    pickM++;
                    lastM = i;
                }
                else if(ch == 'G')
                {
                    pickG++;
                    lastG = i;
                }
            }
        }

         // Calculate travel time up to the last index of each type of garbage 
        for(int i=0;i<lastP;i++)
        {
            travelP += travel[i];
        }

        for(int i=0;i<lastG;i++)
        {
            travelG += travel[i];
        }

        for(int i=0;i<lastM;i++)
        {
            travelM += travel[i];
        }

        // Calculate total time for garbage collection and travel
        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);

        return ans;  // Return the total time
    }





    // 2.******* Using Java *******

    public int garbageCollection(String[] garbage, int[] travel) 
    {
        // pick time 
        int pickG = 0, pickM = 0, pickP = 0;   

        // travel time 
        int travelP = 0, travelG = 0 , travelM = 0; 

        // last index  
        int lastP = 0, lastG = 0, lastM = 0;

        // pick time calculation 
        for(int i=0;i<garbage.length;i++)
        {
            String curr = garbage[i];

            for(int j=0;j<curr.length();j++)
            {
                char ch = curr.charAt(j);

                if(ch == 'P')
                {
                    pickP++;
                    lastP = i;
                }
                else if(ch == 'G')
                {
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M')
                {
                    pickM++;
                    lastM = i;
                }
            }
        }

        // travel time calculkation 
        for(int i=0;i<lastP;i++)
        {
            travelP += travel[i];
        }

        for(int i=0;i<lastG;i++)
        {
            travelG += travel[i];
        }

        for(int i=0;i<lastM;i++)
        {
            travelM += travel[i];
        }

        int ans = (travelP + pickP) + (travelM + pickM) + (travelG + pickG);

        return ans;
    }


