#include<iostream>
using namespace std;

void subTree(int beg, int end, int treeIdx);

int treeOutput[1000], inOrderInput[1000], postOrderInput[1000], postOrderIdx;
int arraySize;
int x=-1;

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    for(int i=0; i<1000; i++) treeOutput[i]=-1;

    cout<<"Array size-->"<<endl;
    cin>>arraySize;

    cout<<"Inorder input--->";
    for(int i=0; i<arraySize; i++)
    cin>>inOrderInput[i];

    cout<<"PostOrder input--->";
    for(int i=0; i<arraySize; i++)
    cin>>postOrderInput[i];

    postOrderIdx=arraySize-1;
    subTree(0, arraySize-1, 1);

    for(int i=1; i<=x; i++) cout<<treeOutput[i]<<" ";
    return 0;
}

void subTree(int beg, int end, int treeIdx)
{
    if(beg>end) return;
    if(postOrderIdx>=arraySize) return;

    int root = postOrderInput[postOrderIdx];
    postOrderIdx--;
    treeOutput[treeIdx]=root;
    x = max(x, treeIdx);
    if(beg==end) return;

    int i;
    for(i=beg; i<=end; i++)
    {
        if(inOrderInput[i]==root) break;
    }

    subTree(i+1, end, 2*treeIdx+1);
    subTree(beg, i-1, 2*treeIdx);

}