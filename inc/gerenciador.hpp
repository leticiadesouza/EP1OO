#ifndef GERENCIADORDEIMAGENS_HPP
#define GERENCIADORDEIMAGENS_HPP
#include <stdlib.h>		//For use of exit()
#include <iostream>		//For use of cin // cout // delete() // new
#include <fstream>		//For use of open() // is_open() // close () //
#include <string>
#include <cstring>
#include "imagemCinza.hpp"//For use of getMagicNumber() // get_parte_segredo // get_medidas ...
#include "imagemRGB.hpp"	//For use of getMagicNumber() // get_parte_segredo // get_medidas ...
#include "processaCinza.hpp"
#include "processaRGB.hpp"
using namespace std;

class Gerenciador{
	public:

		void tratar_imagem_cinza();
		void tratar_imagem_colorida();
	private:
		void oi();
		void obter_segredo(imagemCinza * imagem);
		string obter_info_imagem(); 
};
#endif