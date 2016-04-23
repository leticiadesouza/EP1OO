#include "imagem.hpp"

using namespace std;

char * imagem::get_numero_magico(){
	return numero_magico;
}

void imagem::set_numero_magico(char * numero_magico){
	this->numero_magico = numero_magico;
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
	delete[](numero_magico);
	delete[](medidas);
	delete[](faixa);
};