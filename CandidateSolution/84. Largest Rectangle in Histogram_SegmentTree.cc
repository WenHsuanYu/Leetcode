//using segment tree method
//time complexity: O(nlogn)
//space complexity: O(n)
#define mid(a, b) ((a) + (((b) - (a)) >> 1))

class SegmentTree {
public:
    int start, end, min;
    SegmentTree *left;
    SegmentTree *right;
    //node
    SegmentTree (int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        SegmentTree *root = create(heights, 0, heights.size() - 1);
        return maxArea_partSegment(heights, 0, heights.size() - 1, root);
    }
    
    
    SegmentTree* create(vector<int>& heights, int start, int end) {
        if (start > end)
            return NULL;
        SegmentTree *root = new SegmentTree(start, end);
        
        if (start == end) {
            root->min = start;
            return root;
        } else {
            int middle = mid(start, end);
            root->left = create(heights, start, middle);
            root->right = create(heights, middle + 1, end);
            root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
            return root;
            
        }
        
    }
    
    int query(vector<int> &heights, int start, int end, SegmentTree *root) {
        if (!root || end < root->start || start > root->end) {
            return -1;
        }
        
        if (start <= root->start && end >= root->end) {
            return root->min;
        }
        
        int leftMin = query(heights, start, end, root->left);
        int rightMin = query(heights, start, end, root->right);
        
        if (leftMin == -1)
            return rightMin;
        if (rightMin == -1)
            return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
        
    }
    
    int maxArea_partSegment(vector<int> &heights, int start, int end, SegmentTree *root) {
        if (start > end) {
            return -1;
        }
        if (start == end) {
            return heights[start];
        }
        
        int wholeMin = query(heights, start, end, root);
        return max({heights[wholeMin] * (end - start + 1), maxArea_partSegment(heights, start, wholeMin - 1, root), maxArea_partSegment(heights, wholeMin + 1, end, root)});
    }
    
    
};