class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            // Append length of string, followed by '#', then the actual string
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            // Find the position of the '#' delimiter
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // Get the length of the string (from i to j-1)
            int length = stoi(s.substr(i, j - i));
            
            // Extract the string of the given length after '#'
            string str = s.substr(j + 1, length);
            
            // Add the extracted string to the result vector
            decoded.push_back(str);
            
            // Move 'i' to the start of the next encoded string
            i = j + 1 + length;
        }
        return decoded;
    }
};
