#include <stdlib.h>		
#include <iostream>		
#include <fstream>		
#include "imagemCinza.hpp"
#include "imagemRGB.hpp"
#include "decifraCinza.hpp"
#include "decifraRGB.hpp"
#include "gerenciador.hpp"

using namespace std;

int menu();

int main(int argc, char const *argv[]) {
	Gerenciador gerenciador;
	int valor;	

	do{
		valor = menu();
		switch (valor) {
		case 0:	
			cout << "     Programa encerrado" << endl;
			break;
		case 1:
			gerenciador.tratar_imagem_cinza();		
			break;
		case 2:
			gerenciador.tratar_imagem_colorida();
			break;
		default:
			cout << "ERRO!! Caminho invalido" << endl;
			cout << "Enter para retornar ao menu" << endl;
			cin.clear();
			cin.ignore(10000,'\n'); 
			cin.ignore(1);
		break;
		}

	}while(valor != 0);

	return 0;
}
int menu() {
	int opcao_menu = 4;
	system("clear");//Limpa a Tela
	cout << "*******************************************************" << endl;
	cout << "*             Universidade de Brasilia                *" << endl;
	cout << "*          Disciplina:Orientacao a Objetos            *" << endl;
	cout << "*     Aluna:Leticia de Souza Santos - 15/0015160      *" << endl;
	cout << "*******************************************************" << endl;
	cout << "               Digite a opcao desejada: " << endl;
	cout << "      1 -> Segredo da imagem cinza "      << endl;
	cout << "      2 -> Exibir uma camada de cor na imagem colorida" << endl;
	cout << "      0 -> Sair " << endl;
	cout << "      Opçao:  ";
	cin >> opcao_menu;
	cout << endl;
	return opcao_menu;
}