class Solution {
public:
    // NSL
    vector<int> NSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> left;
        stack<pair<int, int>> s;
        int pseudo = -1;

        for (int i = 0; i < n; i++) {
            if (s.size() == 0) {
                left.push_back(pseudo);
            }
            else if (s.top().first < arr[i]) {
                left.push_back(s.top().second);
            }
            else if (s.top().first >= arr[i]) {
                while (!s.empty() && s.top().first >= arr[i]) {
                    s.pop();
                }

                if (s.size() == 0) {
                    left.push_back(pseudo);
                }
                else {
                    left.push_back(s.top().second);
                }
            }

            s.push({arr[i], i});
        }

        return left;
    }

    // NSR
    vector<int> NSR(vector<int>& arr) {
        int n = arr.size();
        vector<int> right;
        stack<pair<int, int>> st;
        int pseudo = n;

        for (int i = n - 1; i >= 0; i--) {
            if (st.size() == 0) {
                right.push_back(pseudo);
            }
            else if (st.top().first < arr[i]) {
                right.push_back(st.top().second);
            }
            else if (st.top().first >= arr[i]) {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }

                if (st.size() == 0) {
                    right.push_back(pseudo);
                }
                else {
                    right.push_back(st.top().second);
                }
            }

            st.push({arr[i], i});
        }

        reverse(right.begin(), right.end());

        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max = 0;

        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            if (area > max) {
                max = area;
            }
        }

        return max;
    }
};