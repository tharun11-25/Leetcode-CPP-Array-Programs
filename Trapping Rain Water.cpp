class Solution {
public:
void nxtGreater(vector<int>& heights, vector<int>& nextGreater) {
        int maxIndex = -1;
        for (int i = heights.size() - 1; i >= 0; i--) {
            int curr = heights[i];
            if (maxIndex!=-1)
                nextGreater[i] = maxIndex;
            if (maxIndex==-1 || heights[maxIndex] < curr)
                maxIndex=i;
        }
    }
    void prvGreater(vector<int>& heights, vector<int>& prevGreater) {
        int maxIndex = -1;
        for (int i = 0; i < heights.size(); i++) {
            int curr = heights[i];
            if (maxIndex!=-1)
                prevGreater[i] = maxIndex;
            if (maxIndex==-1 || heights[maxIndex] < curr)
                maxIndex=i;
        }
    }
    int trap(vector<int>& heights) {
        vector<int> nextGreater(heights.size(), -1); // index
        vector<int> prevGreater(heights.size(), -1); // index
        nxtGreater(heights, nextGreater);
        prvGreater(heights, prevGreater);
        int maxWater = 0;
        for (int i = 0; i < heights.size(); i++) {
            int lMaxHeight =
                (prevGreater[i] == -1) ? 0 : heights[prevGreater[i]];
            int rMaxHeight =
                (nextGreater[i] == -1) ? 0 : heights[nextGreater[i]];
            int currWater = (min(lMaxHeight, rMaxHeight) <= heights[i])
                                ? 0
                                : min(lMaxHeight, rMaxHeight) - heights[i];
            maxWater += currWater;
        }
        return maxWater;
    }
};
 
