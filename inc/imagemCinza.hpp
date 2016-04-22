//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
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