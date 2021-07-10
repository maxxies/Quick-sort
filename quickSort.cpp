#include<iostream>
#define MAX_SIZE 101

using namespace std;

int arr[MAX_SIZE];
int newArray[MAX_SIZE];
void arrayPartition(int arr[],int a, int b);
int main(){

    int total;
    int start = 0;
    cout<<"Total numbers: "<<endl;
    //Checks and validates input
    while(!(cin>>total)){
        cout<<"An error has occurred.\nEnter a number: "<<endl;
        cin.clear(); //clears input
        cin.ignore(123,'\n'); //discards previous input
    }
    for(int i = 0; i < total; i++){
        cout<<"Enter number: "<<endl;
        int nums;
        while(!(cin>>nums)){
            cout<<"An error has occurred.\nEnter a number: "<<endl;
            cin.clear(); //clears input
            cin.ignore(123,'\n'); //discards previous input
        }
        arr[i] = nums; //adds valid input to an array
    }
    //Prints array
    cout<<"\nNumbers entered:"<<endl;
    for(int i = 0; i<total;i++){
        cout<<arr[i]<<" ";
    }

    arrayPartition(arr,start,total);

    cout<<"\nNumbers sorted:"<<endl;
    for(int i = 0; i<total;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void arrayPartition(int arr[],int a, int b){
    if(a>=b){
        return;
    }
    else{
        //cout<<b<<endl;
        int pivot = arr[b - 1];
        int marker = a-1;
        int temp1;
        int temp2;
        int n;
        for(n = a; n < b ;n++){
            if(arr[n] < pivot){
                marker+=1;
                temp1 = arr[n];
                arr[n] = arr[marker];
                arr[marker] = temp1;
                //cout<<marker<<endl;
            }
        }
        //cout<<pivot<<endl;
        //cout<<n<<endl;
        temp2 = pivot;
        arr[b - 1] = arr[marker + 1];
        arr[marker + 1] = temp2;

        //cout<<"finished"<<endl;
        arrayPartition(arr,a, marker+1);
        arrayPartition(arr,marker+2, b);
    }

}
