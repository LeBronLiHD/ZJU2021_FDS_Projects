# Euclid's Algorithm

[TOC]

### Euclid's Algorithm

- A few simple observations lead to a far superior method: Euclid’s algorithm, or the Euclidean algorithm. First, if $d$ divides $a$ and $d$ divides $a$, then $d$ divides their difference, $a - b$ , where $a$ is the larger of the two. But this means we’ve shrunk the original problem: now we just need to find $gcd(a, a - b$. We repeat until we reach a trivial case.
- $\begin{aligned}
    gcd(27, 33) &= gcd(27, 6)\\ \\ 
    &= gcd(6, 3) \\ \\ 
    &= 3
\end{aligned}$

### Extended Euclidean Algorithm

- The General Solution
- Let $d = gcd(a, b)$, and let $b = b'd,\quad a=a'd$. Since $ax + by$ is a multiple of $d$ for any integers $x,y$, solutions exist only when $d$ divides $c$.
- So say $c = kd$. Using the extended Euclidean algorithm we can find $m, n$ such that $d = ma + nb$, thus we have a solution $x = km, \quad y = kn$.
- Suppose $x',y'$ is another solution. Then $x' - x = t\displaystyle\frac{b}{d} \\ \\ y'  -y = t\displaystyle\frac{a}{d}$
- Solution:
  - $x = km + t\displaystyle\frac{b}{d}$
  - $y = kn + t\displaystyle\frac{a}{d}$
