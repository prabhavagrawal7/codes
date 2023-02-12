#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
// CPP program to find two numbers with
// given Sum and XOR such that value of
#define ll int64_t
void compute(ll S,ll X)
{
	ll A = (S - X)/2;

	ll a = 0, b = 0;

	// Traverse through all bits
	for (int i=0; i<30; i++)
	{
		ll Xi = (X & (1 << i));
		ll Ai = (A & (1 << i));
		if (Xi == 0 && Ai == 0)
		{
			
		}
		else if (Xi == 0 && Ai > 0)
		{
			a = ((1 << i) | a);
			b = ((1 << i) | b);
		}
		else if (Xi > 0 && Ai == 0)
		{
			a = ((1 << i) | a);

			
		}
		else // (Xi == 1 && Ai == 1)
		{
			cout<<-1<<endl;
            return;
		}
	}
    if((a^b)==X && a+b==S)
	cout << a<<" "<<b<<endl;
    else cout<<-1<<endl;
}


void solve(){
      int n;
    cin>>n;

    compute(2*n, n);

}
int main(){
    FAST;
    int t;
    cin>>t;

    while(t--){
        solve();
    }
  
    return 0;
}