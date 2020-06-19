## easyre  

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
