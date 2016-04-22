//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include <stdlib.h>		//For use of exit()
#include <iostream>		//For use of cin // cout // delete() // new
#include <fstream>		//For use of open() // is_open() // close () //
#include "imagemCinza.hpp"//For use of getMagicNumber() // get_parte_segredo // get_medidas ...
#include "imagemRGB.hpp"	//For use of getMagicNumber() // get_parte_segredo // get_medidas ...
#include "processaCinza.hpp"
#include "processaRGB.hpp"
#include "gerenciador.hpp"
//declaração por causa de cin cout e outras chamadas
using namespace std;

int menu();//assinatura da funcao menu

int main(int argc, char const *argv[]) {
	Gerenciador gerenciador;
	int valor;	

	do{
		valor = menu();
		switch (valor) {
		case 0:	
			cout << "Fechando o Programa" << endl;
			break;
		case 1:
			gerenciador.tratar_imagem_cinza();		
			break;
		case 2:
			gerenciador.tratar_imagem_colorida();
			break;
		default:
			cout << "Opção Invalida" << endl;
			cout << "Pressione qualquer tecla para voltar ao menu inicial" << endl;
			cin.clear();
			cin.ignore(10000,'\n');
			cin.ignore(1);
		break;
		}

	}while(valor != 0);

	return 0;
}
int menu() {
	int opcao_menu = 4;		//Variavel para navegar pelo Menu
	system("clear");	//Limpeza da Tela
	cout << "-------------------------------------------------------" << endl;
	cout << "----------Escolha uma opçao do menu abaixo:------------" << endl;
	cout << "1 - Localizar testo em uma imagem em escala de Cinza---" << endl;
	cout << "2 - Ver Apenas uma camada de cor em uma imagem colorida" << endl;
	cout << "0 - Sair-----------------------------------------------" << endl;
	cout << "Opçao:  ";
	cin >> opcao_menu;
	cout << endl;
	return opcao_menu;
}