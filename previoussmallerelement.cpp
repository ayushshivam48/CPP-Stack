#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> pse(const vector<int>& arr) {
    int n = arr.size();
    vector<int> output(n, -1);  // Initialize with -1, indicating no smaller element found
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {  // Traverse from right to left
        // While stack is not empty and the current element is smaller than or equal to the element at the index on the top of the stack
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();  // Pop the index from the stack
        }
        if (!st.empty()) {
            output[i] = arr[st.top()];  // Set the previous smaller element for the current index
        }
        st.push(i);  // Push the current index onto the stack
    }

    return output;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v(n);
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> res = pse(v);

    cout << "Previous Smaller Elements: ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
