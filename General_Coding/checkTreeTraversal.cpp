/*
1. Check Tree Traversal 
Hard Accuracy: 62.2% Submissions: 1895 Points: 8
Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Example 1:

Input:
N = 5
preorder[] = {1, 2, 4, 5, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 5, 2, 3, 1}

5
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1


Output: Yes
Explanation: 
All of the above three traversals 
are of the same tree.
           1
         /   \
        2     3
      /   \
     4     5
Example 2:

Input:
N = 5
preorder[] = {1, 5, 4, 2, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 1, 2, 3, 5}
Output: No
Explanation: The three traversals can 
not be of the same tree.

Your Task:
You don't need to read input or print anything. 
Complete the function checktree() which takes the array preorder[ ], inorder[ ], postorder[ ]
and integer N as input parameters and returns true if the three traversals are of the same tree or not. 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 103

Topic Tags
 Recursion Tree

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void postorder(int pre[], int in[], int l, int h, int &i, vector<int> &v, bool &x)
    {
        if (l > h || !x)
            return;
        int key = pre[i++], k;
        for (k = 0; k <= h; k++)
        {
            if (in[k] == key)
                break;
        }
        if (k == h + 1)
        {
            x = false;
            return;
        }
        postorder(pre, in, l, k - 1, i, v, x);
        postorder(pre, in, k + 1, h, i, v, x);
        v.push_back(key);
    }

    bool checktree(int pre[], int in[], int post[], int len)
    {
        vector<int> v;
        int i = 0;
        bool x = true;
        postorder(pre, in, 0, len - 1, i, v, x);
        if (x == false)
            return false;
        x = true;
        for (i = 0; i < len && i < v.size(); i++)
        {
            if (v[i] != post[i])
            {
                x = false;
                break;
            }
        }
        return x;
    }
};

int main()
{

    int n;
    cin >> n;
    int preorder[n];
    int inorder[n];
    int postorder[n];

    for (int i = 0; i < n; ++i)
        cin >> preorder[i];

    for (int i = 0; i < n; ++i)
        cin >> inorder[i];

    for (int i = 0; i < n; ++i)
        cin >> postorder[i];

    Solution obj;
    if (obj.checktree(preorder, inorder, postorder, n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}