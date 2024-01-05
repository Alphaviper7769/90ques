#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> m;
        vector<string> ans;
        for(auto &i:access_times)
        {
            int a=((i[1][0]-'0')*10+i[1][1]-'0')*60+((i[1][2]-'0')*10+i[1][3]-'0');
            m[i[0]].push_back(a);
        }

        for(auto &i:m)
        {
            if(i.second.size()<3)
            continue;
            sort(i.second.begin(),i.second.end());
            for(int j=0;j<i.second.size()-2;j++)
            {
                //cout<<j<<" "<<i.second.size()<<" "<<i.first<<endl;
                if(abs(i.second[j]-i.second[j+1])<60 && abs(i.second[j]-i.second[j+2])<60)
                {
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example usage
    vector<vector<string>> access_times = {
        {"a", "0549"}, {"b", "0457"}, {"a", "0532"},
        {"a", "0621"}, {"b", "0540"}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the findHighAccessEmployees function with the provided access_times
    vector<string> result = solution.findHighAccessEmployees(access_times);

    // Output the result
    cout << "High Access Employees: ";
    for (const auto& employee : result) {
        cout << employee << " ";
    }
    cout << endl;

    return 0;
}