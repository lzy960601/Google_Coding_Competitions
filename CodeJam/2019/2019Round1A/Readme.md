# 2019 Round 1 Sub-Round A

-   Score : 100
-   Rank : 190

---

## A

- 分析一下特殊情况，发现$n \leq 3, m \leq 3$无解，$2 \times 4$无解
- 剩下的情况，硬编码$4 \times 3$和$4 \times 4$
- 对于$k \geq 5$的情况，构造$2 \times k$和$3 \times k$的情况，之后任意情况可由这两种拼出
- (听说打表也能过，可能你需要一些高超的打表姿势)

## B

- 中国剩余定理($ 4\times 3 \times 5 \times 7 \times 11 \times 13 \times 17$)
- 需要注意$4$不是质数，逆元需要扩展欧几里得求出

## C

- 我们考虑把每个串倒过来，那么就变成了前缀相等
- 显然可以采用Trie树解决
- 在树上贪心即可，贪心策略很好想
