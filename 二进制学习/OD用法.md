## 基本调试方法

- F2 设置断点，只要在光标定位的位置，按F2即可，再按一次F2则会删除断点
- F8 单步步过， 每按一次这个键执行一条反汇编窗口的一条指令，遇到CALL等子程序不进入其代码
- F7 单步步入，功能同F8类似，区别是遇到CALL等子程序是会进入，进入后停在子程序的第一条指令上
- F4  运行到指定位置，作用是直接运行到光标所在的位置处暂停
- F9   运行。
- Ctrl+F9   执行到返回，此命令在执行到一个ret指令时暂停，常用于从系统领空返回到用户调试的程序领空
- Alt+F9   执行到用户代码，可用于从系统领空快速返回到用户调试的程序领空



## 

