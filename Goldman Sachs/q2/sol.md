## Intuition
We are given a series of strings with each employee having an access time. There is no apparent relation between any employees, so we can store the access time of each employee separately using hashmaps. The key in the hashmap is the employee name, and the value is a vector of strings representing access times.

## Approach
Following this approach, we create a hashmap. To be included in the answer, an employee needs to have at least access_time < 60 three times. Thus, we include only those employees who have more than 3 access times (a small optimization, although not necessary but intuitive).

To compare the time, we sort the access_time array of each employee. This makes it easy to compare in a single loop, which is intuitive (refer to the code or run a dry run if you don't understand).

The next step is to run a loop, compute the time, and if it is less than 60 minutes, we include it in the answer and check for other employees.

**computeTime() function:** Here, we compute the time between the first and third access time. There is no need to convert the middle one. We extract hours and minutes separately. If the hours are the same, we compute minutes. If the difference in hours is 1, we compute it using \(60 - m1 + m2\). Run a dry run if you don't understand; otherwise, return any arbitrary large number directly if the answer is not possible.

## Complexity
- **Time complexity:** \(n =\) size of access_times. Complexity = \(O(n)\)
- **Space complexity:** \(O(n)\)

## Code
```cpp
class Solution {
    // Function for computing time
    int computeTime(string &t1, string &t2) {
        int h1 = (t1[0] - '0') * 10 + (t1[1] - '0');
        int h2 = (t2[0] - '0') * 10 + (t2[1] - '0');
        int m1 = (t1[2] - '0') * 10 + (t1[3] - '0');
        int m2 = (t2[2] - '0') * 10 + (t2[3] - '0');

        if (h1 == h2) {
            return m2 - m1;
        } else if (h2 - h1 == 1) {
            return 60 - (m1 - m2);
        }
        return INT_MAX; // answer not possible
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;

        // Creating hashmap
        unordered_map<string, vector<string>> freq;
        for (auto access_time : access_times) {
            freq[access_time[0]].push_back(access_time[1]);
        }

        // Iterating in hashmap
        for (auto &itr : freq) {
            if (itr.second.size() >= 3) {
                sort(itr.second.begin(), itr.second.end());
                for (int i = 2; i < itr.second.size(); i++) {
                    if (computeTime(itr.second[i-2], itr.second[i]) < 60) {
                        ans.push_back(itr.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
