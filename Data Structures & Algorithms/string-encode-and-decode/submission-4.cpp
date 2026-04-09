#include <cstring>
string delimiter = "~";

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (auto& curr : strs)
        {
            encoded_string.append(curr);
            encoded_string.append(delimiter);
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        std::vector<string> decoded_message;

        char* start = s.data();
        char* end = start + s.size();

        string current_string = "";
        while (start < end)
        {
            if (*start == delimiter[0] /* Get the delimiter as a char */)
            {
                decoded_message.push_back(current_string);
                current_string = "";
            } else 
                current_string.push_back(*start);

            start++;
        }

        return decoded_message;
    }
};
