#include <bits/stdc++.h>
using namespace std;

void smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mapping;
        int target = 0;
        for(int i=0; i<req_skills.size(); i++){
            // target = (target<<1)|1;
            target += pow(2,i);
            mapping[req_skills[i]] = i;
        }
        cout<<target<<endl;
        int n = people.size();
        vector<int> skill_people(n,0);
        int temp;
        for(int i=0; i<n; i++){
            temp = 0;
            for(int j=0; j<people[i].size(); j++){
                temp += pow(2, mapping[people[i][j]]);
            }
            skill_people[i] = temp;
        }
        
        for(auto itr : skill_people) cout<<itr<<" ";
        cout<<endl;
        // return skill_people;
        cout<<(skill_people[1] | skill_people[2] | skill_people[3])<<endl;
        int ans;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int k=0; k<n; k++){
            for(int i=0; i<n-k; i++){
                int j = i+k;
                if(i == j) dp[i][j] = skill_people[i];
                else{
                    int result = (dp[i+1][j] | dp[i][j-1]);
                    dp[i][j] = result;
                    if(result == target){
                        cout<<i<<"-----"<<j<<endl;
                        i = n;
                        k = n;
                    }
                }
            }
        }
        
        cout<<endl;
        for(auto itr1 : dp){
            for(auto itr2 : itr1){
                cout<<itr2<<" ";
            }
            cout<<endl;
        }
    }
    
int main()
{
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<string> req_skills(n);
        for(int i=0; i<n; i++){
            cin>>req_skills[i];
        }
        int m; cin>>m;
        vector<vector<string>> people;
        for(int i=0; i<m; i++){
            int p; cin>>p;
            vector<string> temp(p);
            for(int j=0; j<p; j++){
                cin>>temp[j];
            }
            people.push_back(temp);
            temp.clear();
        }
        smallestSufficientTeam(req_skills, people);
        
    }
    return 0;
}