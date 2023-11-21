#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // Added for math functions
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

typedef long long ll;
const int mod = 1000000007;

#define deb(x) cerr << #x << " is " << x << endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    int i = 1;

    while (!nodes.empty() && i < values.size()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (values[i] != -1) { // Change NULL to -1 (assuming -1 represents a null node)
            current->left = new TreeNode(values[i]);
            nodes.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) { // Change NULL to -1
            current->right = new TreeNode(values[i]);
            nodes.push(current->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    inorderTraversal(node->left);
    std::cout << node->val << " ";
    inorderTraversal(node->right);
}

bool findNode(TreeNode* root, int target) {
    if (root == nullptr) {
        return false; // Node not found
    }

    if (root->val == target) {
        return true; // The target node is found
    }

    // Search in the left or right subtree
    return findNode(root->left, target) || findNode(root->right, target);
}

ll findSol(TreeNode* root, int target) {
    if (root == nullptr) {
        return 0;
    }

    if (root->val == target) {
        return root->val;
    }

    ll leftSum = findSol(root->left, target);
    ll rightSum = findSol(root->right, target);

    if (leftSum > 0 || rightSum > 0) {
        return leftSum + rightSum + root->val;
    } else {
        return 0;
    }
}

ll solution(ll n){
    ll sum = 0;
    while (n){
        sum += n;
        n=n/2;    
        //cout<<sum<<endl; 
    }
    //cout<<sum<<endl;
    //sum=sum/10;
    return sum;

}

int main() {
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("solution.txt", "w", stdout);
    #endif

    int numCases;
    cin >> numCases;

    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        ll n;
        cin >> n;

        if (2000 < n) {
            std::cout << solution(n) << std::endl;
        } else {
            std::vector<int> input;
            for (ll i = 1; i <= n; i++) {
                input.push_back(i);
            }

            TreeNode* root = buildTree(input);

            ll targetValue = n;
            ll ancestorSum = findSol(root, targetValue);

            if (ancestorSum > 0) {
                std::cout << ancestorSum << std::endl;
            } else {
                std::cout << "Node " << targetValue << " is not found in the tree." << std::endl;
            }

            delete root;
        }
    }
//mip
    return 0;
}
