# CTF
some collecte ctf exercises including re,misc,crypto,web

# crackme1.exe writeup  
import base64  

s = base64.b64decode("bWdqbHBPOEY/VHM6Uj9UfD9FeF5Cdg==")  
for i in s:  
    for j in "main":  
        i=i^ord(j)  
    print(chr(i),end="")  
    
# CRACKME.ZIP writeup  
name = "NNNN" 名字必须是大写  
s = 0  
for i in name:  
    s+=ord(i)  
print(i^0x5678^0x1234);

# Pusillus.exe Writeup  
flag =[0x71, 0x18, 0x59, 0x1B, 0x79, 0x42, 0x45, 0x4C]  
for i in range(0,len(flag)):  
    flag[i]^=0x32  
d = []  
for i in range(0,len(flag),2):  
    d.append(flag[i]^flag[i+1])  
t = d[0]^d[1]^d[2]^d[3]  
for i in range(0,len(flag)):  
    flag[i]^=t  
result = [chr(x) for x in flag]  
print("".join(result))

# 国色天香.exe writeup  
char	*namebuf = "12345";  
int	namesize = 5;  
char	buffer[100] = { 0 };  
int i = 0;  
do {  
&nbsp；&nbsp；&nbsp；&nbsp；char cVar5 = (namebuf[i] ^ 0x29) + namesize;  
&nbsp；&nbsp；&nbsp；&nbsp；if ((cVar5 < 'A') || ('Z' < cVar5)) {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；cVar5 = namesize + 'R';  
&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；buffer[i] = cVar5;  
&nbsp；&nbsp；&nbsp；&nbsp；(buffer+1)[i] = 0;  
&nbsp；&nbsp；&nbsp；&nbsp；i = i + 1;  
&nbsp；&nbsp；&nbsp；&nbsp；namesize = namesize-1;  
} while (namesize != 0);  
i = 0;  
namesize = 5;  
do {  
&nbsp；&nbsp；&nbsp；&nbsp；char cVar5 = (namebuf[i] ^ 0x27) + namesize + 1;  
&nbsp；&nbsp；&nbsp；&nbsp；if ((cVar5 < 'A') || ('Z' < cVar5)) {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；cVar5 = namesize + 'M';   
&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；(buffer+5)[i] = cVar5;  
&nbsp；&nbsp；&nbsp；&nbsp；(buffer+6)[i] = 0;  
&nbsp；&nbsp；&nbsp；&nbsp；i = i + 1;  
&nbsp；&nbsp；&nbsp；&nbsp；namesize = namesize + -1;  
} while (namesize != 0);  
int j = 0;  
for (int j = 0; buffer[j] != 0; j++){  
&nbsp；&nbsp；&nbsp；&nbsp；char cipher = buffer[j] + 5;  
&nbsp；&nbsp；&nbsp；&nbsp；if ('Z' < (char)cipher) {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；cipher = (buffer)[j] - 8;  
&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；cipher = cipher ^ 0xc;  
&nbsp；&nbsp；&nbsp；&nbsp；if ((char)cipher < 'A') {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；cipher = (char)j + 0x4b;  
&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；else {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；if ('Z' < (char)cipher) {  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；cipher = 0x4b - (char)j;  
&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；}  
&nbsp；&nbsp；&nbsp；&nbsp；printf("%c", cipher);  
}  
printf("\ndone");  
system("pause");  
