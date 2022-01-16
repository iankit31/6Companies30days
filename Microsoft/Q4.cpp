using namespace std;
#define NFS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int 
#define ull unsigned long long 
#define PB push_back
#define MP make_pair
#define M 1000000007
int main() {
	// your code goes here
	NFS
	int t,i,j;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n][m];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	            cin>>a[i][j];
	    }
	    int p,q,r,s;
	    int cnt=0;
	    p=0;q=m-1;r=n-1;s=0;
	    while(cnt!=n*m)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(a[p][j]!=-1)
	            {
	                cout<<a[p][j]<<" ";
	                a[p][j]=-1;cnt++;
	            }
	        }
	        for(i=0;i<n;i++)
	        {
	           if(a[i][q]!=-1)
	            {
	                cout<<a[i][q]<<" ";
	                a[i][q]=-1;cnt++;
	            } 
	        }
	        for(j=m-1;j>=0;j--)
	        {
	            if(a[r][j]!=-1)
	            {
	                cout<<a[r][j]<<" ";
	                a[r][j]=-1;cnt++;
	            }
	        }
	        for(i=n-1;i>=0;i--)
	        {
	           if(a[i][s]!=-1)
	            {
	                cout<<a[i][s]<<" ";
	                a[i][s]=-1;cnt++;
	            } 
	        }
	        p++;q--;r--;s++;
	    }
	    cout<<"\n";
	}
	return 0;
}

            