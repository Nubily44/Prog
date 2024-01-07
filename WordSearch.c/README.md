## Word-Search:

## Busca de uma palavra por um texto indexado em duas estruturas de dados: 
Este programa lê um texto .txt e o estrutura em um arranjo de arranjos de strings (Coluna com Linhas de strings), e posteriormente armazena cada palavra apenas uma vez em uma lista ligada ou em uma árvore binária (dependendoe de como o programa for executado) e por fim, faz buscas nessas estruturas pela ocorrência de determindadas palavras.

O programa recebe um comando ("busca"ou "fim") e uma palavra e retorna quantas vezes ela apareceu no texto dado  e em quais linhas ela apareceu, e fecha o programa caso o comando seja "fim".
Caso a palavra não esteja no texto, o programa irá avisar que ela não foi encontrada

## Tipos de Estruturas Utilizadas:
- Lista:
  - Lista Ligada Simples
- Árvore:
  - Árvore Binária

## Como Compilar e Executar o Programa:
O programa foi desenvolvido e testado com a execução pelo Windows PowerShell.

1. Basta abrir o PowerShell, inserir o comando:
```
cd <filePATH>
```
- Substituindo <filePATH> pelo local onde os arquivos foram salvos

2. Compilar o arquivos .c corretamente:
```
gcc -o <saida.exe> main.c BinTree.c LinkList.c
```
- Substituindo <saida.exe> por um nome a ser escolhido para a sua conveniência

3. Para rodar o programa já compilado:
```
Start-Process -FilePath "<saida>" -ArgumentList "<texto.txt>", "<tipo_de_estrutura>"
```
- Substituindo <saida> pelo executável gerado pelo comando anterior e <texto.txt> pelo arquivo de texto a ser analisado

- em <tipo_de_estrutura> pode ser escolhido "lista" ou "arvore", para serem utilizadas as diferentes estruturas mencionadas

4. Por fim, basta executar os comandos descritos:
```
> busca <palavra>
```
- Para buscar uma palavra
```
> fim
```
- Para finalizar o programa

- **IMPORTANTE**: Os limites para a leitura do texto são: 1000 Linhas de 1000 palavras com 50 caracteres. Qualquer leitura acima desses limites causará problemas em seu funcionamento.
(Caso seja de seu interesse modificar o código, você pode alterar os parâmetros em "// Macros usados para o programa" para os valores que desejar utilizar (só tenha cuidado ao usar valores muito grandes))

