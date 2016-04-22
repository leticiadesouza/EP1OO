//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include "imagem.hpp"

using namespace std;

char * imagem::getMagicNumber(){
	return MagicNumber;
}

void imagem::setMagicNumber(char * MagicNumber){
	this->MagicNumber = MagicNumber;
}

int * imagem::getDimensoes(){
	return Dimensoes;
}

void imagem::setDimensoes(int Dimensoes[2]){
	this->Dimensoes=Dimensoes;
}

int imagem::getProfundidade(){
	return Profundidade;
}

void imagem::setProfundidade(int Profundidade){
	this->Profundidade=Profundidade;
}

string imagem::getComentario(){
	return Comentario;
}

void imagem::setComentario(string Comentario){
	this->Comentario=Comentario;	
}

char *** imagem::getfaixa(){
	return faixa;
}

imagem::imagem(){
};

imagem::~imagem(){
	delete[](MagicNumber);
	delete[](Dimensoes);
	delete[](faixa);
};