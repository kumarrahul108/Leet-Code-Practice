
  // Leet-Code : Q.No => 2469 => Convert the Temperature -> 29th Feb 2024 


  // 1. Using C++ 

    vector<double> convertTemperature(double celsius) 
    {
        vector<double> ans;
        double kel = celsius + 273.15;
        double far = celsius * 1.80 + 32.00;  

        ans.push_back(kel);
        ans.push_back(far);

        return ans;
    }



  // 2. Using Java     

    public double[] convertTemperature(double celsius) 
    {
        // double[] ans = new double[2];    // both waya -> syntax differenec 
        double ans[] = new double[2];


        double kel = celsius + 273.15;
        double far = celsius * 1.80 + 32.00; 

        ans[0] = kel;
        ans[1] = far;

        return ans;
    }   
