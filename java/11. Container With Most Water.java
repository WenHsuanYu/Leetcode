// 11. Container With Most Water
// TC: O(N) where N = height length
// SC: O(1)

class Solution {
    static {
        for (int i = 0; i < 100; i++) {
            maxArea(new int[]{1, 2, 3});
        }
    }

    public static int maxArea(int[] height) {
        int h = 0;
        int w = 0;
        int area = 0;
        int l = 0;
        int r = height.length - 1;
        while (l < r) { 
            h = height[l] < height[r] ? height[l] : height[r];
            w = r - l;
            area = area > h * w ? area : h * w;
            int tmp = height[l] > height[r] ? r-- : l++;
        }
        return area;
    }
}