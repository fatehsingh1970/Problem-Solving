class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> > ip;
        for(int i=0;i<startTime.size();i++)
            ip.push_back(vector<int> {startTime[i],endTime[i],profit[i]});
        sort(ip.begin(),ip.end(),[](vector<int> &a,vector<int> &b){return a[1]<b[1];}); // sort according to the end
        vector<int> dp(endTime.size());
        dp[0]=ip[0][2];
        for(int i=1;i<endTime.size();i++)
        {
                int p=i-1;
                while(p>=0&&ip[p][1]>ip[i][0])
                {
                    p--;
                }
                int x=0;
                if(p>=0&&ip[p][1]<=ip[i][0])
                    x=dp[p];
                dp[i]=max(dp[i-1],x+ip[i][2]);
        }
        return dp[endTime.size()-1];
    }
};
