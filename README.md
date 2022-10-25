# __C++ - Leetcode__
## Day 10-25
* **oop面向对象编程**
  * **继承**
  * **组合composition**：has-a:类中有另外的类作为底层容器，可以完全借用底层容器的功能实现自己的功能
  * **委托**
* **static**：语法在类内的数据成员或者函数成员前面加上**static**关键字，静态成员是不是只能放在public区域？
  * 静态数据：主要用于存放该类创建的对象的公共属性，静态数据在类内声明，必须在类后面进行重新定义：格式double classname::r_rate=8.0,可以不加初值
  * 静态函数： 因为没有this point，不能处理非静态成员数据，只能处理静态数据。调用静态函数方法有两种：第一种通过对象调用，第二种通过类名调用
* **类模板**：设计的时候不写死数据类型，而是用一个T代替类型：template<typename T>,使用时：classname<double> 变量名...
* **函数模板**：在使用的时候不用用尖括号指明输入参数的类型，就是标准库中算法
* **namespace**: 
## Day 10-24
* 主要是进行了包含指针的类String的构建
* 在类中进行声明是很关键的，比如一个类或者一个函数在定义之前使用的话，如果不进行声明就会报错，这时就需要在前置声明区进行声明，声明之后的函数或者类，在后续程序中任何位置都能正常使用，无论是在定义之前还是在定义之后。
* 文件修改之后一定要记得ctrl+s进行保存，不然修改无效啊，很烦的
* classes可以分为两类：**有指针的和无指针的** ，自己创建的包含指针的类，一定要自己实现拷贝构造和拷贝赋值的函数，不能使用默认的，默认的话导致两个指针指向同一个内存单元，造成被赋值对象指针原来指向的内存泄漏。
* **浅拷贝和深拷贝** 现在的理解是，浅拷贝让指针指向了另外的一个地址，深拷贝，将另外一个地址的内容转移到自己的滋镇指向的地址中，拷贝构造函数和拷贝赋值函数就是在进行深拷贝的过程。
* **stack堆**：存在于某作用域（scope）的一块内存空间，例如调用函数的时候，函数本身就会形成一个stack用来放置它所接收的参数，以及返回地址；当函数调用结束后，这个stack就会被自动清除
* **heap栈**：由操作系统提供的一块global内存空间，程序可动态分配从其中获得若干区块，比如使用new申请的空间，程序员要负责该空间的整个生命周期，不用的时候要进行delete掉。
* **static local objects** 添加static关键字后，在某作用内创建的对象就变成了静态对象，生命周期在作用域结束后依然在，直到程序运行完成才调用该对象的析构函数释放内存。
* **全局对象** 声明在所有作用域之外的对象，可以成为全局对象生命周期贯穿整个程序
* **new**:先分配memory（使用malloc()），再调用创建对象的构造函数
* **delete**：先调用析构函数，再释放memory(内部调用free())
* new typename[n]和delete [] 搭配使用，否则会报错
## Day 10-23
* **防卫式声明**<br>
在头文件中添加特定的指令，实现防止重复加载头文件的作用<br>
#ifndef __CLASSNAME__<br>
#define __CLASSNAME__<br>
...<br>
#endif<br>
* 模板**template<typename T>**的使用，可以便于在使用类的时候再指定类内成员的类型，代码的重用性，例如vector<int> a;这样的形式
* 有些成员函数可以在类内直接定义，这样的函数称为**inline函数**，只能是简单函数，最终的决定权由编译器决定；也有些函数在类内仅进行声明，在类外进行定义
* class类内可以划分为两个部分，**私有和公有**的:一般数据和小部分函数设置为私有的，使用关键字private:,大部分成员函数设置为公有的public；
* 类的**构造函数**可以进行多次重载，一般创建在public区，不过有将构造函数创建在私有区的情况，参考*singleton；另外进行重载是有条件的，**构造函数尽量使用列表初始化的方法，尽量类成员的初始化**。
* 类的**常量成员函数**(不会改变类的数据内容的时候，在用符号()后面，函数体{}添加const，**添加const定义常量成员函数有重要意义**，后续在定义const类型的的类对象时，可以顺利调用其中方法，否则会报错
* **参数传递**: 值传递和引用传递(**尽量使用引用传递的方式**，实际上传递参数的地址，可以考虑使用const前修饰传递常量引用）
* **返回值传递**： 值传递和引用传递（**可以的话尽量使用引用传递**）：两种情况
  * 函数的返回结果是放在函数中新创建的地址中，因为是在函数中创建的，所以函数调用结束后，该地址就释放了，所以不能对函数结果进行引用传递。
  * 函数返回结果放在传入参数的地址中，此时传递进来的参数发生了改变，因此传递进来的参数不能定义为const，但是由于结果存放的地址不是在函数中创建的，所以可以使用引用传递的方式返回结果
* **友元(friend)函数**：可以在函数中直接使用类中定义在private中的成员
* **相同class的各个对象互为友元**：就是在类中的函数传递近来的参数
* **操作符重载**
  * 通过类成员函数实现：任何成员函数都有一个隐藏的this指针，指向调用该函数的成员，
* **this关键字**
## Day 10-21
* **vector标准库类型** <br>
vector是长度可变的集合，集合中存放的元素类型相同，在定义时要指明元素的类型。同样可以进行列表初始化和拷贝初始化，以及创建n个相同的元素,首先看能不能满足列表初始化。<br>
通常用法是创建一个空的vector，然后使用**v_name.push_back()** 方法添加元素。可以使用下标运算符访问已存在的元素 ，但是不能用于下标运算符添加元素。**v_name.size()** 返回大小，**v_name.empty()** 返回是否为空。<br>
* **迭代器** <br>
实现对容器的访问，所有的标准库都可以使用迭代器。迭代器类似于指针，其对象是容器中的元素或是字符串中字符，如果对象是类，可以进行解引用；迭代器的获得依靠两个成员**begin** 和**end**，**v_name.begin()** 返回指向容器第一个元素的迭代器，**v_name.end()** 返回指向容器尾元素的下一位置的迭代器。容器为空则begin和end返回同一个迭代器。标准容器迭代器的运算符： * iter 返回迭代器指向元素的**引用**; iter->mem 解引用iter并获取该元素名为mem的成员； ++iter； --iter； ==； ！=；*v_naem.cbegin()和v_name.cend()* 返回常量迭代器，只能对对象进行读操作，不能写操作。还有需要注意：<br>
  * 不能在范围for循环中想vector对象添加元素
  * 任何一种可能改变vector对象容量的操作都会使vector对象的迭代器失效
string和vector提供更多的对迭代器的运算： iter+n; iter-n; iter1-iter2; >,<,>=,<= <br>
* **数组**<br>
数组和vector类似，是存在类型相同对象的容器，不同之处在于数组大小固定，不能随意向数组中增加元素，也不能数组内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值。<br>
  * 数组定义和初始化： 
    * 默认初始化 **typedef  v_name[size](int a[5]);**
    * 列表初始化 **typedef v_name[]={_, _, _, ...}; **     使用列表初始化的时候可以选择不指明长度
  * 针对数组使用的begin和end函数，分别返回指向数组首元素的指针和尾元素下一位置的指针。
  * 数组和指针的关系：使用数组的名字相当于使用的一个指向数组首元素的指针
## Day 10-19
* **类型别名** <br>
两种方法定义等价的类型名,意味着类型别名和类型名等价<br>
  * **typedef**关键字：*typedef double wages；*
  * **using**关键字：*using wages = double；*
* **auto类型说明符** <br>
auto让编译器根据初始值推算变量的类型，auto定义的变量必须有初始值；另外auto会忽略掉顶层const，保留底层const
* **decltype类型说明符** <br>
编译器分析表达式并得到其类型，作为新变量的类型
* **定义数据结构**<br>
  * struct 类名 {类体} 对象名（可选）；**最后的分号不能少**；类中的变量没有进行初始化的时候，在创建变量的时候会进行默认初始化0，空字符串等。
* **头文件** 就是类名.h文件，存放只能被定义一次的实体，如类、const、constexpr变量等；牵扯到一个头文件多次包含的问题，用到头文件保护符在头文件开始加上下面的防卫式声明代码<br>
    *#ifndef SALES_DATA_H*<br>
    *#define SALES_DATA_H*<br>
    *...完整的Sales_data类定义*<br>
    *#endif*<br>
* **string**标准库类型
  * **拷贝初始化和直接初始化：** 拷贝初始化使用等号赋值的方式，等号右边可以是字符串常量或已经定义过的字符串变量名；直接初始化使用*string s1(10,'c')* 这种形式，注意只能是字符，不能是字符串。
  * 遍历字符串中所有字符可以使用范围for语句例如：*string s="ashfafh"; for (auto c ：s) {};* 如果想要改变字符串中的字符的话，要把循环变量定义成引用类型*for (auto &c ：s) {};*
  * 遍历一部分字符可以使用**下标运算符[]** 下标运算符的输入参数是string::size_type类型 和**迭代器**
  * string::size_type类型是size()方法的返回类型，也是字符串索引的类型，无符号类型。
## Day 10-18
* **const限定符** 使用const限定符对变量的类型进行限定，将变量变成一个常量（*const int val = 0；*）；同引用一样**创建const常量的时候必须初始化**
  + **const的引用** ：把引用绑定到const对象上，就不能通过引用改变其绑定的对象的值了，因为其绑定的对象是一个const常量，不允许改变。引用的类型必须和其所引用对象的类型相同，但是**第一种例外情况**：在初始化常量引用的时候，允许用任意表达式作为初始值，只要该表达式的值能转换成引用的对象即可。另外，**对const的引用可以引用一个并非常量的对象**。总结来说，对const引用的意思就是**给引用添加了const限定符之后，不允许通过这个引用修改其引用对象的值，而且在初始化的时候可以使用任何表达式，不在拘泥于必须和引用对象的类型相同**，格式：*const int &refval = a；*。
  + **指针和const**：<br>
    +  **指向常量的指针**：其实定义的指向常量的指针的对象可以是常量也可以是非常量，只不过不能使用这个指针改变指向对象的值，和常量引用类似，格式: const int *ptr = &b;
    +  **const指针**：因为指针是对象，可以将指针本身定义为常量,常量指针必须初始化，即其值就是存放的地址不允许改变，指向的对象不能改变了，格式: int *const curptr = &b;
    +  **顶层const**：指针本身是一个常量（后者是任意类型是常量）； **底层const**：指针指向的对象是一个常量（与指针和引用等复合类型的基本类型部分有关）
## Day 10-16
完成了 **TFT** 模型的构建后续有两个任务：<br>
* 数据在模型中流动的时候维度变化情况，这个一定要搞明白的
* 使用的数据集用pd模块处理，构建成需要的数据格式

## Day 10-11
**学习[pytorch-forecasting](https://pytorch-forecasting.readthedocs.io/en/stable/getting-started.html)** <br>

## Day 10-10
**[Temporal Fusion Transformers for interpretable multi-horiizon times series forecasting](https://www.sciencedirect.com/science/article/pii/S0169207021000637)**<br>
<div align="center">
	<img src="https://ars.els-cdn.com/content/image/1-s2.0-S0169207021000637-gr2.jpg" width="60%">
</div><br>

+ 这篇文章提出的 **Temporal Fusion Transformer** 模型主要应用于多步时间序列预测问题
  * 相较于传统的transformer模型具有较好的可解释性，可以量化的显示出各个变量对于某个时间步预测结果的重要程度；
  * 将输入变量划分为三类：1）仅有历史数据的变量（eg:气象因素等） 2）未来已知的变量（eg: 年月日等时间变量） 3）静态协变量（不变的值，文章很重视该变量的作用）；
  * 损失函数：使用联合分位数损失，相应可以在每个时间步得到不同分位数的预测值，后续会进一步介绍。
+ **模型结构**
  * **门控机制（Gating mechanisms）**： **GRN** 文章中使用最多的网络结构，让模型仅在需要的时候对输入进行非线性处理，使模型能有效处理复杂的情况，中间关键的是使用GLU作为激活函数，达到非线性处理目的<br>
  ![GRN](https://github.com/dongyang-feng/C-Leetcode/blob/main/Gating%20mechanisms.png)<br>
  * **变量选择网络（Variables election networks）**:模型对所有三种输入都使用了变量选择网络，作用首先可以关注到对预测结果重要的变量，其次能移除掉输入中的不必要的输入。变量选择网络的输入是各个变量，针对离散变量使用 **Entity embeddings** 的方法得到其特征表示，对于连续变量使用**线性变换**得到一个d维的向量。每种变量有一个GRN网络，并且在所有时间步上共享参数，进行特征选择的使用到权重的概念，跟注意力机制有些相似，但是不完全相同。特征选择执行过后，每个时间步得到一个特征向量。<br>
  ![VSN](https://github.com/dongyang-feng/C-Leetcode/blob/main/VSN.png)<br>
  * **静态协变量编码器（Static covariate encoders）**:使用四个GRN网络，以静态协变量作为输入得到四个不同的嵌入向量，分别在不同的地方用到
  * **使用Seq2Seq进行局部增强**：编码器和解码器使用的都是LSTM，编码器的隐状态和cell state使用静态协变量编码器的两个输出值进行初始化，另外编码器每个时间步的输入是t时刻之前的特征向量，解码器使用的是t时刻之后的特征向量，LSTM处理得到的结果还需要使用GLU和残差处理，具体形式如下式所示：<br>
  ![Seq2Seq](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-48-22.png)<br>
  * **静态增强层（Static enrichment layer）**： 对Seq2Seq进行局部增强得到的向量在使用GRN网络进行静态增强，这里GRN的参数在所有时间步上是共享的<br>
  ![SEL](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-48-38.png)<br>
  * **可解释的多头注意力机制（Interpretable multi-head attention）**：对多头注意力机制进行了修改，如下列公式所示：<br>
  ![](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-38-43.png)<br>
  ![](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_21-38-52.png)<br>
  * **时间自注意力层（Temporal self-attention layer）**：使用上面介绍的可解释多头注意力机制，输入将上一层静态增强层的所有时间步的结果组成一个矩阵（K+t+1*d）
  * **位置前馈层（Position-wise feed-forward layer）**：该层到最后的输出结果之间多次使用了GRN网络、GLU和残差连接。
+ **损失函数**：（loss function）<br>
![](https://github.com/dongyang-feng/C-Leetcode/blob/main/Snipaste_2022-10-10_22-07-42.png)<br>

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





  
  
  









