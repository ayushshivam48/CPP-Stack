#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> pge(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);  // Initialize with -1, indicating no greater element found
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {  // Traverse from right to left
        // While stack is not empty and the current element is greater than or equal to the element at the index on the top of the stack
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();  // Pop the index from the stack
        }
        if (!st.empty()) {
            output[i] = arr[st.top()];  // Set the previous greater element for the current index
        }
        st.push(i);  // Push the current index onto the stack
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> res = pge(v);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
