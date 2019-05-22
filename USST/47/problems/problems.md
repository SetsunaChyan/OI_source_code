### B. Haruhi's Product

Although Haruhi's math is very good, she still suffers from some math problems, so you need to help her calculate the following product:

$$
\prod_{i=1}^n \prod_{j=1}^n \prod_{k=1}^n m^{gcd(i,j)[k|gcd(i,j)]} \space \% \space p
$$

where $[Expression]=\begin{cases} 0, & \text{if the expression is false} \\ 1, & \text{if the expression is true}\end{cases}$ , $gcd(x,y)$ represents the greatest common divisor of $x$ and $y$ , $x|y$ means that $x$ is a factor of $y$.



#### INPUT

Each test file contains a single test case. In each test file:

There are three positive integers $n(1 \leq n \leq 100),m(1 \leq m \leq 2 \times 10^9),p(1 \leq p \leq 2 \times 10^9)$ which are separated by spaces.

 

#### OUTPUT

An integer representing your answer.



#### SAMPLE INPUT

2 2 1000000007



#### SAMPLE OUTPUT

128





### C. Haruhi's Othello Game

$Haruhi$ 最近迷上了一种游戏，她想要和你比一比。棋盘是一棵有根树，$Haruhi$ 和你把一颗棋子放到有根树的根上，你们轮流把这个棋子往当前棋子所在结点的一个儿子移动一步，不能再移动的玩家就算失败。

当然你必须要让 $Haruhi$ 赢，不然我们可能要在下一个世界才能看到你啦。为此你必须判断某种棋盘中先手是否有必胜策略。



#### INPUT

第一行一个整数 $T$， 表示有 $T$ 组数据。

接下去每组数据的第一行有两个数 $n,r$ ，表示树有 $n$ 个节点，其中 $r$ 为根节点编号(从 $1$ 开始编号)。

接下去 $n-1$ 行每行两个数字 $u,v$ ，表示点 $u$ 和 $v$ 之间有一条边。



#### OUTPUT

每组数据输出一行，"Haruhi go first." 表示 $Haruhi$ 先手有必胜策略，"Haruhi go secondary." 表示 $Haruhi$ 后手有必胜策略。



#### SAMPLE INPUT
2
3 1
1 2
2 3
5 4
1 2
1 3
3 4
4 5




#### SAMPLE OUTPUT

Haruhi go secondary.
Haruhi go first.







