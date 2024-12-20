#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include <unordered_map>
using namespace std;

string correctBracketSequence(const string &s) {
    stack<int> st; // Stack to store the indices of unmatched opening brackets
    string result = s;
    vector<bool> toRemove(s.length(), false);

    // Mapping of closing to opening brackets
    unordered_map<char, char> bracketMap = {{')', '('}, {'}', '{'}, {']', '['}};
    unordered_map<char, char> reverseBracketMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    // Traverse the string
    for (int i = 0; i < s.length(); ++i) {
        if (bracketMap.count(s[i])) {  // If it's a closing bracket
            if (!st.empty() && result[st.top()] == bracketMap[s[i]]) {
                // Matched opening bracket on top of stack
                st.pop();
            } else {
                // Unmatched closing bracket, mark it for removal
                toRemove[i] = true;
            }
        } else if (reverseBracketMap.count(s[i])) {  // If it's an opening bracket
            // Push the index of the opening bracket onto the stack
            st.push(i);
        }
    }

    // Mark all unmatched opening brackets in the stack for removal
    while (!st.empty()) {
        toRemove[st.top()] = true;
        st.pop();
    }

    // Build the resulting string excluding marked positions
    string correctedSequence;
    for (int i = 0; i < s.length(); ++i) {
        if (!toRemove[i]) {
            correctedSequence += s[i];
        }
    }

    return correctedSequence;
}

int main() {
    string s;
    cout << "Enter the bracket sequence: ";
    cin >> s;

    string result = correctBracketSequence(s);
    cout << "Corrected bracket sequence: " << result << endl;

    return 0;
}
