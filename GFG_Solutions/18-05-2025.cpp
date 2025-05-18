//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    return new Node(val);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution
{
private:
    void spiralForm(Node *root, vector<int> &result)
    {
        queue<pair<int, Node *>> q;
        q.push({0, root}); // Start with level 0

        map<int, vector<int>> levels;

        while (!q.empty())
        {
            pair<int, Node *> current = q.front();
            q.pop();

            int level = current.first;
            Node *node = current.second;

            levels[level].push_back(node->data);

            if (node->left)
            {
                q.push({level + 1, node->left});
            }

            if (node->right)
            {
                q.push({level + 1, node->right});
            }
        }

        // Add values to result in spiral order
        for (auto it : levels)
        {
            int level = it.first;
            vector<int> nodes = it.second;

            if (level % 2 == 0)
            {
                reverse(nodes.begin(), nodes.end()); // Reverse even levels
            }

            for (int val : nodes)
            {
                result.push_back(val);
            }
        }
    }

public:
    vector<int> findSpiral(Node *root)
    {
        // code here
        vector<int> arr;
        if (!root)
            return arr;
        spiralForm(root, arr);
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends