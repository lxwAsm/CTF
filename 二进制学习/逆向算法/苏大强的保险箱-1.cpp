#include <iostream>
#include <string>
using namespace std;

int main(){
	char a[10]={0x0A,0x7,0x41,0x0B,0x2C,0x0C,0x3D,0x38,0x27,0x73};
	char b[10]={0xD5,0x9E,0xB4,0x70,0x78,0x60,0x82,0x70,0x39,0x5E};
	string s="";
	for(int i=0;i<10;i++){
	   s+=b[9-i]-i-a[i]	;
	}
	
	//�ַ���������� 
	for(int i =s.size();i>=0;i--){
		cout<<s[i];
	}
	return 0;
}
