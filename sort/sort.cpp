#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> randomint(int a,int b,int n)
{
	vector<int> v;
	for(int i=0;i<n;i++) {
		v.push_back(a+rand()%(b-a-1));
	}
	return v;
}

bool issorted(vector<int>& v) {
	for(int i=1;i<v.size();i++) {
		if(v[i-1] > v[i])
			return false;
	}
	return true;
}

void printarr(vector<int> &v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\t";
	cout<<endl;
}

int partion(vector<int>& v,int l,int r) {
	int tv=v[l];
	int k=l;
	for(int i=l+1;i<=r;i++) {
		if(v[i]<tv) 
			swap(v[++k],v[i]);
	}
	swap(v[k],v[l]);
	return k;
}

void qsort(vector<int>& v,int l,int r) {
	if(l < r){
		int k=partion(v,l,r);
		qsort(v,l,k-1);
		qsort(v,k+1,r);
	}
}

void quicksort(vector<int>& v) {
	qsort(v,0,v.size()-1);
}

void heapify(vector<int>& v,int index,int size) {
	int lchild=2*index+1;
	int rchild=2*index+2;
	int maxIndex=index;
	if(lchild < size && v[lchild] > v[maxIndex])
		maxIndex=lchild;
	if(rchild < size && v[rchild] > v[maxIndex])
		maxIndex=rchild;
	if(maxIndex != index) {
		swap(v[index],v[maxIndex]);
		heapify(v,maxIndex,size);
	}
}

void buildheap(vector<int>& v) {
	for(int i=v.size()/2;i>=0;i--) {
		heapify(v,i,v.size());
	}
}

void heapsort(vector<int>& v) {
	buildheap(v);
	int size=v.size();
	for(int i=v.size()-1;i>=0;i--) {
		swap(v[0],v[i]);
		heapify(v,0,--size);
	}
}

void merge(vector<int>& v,int l,int m,int r) {
	vector<int> t(r-l+1,0);
	for(int i=l;i<=r;i++)
		t[i-l]=v[i];
	int i=l,j=m+1,k=l;
	while(i <= m && j <= r) {
		if(t[i-l] < t[j-l]) {
			v[k++]=t[i-l];
			i++;
		} else {
			v[k++]=t[j-l];
			j++;
		}
	}
	while(i <= m) {
		v[k++]=t[i-l];
		i++;
	}
	while(j <= r) {
		v[k++]=t[j-l];
		j++;
	}
}

void _mergesort(vector<int>& v,int l,int r) {
	if(l < r) {
		int mid=(l+r)/2;
		_mergesort(v,l,mid);
		_mergesort(v,mid+1,r);
		merge(v,l,mid,r);
	}
}

void mergesort(vector<int>& v) {
	_mergesort(v,0,v.size()-1);
}

int main()
{
	srand(time(NULL));
	bool res=true;
	for(int i=0;i<100;i++) {
		vector<int> v=randomint(0,50000,1000000);
		quicksort(v);
//		heapsort(v);
//		mergesort(v);
//		sort(v.begin(),v.end());
		res&=issorted(v);
	} 
	cout<<res<<endl;
	return 0;
}
