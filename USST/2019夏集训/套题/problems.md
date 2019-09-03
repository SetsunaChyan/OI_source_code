### A. Wiki with Numbers

有一个长度为 $n$ 的数列 $a_1,a_2,\cdots,a_n$ 和一个整数 $k$ 。你需要找到所有满足 $a_i+a_j-|i-j| \geq k$ 的 $(i,j)$ 无序对对数。所谓无序对，即 $(i,j)$ 与 $(j,i)$ 会被认为是同一种。

多组数据，请使用较快的读入方式。

第一行一个正整数 $T(1 \leq T \leq 1000)$，表示测试数据的组数。

每组第一行两个正整数 $n,k(1 \leq k \leq n \leq 2 \times 10^5)$。

接下来 $n$ 个正整数 $a_i(1\leq a_i \leq n)$。

对于每个测试点，$\sum n \leq 10^6$。

对于每组，输出一行一个答案。



### J. Wiki with Random Number Generator

$\text{IBN-5100}$ 是一台远古时期的个人电脑，上面流行了一种 $Dpp$ 语言(看上去和 $Cpp$ 很像)。这门语言的标准库提供了一个函数 $\text{system_rand()}$ ，它的作用是等概率地返回 $[0,k-1]$ 内的一个整数。而且 $Dpp$ 语言运算自带高精度，可以认为这种语言不存在整型溢出。

由于特殊需求，有人编写了如下函数，用来生成返回 $[0,m-1]$ 内的一个整数。

```cpp
int my_rand(int m)
{
   	return (system_rand()+system_rand())%m;
}
```

容易发现，这样得到的随机数并不是均匀分布的。

给定 $m$ 和 $k$ ，你需要分析这个函数返回值恰好为 $0$ 的概率。

为了防止精度误差，你需要输出概率在模 $998244353$ 意义下的答案。

**如果你不知道模意义下的分数，请阅读以下部分:**

容易证明，我们的答案一定是个有理数，那么它一定可以写成最简分数 $\frac{p}{q}$ ，其中 $p,q$ 互素。

那么 $\frac{p}{q}\ mod\ 998244353=p \times q^{-1}\ mod\ 998244353=p \times q^{998244353-2}\ mod \ 998244353$ 。

也就是说，你不需要知道为什么，只要输出 $p \times q^{998244351}\ mod\ 998244353$ 即可。

**如果你不知道快速幂，请阅读以下部分:**

直接暴力求 $x^{998244351}$ 会超时，使用 $\text{pow()}$ 函数会丢失精度。

所以请使用以下代码求幂，时间复杂度为 $\Theta(\log_2{y})$。

```cpp
//以下函数返回x的y次方模mod
long long quick_power(long long x,long long y,long long mod)
{
	long long ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
```

多组数据。

第一行一个正整数 $T(1 \leq T \leq 10)$，表示测试数据的组数。

每组一行两个正整数 $m,k(2 \leq k,m \leq 10^5)$，含义见题面。

对于每组数据输出一个整数。



### K. Wiki with fAKe Algorithm Generator

糊假算是人生中的一大乐事，叉别人的假算法更加的开心。

![p3_png1](F:\CPP\OI\CF_RJY_LYD\USST\2019夏集训\套题\p3_png1.png)

最近，$Wiki$ 拿到了一道串串题。给定一个长度为 $n$ 的只包含 $0$ 与 $1$ 的串 $S$，保证 $S_1=S_n=1$。定义 $f(i)$ 为距离 $S_i$ 最近的那个 $1$ 与它的距离，其中 $i$ 到 $j$ 的距离为 $|j-i|+1$ ，特别地，如果 $S_i$ 本身就是 $1$ 那 $f(i)=0$ 。求 $\sum_{i=1}^n f(i)$。

$Wiki$ 糊了一个复杂度糟糕的伪代码如下。

```pseudocode
// Let s[1..n] be the string S.

function cal(x)
begin
	cnt1=0
	cnt2=0
	for i=x downto 1
		if s[i] equals to '1'  // *
			break
		else
			cnt1=cnt1+1
	for i=x to n
		if cnt2 >= cnt1 
			break
		if s[i] equals to '1'  // *
			break
		else
			cnt2=cnt2+1
	return min(cnt1,cnt2)
end

function solve(s)
begin
	ans=0
    for i=1 to n
    	ans=ans+cal(i)
    return ans
end
```

你要做的不是做出那道题，而是计算出对于给定的 $S$， $Wiki$ 的伪代码会执行几次字符的判断(即打了星号注释的那两行会被执行几次)。

多组数据。

第一行一个正整数 $T(1 \leq T \leq 1000)$，表示测试数据的组数。

每组一行一个字符串 $S(1 \leq |S| \leq 10^5)$，第一个字符和最后一个字符一定是 $1$。

对于每个测试点，$\sum |S| \leq 10^6$。

对于每组数据输出一行一个整数表示比较的次数。