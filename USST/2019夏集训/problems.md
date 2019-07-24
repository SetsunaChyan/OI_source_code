### p1. A Simple Problem On LIS

给定一个长度为 $n$ 的数列 $a$ ，我们等概率地取出任意一个上升子序列，求每个数被选中的概率，对 $998244353$ 取模。

第一行输入一个整数 $n(1 \leq n \leq 5 \times 10^5)$ 表示数列 $a$ 的长度。

接下来一行输入 $n$ 个整数 $a_i(1 \leq a_i \leq 10^9)$。

输出 $n$ 个整数，表示每个数字被选中的概率。

模意义下的除法 $\frac{a}{b}$ ，可以写成 $ab^{-1} (mod\space P)$ ，也就是 $a$ 乘以 $b$ 的逆元。



### p2. DHR树

$DHR$ 发明了一个序列上万能的数据结构，他结合并应用了 $Splay$，$Treap$ ，替罪羊树，$K-D\ Tree$ ，$LCT$ ，珂朵莉树，$Trie$ ，$ZKW$ 线段树，闵科夫斯基和合并凸包​，带修莫队，各种树套树和树套树套树 $\cdots$ 

$DHR$ 已经准备写 $paper$ 发顶会拿图灵奖了，不幸的是他突然忘记怎么写了，现在他邀请你实现其中的一个小功能，迈出走向图灵奖的第一步。

现在你有 $n$ 个数，不妨记为 $a_1,a_2,\dots ,a_n$，在一开始它们都是 $0$。你需要处理接下来的 $m$ 个毒瘤操作。操作总共有四种类型。

操作一：把从 $a_x$ 到 $a_y$ 的每一个数都加上 $c$。

操作二：把从 $a_x$ 到 $a_y$ 的每一个数都乘上 $c$。

操作三：把从 $a_x$ 到 $a_y$ 的每一个数赋值为 $c$。

操作四：求 $\sum_{i=x}^y a_i^p \ mod\ 10007$。

第一行两个正整数 $n,m(1 \leq n,m \leq 10^5)$ 。

接下来 $m$ 行，每行都是"$1\ x\ y\ c$"或"$2\ x\ y\ c$"或"$3\ x\ y\ c$"或"$4\ x\ y\ p$"中的一种。

约定 $1 \leq x \leq y \leq n,1 \leq c \leq 10^4,1 \leq p \leq 3$。

对于每一个操作四输出一行结果。



### p3. 射手座之日Ⅱ

电研社社长目前有着 $30000$ 艘独立成列的战舰(编号从 $1$ 开始)，其中第 $i$ 艘战舰在第 $i$ 列。$Nagato$ 能够监听到他发出的合并指令为 $M_{i,j}$，含义为第 $i$ 号战舰所在的整个战舰队列，作为一个整体(头在前尾在后)接至第 $j$ 号战舰所在的战舰队列的尾部。显然战舰队列是由处于同一列的一个或多个战舰组成的。合并指令的执行结果会使队列增大。在他发布命令调动舰队的同时，作为一名泉水指挥官，$Haruhi$ 会发出询问指令 $C_{i,j}$。该指令意思是，询问电脑，电研社社长的第 $i$ 号战舰与第 $j$ 号战舰当前是否在同一列中，如果在同一列中，那么它们之间布置有多少战舰。

最终的决战已经展开，$SOS$ 团的历史又翻过了一页……

第一行有一个整数 $T(1 \leq T \leq 500,000)$ ，表示总共有 $T$ 条指令。

以下有 $T$ 行，每行有一条指令。指令有两种格式：

1. $M_{i,j}$ ： $i$ 和 $j$ 是两个整数 $(1 \le i,j \le 30000)$，表示指令涉及的战舰编号。如果第 $i$ 艘战舰和第 $j$ 艘战舰在合并前已经在同一列内了，那这是他制造的假消息，请你无视它。
2. $C_{i,j}$ ： $i$ 和 $j$ 是两个整数 $(1 \le i,j \le 30000)$，表示指令涉及的战舰编号。该指令是 $Haruhi$ 发布的询问指令。

依次对输入的每一条指令进行分析和处理：

如果是电研社社长发布的舰队调动指令，则表示舰队排列发生了变化，你的程序要注意到这一点，但是不要输出任何信息。

如果是 $Haruhi$ 发布的询问指令，你的程序要输出一行，仅包含一个整数，表示在同一列上，第 $i$ 号战舰与第 $j$号战舰之间布置的战舰数目。如果第 $i$ 号战舰与第 $j$​ 号战舰当前不在同一列上，则输出 $-1$。



