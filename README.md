# efficiency_contrast_octave_matlab_python_c-
octave matlab python c++速度/效率 对比 附动图

博客链接：https://blog.csdn.net/weixin_42378324/article/details/108299779

**本文中所用的测试程序只包含基本运算和for循环，即本文并不探究这几种语言在进行向量/矩阵运算以及各种优化操作时的效率问题。**
测试程序为计算一维热传导的代码，每完成1s的计算输出一次（计算1s需要500次内层循环（这个内层循环里还有一个几十次的循环））

计算30分钟 matlab与c++的耗时为 3s
计算2分钟 python的耗时为 31s，octave的耗时为210s

结论：**当只进行基本运算和for循环时，matlab的效率与c++不相上下，python与其相差约两个数量级，而octave又与python相差约一个数量级**

可以看动图直观感受一下：
#### octave
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200829224613175.gif#pic_center)
#### matlab
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200829224647335.gif#pic_center)
#### python
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200829224908117.gif#pic_center)
#### c++
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200829224949681.gif#pic_center)

为了和matlab程序达到近似的运算量，对其他语言的程序进行了修改，所以逻辑上是不正确的，正确的代码我会在近期的一篇讲解18国赛a题的文章中贴出）
matlab测试程序，来源：18国赛a题优秀论文）
