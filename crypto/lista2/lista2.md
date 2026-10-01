# Lista 1 - Infosec - Aline Crispim de Moraes (Nusp: 14567051)

## 1

Considerando um distinguidor:

D: {0,1}^n -> {0,1} em que D(x1, x2, ..., xn) = 1 se (x1 XOR x2 XOR ... XOR xn) e 0 C.C.

A vantagem desse distinguidor é P(D(G(s) = 1) = 1). Pelo distinguidor ter o mesmo mecanismo que G(s), a probabilidade é 1

Porém, para uma entrada uniforme, o bit xn+1 será indepentende e manterá a uniformidade, portanto sua probabilidade é 1/2

Assim, o Gerador não é seguro, já que o distinguidor D apresenta vantagem sobre o gerador G(s)

## 2

2.1
c1 XOR c2 = (m1 XOR G(k)) XOR (m2 XOR G(k)) = m1 XOR G(k) XOR m2 XOR G(k) = m1 XOR m2 XOR G(k) XOR G(k) = m1 XOR m2

2.2

c1 = 10110110
c2 = 01101100
c1 XOR c2 = 11011010

c1 XOR c2 = m1 XOR m2
11011010 = 01000001 XOR m2
m2 = 10011011

## 3

LCE: por cada bloco no LCE ser codificado individualmente, a mensagem será danificada em apenas um bit (o bit afetado)

EBC: no EBC, devido ao fato de que para codificar um novo bloco, é usado um XOR com a cifra do bloco anterior, todos os blocos seguintes ao bit danificado serão afetados, e a mensagem será parcialmente comprometida

Ctr: Já no Ctr, apenas os blocos também são codificados individualmente, e portanto só um bit da mensagem será afetado

## 4

4.1
L1 = 1010
R1 = 1100 XOR (0110 XOR 1010) = 1100 XOR 1100 = 0000

(L1, R1) = (1010, 0000)

4.2

j = i+1 (notação)

Lj = Ri
Rj = Li XOR f(Ri)

Ri = Lj
Li = Rj XOR f(Ri) = Rj XOR f(Lj)
