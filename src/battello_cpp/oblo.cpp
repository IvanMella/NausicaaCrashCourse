 //BATTELLO
#include <iostream>

using namespace std;

int main()
{
    int n = 8;
    int left[]= {0,1,1,1,0,0,1,0};
    int right[] = {0,0,0,1,1,0,1,1};
    int sum[n];
    for(int i = 0; i < n; i++)
    {
        sum[i]=left[i]+right[i];
        //cout<<sum[i]<<" ";
    }
    int result[4][8]={
	{1,1,1,2,1,0,2,1},
	{1,1,1,0,1,1,2,1},
	{1,1,2,2,1,0,1,1},
	{0,1,1,2,1,1,2,1}

    }
    for(int i = 0; i < n/2; i++);
    {
        for(int j = 0; j < n; j++);
        {
            if(sum[j]==result[j][i])
		{
		    cout<<"il risultato e corretto";
		}
        }
    }
    return 0;
}
