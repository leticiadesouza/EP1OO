#ifndef PROCESSA_HPP
#define PROCESSA_HPP
#include <iostream>
#include <string>
using namespace std;
//classe generica de processamento que sera especificada nas classes processaCinza e processaRGB
class processa {
	protected:
		string segredoCinza;
		char *** faixaRGB;
	public:
		char *** getFaixaRGB();	//Retorna a faixaRGB
		string getSegredoCinza(); //Retorna o segredo presente na imagem cinza 
		processa();
};

#endif