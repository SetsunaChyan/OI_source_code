<p align="center"><font face="华文中宋" size=5>USSTSIW-ACM集训队练习赛第49场</font></p>



激动人心的滚榜被我搞砸了QAQ，期待一下正式赛的滚榜吧。



#### A. Haruhi with Reincarnation

一个提交也没有鸭，我又一次完成了零封。

题目是个裸的线段树区间修改区间查找，状态压缩了以后区间改就是按位或，区间查就是按位与，然后就做完了呀。




#### B. Haruhi with Circle

<font face="微软雅黑">First solved: 林嘉麒, 01:12 (+3).</font>

n个小圆的圆心与大圆圆心所构成的圆心角的和是否大于2*π，如下图所示：

​                  ![B](F:\CPP\OI\CF_RJY_LYD\USST\49\problems\B.jpg)                                

由上图可知，$∠a=asin(r/(R-r))$ ，即判断 $2*n*∠a$ 是否大于 $2*π$（**这里的 $π$ 可用 $acos(-1.0)$ 求得**），也就是判断 $π-n* asin(r/(R-r))$ 是否大于 $0$ ，如果大于等于说明能放置 $n$ 个小圆，否则不能放置。这里要注意一下精度问题，因为 $acos(-1.0)$ 计算得到的π位数有限，因此，你需要给它加上一个极小值 $eps$ （例如 $eps=1e-8$ ）来保证题目的精度要求，也即：

**if(n>1 && acos(-1.0)+1e-8-n\* asin(r/(R-r))>=0)  cout<<”Yes”;**

**这里有一个特判：**当 $n=1$ 的时候，只有在满足 $R>=r$ 的情况下才输出”Yes”，否则输出”No”。




#### C. Haruhi with Bookcase

<font face="微软雅黑">First solved: 李扬, 02:02 (+).</font>

被题面埋没得水题。不妨设原书列放在 $1-n$ 的位置上，因为不存在任何删除操作，后续放的书只需要依次往左右堆放即可，仅记录最左侧与最右侧的书的位置 $l$ 与 $r$ ，对于查询，首先需要得到他在书列中的位置，可以插入时用 $map<int,int> $ 维护，之后看它离 $l$ 近还是 $r$ 近。



#### D. Haruhi with Colors

<font face="微软雅黑">First solved: 邓浩然, 00:12 (+).</font>

做法应该有很多，可以顺序找到第一个形如![D](F:\CPP\OI\CF_RJY_LYD\USST\49\problems\D.png)的 $0$ ，然后涂满这个 $0$ 所在的联通域就行。



#### E. Haruhi with CS

<font face="微软雅黑">First solved: 阙寅清, 00:18 (+).</font>

每次射击对方一半的人 $(n/4)$ ，三轮攻击下来最多射中 $(n/2+n/4)$ 。



#### F. Haruhi with Balloon

<font face="微软雅黑">First solved: 邓浩然, 01:08 (+).</font>

字符串排序。方法有很多，你可以用 $struct$ 存放三个题目中的变量，然后根据题目要求重新编写 $sort$ 的比较函数，输出答案即可。当然，你也可以使用 $map<sting,map<string,int>>$ 结构，因为 $map$ 默认按照字典序升序排列，所以唯一需要处理的就是将相同产地和颜色的气球累加即可，按格式输出结果就 $ok$ 了。



#### G. Haruhi with Warmth

<font face="微软雅黑">First solved: 邵世林, 00:03 (+).</font>

$C$ 语言课后练习题难度，不用我多说了8。



#### H. Haruhi with Translation

<font face="微软雅黑">First solved: 林嘉麒, 00:07 (+).</font>

字符比较。首先判断两个字符串长度是否一致，如果长度不一样则结果必为“NO”。如果长度一致，则依次比较两个字符串的首尾是否一样，如果在比较的过程中发现有两个对应位置的字符不一样，就跳出循环输出“NO”。如果比较到最后一个字符都一样，输出“YES”。

