#ifndef IMAGEMRGB_HPP
#define IMAGEMRGB_HPP
#include "imagem.hpp"
#include <iostream>
#include <fstream>

class imagemRGB: public imagem
{
public:
	imagemRGB(const char * Arquivo);	//Construtor do objeto
	~imagemRGB();	//destrutor 
};

#endif