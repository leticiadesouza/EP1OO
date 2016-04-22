#ifndef IMAGEM_HPP
#define IMAGEM_HPP
#include <iostream>
#include <string>
//declaração por causa das strings
using namespace std;
// Classe abstrata criada para conter Atributos das classes filhas
// e funções generiacas para pegar e retornar o valor dos atributos
class imagem
{
	// Atributos 
protected:
	char * MagicNumber;	//Ponteiro para alocar Numero magico da imagem
	int * medidas;	//Ponteiro para alocar Dimensões da imagem
	int Profundidade;	//Variavel para alocar profundidade de cores da imagem
	string parte_segredo;	//Variavel para alocar comentarios que possam conter na imagem
	char *** faixa;	//Ponteiro para alocar a intensidade de cada pixel da imagem
	// Metodos
public:
	char * getMagicNumber();	//Envia o numero magico
	void setMagicNumber(char * MagicNumber);	//Seta o numero magico
	int * get_medidas();	//Envia o ponteiro para o inicio de aonde estão as dimensões
	void setmedidas(int medidas[2]);	//Seta o valor de cada das dimensões
	int getProfundidade();	//Envia o valor da profundidade de cores
	void setProfundidade(int Profundidade);	//Seta a profundidade de cores
	string get_parte_segredo();	//Envia o comentario da imagem
	void setparte_segredo(string parte_segredo);	//Seta o comentario
	char *** get_faixa();	//Envia o ponteiro para o inicio do valor das cores
	imagem();	//Construtir virtual
	~imagem();	//Destrutor para liberar a memoria das variaveis alocadas dinamicamente
};

#endif