### p4. A Simple Problem On Different Numbers

有一个长度 $n$ 的整数序列 $a_1,a_2,\cdots,a_n$ ， 接下来有 $Q$ 次询问。每次询问会询问你一个区间 $[l_i,r_i]$ ，你需要回答在 $a_{l_i},a_{l_i+1},\cdots,a_{r_i}$ 中有多少个不同的数。

第一行一个正整数 $n(1 \leq n \leq 5 \times 10^5)$ 。

第二行 $n$ 个数 $a_i(0 \leq a_i \leq 10^6)$。

第三行一个整数 $Q(1 \leq Q \leq 5 \times 10^5)$ 。

接下来 $Q$ 行，每行两个正整数 $l_i,r_i(1 \leq l_i \leq r_i \leq n)$ ，表示询问的区间。

$Q$ 行，每行一个整数，依次表示询问对应的答案。 



### p5. A Simple Problem On Graph

你有一张含 $n$ 个点和 $m$ 条边的无向图，数据保证没有重边。你能删掉一些点，与这些点相连的边会被一起删去。但是你不能同时删掉相邻的两个点。请问最少要删去几个点使得整张图上不剩一条边。

第一行两个正整数 $n,m(1 \leq n,m \leq 3 \times 10^5)$ 。

接下来 $m$ 行，每行两个整数 $A,B(1 \leq A,B \leq n)$，表示点 $A$ 和点 $B$ 之间有一条边。

如果不存在解则输出 $QAQ$ ，否则输出最少需要删去几个点。



### p6. 树成生小最

你有一棵恰好包含 $n$ 个节点的树，你想要加一些边使它成为一个完全图(即任意两个不相同的节点之间都有一条边)，使得这个完全图的最小生成树唯一且恰好为一开始的这棵树。

求**增加的边**的权值总和最小是多少。

第一行一个正整数 $n(1 \leq n \leq 10^5)$。

接下来 $n-1$ 行，每行三个正整数 $x,y,z(1 \leq x,y \leq n,1 \leq 100 \leq z)$，表示 $x$ 与 $y$ 之间有一条权值为 $z$ 的边。

输出一个整数表示权值总和最小值。



### p7. Oneman233

时间不多了，你需要写一种数据结构来维护一个数列，它需要支持以下两种操作。

+ $Q\ L$ : 查询当前数列末尾 $L$ 个数中的最大数。
+ $A\ n$ : 把 $n$ 加上 $t$ ，并对 $D$ 取模，然后将其插入到数列的末尾，其中 $t$ 是最近一次查询操作的答案(如果还未执行过查询操作则 $t=0$ )。

一开始数列是空的。

第一行两个整数 $M,D(1 \leq M \leq 2 \times 10^5)$ ，分别表示操作个数和模数。

接下来 $M$ 行，每行一个形如题面中提到的两种操作。

其中 $|n|  \leq 10^9 , 0 < L$ 。

输入保证任何时候 $L$ 不会超过当前数列的长度。

对于每一个查询操作输出一行一个结果。




### p9. kr12138

时间不多了，想必你已经能熟练掌握如何求最大子段和了，这次你要回答我的 $q$ 个询问。

给定一个长度为 $n$ 的数列，每次询问一个区间 $[l,r]$ ，你需要回答这个区间内最大子段和的左端点和右端点。如果有多个解，输出左端点最小的，如果仍然有多个解，在左端点最小的情况下输出右端点最小的。

第一行两个正整数 $n,q(1 \leq n,q \leq 5 \times 10^5)$ 。

第二行 $n$ 个整数 $a_1, \cdots , a_n(|a_i| \leq 10^9)$ ，表示整个数列。

接下来 $q$ 行，每行两个正整数 $l,r(1 \leq l,r \leq n)$ 。

对于每个询问，输出一行两个整数表示最大子段和区间的左端点和右端点。



### p10. Knights

Berland is facing dark times again. The army of evil lord Van de Mart is going to conquer the whole kingdom. To the council of war called by the Berland's king Valery the Severe came $n$ knights. After long discussions it became clear that the kingdom has exactly $n$  control points (if the enemy conquers at least one of these points, the  war is lost) and each knight will occupy one of these points. 

