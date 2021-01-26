#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int a[N];
// Array for storing and printing of order
vector<int> postOrder; // post order
vector<int> preOrder; // pre order
vector<int> inOrder; // in order


// function for generation of preorder expression
void preOrderGenerator(int cur,int node_t){
	
	if(cur >= node_t) return;
	if(a[cur] == -1) return;
	
	preOrder.push_back(a[cur]);
	
	//1st recursive call -> for right to left traversal
	preOrderGenerator(2*cur,node_t);
	//2nd recursive call -> for left to right traversal
	preOrderGenerator(2*cur+1,node_t);
}

// function for generation of postorder expression
void postOrderGenerator(int cur, int node_t){
	
	if (cur >= node_t) return;
	if (a[cur] == -1) return;
	
	postOrderGenerator(2*cur,node_t);
	postOrderGenerator(2*cur+1,node_t);
		
	postOrder.push_back(a[cur]);
}

// function for generation of in order expression
void InOrderGenerator(int cur, int node_t){
	
	if (cur >= node_t) return;
	if (a[cur] == -1) return;
	
	
	
	InOrderGenerator(2*cur,node_t);
	
	inOrder.push_back(a[cur]);
	
	InOrderGenerator(2*cur+1,node_t);
	
	
}


int main (){
	
	int n;
	cin>>n;

	int b_occur = 1;
	int actualp = 0;
	
	while (1){
		int x;
		cin>>x;
		
		if (x==-1){
			a[b_occur++] = x;
		}
		else {
			a[b_occur++] = x;
			actualp++;
		}
		if (actualp == n) break;
	}
	
	for (int i = 1; i<b_occur;i++){
		
		printf("%4d ",a[i]);
	}
	puts("");
	for (int i=1;i<b_occur;i++){
		printf("%4d ",i);
	}
	puts("");
	
	preOrderGenerator(1,b_occur);	
	
	printf("Pre order : ");
	for (int x : preOrder) printf("%4d ",x) ;
	puts("");
	
	postOrderGenerator(1,b_occur);
	
	printf("Post order : ");
	for (int x : postOrder) printf("%4d ",x) ;
	puts("");
	
	InOrderGenerator(1,b_occur);
	
	printf("In order : ");
	for (int x : inOrder) printf("%4d ",x) ;
	puts("");
}
