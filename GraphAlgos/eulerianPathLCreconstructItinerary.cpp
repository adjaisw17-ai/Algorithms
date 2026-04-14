class Solution {
public:
    map<string,vector<string>>mp;
    map<string,int>indegree;
    vector<string>ans;

    void dfs(string currAirport){
        vector<string>&dest= mp[currAirport];
        while (!dest.empty()){
            string nextAirport=dest.back();
            dest.pop_back();
            dfs(nextAirport);
        }
        ans.push_back(currAirport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto e:tickets){
            mp[e[0]].push_back(e[1]);
            //indegree[e[1]]++;          
        }

        for (auto &entry:mp){
            sort(entry.second.rbegin(),entry.second.rend());
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;

    }
};