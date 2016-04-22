#include "processaCinza.hpp"
using namespace std;

processaCinza::processaCinza(char *** faixa, int * medidas,string parte_segredo){

	//variavel que aponta o inicio da mensagem
	int inicio;
	{//Abrindo escopo
		char * segredo_array;
		segredo_array = new char[parte_segredo.size()];
		parte_segredo.copy(segredo_array,parte_segredo.size(),0);
		unsigned int contador = 0;
		locale loc;
		while(contador == parte_segredo.size() || isdigit(segredo_array[contador],loc)==0 ){ // e um numero?
			contador++;
		}
		inicio  = atoi(segredo_array+contador);	
		delete(segredo_array);	//deletando o ponteiro segredo_array
	}//Fechando escopo

	int posicao = 0;	
	int medida = (*(medidas));
	int linha =  ( ( inicio ) / ( medida ) ) ;	//acha linha
	int coluna = ( inicio - (linha) *  medida ); //Acha coluna 
	int cont_bits = 0;	//numero de bits
	int fim = 0;
	int proxima_medida = (*(medidas + 1 ));	//evitando ponteiro
	char letra_atual; //letra corrente

	for (int cont_linhas = linha; cont_linhas < medida ; ++cont_linhas)
	{
		for (int cont_colunas = coluna; cont_colunas < proxima_medida ; ++cont_colunas)
		{
			letra_atual = (letra_atual | ((faixa[cont_linhas][cont_colunas][0]) & (0x01)));	//concatena os ultimos bits
			cont_bits++;
			if (cont_bits == 8){	//verifica se todos os bits foram encontrados 
				if (fim == 1){	//Verifica se já foi achada toda mensagem

				}else if (letra_atual == '#') {	//e o ultimo digito?
					segredoCinza.insert(posicao,1,letra_atual);	//adiciona ultimo digito
					posicao++;
					fim = 1;
				}else {
					cont_bits = 0 ;	//reinicia o contador
					segredoCinza.insert(posicao,1,letra_atual);	//concatena a string
					posicao++; 
					letra_atual = (letra_atual & 0x00);
				}
			}else {	//achou todos os bits?
				letra_atual = (letra_atual<<1);
			} 
		}
		coluna = 0;	//reinicia da primeira coluna
	}

}