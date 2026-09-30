class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {

            auto [freq, ch] = pq.top();
            pq.pop();

            // Can't use this character because it
            // would create three consecutive characters
            if (ans.size() >= 2 &&
                ans[ans.size() - 1] == ch &&
                ans[ans.size() - 2] == ch) {

                // No alternative character available
                if (pq.empty()) {
                    break;
                }

                // Take second most frequent character
                auto [freq2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                freq2--;

                if (freq2 > 0) {
                    pq.push({freq2, ch2});
                }

                // We didn't use ch, so put it back
                pq.push({freq, ch});
            }
            else {
                // We can safely use ch
                ans += ch;
                freq--;

                if (freq > 0) {
                    pq.push({freq, ch});
                }
            }
        }

        return ans;
    }
};