#include<iostream>
#include<cmath>
#include<string>

using namespace std;

void
fastio ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
}

int
main (void)
{
  fastio ();
  int a, b;
  cin >> a >> b;
  int num = a + b*1000000;
  int flag = 0;
  for (int i = 2; i <= sqrt (a); i++)
    {
      if (a % i == 0)
	{
	  flag = 1;
	  break;
	}
    }
  if (!flag)
    {
      for (int i = 2; i <= sqrt (num); i++)
	{
	  if (num % i == 0)
	    {
	      flag = 1;
	      break;
	    }
	}
	    if(!flag)
	        cout <<"Yes"<<'\n';
	   else
	   cout<<"No" <<'\n';
    }
    else
	   cout<<"No" <<'\n';
  return 0;
}
