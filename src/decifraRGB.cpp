//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include "processaRGB.hpp"

processaRGB::processaRGB(char *** faixa, int * Dimensoes, int Cor){

//----------------------------------
//---------Cor 0x00 = Vermelho------
//---------Cor 0x01 = Verde---------
//---------Cor 0x10 = Azul----------
//----------------------------------

int I = (*(Dimensoes));	//Passa de ponteiro para alocação estatica
int J = (*(Dimensoes + 1 ));	//Passa de ponteiro para alocação estatica
int CorAtual = 0;	//Variavel para acompanhar qual cor o processo esta verificando no memento

//Alocação de camadaRGB
faixaRGB = new char ** [I];
	for (int i = 0; i < I; ++i)
	{
		faixaRGB[i] = new char * [J];
		for (int j = 0; j < J; ++j)
		{
			faixaRGB[i][j] = new char [3];
		}
	}

	for (int i = 0; i < I; ++i)
	{
		for (int j = 0; j < J; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (CorAtual==Cor)	faixaRGB[i][j][k] = faixa[i][j][k];	//Caso a cor atual seja a escolhida pelo usuario essa cor é copiada
				else	faixaRGB[i][j][k] = 0x00;	//Caso a cor atual seja diferente da escolhida pelo usuario essa cor é apagada
				CorAtual++;	//É incrementado cor atual
				if (CorAtual==3) CorAtual=0;	//Caso cor atual seja maior que o valor maximo ela é resetada para o inicio
			}
		}
	}
}