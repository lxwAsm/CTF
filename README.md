# CTF
some collecte ctf exercises including re,misc,crypto,web  
[CTF wiki](https://wiki.x10sec.org/)  
[博客](https://blog.csdn.net/CosmopolitanMe)    

# easyre  

---

BUUCTF刷题----RE第一题

---

### 运行程序观察程序特征

题如其名，运行过程真就很easy，命令行平白直叙：

![图1](https://github.com/lxwAsm/CTF/blob/master/%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%A6%E4%B9%A0/easyre/1.PNG)

过程简单：输入  回车完事



### 查壳

使用EXEinfo查壳，发现无壳



### IDA分析

因为没啥有用信息，所以直接把程序拖入IDA 分析

![图2](https://github.com/lxwAsm/CTF/blob/master/%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%A6%E4%B9%A0/easyre/2.PNG)





如上图所示，程序流程很简单，过程很明显，可以清楚看到Flag



### 算法逆向

IDA F5可得到大概流程

![图4](https://github.com/lxwAsm/CTF/blob/master/%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%A6%E4%B9%A0/easyre/4.PNG)

可知 ：该程序 输入两次 判断两次输入字符串是否相等：

- 相等： 输出Flag
- 不相等： 输出 Sorry语句

注意：**由于程序运行问题，结果输出一闪而过，需要下断点才能看到输出的字符串**

![图3](https://github.com/lxwAsm/CTF/blob/master/%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%A6%E4%B9%A0/easyre/3.PNG)



### 另辟蹊径

由于程序很简单，我原本初步的推测是输入固定的字符串与程序中已经存储的字符串进行对比来判断是否输出Flag

程序中的固定字符串 一般存在数据段，所以我用PEview查了以下该EXE，在.rdata段发现了惊喜！

![图5](https://github.com/lxwAsm/CTF/blob/master/%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%A6%E4%B9%A0/easyre/5.png)



### 总结

- 该题比较简单，字符串明文存储，无壳，所以拖入IDA pro可以很清楚程序流程，得到Flag
- 或者在PE中也可以清楚看到Flag,该方式中前期对程序流程的预估有点失误，存在一定的巧合性和必然性

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
&nbsp;&nbsp;&nbsp;&nbsp;char cVar5 = (namebuf[i] ^ 0x29) + namesize;  
&nbsp;&nbsp;&nbsp;&nbsp;if ((cVar5 < 'A') || ('Z' < cVar5)) {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cVar5 = namesize + 'R';  
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;buffer[i] = cVar5;  
&nbsp;&nbsp;&nbsp;&nbsp;(buffer+1)[i] = 0;  
&nbsp;&nbsp;&nbsp;&nbsp;i = i + 1;  
&nbsp;&nbsp;&nbsp;&nbsp;namesize = namesize-1;  
} while (namesize != 0);  
i = 0;  
namesize = 5;  
do {  
&nbsp;&nbsp;&nbsp;&nbsp;char cVar5 = (namebuf[i] ^ 0x27) + namesize + 1;  
&nbsp;&nbsp;&nbsp;&nbsp;if ((cVar5 < 'A') || ('Z' < cVar5)) {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cVar5 = namesize + 'M';   
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;(buffer+5)[i] = cVar5;  
&nbsp;&nbsp;&nbsp;&nbsp;(buffer+6)[i] = 0;  
&nbsp;&nbsp;&nbsp;&nbsp;i = i + 1;  
&nbsp;&nbsp;&nbsp;&nbsp;namesize = namesize + -1;  
} while (namesize != 0);  
int j = 0;  
for (int j = 0; buffer[j] != 0; j++){  
&nbsp;&nbsp;&nbsp;&nbsp;char cipher = buffer[j] + 5;  
&nbsp;&nbsp;&nbsp;&nbsp;if ('Z' < (char)cipher) {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cipher = (buffer)[j] - 8;  
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;cipher = cipher ^ 0xc;  
&nbsp;&nbsp;&nbsp;&nbsp;if ((char)cipher < 'A') {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cipher = (char)j + 0x4b;  
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;else {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if ('Z' < (char)cipher) {  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cipher = 0x4b - (char)j;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;}  
&nbsp;&nbsp;&nbsp;&nbsp;printf("%c", cipher);  
}  
printf("\ndone");  
system("pause");  

# CrackHead.exe
DWORD	init_key(){  
&nbsp;&nbsp;&nbsp;&nbsp;unsigned int type;  
&nbsp;&nbsp;&nbsp;&nbsp;unsigned __int8 v1,v2;  
&nbsp;&nbsp;&nbsp;&nbsp;char	VolumeNameBuffer[100] = { 0 };  
&nbsp;&nbsp;&nbsp;&nbsp;type = GetDriveTypeA(0);  
&nbsp;&nbsp;&nbsp;&nbsp;GetVolumeInformationA(0, VolumeNameBuffer, 100, 0, 0, 0, 0, 0);  
&nbsp;&nbsp;&nbsp;&nbsp;v1 = (unsigned __int8)type;  
&nbsp;&nbsp;&nbsp;&nbsp;v2 = 0;  
&nbsp;&nbsp;&nbsp;&nbsp;do  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v2 += *(DWORD *)VolumeNameBuffer * v1--;  
&nbsp;&nbsp;&nbsp;&nbsp;while (v1);  
&nbsp;&nbsp;&nbsp;&nbsp;*(DWORD *)VolumeNameBuffer = v2;  
&nbsp;&nbsp;&nbsp;&nbsp;return v2 ^ 2038068563;  
}  

### 宛若游龙 
import string  
name = 'HardCodeD'  
buf = []  
for j in range(len(name)):  
&nbsp;&nbsp;&nbsp;&nbsp;t = ord(name[j]) % 10 ^ j;  
&nbsp;&nbsp;&nbsp;&nbsp;cipher = t + 2;  
&nbsp;&nbsp;&nbsp;&nbsp;if (10 < cipher):  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cipher = t - 8  
&nbsp;&nbsp;&nbsp;&nbsp;buf.append(cipher)  
print(buf)  
for i in buf:  
&nbsp;&nbsp;&nbsp;&nbsp;for j in string.printable:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if ord(j)%10==i:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print(j,end='')  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break  
&nbsp;&nbsp;&nbsp;&nbsp;else:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print(i,'not found')  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;exit(0)  
