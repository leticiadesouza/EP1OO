//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include "processaRGB.hpp"

processaRGB::processaRGB(char *** faixa, int * medidas, int cor){

//----------------------------------
//---------cor 0x00 = Vermelho------
//---------cor 0x01 = Verde---------
//---------cor 0x10 = Azul----------
//----------------------------------

int I = (*(medidas));	//Passa de ponteiro para alocação estatica
int J = (*(medidas + 1 ));	//Passa de ponteiro para alocação estatica
int cor_atual = 0;	//Variavel para acompanhar qual cor o processo esta verificando no memento

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
				if (cor_atual==cor)	faixaRGB[i][j][k] = faixa[i][j][k];	//Caso a cor atual seja a escolhida pelo usuario essa cor é copiada
				else	faixaRGB[i][j][k] = 0x00;	//Caso a cor atual seja diferente da escolhida pelo usuario essa cor é apagada
				cor_atual++;	//É incrementado cor atual
				if (cor_atual==3) cor_atual=0;	//Caso cor atual seja maior que o valor maximo ela é resetada para o inicio
			}
		}
	}
}