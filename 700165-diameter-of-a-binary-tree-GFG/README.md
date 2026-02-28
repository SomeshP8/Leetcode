# [Diameter of a Binary Tree](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)
## Medium
Given the root of a binary tree, your task is to find the diameter of the binary tree.
The diameter (also called the width) of a binary tree is defined as the number of edges on the longest path between any two leaf nodes. Note that this path may or may not pass through the root of the tree.
Examples:
Input: root = [1, 2, 3]
Output: 2Explanation: The longest path has 2 edges (node 2 -&gt; node 1 -&gt; node 3).
Input: root[] = [5, 8, 6, 3, 7, 9]
Output: 4Explanation: The longest path has 4 edges (node 3 -&gt; node 8 -&gt; node 5 -&gt; node 6 -&gt; node 9).
Constraints:1 ≤ number of nodes ≤ 1030 ≤ node-&gt;data ≤ 105