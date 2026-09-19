class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int asteroid : asteroids) {

            if (asteroid > 0) {
                ans.push_back(asteroid);
            }
            else {
                int x = -asteroid;

                while (!ans.empty() && ans.back() > 0) {

                    if (ans.back() < x) {
                        // positive asteroid explodes
                        ans.pop_back();
                    }
                    else if (ans.back() == x) {
                        // both explode
                        ans.pop_back();
                        x = 0;
                        break;
                    }
                    else {
                        // negative asteroid explodes
                        x = 0;
                        break;
                    }
                }

                if (x != 0) {
                    ans.push_back(-x);
                }
            }
        }

        return ans;
    }
};