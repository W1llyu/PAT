//
// Created by Will Yu on 2019/9/3.
//

#ifndef PAT_BINTREE_H
#define PAT_BINTREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Node {
    int val, level, height;
    Node *left, *right;

    Node(int _val, int _level) {
        val = _val;
        level = _level;
        height = 0;
        left = right = nullptr;
    }

    explicit Node(int _val) {
        val = _val;
        height = level = 0;
        left = right = nullptr;
    }
};
#endif //PAT_BINTREE_H
