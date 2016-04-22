//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#ifndef	PROCESSARGB_HPP
#define	PROCESSARGB_HPP
#include <iostream>
#include "processa.hpp"
//especificacao da classe processa referente as imagens coloridas
class processaRGB : public processa {
public:
	processaRGB(char *** faixa, int * Dimensoes, int Cor);
};

#endif

