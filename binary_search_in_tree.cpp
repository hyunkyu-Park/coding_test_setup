#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int low,int high){
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = helper(nums, low, mid-1);
            root->right = helper(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
};

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    return 0;
}