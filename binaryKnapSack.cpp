#include<iostream>
#include<algorithm>
using namespace std;

class item{
    public:
    double weight;
    double profit;
    item(){
        weight=0;
        profit=0;
    }
    item(double w,double p){
        weight=w;
        profit=p;
    }
};
bool compareItemsByWeight(const item* a, const item* b) {
    return a->weight < b->weight;
}

 int findMax(int n1, int n2) {
      if(n1>n2) {
         return n1;
      } else {
         return n2;
      }}
int main(){
int capacity,num;
cout<<"Enter capacity:\n";
cin>>capacity;
cout<<"Enter number of items:\n";
cin>>num;

int arr[num+1][capacity+1];
item *items[num];
for(int i=0;i<num;i++){
double w,p;
cout<<"Enter weight:\n";
cin>>w;
cout<<"Enter profit:\n";
cin>>p;
items[i]=new item(w,p);
}

sort(items,items+num,compareItemsByWeight);

for(int i=0;i<=num;i++){
    for(int j=0;j<=capacity;j++){
        if(i==0||j==0){
            arr[i][j]=0;
        }
        else if(items[i-1]->weight<=j){
arr[i][j] = findMax(items[i-1]->profit + arr[i-1][j - (int)items[i-1]->weight], arr[i-1][j]);
        }
        else{
            arr[i][j]=arr[i-1][j];
        }

    }
}


 double maxProfit =(arr[num][capacity]);
 cout << "Maximum Profit: " << maxProfit << endl;
 return 0;
}