Berland is divided into $m+ 1$ regions with $m$  fences, and the only way to get from one region to another is to climb  over the fence. Each fence is a circle on a plane, no two fences have  common points, and no control point is on the fence. You are given $k$ pairs of numbers $a_i$, $b_i$ . For each pair you have to find out: how many fences a knight from control point with index $a_i$ has to climb over to reach control point $b_i$ (in case when Van de Mart attacks control point $b_i$  first). As each knight rides a horse (it is very difficult to throw a  horse over a fence), you are to find out for each pair the minimum  amount of fences to climb over.

The first input line contains three integers $n, m,k (1 \leq  n,m \leq 1000, 0 \leq k \leq 100000)$. Then follow $n$ lines, each containing two integers $K_{x_i}, K_{y_i} ( - 10^9 \leq K_{x_i}, K_{y_i} \leq 10^9)$ — coordinates of control point with index $i$. Control points can coincide.

Each of the following $m$ lines describes fence with index $i$ with three integers $r_i, C_{x_i}, C_{y_i} (1 \leq r_i \leq 10^9,  -10^9 \leq C_{x_i}, C_{y_i} \leq 10^9)$ — radius and center of the circle where the corresponding fence is situated.

Then follow $k$ pairs of integers $a_i, b_i (1 \leq a_i, b_i  \leq  n)$, each in a separate line — requests that you have to answer. $a_i$ and $b_i$ can coincide.

Output exactly $k$ lines, each containing one integer — the answer to the corresponding request.




### p11. Infinity#7

$Frontier$ 是你的家园，在她上面有 $n$ 座村庄，村庄间由 $m$ 条双向道路所连接。每一条道路对车辆有载重要求。现在有 $q$ 辆货车(他们是互相独立的)在运输货物，你想知道，在任何车辆都不超重的情况下，一次最多能运多少货物。

第一行两个正整数 $n,m(1 < n \leq 10^4,1 < m \leq 5 \times 10^4)$ 。

接下来有 $m$ 行，每行三个正整数 $x,y,z(1 \leq x,y \leq n,x \neq y,0 \leq z \leq 10^5)$ ，表示 $x$ 村与 $y$ 村间有一条限重为 $z$ 的双向道路(即载重严格大于 $z$ 的车辆不能通过)。

接下来一行一个正整数 $q(1 \leq q \leq 3 \times 10^4)$ 。

接下来有 $q$ 行，每行两个正整数 $x,y(1 \leq x,y \leq n,x \neq y)$ ，表示这辆货车想从 $x$ 村开往 $y$ 村。

**村庄间可以不联通，可以有重边，但不会有自环。**

共 $q$ 行，表示对于某一辆货车，它所能够的最大载重是多少。如果货车不能到达目的地则输出 $-1$ 。



### p13. yxxxxxxx

时间不多了，但你在睡觉前还是想玩一会游戏。

有水平铺放着的 $n+1$ 个格子，从左往右分别被标号为 $0,1,\cdots , n$ ，这些格子并不一定是连续的。每个格子内有一个整数，表示到达这个格子能得到的分数。其中 $0$ 号格子是起点，而你一开始站在起点上。

游戏规则如下：

+ 玩家每次都必须跳到当前格子右方的某个格子里，玩家可以在任意时刻结束游戏，获得的分数是曾到达过的格子中的数字之和。

+ 在一开始，你的弹跳距离固定为 $d$ ，但是你可以花费 $g$ 个金币升级，使你的灵活性增加 $g$ 。也就是，当 $g  < d$ 时，你可选择的弹跳距离为 $d-g,d-g+1,\cdots ,d+g-1,d+g$ ，而当 $g \ge d$ 时，你可选择的弹跳距离为 $1,2,3,\cdots ,d+g-1,d+g$ 。

现在你想获得至少 $k$ 分，然后睡觉，请问最少花费多少金币。

第一行三个正整数 $n,d,k(1 \leq n \leq 5 \times 10^5 , 1 \leq d \leq 2000 , 1 \leq k \leq 10^9)$ 。

接下来 $n$ 行，每行两个整数 $x_i,s_i(1 \leq x_i \leq 10^9 , 1 \leq |s_i| \leq 10^5)$ ，分别表示第 $i$ 号格子与 $0$ 号格子的距离、这个格子内的整数。

一行一个整数，表示你最少需要花多少金币才能睡觉。如果你无法入眠，则输出 $-1$。

样例 $1$ : $2$ 个金币升级后，依次选择的向右弹跳的距离分别为 $2,3,5,3,4,3$ ，先后到达的位置分别为 $2,5,10,13,17,20$ ，对应 $1,2,3,5,6,7$ 这 $6$ 个格子。这些格子中的数字之和 $15$ 为你获得的分数。

