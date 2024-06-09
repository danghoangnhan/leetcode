#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const auto& str : strs) {
            encoded += to_string(str.size()) + '|' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0;
        while (i < s.size()) {
            size_t delim_pos = s.find('|', i);
            if (delim_pos == string::npos) {
                break; // No more delimiters found (just a safety check)
            }
            // Extract the length of the next string
            int len = stoi(s.substr(i, delim_pos - i));
            // Extract the string itself
            decoded.push_back(s.substr(delim_pos + 1, len));
            // Move index i to the start of the next string segment
            i = delim_pos + 1 + len;
        }
        return decoded;
    }
};
