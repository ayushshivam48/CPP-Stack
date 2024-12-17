#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nse(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);  // Initialize with -1, indicating no smaller element found
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        // While stack is not empty and the current element is smaller than the element at the index on the top of the stack
        while (!st.empty() && arr[i] < arr[st.top()]) {
            output[st.top()] = arr[i];  // Set the next smaller element for the top index
            st.pop();  // Pop the index from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }

    // Remaining elements in the stack have no smaller element to the right
    // No additional processing is needed because the output vector is already initialized to -1

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

    vector<int> res = nse(v);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