样例 $2$ : 最大数字之和为 $18$ ，无论如何都无法获得 $20$ 分。



### p14. QodeForces

比赛开始前，有 $n$ 个 $ICPC$ 的参赛选手排成一列等在门外。他们从左往右依次标号为 $1,2,3,\cdots,n$ 。第 $i$ 位选手的 $QodeForces$ 的 $Rating$ 值达到了 $a_i$ 。

$QLS$ 是 $Quailty$ 师范大学的教练，他准备选出一个长度恰为 $m$ 的连续子区间 $[l,l+m-1]$ ，然后从左往右依次视察每个选手。在一开始，他会记下两个数字，$maxrating=-1$ 和 $count=0$ 。每当他看到一位选手(不妨设他为 $k$) ，如果 $a_k \gt maxrating$ ，则他令 $maxrating=a_k,count=count+1$ 。

小 $T$ 知道 $QLS$ 不擅长数数，他想知道对于任意一个区间 $[i,i+m-1] (1 \leq i \leq n-m+1)$ ，最终的 $maxrating_i$ 和 $count_i$ 会是多少。

第一行七个整数 $n,m,k,p,q,r,MOD(1 \leq m,k \leq n \leq 10^7,5 \leq p,q,r,MOD \leq 10^9)$，分别表示参赛人数、区间长度和五个参数 $k,p,q,r,MOD$。

第二行 $k$ 个整数 $a_1,a_2, \cdots ,a_n(0 \leq a_i \leq 10^9)$ ，分别表示前 $k$ 位选手的 $rating$ 。

为了避免过大的输入文件，$a_i(k \lt i \leq n)$ 将由以下公式生成。
$$
a_i=(p \times a_{i-1} + q \times i + r) \ \text{mod} \ MOD
$$
输入数据保证 $k \leq 5 \times 10^5$。

为了避免过大的输出文件，设 $maxrating_i$ 和 $count_i$ 是区间 $[i,i+m-1]$ 的答案，你只需要输出两个整数 $A$ 和 $B$。

其中 $A$ 和 $B$ 由以下公式得到。
$$
A=\sum_{i=1}^{n-m+1} (maxrating_i\oplus i)\\ B=\sum_{i=1}^{n-m+1} (count_i\oplus i)
$$


### p15. Zero to Ichi

你有一个 $n \times n$ 的矩阵 $C_{i,j} (1 \leq i,j \leq n)$ ，你需要构造一个 $n \times n$ 的 $01$ 矩阵 $X_{i,j}(1 \leq i,j \leq n)$ ，使得 $\sum_{i=1}^n \sum_{j=1}^n C_{i,j} \times X_{i,j}$ 最小。

但是这样太简单了，所以你的 $X$ 矩阵必须同时满足以下条件。

+ $\sum_{i=2}^n X_{1,i}=1$
+ $\sum_{i=1}^{n-1} X_{i,n}=1$
+ 对于任意的 $i(1 < i < n)$ 满足 $\sum_{k=1}^n X_{k,i} = \sum_{j=1}^n X_{i,j}$

好像太抽象了，举个栗子，如果 $n=4$ ，我们可以得到以下等式。

+ $X_{1,2}+X_{1,3}+X_{1,4}=1$
+ $X_{1,4}+X_{2,4}+X_{3,4}=1$
+ $X_{1,2}+X_{2,2}+X_{3,2}+X_{4,2}=X_{2,1}+X_{2,2}+X_{2,3}+X_{2,4}$
+ $X_{1,3}+X_{2,3}+X_{3,3}+X_{4,3}=X_{3,1}+X_{3,2}+X_{3,3}+X_{3,4}$

第一行一个整数 $n(2 \leq n \leq 100)$ 。

接下来有个 $n \times n$ 的矩阵，第 $i$ 行的第 $j$ 列上的数字就是 $C_{i,j}(0 \leq C_{i,j} \leq 10^5)$ 。

你需要输出 $\sum_{i=1}^n \sum_{j=1}^n C_{i,j} \times X_{i,j}$ 可能的最小值。



### p16. Aimo

最近，你发现自己太 $Naive$ 了，所以你选择了念诗为了提高自己的知识水平。一首诗的知识水平由每句诗句的最长公共前缀决定，具体来说，假设最长公共前缀的长度是 $k$ ，且这首诗由 $m$ 句诗句所组成，那么这首诗的知识水平将高达 $k*m$ 。

你是个带诗人，希望从一组诗句当中选择一些组成新的一首诗，使得它的知识水平最高。好在诗句都是由 $01$ 字符串构成的，你可以很轻松的处理它们，这是坠吼的。

