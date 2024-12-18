#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> pge(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);  // Initialize with -1, indicating no previous greater index found
    stack<int> st;

    for (int i = 0; i < n; i++) {  // Traverse from left to right
        // While stack is not empty and the current element is greater than or equal to the element at the index on the top of the stack
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();  // Pop the index from the stack
        }
        if (!st.empty()) {
            output[i] = st.top();  // Set the index of the previous greater element for the current index
        }
        st.push(i);  // Push the current index onto the stack
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> res = pge(v);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
