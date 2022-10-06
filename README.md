# __C++ - Leetcode__
---
## Day 1
### 1.学习使用git
* 首先创建一个空的文件夹用于存放将要下载的项目
* 找到目标项目在GitHub中存放的地址，__复制__
* 在空文件夹中右键，选择 __Git Bash Here__
* 在弹出的命令行窗口使用 __git clone [目标项目地址]__
* 打开下载的文件夹，右键使用VSCode打开即可

### 2.学习使用VScode编译C++程序的整个过程
成功在VScode中实现C/C++环境的搭建，中间牵扯到不同的终端问题，现在使用cmd终端
### 3.时间复杂度
* __时间复杂度定义：__*假设算法的问题规模为n，那么操作单元数量便使用函数f(n)表示，随着数据规模的增大，算法执行时间的增长率和f(n)的增长率相同，这叫做算法的渐进时间复杂度，简称时间复杂度，记为O(f(n)).*
* __时间复杂度的顺序:__*O(1)常数阶 < O(logn)对数阶 < O(n^2)平方阶 < O(n^3)立方阶 < O(2^n)指数阶* （不在考虑常数项，系数或是常数项）
* __复杂表达式的简化:__

  * 去掉运行时间中的加法常数项 
  * 去掉常数系数
  * 只保留最高项
---
## Day 2
暂时的想法使用使用transformer模型，针对每一个输入变量，具体指历史功率数据、天气变量等分贝使用transformer进行特征提取，只使用encoder部分，然后将得到的信息融合进行预测
参考论文：
另一方面就是看看基于天空图像的论文，这个肯定要参考辐照度预测的文章



