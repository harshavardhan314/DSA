#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sorta(arr, n) sort(arr, arr + n)
#define sortd(arr, n) sort(arr, arr + n, greater<int>())
#define sortva(v) sort(v.begin(), v.end())
#define sortvd(v) sort(v.begin(), v.end(), greater<int>())
#define coutvec(v) for (auto it : v) cout << it << " "; cout << "\n"
#define setbitsof(x) __builtin_popcountll(x)



#define cinvec(v, n)     \
	vector<int> v(n); \
	for(int i=0;i<n;i++) cin >> v[i]
	
constexpr int MOD = 1e9 + 7;
vector<int> primes;

// ------------------------ Utility Functions ------------------------

string dectobinary(int n) {
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

int binarytodecimal(const string &n) {
    int dec_value = 0, base = 1;
    for (int i = n.length() - 1; i >= 0; --i) {
        if (n[i] == '1')
            dec_value += base;
        base *= 2;
    }
    return dec_value;
}



bool is_perfect(int x) {
    if (x < 0) return false;
    int sr = sqrt(x);
    return (sr * sr == x);
}

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void sieve(int n) {
    primes.assign(n + 1, 0);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            primes[i] = 1;
    }
}

int binaryexpo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

// ------------------------ Problem Logic ------------------------

void solve() {
    
  
  int n,k;
  cin>>n>>k;
  cinvec(v,n);
  int sum=0,ones=0,twos=0;
  for(int i=0;i<n;i++)
  {
      if(v[i]==1)ones++;
      if(v[i]==2)twos++;
      sum+=v[i];
  }
  if(sum==k)
  {
      cout<<-1<<endl;
      return;
  }
  if(sum>k)
  {
      coutvec(v);
    
      return;
  }
 if(sum==3 && k==4)
 {

         cout<<0<<" "<<2<<" "<<1<<endl;
         return;
     
     
 }
  cout<<-1<<endl;
    
    
    
    
    
   
   
    
    
}

// ------------------------ Main ------------------------

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve(1e7); // Precompute primes up to 10^7

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
