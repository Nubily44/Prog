# Lista 1 - Infosec - Aline Crispim de Moraes (Nusp: 14567051)

## 1

Considerando:
m  = 101010
c  = 110001
m' = 001011

c = m XOR G(k)

basta aplicar c' = c XOR m XOR m' e obter
c' = 110001 XOR 101010 XOR 001011
c' = 010000

## 2

Considerando que H(x) é uma função de Hash pública, qualquer atacante poderia substituir m por m', e criar H(m'), assim não garantindo nem a integridade nem a autenticidade da mensagem.

Assim, uma solução seria utilizar o protocolo CBC-MAC, que utiliza uma chave compartilhada K para a criação de fk, que é utilizada em cadeia em todos os blocos da mensagem m a fim de criar a tag t, que garante tant oa integridade (ja que qualquer mudança em um bloco mudaria a tag) e autenticidade (já que a mensagem original é a unica que gera a tag t)

## 3

Como f(x,y) = x . y = z, para conseguirmos achar uma pré-imagem de z, podemos considerar que x ou y seja igual a 1, e seu par igual a z. Além disso, para chegarmos a todos os valores possíveis de x e y que geram z, basta começarmos a dividir esse resultado por todos os fatores primos, iniciando pelo 2

