#ifndef IMAGEMRGB_HPP
#define IMAGEMRGB_HPP
#include "imagem.hpp"
#include <iostream>
#include <fstream>
//Classe filha de "imagens" para alocação na memoria dos atributos
//de imagens coloridas
class imagemRGB: public imagem
{
public:
	imagemRGB(const char * Arquivo);	//Construtor do objeto
	~imagemRGB();	//destrutor virtual que chama destutor da classe imangens
};

#endif