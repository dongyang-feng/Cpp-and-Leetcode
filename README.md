# __C++ - Leetcode__
## Day 10-5
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
## Day 10-6
* 暂时的想法使用使用transformer模型，针对每一个输入变量，具体指历史功率数据、天气变量等分别使用transformer进行特征提取，只使用encoder部分，然后将得到的信息融合使用全连接层进行预测
* 另一方面就是看看基于天空图像的论文，这个肯定要参考辐照度预测的文章
## Day 10-7
* 学习了 **TFT（Temporal Fusion Transformers）** 模型，来自论文 **[Temporal Fusion Transformers for interpretable multi-horiizon times series forecasting](https://www.sciencedirect.com/science/article/pii/S0169207021000637)**。TFT是transformer的一种变体，论文中的消融实验发现，针对如光伏功率这样的周期性较强的数据，整个TFT架构中发挥较大作用的模块是**self-attention部分**，启示可以考虑其他类似的transformer变体。<br>
在22年论文 **[Application of Temporal Fusion Transformer for Day-Ahead PV Power Forecasting](https://www.mdpi.com/1996-1073/15/14/5232)** 中使用TFT进行提前一天的光伏功率预测，还没有看到与数据融合和算法优化同时应用TFT模型， 不过在风速预测中有一篇22年发表于Energy的文章 **[Interpretable wind speed prediction with multivariate time series and temporal fusion transformers](https://www.sciencedirect.com/science/article/abs/pii/S0360544222008933)** 有了类似的思路进行VMD+ADE+TFT的融合模型，可以作为参考。
* **[Temporal Fusion Transformers for interpretable multi-horiizon times series forecasting](https://www.sciencedirect.com/science/article/pii/S0169207021000637)** 考虑了多种变量，包括静态协变量、外部数据（其他输入变量的历史相关信息）、以及未来分布已知的输入，整个的模型架构如下图所示：
<div align="center">
	<img src="https://ars.els-cdn.com/content/image/1-s2.0-S0169207021000637-gr2.jpg" width="60%">
</div><br>
后续补全该篇文章的阅读心得

## Day 10-8
**[Application of Temporal Fusion Transformer for Day-Ahead PV Power Forecasting](https://www.mdpi.com/1996-1073/15/14/5232)**(Energies)<br>
* **Main idea**:首次使用TFT作为预测模型实现提前一天光伏功率的每小时点预测<br>
**输入变量：** 如下表所示
<div align="center">
	<img src="https://github.com/dongyang-feng/C-Leetcode/blob/main/Energies-22-TFT-inputs.jpg" width="60%">
</div><br>
* 本篇文章是直接使用了TFT模型，没有其他的一些数据分解方法，这里出现的意义仅在于首次使用TFT进行光伏功率的预测作为一个记录。后续可以考虑实现区间预测，以及加入数据分解的方法<br>
<br>

**[Interpretable wind speed prediction with multivariate time series and temporal fusion transformers](https://www.sciencedirect.com/science/article/abs/pii/S0360544222008933)** (Energy)<br>
* 这篇文章的实验细节等交代的都很清楚，可以仔细的研究参考。

## Day 10-10
**[Temporal Fusion Transformers for interpretable multi-horiizon times series forecasting](https://www.sciencedirect.com/science/article/pii/S0169207021000637)**<br>
<div align="center">
	<img src="https://ars.els-cdn.com/content/image/1-s2.0-S0169207021000637-gr2.jpg" width="60%">
</div><br>

+ 这篇文章提出的 **Temporal Fusion Transformer** 模型主要应用于多步时间序列预测问题
  * 相较于传统的transformer模型具有较好的可解释性，可以量化的显示出各个变量对于某个时间步预测结果的重要程度；
  * 将输入变量划分为三类：1）仅有历史数据的变量（eg:气象因素等） 2）未来已知的变量（eg: 年月日等时间变量） 3）静态协变量（不变的值，文章很重视该变量的作用）；
  * 损失函数：使用联合分位数损失，相应可以在每个时间步得到不同分位数的预测值，后续会进一步介绍。
+ 模型结构
  * 门控机制（Gating mechanisms）： **GRN** 文章中使用最多的网络结构，可以让模型仅在需要的时候对输入进行非线性处理，让模型可以更复杂以应对更复杂的模型，中间关键的是使用GLU作为激活函数，达到非线性处理目的<br>
  ![GRN](https://github.com/dongyang-feng/C-Leetcode/blob/main/Gating%20mechanisms.png)<br>
  * 变量选择网络（Variables election networks）:模型对所有三种输入都使用了变量选择网络，作用首先可以关注到对预测结果重要的变量，其次能移除掉输入中的不必要的输入。变量选择网络的输入是各个变量，针对离散变量使用 **Entity embeddings** 的方法得到其特征表示，对于连续变量使用**线性变换**得到一个d维的向量。每种变量有一个GRN网络，并且在所有时间步上共享参数，进行特征选择的使用使用到权重的概念，跟注意力机制有些相似，但是不完全相同。特征选择执行过后，每个时间步得到一个特征向量。<br>
  ![VSN](https://github.com/dongyang-feng/C-Leetcode/blob/main/VSN.png)<br>
  * 静态协变量编码器（Static covariate encoders）:使用四个GRN网络，以静态协变量作为输入得到四个不同的嵌入向量，分别在不同的地方用到
  * 使用Seq2Seq进行局部增强：编码器和解码器使用的都是LSTM，编码器的隐状态和cell state使用静态协变量编码器的两个输出值进行初始化，另外编码器每个时间步的输入是t时刻之前的特征向量，解码器使用的是t时刻之后的特征向量，LSTM处理得到的结果还需要使用GLU和残差处理，具体形式如下式所示：<br>
  ![Seq2Seq](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-48-22.png)<br>
  * 静态增强层（Static enrichment layer）： 对Seq2Seq进行局部增强得到的向量在使用GRN网络进行静态增强，这里GRN的参数在所有时间步上是共享的<br>
  ![SEL]()<br>
  * 可解释的多头注意力机制（Interpretable multi-head attention）：对多头注意力机制进行了修改，如下列公式所示：<br>
  ![](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-38-43.png)<br>
  ![](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-38-52.png)<br>
  
  
  









