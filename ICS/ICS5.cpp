#include<bits/stdc++.h>
using namespace std;


vector<int> point(int a , int b)
{
	int lhs,rhs,y;
	
	vector<int> p;
	
	if((4*a*a*a + 27*b*b) != 0)
	{
		int x = 1;
		
		while(1)
		{
			rhs = x*x*x + a*x + b;
			y = (int)sqrt(rhs);
			lhs = y*y;
			
			if(lhs == rhs)
			{
				p.push_back(x);
				p.push_back(y);
				return p;
			}
			else
			{
				x++;
			}
		}
		
	}
	else
	{
		cout<<"\n\n\t Invalid ... ";
		p.push_back(-1);
		p.push_back(-1);
		return p;
	}
	
}


int main()
{
	int a,b;
	vector<int> publicA;
	vector<int> publicB;	
	vector<int> G;
	vector<int> cipher;
		
	//Eleptic Curve Parameters 
	
	cout<<"\n\n\tEnter a and b : ";
	cout<<"\n\ta : ";
	cin>>a;
	
	cout<<"\n\tb : ";
	cin>>b;
	
	
	int nA,nB;
	
	cout<<"\n\n\tEnter Private A : ";
	cin>>nA;
	
	cout<<"\n\n\tEnter Private B : ";
	cin>>nB;
	
	G = point(a,b);
	
	if(G[0] == -1 && G[1] == -1)
	{
		return 0;
	}
	
	publicA.push_back( nA*G[0]);
	publicA.push_back( nA*G[1]);
	
	publicB.push_back( nB*G[0]);
	publicB.push_back( nB*G[1]);
	
	
	int k = nA*(publicB[0] + publicB[1] );
	
	//int k2 = nB*(publicA[0] + publicA[1]);
	//cout<<"\n\n\tkeys : "<<k<<"\t"<<k2;
	
	int m;
	
	cout<<"\n\n\tEnter Plain Text : ";
	cin>>m;
	
	int c1 = k*(G[0]+G[1]);
	int c2 = m + k*(publicB[0]+publicB[1] );
	
	cipher.push_back(c1);		
	cipher.push_back(c2);
	
	cout<<"\n\n\tCipher Text : ( "<<cipher[0]<<" , "<<cipher[1]<<" )";

	cout<<"\n\n\tDecryption : ";
	
	int dtext = c2 - c1*nB;
	
	cout<<"\n\n\tDecrypted Message : "<<dtext;
	
	return 0;
}


