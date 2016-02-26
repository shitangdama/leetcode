#!/usr/bin/python
# -*- coding: utf-8 -*-
# Author:      illuz <iilluzen[at]gmail.com>
# File:        AC_simulation_n.py
# Create Date: 2015-02-22 10:37:20
# Usage:       AC_simulation_n.py 
# Descripton:  The same as vesion I


class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        header = TreeNode(0)
        header.next = root
        while header.next:
            cur = header.next
            prev = header
            header.next = None
            while cur:
                if cur.left:
                    prev.next = cur.left
                    prev = prev.next
                if cur.right:
                    prev.next = cur.right
                    prev = prev.next
                cur = cur.next
# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    def _connect(self, prev, curt):
        if prev is not None:
            prev.next = curt
        
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        
        parent = root
        root.next = None
        while parent is not None:
            last, first = None, None
            while parent is not None:
                for node in [parent.left, parent.right]:
                    if node is None:
                        continue
                    self._connect(last, node)
                    if last is None:
                        first = node
                    last = node
                parent = parent.next
            parent = first
