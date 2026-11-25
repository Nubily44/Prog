# Lista 4 - Infosec - Aline Crispim de Moraes (Nusp: 14567051)

## 1

1.1

G = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},  a * b mod 11

2^0 = 1
2^1 = 2
2^2 = 2*2mod11 = 4
2^3 = 4*2mod11 = 8
2^4 = 8*2mod11 = 5
2^5 = 5*2mod11 = 10
2^6 = 10*2mod11 = 9
2^7 = 9*2mod11 = 7
2^8 = 7*2mod11 = 3
2^9 = 3*2mod11 = 6

Portanto o grupo é cíclico

1.2

Alice envia 2^3 = 8, G e 2

Bob recebe, e retorna 2^7 = 7 para Alice

Alice então faz (2^7)^3 e Bob faz (2^3)^7, ambos chegando no valor: 2^21mod11 = 2

1.3

Eva demoraria para descobrir os dois números utilizados por Alice e Bob equivalente a testar todos os logaritmos discretos da operação. Essa busca, em um grupo de 10 elementos é trivial, e portanto a forma de comunicação não é segura, mas em um caso real, seriam utilizados cententas se não milhares de elementos, o que aumentaria seu tempo de busca exponencialmente-

1.4

Não, pois o sistema de Diffie Hellman ainda é vulnerável a um ataque de Man in the Middle, em que Eva entra no meio da comunicação, e estabelesce um contato direto com Alice e Bob, de forma a interceptar todas as mensagens e le-las com seu par de chaves publica e privada, atuando como um meio

## 2

2.1

p = 5
q = 11
e = 3

N = p \* q = 55
Phi(N) = (p-1)(q-1) = 10 \* 4 = 40

d \* e = 1mod40 -> 3d = 1mod40

testando multiplos de 3 perto dos multiplos de 40

3 \* 14 = 42 -> 2
3 \* 27 = 84 -> 1

d = 27

Logo pk = <3, 55>
e sk = <27, 55

2.2

m = 7
pk = <3, 55>
sk = <27, 55

c = 7^3mod55 = 343 mod55 = 13
m = 13^27mod55 = 7

