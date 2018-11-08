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


