#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
#define f first 
#define s second
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int m = 1e5 + 7 ;
vector<int> adj[m] ;

int dfs(int curr , int par , int &sum)
    {   
        int cnt = 1 ;
        for(auto it : adj[curr])
          {
            if(it != par)
              {
                cnt = cnt +  dfs(it , curr , sum) ;
              }
          } 
        sum = sum + cnt ;
        return cnt ;
    }

//brute force approach to find the retooting of the tree...
void solve()
     {
         int n ;
         cin>>n;
         
        // creating the adjency matrix here!!!
         for(int i= 0 ; i < n-1 ; i++)
           {
             int u , v ;
             cin>>u>>v;
             adj[u].push_back(v);
             adj[v].push_back(u) ;
           }

        int maxi = INT_MIN , node ;

        for(int i = 1 ; i <= n ; i++)
           {
              int sum = 0 ;
              dfs(i , 0 , sum);
              if(maxi < sum)
                {
                   node = i ;
                   maxi = sum ;
                }
           }

          cout<<"maximum value of the node..."<<node<<"  maximum value "<<maxi<<endl;
          return ;       
     }

int main()
  {
    
    #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r", stdin) ;
      freopen("output.txt" , "w" ,stdout);
    #endif

    int t = 1 ;
    // cin>>t;

    while (t--)
    {
      solve() ;
    }
    


  }
