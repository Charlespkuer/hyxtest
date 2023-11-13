#CP课程作业说明文档

`黄羽翔 2100011536`

**语言、环境说明：** 利用b站上的教程，在VSCode上配置了C/C++语言环境，使用MinGW作为编译器，C/C++扩展版本为1.8.4，在控制台中运行.cpp文件。.py文件利用IDLE运行即可（可能需要装一些常见包），.nb文件利用wolfram notebok运行即可。

##第一次作业

###1、数值误差的避免

**源文件**：`1.cpp`
**可执行文件**：`1.exe`
**输入格式**：出现文字`开始请扣1`时请扣`1`开始，输入其它数字将在输入完成后输出`不算啦！`。后出现文字`输入保留小数位数a，输入小于等于0的数以采用科学计数法`时，请输入`正整数`以确定输出结果在小数点后的保留位数，输入小于等于0的数将在输入完成后利用科学计数法输出
**输出格式**：周期性输出`x=...时`，`a方法得到e^-x=...`，`b方法得到e^-x=...`，`c方法得到e^-x=...`

###2、矩阵的模与条件数

**源文件**：`2.cpp`
**可执行文件**：`2.exe`
**输入格式**：显示`请输入矩阵A阶数n：`，输入正整数以创建n阶矩阵A
**输出格式**：若计算得到矩阵行列式不为0，则显示`矩阵A行列式为：...`，`由于矩阵A行列式不为0，故A不为奇异矩阵`。若矩阵行列式为0，则显示`矩阵A行列式为：0`，`由于矩阵A行列式为0，故A为奇异矩阵`，并显示矩阵A逆矩阵的计算结果

###3、Hilbert 矩阵

**源文件**：`3.cpp`
**可执行文件**：`3.exe`
**输入格式**：计算第三小问，显示`输入1-10之间的整数n以计算H_n，输入其它数以跳过此问`，随后显示`输入保留小数位数a，输入小于等于0的数以采用科学计数法`，本问计算完成后计算第四小问，显示`输入保留小数位数a，输入小于等于0的数以采用科学计数法`，按照提示输入即可
**输出格式**：第三小问输出`H_n=...`，第四小问循环输出`n=...时`，`使用GEM算法得到解为`，`x={ ... ... }`，`使用Choleskey算法得到解`，`x={ ... ... }`

###4、矩阵与二次型

**源文件**：`4.nb`
**输出格式**：利用mathematica的wolfram notebook打开即可

###5、正定矩阵
