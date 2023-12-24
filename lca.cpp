#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
#define f first 
#define s second
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int N = 1e5 + 7 ;
const int M = 20 ;

vector<int> adj[N] ;
int Dep[N] , Par[N][M] ;

int XOR[N] ;

//build the dfs codes...
void dfs(vector<int> &a , int curr , int par)
     {
        Dep[curr] = Dep[par] + 1 ;
        Par[curr][0] = par ; 

        XOR[curr] = XOR[par]^a[curr-1] ;

        for(int j = 1 ; j < M; j++)
           {
              Par[curr][j] =  Par[Par[curr][j-1]][j-1] ;
           }
        
        for(auto it : adj[curr])
           {
             if(it != par)
               {
                 dfs(a , it , curr);
               }
           }
     }


//finding the lowest common ancestor of any nodes..
int LCA(int u , int v)
        {
            if(u == v)
              return u ;

            if(Dep[u] < Dep[v] )
              swap(u , v) ;

            int diff = Dep[u] - Dep[v] ;

           //u at the heigher depth as compare to the v
            for(int j = M-1 ; j >= 0 ; j--)
               {
                 if( ( (diff>>j) & 1) )
                   {
                       u = Par[u][j] ;
                   }
               }

           if(u == v)
             return u ;

            //now u and v are the  same depth//
            for(int j = M-1 ; j >= 0 ; j--)
               {
                if(Par[u][j] != Par[v][j])
                    {
                      u = Par[u][j] ;
                      v = Par[v][j] ;
                    }
               } 

            return Par[u][0] ;
        }


//finding the distance between any two nodes....
int finddistance(int u , int v)
          {
               int lca = LCA(u , v) ;
               cout<<lca<<" ";

               return (Dep[u]  ) + (Dep[v] ) - 2*(Dep[lca]) ;
          }

//finding the xor between given two nodes..

int findxor(vector<int> a , int u , int v)
           {
              int lca = LCA(u , v);
              cout<<lca<<" ";

              return ( XOR[u]^XOR[lca] )^( XOR[v]^XOR[lca]) ^ a[lca-1] ;
           }


void solve()
     {
        //takin the input of the number of nodes...
        int n ;
        cin>>n;

        vector<int> a ;

         for(int i = 0 ; i < n ; i++)
            {
                 int tmp ;
                 cin>>tmp;
                 a.push_back(tmp);
            }

       //taking the inputs of the edges ..
        for(int i = 0 ; i < n-1 ; i++)
           {
             int u , v ;
             cin>>u>>v;

             adj[u].push_back(v);
             adj[v].push_back(u) ;
           }

         dfs(a , 1 ,0);

         cout<<findxor(a , 3 , 5)<<endl;
         cout<<findxor(a , 4 , 5)<<endl;

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
