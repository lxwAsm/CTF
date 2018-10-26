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
