#include<iostream>

#include<math.h>
#include<stdlib.h> 
using namespace std; 
	struct ts
{
	int size;
	int top1,top2;
	int arr[100];
}stk;
makestacks(int n)
{
	stk.size=n;
	stk.top1=-1;
	stk.top2=n;
	
	
}
 void push1(int x) 
   { 
        stk.top1++; 
        stk.arr[stk.top1] = x; 
      
   }  
   void push2(int x) 
   { 
        stk.top2--; 
        stk.arr[stk.top2] = x; 
   } 
  
  
   int pop1() 
   { 
        int x = stk.arr[stk.top1]; 
        stk.top1--; 
        return x;
   }  
   int pop2() 
   { 
          int x = stk.arr[stk.top2]; 
          stk.top2++; 
          return x; 
      
   } 
   
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void selectionsort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
   
    for (i = 0; i < n-1; i++)  
    {  
       
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
     
        swap(&arr[min_idx], &arr[i]);  
    }  
} 
int mod(int a[],int n) {
   int maxValue = 0, maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;
      
      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }

   return maxValue;
} 
int main() 
{ 
	int n,m,oper,stack,ind; cin>>n>>m; int aux[100],r=0;

	
    makestacks(n); 
    while(m--)
    {
    	cin>>oper>>stack>>ind;
    	if(oper==1)
    		aux[r++]=ind;
    	if(oper==1)
    	{
    		if(stack==1)
    			push1(ind);
    		else
    			push2(ind);
		}
		else
		{
			if(stack==1)
    			pop1();
    		else
    			pop2();
		}
	}
	int N=stk.top1+1+(n-stk.top2);
	int b[N],s=0;
	for(int i=0;i<stk.top1+1;i++){
		b[i]=stk.arr[i];
		}
	for(int i=stk.top1+1;i<N;i++){
		int c=1;
		b[i]=stk.arr[n-c];
		c++;
		}
	int c[N];
	for(int i=0;i<N;i++)
	c[i]=b[i];
	for(int i=0;i<r;i++)
	s=s+aux[i];
		
	float mean=s/r;
	
	selectionsort(b,N);
	double median = (N%2==0)?(b[N/2-1]+b[N/2])/2:b[N/2];
	
	double mode = mod(c,r);
	double d=0,dev;
	for(int i=0;i<r;i++)
		d=d+(aux[i]-(double)s/r)*(aux[i]-(double)s/r);
	dev=d/r;
	double stddev=sqrt(dev);
	
	cout<<(double)s/r<<" "<<median<<" "<<mode<<" "<<stddev<<endl;

		for(int i=0;i<N;i++){
		
		cout<<c[i]<<" ";
		if(i==stk.top1)
			cout<<endl;}
			
		
  return 0;
} 
