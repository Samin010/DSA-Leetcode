class Solution {
public:
    int countPrimes(int n) {
        // Sieve of Erastothenes TC: O(Nlog(log(N)))
        if(n<=2)return 0;
        vector<int> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            // check if the no. is prime and mark its multiples as false
            if (isPrime[i]) {
                for (int p = i * i; p <= n; p += i) {
                    isPrime[p] = 0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(isPrime[i]==1)ans++;
        }
        return ans;
    }
};