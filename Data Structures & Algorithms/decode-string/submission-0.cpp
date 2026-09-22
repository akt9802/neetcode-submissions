class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int count = 0;

        for (char ch : s) {

            // Build the number
            if (isdigit(ch)) {
                count = count * 10 + (ch - '0');
            }

            // Entering a new bracket
            else if (ch == '[') {
                countStack.push(count);
                stringStack.push(current);

                count = 0;
                current = "";
            }

            // Leaving a bracket
            else if (ch == ']') {
                int k = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string repeated = "";

                for (int i = 0; i < k; i++) {
                    repeated += current;
                }

                current = previous + repeated;
            }

            // Normal character
            else {
                current += ch;
            }
        }

        return current;
    }
};