第一行一个正整数 $n(1 \leq n \leq 10^4)$ ，表示接下来有 $n$ 句诗句。

接下来 $n$ 行，每行一个只包含 $0,1$ 的字符串 $s(1 \leq |s| \leq 200)$ 。

你只需要输出能组成的最高的知识水平是多少就行了。





### p18. 星間飛行

**(<ゝω·)☆KIRA！**

终于，你有属于自己的飞船啦！你缜密地观察着帝国的地图，你发现帝国由 $n$ 个星球，$m$ 条航道组成，形成了一张没有自环，没有重边的无向连通图。现在，你在你的家园 $Frontier$ ，也就是你眼中的 $1$ 号星球，你想要前往 $n$ 号星球看李兰卡的演唱会。

你的飞船有两项属性:

+ 最大折越距离 $D$ : 你无法在任何长度大于 $D$ 的航道上进行折越。
+ 最大折越次数 $E$ : 你最多只能折越 $E$ 次。


很遗憾的是，你的飞船的这两项属性在一开始都为 $0$ 。但别灰心！你可以花费 $c$ 个金币使你的飞船升 $1$ 级，这可以让你的 $D$ 和 $E$ 同时增加，其中 $D$ 增加了 $d$ ，$E$ 增加了 $e$ 。

现在你想知道，你最少需要花费多少个金币才能到达 $n$ 号星球呢。

第一行两个正整数 $n,m(2 \leq n \leq 10^5,n-1 \leq m \leq 10^5)$ 。

第二行三个正整数 $c,d,e(1 \leq c,d,e \leq 10^4)$ ，含义见题面。

接下来 $m$ 行，每行三个正整数 $u,v,w(1 \leq u,v \leq n,1 \leq w \leq 10^4$，表示星球 $u$ 和星球 $v$ 之间有一条长为 $w$ 的航道。

输出一个整数表示最小花费，如果无解则输出 $-1$ 。



### p19. DHR分治

Long long ago, there was an integer sequence $a$. 

$DHR$ think this sequence is messy, so he will count the number of inversions in this sequence. Because he is angry, you will have to pay $x$ yuan for every inversion in the sequence. 

You don't want to pay too much, so you can try to play some tricks before he sees this sequence. You can pay $y$ yuan to swap any two adjacent elements. 

What is the minimum amount of money you need to spend? 

The definition of inversion in this problem is pair $(i,j)$ which $1 \leq i < j  \leq n$ and $a_i > a_j$. 

In the first line, three integers, $n,x,y$ , $n$ represents the length of the sequence. 

In the second line, $n$ integers separated by spaces, representing the original sequence $a$. 

$1 \leq n,x,y \leq 10^5$, numbers in the sequence are in $[−10^9,10^9].$ 

A single integer representing minimum money to pay.



### p20. DHR线性基

当然，这题和线性基没什么关系，但是和 $DHR$ 线性基有关，你需要从 $n$ 个数挑出两个数，使其异或值最大。

第一行一个正整数 $n(1 \leq n \leq 10^5)$ 。

第二行 $n$ 个整数 $a_i (0 \leq a_i < 2^{31})$ 。

输出一个能够得到的最大异或值。



### p21. Square

在一个 $n \times m$ 的只包含 $0$ 和 $1$ 的矩阵里找出一个不包含 $0$ 的最大正方形，输出边长。

第一行为两个整数 $n,m(1 \leq n,m \leq 10^3)$，接下来 $n$ 行，每行 $m$ 个数字，用空格隔开，$0$ 或 $1$ 。

一个整数，最大正方形的边长。



### p22. Azusa

因为梓喵是喵喵，所以这题也是猫猫题(理直气壮)。

梓喵有一个长度为 $n$ 的数列 $a_1,a_2, \cdots ,a_n$，她每次可以选择一个区间 $[l,r]$，使下标在这个区间内的数都加一或者都减一。

梓喵想要知道至少需要多少次操作才能使数列中的所有数都一样。除此之外，她还想知道在保证最少次数的前提下，最终得到的数列可能有多少种。

第一行输入正整数 $n(1 \leq n \leq 10^6)$ 。

接下来 $n$ 行，每行输入一个整数，第 $i+1$ 行的整数代表 $a_i( 0 \leq a_i \leq 2^{31}-1)$。

第一行输出最少操作次数。

第二行输出最终能得到多少种结果。

![Azusa](F:\CPP\OI\CF_RJY_LYD\USST\2019夏集训\Azusa.jpg)