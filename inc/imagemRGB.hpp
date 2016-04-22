//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
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