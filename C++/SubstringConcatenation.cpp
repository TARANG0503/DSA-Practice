
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string, int> map;
    unordered_map<string, int> tempMap;
    int n = B.size();
    vector<int> result;
    if(n == 0) return result;

    int m = B[0].length();
    if(A.length() < m*n) return result;

    for(int i=0;i<n;i++)
        map[B[i]]++;

    for(int i=0;i<=A.length()-(m*n);i++){
        tempMap = map;
        bool available =false;
        for(int j=0;j<n;j++){
            int var = i+(j*m);
            string str = A.substr(var, m);
            if(tempMap.find(str) != tempMap.end()){
                if(j == n-1) available = true;
                tempMap[str]--;
                if(tempMap[str] == 0)
                    tempMap.erase(str);
            } else
                break;
        }
        
        if(available)
            result.push_back(i);
    }
    return result;
}

