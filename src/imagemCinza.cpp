#include "imagemCinza.hpp"
using namespace std;

imagemCinza::imagemCinza(const char * arquivo){
	MagicNumber = new char[3];
	medidas = new int[2];

	ifstream leitor;

	leitor.open (arquivo, ifstream::in | ifstream::binary);
	leitor.getline(MagicNumber,3);	//numero magico ja definido como primeiro valor do arquivo
		
	{	//criando escopo
		int saida = 0;	//confere se todos os parametros foram encontrados
		char auxiliar;	//guarda o proximo caractere 
		while (saida < 2){

			auxiliar = leitor.peek();	//confere o proximo caractere 
			if (auxiliar == '#'){	//e comentario?
				getline (leitor,parte_segredo);
				parte_segredo = parte_segredo + " ";
				setparte_segredo(parte_segredo);
			}
			else if (saida == 0) {//nao e comentario e nao tem caractere salvo no arquivo, valor das dimencoes e salvo
				leitor >> medidas[0];
				leitor >> medidas[1];
				saida ++;
			}
			else if (saida == 1){	//nao e comentario e tenha caractere salvo no arquivo, e salvo o valor da profundidade
				int Numeros;
				leitor >> Numeros;
				setProfundidade(Numeros);
				saida++;
			}
		} 

		auxiliar = leitor.peek(); //guarda o proximo caractere
		if (auxiliar == '\n') {	//ignorar em caso de quebra de linha
			leitor.seekg (1, leitor.cur);
		}
	} //Fechando escopo

	faixa = new char ** [medidas[0]];
	for (int i = 0; i < medidas[0]; ++i) {
		faixa[i] = new char * [medidas[1]];
		for (int j = 0; j < medidas[1]; ++j) {
		faixa[i][j] = new char ;
		}
	}
	for (int i = 0; i < medidas[0]; ++i) {//copia o valor do arquivo na memoria
		for (int j = 0; j < medidas[1]; ++j) {
			leitor.get(faixa[i][j][0]);
		}
	}
	leitor.close();
};

imagemCinza::~imagemCinza(){
};
