#ifndef GERENCIADORDEIMAGENS_HPP
#define GERENCIADORDEIMAGENS_HPP
#include <stdlib.h>		//For use of exit()
#include <iostream>		//For use of cin // cout // delete() // new
#include <fstream>		//For use of open() // is_open() // close () //
#include <string>
#include <cstring>
#include "imagemCinza.hpp"//For use of get_numero_magico() // get_parte_segredo // get_medidas ...
#include "imagemRGB.hpp"	//For use of get_numero_magico() // get_parte_segredo // get_medidas ...
#include "decifraCinza.hpp"
#include "decifraRGB.hpp"
using namespace std;

class Gerenciador{
	public:

		void tratar_imagem_cinza();
		void tratar_imagem_colorida();
	private:
		//void verifica_formato(ofstream arquivo, string caminho_arquivo);
		void obter_segredo(imagemCinza * imagem);
		string obter_info_imagem(); 
		void imprime_oi();
		void verifica_formato(string caminho_arquivo, char numero_magico[3]);
};
#endif