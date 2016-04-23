#ifndef	DECIFRACINZA_HPP
#define	DECIFRACINZA_HPP
#include <iostream>
#include <string>
#include <stdio.h>		
#include <locale>		
#include "decifra.hpp"

using namespace std;
//especificacao da classe decifra referente as imagens em escalas de cinza
class decifraCinza : public decifra {
public:
	decifraCinza(char *** faixa, int * medidas, string parte_segredo);
};

#endif

