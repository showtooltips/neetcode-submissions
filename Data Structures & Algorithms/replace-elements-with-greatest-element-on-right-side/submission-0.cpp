class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1) {
            arr[0] = -1;
        }
        // initialize two pointers, l and r at the start of the array
        // while l < arr.size
            // if l == r
                // walk r to the right 1 position 
                // while r < arr.size
                    // if value at position r greater or equal to temp
                        // store the index of that value in temp var
                    // increment r
                // r = temp
            // if arr[r] > arr[l]: arr[l] = arr[r]
            // increment l
        // arr[l] = -1;
        int l = 0;
        int r = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (i == r) {
                l++;
                r = l + 1;

                while (r < arr.size()) {
                    if (arr[r] >= arr[l]) {
                        l = r;
                    }
                    r++;
                }
                r = l;
            }
            arr[i] = arr[r];
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};