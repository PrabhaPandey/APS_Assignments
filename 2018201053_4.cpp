#include <iostream>
using namespace std;
//load factor=1.5 (i.e. if one element more after 1000 insertions is added then vector becomes of size 2000)
class vector{
	int * vector_array;
	int size1; //make function make private
	public :
	int index=-1;
	
	vector()
	{
		vector_array=(int *)malloc(sizeof(int)*10);//change 10 to somethong else
		size1=10;
	}
	vector(int n, int x){
		vector_array=(int *) malloc(sizeof(int)*n);
		size1=n;
		for(int i=0;i<n;i++)
		{
			vector_array[i]=x;
			index++;
		}
	}
	void push_back(int x)
	{
		int size2=size1;
		if(index>=(size1/2))
		{
			size2=2*size1;
			vector_array=(int *)realloc(vector_array,size2*sizeof(int)); 
		}
		index++;
		vector_array[index]=x;
		size1=size2;
	}
	void pop_back()
	{
		int size2=size1;
		index--;
		if(index<=(size1)/4)//find shrink condition
		{
			size2=size1/2;
			vector_array=(int *)realloc(vector_array,size2*sizeof(int));
		}
		size1=size2;
	}
	int size()
	{
		return size1;
	}
	void insert(int ind,int x)
	{
		push_back(x);
		int temp=vector_array[index];
		int i=index;
		while(i!=ind)
		{
			vector_array[i]=vector_array[i-1];
			i--;
		}
		vector_array[i]=temp;
	}
	void erase(int ind)
	{
		int i=ind;
		while(i!=index)
		{
			vector_array[i]=vector_array[i+1];
			i++;
		}
		index=index-1;
	}
	int front()
	{
		return vector_array[0];
	}
	int back()
	{
		return vector_array[index];
	}
	int& operator[] (int x) {																										
          return vector_array[x];
     }
};
int main()
{
	vector v;
	vector v1(2,3);
	cout << v.size()<<"\n";
	v.push_back(2);
	v.push_back(6);
	v.push_back(7);
	v.push_back(5);
	v.push_back(9);
	v.push_back(10);
	v.push_back(11);
	cout << v.size()<<"\n";
	v.pop_back();
	v.pop_back();
	for(int i=0;i<=v.index;i++)
		cout << v[i] << " ";
	cout << "\n";
	v.insert(3,10);
	for(int i=0;i<=v.index;i++)
		cout << v[i] << " ";
	cout << "\n";
	v.erase(3);
	for(int i=0;i<=v.index;i++)
		cout << v[i] << " ";
	cout << "\n";
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v.size()<<"\n";

	cout << v1.size()<<"\n";
	v1.push_back(8);
	cout << v1.size()<<"\n";
	v1.push_back(10);
	cout << v1.size()<<"\n";
	v1.push_back(11);
	cout << v1.size()<<"\n";
	v1.pop_back();
	v1.pop_back();
	cout << v1.size()<<"\n";
	
	for(int i=0;i<=v1.index;i++)
		cout << v1[i] << " ";
	cout << "\n";
	cout << v1.size()<<"\n";
}