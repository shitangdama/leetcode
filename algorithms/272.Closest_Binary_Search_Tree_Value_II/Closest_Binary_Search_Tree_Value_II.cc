<<<<<<< HEAD
/*
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 */
class Solution {
  public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
      priority_queue<pair<double, int>> pq;
      closestK(root, pq, target, k);
      vector<int> closest;
      while (!pq.empty())
	closest.push_back(pq.top().second), pq.pop();
      return closest;
    }
  private:
    void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq, double target, int k) {
      if (!node) return;
      pq.push(make_pair(abs(target - node -> val), node -> val));
      if (pq.size() > k) pq.pop();
      closestK(node -> left, pq, target, k);
      closestK(node -> right, pq, target, k);
    }
=======
/*
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 */
class Solution {
  public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
      priority_queue<pair<double, int>> pq;
      closestK(root, pq, target, k);
      vector<int> closest;
      while (!pq.empty())
	closest.push_back(pq.top().second), pq.pop();
      return closest;
    }
  private:
    void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq, double target, int k) {
      if (!node) return;
      pq.push(make_pair(abs(target - node -> val), node -> val));
      if (pq.size() > k) pq.pop();
      closestK(node -> left, pq, target, k);
      closestK(node -> right, pq, target, k);
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};