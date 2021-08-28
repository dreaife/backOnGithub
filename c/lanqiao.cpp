#include <iostream>
#include <string>
using namespace std;
int main(){
  string arr;
  int num[26]={0};
  int max=0;
  char max_sq;
  cin>>arr;
  for(int i=0;i<arr.length();i++){
    num[arr[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if(num[i]>=max){
      max=num[i];
      max_sq=char('a'+i);
    }
  }
  cout<<max_sq<<endl;
  cout<<max;
  return 0;
}
