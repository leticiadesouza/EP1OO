# Exercício de Programação 1 - Orientação a Objetos
### Instruções para compilação do programa:

* Utilize o comando make
```sh
$ make
```
* Há duas opções para compilar o programa:
```sh
$ ./bin/main
$ make run
```
* As imagens de formato PGM E PPM estão diponíveis para teste na pasta doc 
* No menu, digite a opção referente ao tipo de imagem que deseja decifrar (pgm ou ppm);
* Digite o caminho que localize o arquivo que deseja abrir.
    > Exemplo: /home/leticia/Área de Trabalho/EP1OO/doc
* Digite o nome da imagem;
    > Exemplos: 
    - imagem1.pgm 
    - mensagem1.ppm

## Imagem PGM:

* Caso a mensagem seja do formato PGM, o programa exibirá o segredo por trás da imagem escolhida para ser decifrada (dentre as opções de imagens.pgm inclusas na pasta doc);
* Caso o programa exiba a mensagem de erro, pressione enter para retortar às opções de menu e digite 0 para sair do programa
* Tente revelar o segredo novamente dando os seguintes comandos ao sair do menu:
```sh
$ make clean
$ make 
$ make run
```
* Siga, novamente, as intruções a partir da localização do caminho da imagem; 
* O erro é recorrente, de modo que, ao sair e retornar ao programa o segredo é exibido de forma aleatória;
### Imagem PPM:
* Caso a imagem seja do formato PGM, entre com a opção de cor desejada; 
* Após selecionar a opção, o segredo será salvo no caminho indicado no terminal;
* Através do caminho, poderá ser conferido se a imagem foi gerada, de fato.
