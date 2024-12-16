#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nge(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    
    for (int i = 1; i < n; i++) {  // Start from 1 instead of 0
        while (!st.empty() && arr[i] > arr[st.top()]) {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    // Optional: The elements left in the stack have no greater element
    // The while loop is not mandatory since the default value in `output` is -1

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {  // Ensure that input elements are taken correctly
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> res = nge(v);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
