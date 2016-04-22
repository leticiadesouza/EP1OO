#ifndef	PROCESSACINZA_HPP
#define	PROCESSACINZA_HPP
#include <iostream>
#include <string>
#include <stdio.h>		
#include <locale>		
#include "processa.hpp"

using namespace std;
//especificacao da classe processa referente as imagens em escalas de cinza
class processaCinza : public processa {
public:
	processaCinza(char *** faixa, int * Dimensoes,string Comentario);
};

#endif

