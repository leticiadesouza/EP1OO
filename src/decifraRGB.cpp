#include "decifraRGB.hpp"

decifraRGB::decifraRGB(char *** faixa, int * medidas, int cor){

int medida = (*(medidas));	//evitando ponteiro
int proxima_medida = (*(medidas + 1 ));	//evitando ponteiro
int cor_atual = 0;	//cor atual

//Alocação das faixasRGB
faixaRGB = new char ** [medida];
	for (int i = 0; i < medida; ++i) {
		faixaRGB[i] = new char * [proxima_medida];
		for (int j = 0; j < proxima_medida; ++j) {
			faixaRGB[i][j] = new char [3];
		}
	}

	for (int i = 0; i < medida; ++i) {
		for (int j = 0; j < proxima_medida; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (cor_atual==cor){// e a cor escolhida pelo usuario?	
					faixaRGB[i][j][k] = faixa[i][j][k]; //salva cor
				}else {	
					faixaRGB[i][j][k] = 0x00; //excluir cor diferente da cor desejada
				}	
				cor_atual++;	//acrescenta cor atual
				if (cor_atual==3) cor_atual=0;	//volta para o inicio caso a cor atual ultrapasse o valor magico
			}
		}
	}
}