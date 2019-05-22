<p align="center"><font face="华文中宋" size=5>usstsiw第四十六次热身赛题解报告</font></p>

<font face="华文行楷">A题题解（难度：☆）</font>

<font face="微软雅黑">First solved: 我佛了, 00:35 (+1).</font>

$DFS$。比较简单的四联通 $DFS$ 题，需要注意的一点是：因为要保证刚好在 $T$ 的时间走到终点，因此可能需要迂回绕道进行，比如:

![A](F:\CPP\OI\CF_RJY_LYD\USST\46\problems\A.png)

如上图所示，如果单纯从 $S$ 走到 $D$ ，最快只需要 $4$ 步就能到达，但是题目要求 $6$ 步，因此需要迂回行走！这里就涉及到剪枝问题（<font color=red>**奇偶剪枝**</font>）：输入起点和终点的坐标，判断 $T-(|x_S-x_D|+|y_S-y_D|) $奇偶性，如果为奇数则不可能走到（<font color=red>**因为迂回行走多出来的步数必定为偶，可以画图验证**</font>），输出“No”;如果为偶数，则进行判断。



<font face="华文行楷">B题题解（难度：☆）</font>

<font face="微软雅黑">First solved: 立直一发AC, 01:03 (+).</font>

$BFS$ 。当然你也可以用 $DFS$ ，<font color=red>**但是题目涉及最值求解的时候建议使用BFS**</font>。做的时候只需将字符行列坐标转换为数字，这样处理起来比较方便，其它都是常规操作，不再赘述！



<font face="华文行楷"> C题题解（难度：☆）</font>

<font face="微软雅黑">First solved: 我佛了, 02:56 (+4).</font>

$1e19$ 刚好爆的 $long long$ ，所以只需要开$unsigned\space long\space long$ 
答案用 $\%.3f$ 的 $double$ 输出就行了



<font face="华文行楷"> D题题解（难度：☆）</font>

<font face="微软雅黑">First solved: 我佛了, 00:16 (+).</font>

比较经典的贪心，读入之后快排，定义两个指针 $z,y$ ，分别从 $0$ 和 $n-1$ 开始，
如果左侧的小数加上右侧的大数比规定范围 $w$ 小，就把它们俩分在一组，$ans++,z++,y--$ ，
不然就把右侧的数单独分在一组，$ans++,y--$ 。



<font face="华文行楷"> E题题解（难度：☆）</font>

<font face="微软雅黑">First solved: TREE (3), 01:50 (+).</font>

二项式定理 ${(a \times x+b \times y)}^k = \sum_{i=0}^k C_k^i (ax)^i (by)^{k-i}$ ，所以答案就是 $C_k^n a^n b^{k-n} \% 10007$ 。

考虑到组数很多，可以先打个组合数的表，再快速幂求 $a^n$ 和 $b^{k-n}$ 。



<font face="华文行楷"> F题题解（难度：0）</font>

<font face="微软雅黑">First solved: TREE (3), 00:47 (+).</font>

打表的话本地随便跑。

这里讲一下在线做法。

因为 $T_n=\frac{n \times (n+1)}{2}$ ，令 $n=2h-1$ 得到 $T_{2h-1}=\frac{(2h-1) \times 2h}{2} = h \times (2h-1) = H_h$ 。于是你证明了每一个  $Hexagonal$ 数都是 $Triangle$ 数。

因为 $P_n=\frac{n \times (3n-1)}{2}$ ，移项可以发现 $3n^2-n-2P_n=0$ ，反解得 $n=\frac {1 + \sqrt {1+24P_n}}{6}$ ，也就是说只要对任意整数 $X$ 是 $Pentagonal$ 数的充要条件是：把 $X$ 当做 $P_n$ 带入上式得到的 $n$ 是一个正整数。

现在你能 $O(1)$ 判 $Triangle$ 数和 $Pentagonal$ 数啦，枚举 $Hexagonal$ 数即可。



<font face="华文行楷">G题题解（难度：?）</font>

$Pick$ 定理：对于格点多边形，$2S=2a+b-2$ ，其中 $a$ 表示多边形内部的点数，$b$ 表示多边形边界上的点数，$S$ 表示多边形的面积。
于是这题只需要求出面积与每条边上的整点数，任意多边形的面积叉积一下就可以求，一条边上的整点数$=gcd(|x_1-x_2|,|y_1-y_2|)$ (想想为什么)。



<font face="华文行楷">H题题解（难度：☆）</font>

<font face="微软雅黑">First solved: 我佛了, 01:25 (+).</font>

$dp_{i,j}$ 表示第 $j$ 天后在第 $i$ 个洞的方案数，$dp_{s,0}=1,dp_{i,j}=dp_{i-1,j-1}+dp_{i+1,j-1},ans=dp_{t,m}$ 。



<font face="华文行楷">I题题解（难度：☆☆☆）</font>

