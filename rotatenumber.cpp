// Online C++ compiler to run C++ program online
#include <iostream>
#include <array>
using namespace std; 
void rotate_first(int arr[], int n) {
    int last_element = arr[n-1];
  for(int i=n-1; i>0; i--)
  arr[i]=arr[i-1];
  arr[0]=last_element;
}
int main(){
    
    int n;
	int r; 
    cout<<"Enter the limit of  Array";
    cin>>n;
	cout<<" Enter the number of rotation";
    cin>>r;
    int arr[n];
    cout<<"Enter the array";
    for (int i = 0; i<n;i++)
{
	cin>>arr[i];
}


for (int j = 0;j<r;j++){
	rotate_first(arr, n);
}

cout << "The rotated array is: [";
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
    
