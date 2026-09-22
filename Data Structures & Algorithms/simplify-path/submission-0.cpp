class Solution {
public:
    string simplifyPath(string path) {

        // left and right used for getting directory name
        vector<string> temp;

        int left = 1;
        int right = 1;

        while (right < path.length()) {

            // Found the end of a directory
            if (path[right] == '/') {

                if (right > left) {

                    string dir = path.substr(left, right - left);

                    if (dir == "..") {

                        if (!temp.empty()) {
                            temp.pop_back();
                        }

                    } 
                    else if (dir == ".") {
                        // do nothing
                    } 
                    else {
                        temp.push_back(dir);
                    }
                }

                // Move left after EVERY slash
                left = right + 1;
            }

            // IMPORTANT: right++ must be INSIDE the loop
            right++;
        }

        // Process the LAST directory
        if (right > left) {

            string dir = path.substr(left, right - left);

            if (dir == "..") {

                if (!temp.empty()) {
                    temp.pop_back();
                }

            } 
            else if (dir == ".") {
                // do nothing
            } 
            else {
                temp.push_back(dir);
            }
        }

        // Build answer
        string ans = "";

        for (int i = 0; i < temp.size(); i++) {
            ans += "/" + temp[i];
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};