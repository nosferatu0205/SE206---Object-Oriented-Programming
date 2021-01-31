#include<bits/stdc++.h>
using namespace std;

void subTree(int beg, int end, int treeIdx);
int treeOutput[1000], inOrderInput[1000], preOrderInput[1000], preOrderIdx=0;

int arraySize;
int x=-1;
int i;

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    for(int i=0; i<1000; i++) treeOutput[i]=-1;

    cout<<"Array size--->";
    cin>>arraySize;

    cout<<"Inorder input--->";
    for(int i=0; i<arraySize; i++)
    {
        cin>>inOrderInput[i];
    }

    cout<<"Preorder input--->";
    for(int i=0; i<arraySize; i++)
    {
        cin>>preOrderInput[i];
    }

    subTree(0, arraySize-1, 1);
    
    for(int i=1; i<=x; i++)
    {
    cout<<treeOutput[i]<<" ";
   // cout<<preOrderInput[i]<<" ";
   // cout<<inOrderInput[i]<<" ";
}
}

void subTree(int beg, int end, int treeIdx)
{
    if(beg>end) return;
    if(preOrderIdx>=arraySize) return;

    int root = preOrderInput[preOrderIdx];
    preOrderIdx++;
    treeOutput[treeIdx] = root;
    x=max(x, treeIdx);

    if(beg==end) return;

    int i;
    for(i=beg; i<=end; i++)
    {
        if(inOrderInput[i]==root) break;

    }

    subTree(beg, i-1, 2*treeIdx);
    subTree(i+1, end, 2*treeIdx+1);
}