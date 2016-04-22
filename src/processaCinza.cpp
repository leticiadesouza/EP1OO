//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include "processaCinza.hpp"
//declaração por causa das strings
using namespace std;

processaCinza::processaCinza(char *** faixa, int * Dimensoes,string Comentario){

	//Achando o Inicio da mensagem escondida
	int Inicio;
	{//Abrindo escopo para uso de variaveis locais
		char * buffer;
		buffer = new char[Comentario.size()];
		Comentario.copy(buffer,Comentario.size(),0); //Transformanda de String para *char para poder usar isdigit
		unsigned int i = 0;
		locale loc;
		while(isdigit(buffer[i],loc)==0 || i == Comentario.size()){	//Verificando se o valor é um numero ou não
			i++;
		}
		Inicio  = atoi(buffer+i);	//Transformando de char para inteiro
		delete(buffer);	//Liberando a memoria de buffer
	}//Fechando escopo para destruir variaveis locais

	char Letra; //Varivel para acumular a letra atual
	int Contador = 0;	//Conta o numero de Bits extraidos
	int FimDaBusca = 0;	//Verifica se foram achado todas as letras
	int k = 0;	//Salva a posição a ser salva a letra na string
	int I = (*(Dimensoes));	//Passa de ponteiro para alocação estatica
	int J = (*(Dimensoes + 1 ));	//Passa de ponteiro para alocação estatica
	int Inicio2 =  ( ( Inicio ) / ( I ) ) ;	//Acha a linha aonde se começa o texto escondido
	int Inicio3 = ( Inicio - (Inicio2) *  I ); //Acha a coluna aonde se começa o texto escondido

	for (int i = Inicio2; i < I ; ++i)
	{
		for (int j = Inicio3; j < J ; ++j)
		{
			Letra = (Letra | ((faixa[i][j][0]) & (0x01)));	//Remove ultimo Bit do pixel atual e salva em Letra, com os pixels anteriores
			Contador++;	//Atualiza o numero de bits achados
			if (Contador == 8){	//Se for achado todos os bits 
				if (FimDaBusca == 1){	//Verifica se já foi achada toda mensagem

				}
				else if (Letra == '#')	//Verifica se é o ultimo argumento a ser achado
				{
					segredoCinza.insert(k,1,Letra);	//Adiciona o ultimo arquimento ao fim da string
					k++;	//Acumulador para posição final da string
					FimDaBusca = 1;	//Argumento para definir que a busca acabou
				}
				else
				{
					Contador = 0 ;	//Reseta contador de bits achados
					segredoCinza.insert(k,1,Letra);	//Adiciona o ultimo arquimento ao fim da string
					k++; //Acumulador para posição final da string
					Letra = (Letra & 0x00); //Zera o conteudo de letra
				}
			}
			else	//Caso não tenha achado todos os bits
			{
				Letra = (Letra<<1);	//da um shift para a esquerda no contrudo de letra, deixando o ultimo bit livre para o novo arguimento
			} 
		}
		Inicio3 = 0;	//Limpa Variavel Inicio 3 para começar no inicio da proxima linha;
	}

}