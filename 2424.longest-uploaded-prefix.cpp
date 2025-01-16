/*
 * @lc app=leetcode id=2424 lang=cpp
 *
 * [2424] Longest Uploaded Prefix
 */

// @lc code=start
class LUPrefix {
private:
    int longestPrefix;
    vector<bool> videos;
    
public:
    LUPrefix(int n) : longestPrefix(0), videos(n + 1, false) {}
    
    void upload(int video) {
        videos[video - 1] = true;
        
        if (video - 1 == longestPrefix) {
            while (longestPrefix < videos.size() && videos[longestPrefix]) {
                longestPrefix++;
            }
        }
    }
    int longest() {
        return longestPrefix;
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end

