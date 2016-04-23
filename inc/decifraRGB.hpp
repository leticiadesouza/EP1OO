#ifndef	DECIFRARGB_HPP
#define	DECIFRARGB_HPP
#include <iostream>
#include "decifra.hpp"
//especificacao da classe decifra referente as imagens coloridas
class decifraRGB : public decifra {
public:
	decifraRGB(char *** faixa, int * medidas, int cor);
};

#endif

