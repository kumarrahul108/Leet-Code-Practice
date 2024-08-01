
// Leet-Code : Q.No => 2678 => Number of Senior Citizens => 1 August



// 1.******* Using C++ ******* 


// *** Approach - 1 **** 

class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int senior = 0;
        for(string info : details) 
        {
            char tens = info[11];
            char ones = info[12];

            if(tens > '6' || (tens == '6' && ones > '0'))
            {
                senior++;
            }
        }   

        return senior; 
    }
};     



// *** Approach - 2 **** 

class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int seniorCount = 0;
        for(auto x : details) 
        {
            int age = stoi(x.substr(11,2));
            seniorCount += age > 60;
        }    

        return seniorCount;
    }
};




// 2.******* Using Java ******* 

class Solution {
    public int countSeniors(String[] details) 
    {
        int seniorCount = 0;
        for(String x : details)
        {
            int age = Integer.parseInt(x.substring(11,13));
            if(age > 60)
            {
                seniorCount++;
            } 
        }    

        return seniorCount;
    }
}