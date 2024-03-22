#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//next_permutation() function needs <algorithm> and the original container must be sorted
//sort(perm.begin(), perm.end())
int main() {
    // original vector
    vector<int> perm = {1, 2, 3};

    // first permutation
    cout << "처음 순열: ";
    for (int num : perm) {
        cout << num << " ";
    }
    cout << endl;

    auto check = next_permutation(perm.begin(), perm.end());
    // get all next permutations using next_permutation() function
    while (next_permutation(perm.begin(), perm.end())) {
        cout << "다음 순열: ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
