#include<iostream>
#include<math.h>
using namespace std;
int n;
int key1[8],key[10];
int pt[8],key2[8];
void P10(int* key)
{
    int P10[10]={3,5,2,7,4,10,1,9,8,6};
    int key1[10];
    for(int i=0;i<10;i++)
    {
        key1[i]=key[P10[i]-1];
    }
    for(int i=0;i<10;i++)
    {
        key[i]=key1[i];
    }
}
void P8(int* key,int* key1)
{
    int P8[8]={6,3,7,4,8,5,10,9};
    //int key1[8];
    for(int i=0;i<10;i++)
    {
        key1[i]=key[P8[i]-1];
    }
    cout<<endl;
}

int* shift(int* k,int t)
{
    if(t==1)
    {
        int temp=k[0];
        for(int i=0;i<4;i++)
        {
            k[i]=k[i+1];
        }
        k[4]=temp;
        temp=k[5];
        for(int i=5;i<9;i++)
        {
            k[i]=k[i+1];
        }
        k[9]=temp;
    }
    else
    {
        for(int j=0;j<3;j++)
        {
            int temp=k[0];
            for(int i=0;i<4;i++)
            {
                k[i]=k[i+1];
            }
            k[4]=temp;
            temp=k[5];
            for(int i=5;i<9;i++)
            {
                k[i]=k[i+1];
            }
            k[9]=temp;
            cout<<"s is:";
            for (size_t i = 0; i < 10; i++)
            {
                cout<<k[i];
            }
            cout<<endl;     
        }    
    }   
}
void IP()
{
    int IP[8]={2,6,3,1,4,8,5,7};
    int pt1[8];
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        pt1[i]=pt[IP[i]-1];
    }
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        pt[i]=pt1[i];
    }
    cout<<endl;
}
void IPi(int* pt,int* ct)
{
    int IP[8]={4,1,3,5,7,2,8,6};
    for(int i=0;i<8;i++)
    {
        ct[i]=pt[IP[i]-1];
    }
    cout<<endl;
}
void EP(int* pt,int* pt1)
{
    int EP[8]={4,1,2,3,2,3,4,1};
    for(int i=0;i<8;i++)
    {
        pt1[i]=pt[EP[i]-1+4];
    }
    cout<<endl;
}
void XOR(int* a,int* b,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0&&b[i]==0)
        {
            a[i]=0;
        }
        else if(a[i]==0&&b[i]==1)
        {
            a[i]=1;
        }
        else if(a[i]==1&&b[i]==0)
        {
            a[i]=1;
        }
        else if(a[i]==1&&b[i]==1)
        {
            a[i]=0;
        }    
    }
}
void P4(int* key)
{
    int P4[4]={2,4,3,1};
    int key1[4];
    for(int i=0;i<4;i++)
    {
        key1[i]=key[P4[i]-1];
    }
    for(int i=0;i<4;i++)
    {
        key[i]=key1[i];
    }
    cout<<endl;
}
void sbox(int* pt,int* r)
{
    int S0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
    int S1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,2}};
    int row,column;
    if(pt[0]==0&pt[3]==0){row=0;}
    else if(pt[0]==0&pt[3]==1){row=1;}
    else if(pt[0]==1&pt[3]==0){row=2;}
    else {row=3;}
    if(pt[1]==0&pt[2]==0){column=0;}
    else if(pt[1]==0&pt[2]==1){column=1;}
    else if(pt[1]==1&pt[2]==0){column=2;}
    else {column=3;}
    int temp1=S0[row][column];
    if(pt[4]==0&pt[7]==0){row=0;}
    else if(pt[4]==0&pt[7]==1){row=1;}
    else if(pt[4]==1&pt[7]==0){row=2;}
    else {row=3;}
    if(pt[5]==0&pt[6]==0){column=0;}
    else if(pt[5]==0&pt[6]==1){column=1;}
    else if(pt[5]==1&pt[6]==0){column=2;}
    else {column=3;}
    int temp2=S1[row][column];
    int i=3;
    if(temp1==0){r[0]=0;r[1]=0;}
    else if(temp1==1){r[0]=0;r[1]=1;}
    else if(temp1==2){r[0]=1;r[1]=0;}
    else{r[0]=1;r[1]=1;}
    if(temp2==0){r[2]=0;r[3]=0;}
    else if(temp2==1){r[2]=0;r[3]=1;}
    else if(temp2==2){r[2]=1;r[3]=0;}
    else{r[2]=1;r[3]=1;}
}
void joint(int* pt,int* a,int* b)
{
    for(int i=0;i<4;i++)
    {
        pt[i]=a[i];
    }
    for(int i=4;i<8;i++)
    {
        pt[i]=b[i-4];
    }
}
void des(int* key1,int* key2,int* pt)
{
    int pt1[8],pt2[8];
    IP();
    cout<<endl;  
    //Round 1
    EP(pt,pt1);
    cout<<endl;    
    XOR(pt1,key1,8);
    int l[4],r[4],r1[4];
    for(int i=0;i<4;i++)
    {
        l[i]=pt[i];
        r[i]=pt[i+4];
    }
    sbox(pt1,r1);
    P4(r1); 
    XOR(l,r1,4);
    joint(pt,r,l);
    //Round 2////////////////////////////////////////////////////
    EP(pt,pt1);
    XOR(pt1,key2,8);
    for(int i=0;i<4;i++)
    {
        l[i]=pt[i];
        r[i]=pt[i+4];
    }
    sbox(pt1,r1);
    P4(r1);
    XOR(l,r1,4);
    joint(pt,l,r);
    int ct[8];
    IPi(pt,ct);
    if(n==1)
    {
        cout<<"Cipertext is:";
        for(int i=0;i<8;i++)
        {
            cout<<ct[i];
        }
        cout<<endl;
    }
    if(n==2)
    {
        cout<<"Plaintext is:";
        for(int i=0;i<8;i++)
        {
            cout<<ct[i];
        }
        cout<<endl;
    }
}
int main()
{
    
    while(1){
        
        cout<<"For encryption press 1 and for decryption press2:";
        cin>>n;
        if(n==1)
        {
            cout<<"Enter plaintext:";
            for (size_t i = 0; i < 8; i++)
            {
                cin>>pt[i];
            }
        }
        else if(n==2)
        {
            cout<<"Enter ciphertext:";
            for (size_t i = 0; i < 8; i++)
            {
                cin>>pt[i];
            }
        }
        else
        {
            cout<<"Enter valid input"<<endl;
            continue;
        }
        int ke[8];
        cout<<"Enter key:";
        for (size_t i = 0; i < 10; i++)
        {
            cin>>key[i];
            ke[i]=key[i];
        }
        //for k1
        P10(ke);
        shift(ke,3);
        for(int i=0;i<10;i++)
        {
            cout<<ke[i];
        }
        cout<<endl;
        P8(ke,key2);
        cout<<"key 2 is:";
        for(int i=0;i<8;i++)
        {
            cout<<key2[i];
        }
        P10(key);
        shift(key,1);
        P8(key,key1);
        cout<<"key 1 is:";
        for(int i=0;i<8;i++)
        {
            cout<<key1[i];
        }
        cout<<endl;
        if(n==1)
        {
            des(key1,key2,pt);
        }
        else if(n==2)
        {
            des(key2,key1,pt);  
        }
        
    }
    return 0;
}
