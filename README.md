# CTF
some collecte ctf exercises including re,misc,crypto,web

# crackme1.exe writeup
import base64

s = base64.b64decode("bWdqbHBPOEY/VHM6Uj9UfD9FeF5Cdg==")
for i in s:
    for j in "main":
        i=i^ord(j)
    print(chr(i),end="")
