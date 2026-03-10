class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& a, int k, int m) {
        int n = a.size();
        ll ans = 0;
        map<int,int> freq1, freq2;
        int j1 = -1, j2 = -1, cnt = 0;
        for(int i=0;i<n;i++) {
            while(j1<n && freq1.size()<k+1) {
                j1++;
                if(j1<n) freq1[a[j1]]++;
            }
            while(j2<n && cnt<k) {
                j2++;
                if(j2<n) {
                    freq2[a[j2]]++;
                    if(freq2[a[j2]]==m) cnt++;
                }
            }
            if(j1 > j2) ans+=(j1-j2);
            
            freq1[a[i]]--;
            if(!freq1[a[i]]) freq1.erase(a[i]);

            freq2[a[i]]--;
            if(freq2[a[i]]==m-1) cnt--;
        }

        return ans;
    }
};