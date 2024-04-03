// Leet-Code : Q.No => 113 => Path Sum - II => 3rd April 2024 


    //   dfs + tree 


    // 1.******* Using C++ *******

     // Recursive function to find all paths in the binary tree with the target sum
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, int sum, vector<int> temp)
    {
        // Base case: If the current node is NULL, return 
        if(root == NULL)
        {
            return;
        }

        // Update the current sum with the value of the current node
        sum += root->val;

        // Add the value of the current node to the temporary path
        temp.push_back(root->val);

        // If the current node is a leaf node and the sum equals the target sum, add the path to the result
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == sum)
            {
                ans.push_back(temp);
            }
        }

        // Recursively traverse the left and right subtrees
        solve(root->left,targetSum,ans,sum,temp);
        solve(root->right,targetSum,ans,sum,temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;  // Vector to store the result paths
        vector<int> temp;       // Temporary vector to store the current path
        int sum  = 0;            // Variable to store the current sum

        // Call the recursive function to find all paths with the target sum
        solve(root, targetSum, ans , sum , temp);

        // Return the result paths
        return ans;        
    }





    // 2.******* Using Java *******


    class Solution {
    public void solve(TreeNode root, int targetSum, List<Integer> temp, List<List<Integer>> path, int sum)
    {
        // base casec 
        if(root == null)
        {
            return;
        }

        // 1-case solve karo
        sum += root.val;
        temp.add(root.val);

        if(root.left == null && root.right == null)
        {
            if(targetSum == sum)
            {
                path.add(new ArrayList<>(temp));
            }
        }

        // recurssion 
        solve(root.left,targetSum,new ArrayList<>(temp),path,sum);
        solve(root.right,targetSum,new ArrayList<>(temp),path,sum);        
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) 
    {
        List<List<Integer>> path = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        int sum = 0;

        solve(root,targetSum,temp,path,sum);

        return path;
    }
}

/*
In Java, when you add an object to a collection,
 you're actually adding a reference to that object. 
 So, if you directly add temp to ans, you'll be adding a reference to the same temp list each time, 
 and when you modify temp in subsequent iterations of your recursive function, 
 you'll also be modifying the elements stored in ans.
*/

