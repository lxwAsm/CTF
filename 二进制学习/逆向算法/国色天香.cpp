#include <iostream>
#include <string>
using namespace std;
int main(){
	string s="1234566";
	string s2="";
	string s3="";
	int i = 5;
	int j =0;
	do{
		char x = i + (s[j]^0x29);
		//cout<< x << "||"<<(s[j]^0x29)<<endl;
		if(x<65||x>90){
			x = i+ 82;
		}
		cout<<s[j]<<":"<<x<<endl;
		s2+=x;
		i--;
		j++;
	}while(i);
	cout<<s2<<endl;
	i=5;
	j=0;
	do{
		char x = i + (s[j]^0x27)+1;
		if(x<65||x>90)
			x = i+77;
		cout<<s[j]<<":"<<x<<endl;
		s2+=x;
		i--;
		j++;	
	}while(i);
	cout<<s2<<endl;
	for(int k= 0;i<10;i++){
		char c = s2[k]+5;
		char m;
		if(c>90){
			c-=13;
		}
		m =  c^0xc;
		cout<<m<<endl;
		if(m<65){
			m=k+75;
		}
		if(m>90){
			m =75-k;
		}
		k++;
		s3+=m;
	}
	cout<<s3;
	return 0;
}
