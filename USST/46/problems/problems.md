### E.Haruhi's present

求 $(a \times x + b\times y)^k$ 的第 $n$ 项的系数 ( $x$ 的次数为 $n$ 的那一项) 对 $10007$ 取模的值。



#### INPUT

**多组输入，请处理到文件尾，请使用较快的输入输出方式。**

最多 $4 \times 10^5$ 组数据。

每组一行四个整数 $a,b,k,n(1 \leq a,b \leq 10^6,1 \leq k \leq 1000,0 \leq n \leq k)$ 。



#### OUTPUT 

每组一行一个整数。



#### SAMPLE INTPUT

1 1 3 1
1 1 4 2



#### SAMPLE OUTPUT

3
6



### F.Haruhi's Polygon Number

多边形数定义如下：

$Triangle$ ，$T_n=\frac{n \times (n+1)}{2}$。

$Pentagonal$ ，$P_n=\frac{n \times (3n-1)}{2}$。

$Hexagonal$ ，$H_n=n \times (2n-1)$。

$Haruhi$ 发现 $T_{285} = P_{165} = H_{143} = 40755$ ，现在她想知道下一对满足 $T_a=P_b=H_c=X$ 时的 $X$ 的值。



#### INPUT

无



#### OUTPUT

一行一个整数 $X$ 。





### I.Haruhi's Mogic

$Haruhi$ 的阿狸跑掉了！

$Haruhi$ 幻想着使用她的魔法找回阿狸。然而报道出了偏差，于是她学会了膜法。

在她的幻想中，使用魔法需要咏唱一段咒文，幸运的是咒文就是下式的值。

$$
\sum_{i=1}^{a} \sum_{j=1}^{b} [gcd(i,j)==k]
$$

没有阿狸搓她要死了，救救孩子吧。



#### INPUT

第一行一个正整数 $T(1 \leq T \leq 10)$ ，表示接下来有 $T$ 组数据。

接下来 $T$ 行每行有 $3$ 个正整数 $a,b,k(1 \leq a,b,k \leq 1000000)$ 。



#### OUTPUT

输出 $T$ 行，每行一个整数代表咒文。



#### SAMPLE INPUT

1
3 5 1




#### SAMPLE OUTPUT

12




