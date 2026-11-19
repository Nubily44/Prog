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