#ifndef IMAGEMCINZA_HPP
#define IMAGEMCINZA_HPP
#include "imagem.hpp"
#include <iostream>
#include <fstream>
//especificacao da classe imagem referente as imagens em escalas de cinza
class imagemCinza: public imagem { 
	public:
		imagemCinza(const char * Arquivo);	//Construtor do objeto
		~imagemCinza();	//destrutor virtual que chama destutor da classe imangens
};

#endif