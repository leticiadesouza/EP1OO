#include "imagem.hpp"

using namespace std;

char * imagem::getMagicNumber(){
	return MagicNumber;
}

void imagem::setMagicNumber(char * MagicNumber){
	this->MagicNumber = MagicNumber;
}

int * imagem::get_medidas(){
	return medidas;
}

void imagem::setmedidas(int medidas[2]){
	this->medidas=medidas;
}

int imagem::getProfundidade(){
	return Profundidade;
}

void imagem::setProfundidade(int Profundidade){
	this->Profundidade=Profundidade;
}

string imagem::get_parte_segredo(){
	return parte_segredo;
}

void imagem::setparte_segredo(string parte_segredo){
	this->parte_segredo=parte_segredo;	
}

char *** imagem::get_faixa(){
	return faixa;
}

imagem::imagem(){
};

imagem::~imagem(){
	delete[](MagicNumber);
	delete[](medidas);
	delete[](faixa);
};