莫比乌斯反演魔术！

因为蓝桥国赛好像有出过板子题，所以出了一题提高大家的姿势水平。



#### 积性函数

如果一个数论函数 $f(n)$ ，若 $m,n$ 互质，则 $f(n*m)=f(n)*f(m)$ ，我们称 $f(n)$ 是积性函数。



#### 狄雷克利卷积

$f(n),g(n)$ 分别是两个数论函数，则我们定义函数间的运算 $(f * g)(n)=\sum_{d|n} f(d)g(\lfloor \frac {n}{d} \rfloor )$ 为狄雷克利卷积。

狄雷克利卷积在数论函数集上满足交换律、结合律、分配律、单位元存在、逆元存在。且若 $f(n),g(n)$ 都是积性函数则 $(f*g)(n)$ 也是积性函数。

其中单位元是 $\epsilon (n)=[n==1]$ ，满足 $f*\epsilon=f$ 。



#### 莫比乌斯反演

现在再介绍两种常用的积性数论函数。

$$
I(n)=1
$$

$$
\mu (n)=[max(c_1,c_2,\dots,c_k) \leq 1](-1)^k \qquad (n=p_1^{c_1}p_2^{c_2}\cdots p_k^{c_k})
$$

我们发现 $\mu * I=\epsilon$ ，即 $\mu $ 与 $I$ 互为逆元。



好了，我们开始进入正题。

如果有两个数论函数 $F(n),f(n)$ 满足


$$
F=f*I
$$

我们把这个式子的两端都乘上 $\mu$ ，就得到了

$$
f=\mu * F
$$

好像看上去不是很神奇，我们把它补全：

$$
F(n)=\sum_{d|n} f(d) \implies f(n)=\sum_{d|n} \mu(d)F(\lfloor \frac {n}{d} \rfloor)
$$

它也等价于
$$
F(n)=\sum_{n|d} f(d) \implies f(n)=\sum_{n|d} \mu(\lfloor \frac {d}{n} \rfloor)F(d)
$$
这就是莫比乌斯反演魔术的两个核心公式啦。

用人话说，这个反演过程就类似一个容斥，而 $\mu (n)$ 就是容斥时的系数，手玩一下就明白啦。

有了莫比乌斯反演，当我们遇到一个不太好求的 $f(n)$ 时，我们可以选择构造更容易求得的 $F(n)$ ，然后打表 $\mu (n)$ ，反演后就能推 $f(n)$ 了。

有关求 $\mu (n)$ ，因为 $\mu$ 是个积性函数，线性筛和埃筛魔改一下就行。



#### 本题题解

好起来了，回到这道题，题意是让我们求 $1 \leq i \leq a,1 \leq j \leq b$ 内最大公约数为 $k$ 的有序数对数。

不妨把它化为 $1 \leq i \leq \lfloor \frac {a}{k} \rfloor , 1 \leq j \leq \lfloor \frac {b}{k} \rfloor$ 内互素的有序数对数，因为很容易发现这两个有序数对集合之间是可以互相一一对应的。

令 $p=\lfloor \frac {a}{k} \rfloor,q=\lfloor \frac {b}{k} \rfloor$ ，于是题目变成了求

$$
f(1) = \sum_{i=1}^{p} \sum_{j=1}^{q} [gcd(i,j)==1]
$$

根据套路，我们令 

$$
F(n)=\sum_{n|d} f(d) = \sum_{n|d} \sum_{i=1}^{p} \sum_{j=1}^{q} [gcd(i,j)==d]
$$

关注一下 $F(n)$ 的含义，发现它表示的是满足 $gcd(i,j)==n的倍数$ 的有序数对数。因为 $n|gcd(i,j) \implies n|i  \space or \space n|j$ ，那么显然有

$$
F(n)=\lfloor \frac {p}{n} \rfloor \times \lfloor \frac {q}{n} \rfloor
$$

再利用莫比乌斯反演，得
$$
f(n)=\sum_{n|d}\mu(\lfloor \frac {d}{n} \rfloor)F(d)
\\
f(1)=\sum_{1|d}\mu(d)F(d)=\sum_{i=1}^{min(p,q)}\mu(i) \times \lfloor \frac {p}{i} \rfloor \times \lfloor \frac {q}{i} \rfloor
$$
单组时间复杂度 $O(min(p,q))$ ，目前已经足够通过本题了。

事实上我们可以做得更好，因为 $\lfloor \frac {p}{i} \rfloor$ 和 $\lfloor \frac {q}{i} \rfloor$ 的取值是 $O(\sqrt p + \sqrt q)$ 个的，所以预处理 $\mu$ 的前缀和后可以 $O(1)$ 求单块的和，单组时间复杂度 $O(\sqrt p + \sqrt q)$ 。

如果题目更毒瘤你可以杜教筛 $O(n^{\frac {2}{3}})$ 搞出 $\mu$ 的前缀和。

