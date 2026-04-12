#include<bits/stdc++.h>
using namespace std;

//given an array a of size N
int N;
t[4*N];
//segment tree of 4 times the size of n

void build(int a[],int v,int tl, int tr){

	if (tl==tr){
		t[v]=a[tl];
	}

	else{
		int tm=(tl+tr)/2; 
		build(a,2*v,tl,tm);      //left child
		build(a,2*v,tm+1,tr);   //right child
		t[v]=t[2*v]+t[2*v+1];  //sum from children
	}

}

int sum(int v,int tl,int tr, int l ,int r){
	if (l>tr || r < tl){
		return 0;
	}

	if (l==tl && r==tr){
		return t[v];
	}

	int tm =(tl+tr)/2;
	return sum(2*v,tl,tm,l,min(r,tm)) + sum(2*v,tm+1,max(l,tm+1),r);  //min and max used so as to ensure ki range (continued on next line)
	// child ki range se bahar na chali jaye
	//jo l and r hai unke andar wale tl and tr ka sum hota hai
}


void update(int v, int tl, int tr, int pos, int newVal){

	if (tl==tr){
		t[v]=newVal;
	}

	else{
		int tm= (tl+tr)/2;
		if (pos<=tm){        // if pos< tm then left child pe milega otherwise right child pe milega
			update(2*v,tl,tm,pos,newVal);
		}
		else{
			update(2*v,tm+1,tr,pos,newVal);
		}
		t[v]=t[2*v]+t[2*v+1];   // finally update kardiya t[v] ko bhi
	}

}