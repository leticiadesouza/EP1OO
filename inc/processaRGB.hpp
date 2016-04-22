#ifndef	PROCESSARGB_HPP
#define	PROCESSARGB_HPP
#include <iostream>
#include "processa.hpp"
//especificacao da classe processa referente as imagens coloridas
class processaRGB : public processa {
public:
	processaRGB(char *** faixa, int * medidas, int cor);
};

#endif

