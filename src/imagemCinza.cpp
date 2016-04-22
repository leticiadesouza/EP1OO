#include "imagemCinza.hpp"
//Declaração por causa do ifstream
using namespace std;

imagemCinza::imagemCinza(const char * arquivo){
	MagicNumber = new char[3];
	Dimensoes = new int[2];

	ifstream leitor;

	leitor.open (arquivo, ifstream::in | ifstream::binary);
	leitor.getline(MagicNumber,3);	//numero magico ja definido como primeiro valor do arquivo
		
	{	//Abrindo escopo para uso de variaveis locais
		int saida = 0;	//Variavel para contar se todos os parametros foram achados
		char auxiliar;	//Variavel auziliar para ver o proximo argumento sem mover o ponteiro do arquivo
		while (saida < 2){

			auxiliar = leitor.peek();	//'Espiando' a proxima letra do arquivo
			if (auxiliar == '#'){	//Caso seja comentario salva o valor em comentario
				getline (leitor,Comentario);
				Comentario = Comentario + " ";
				setComentario(Comentario);
			}
			else if (saida == 0)	//Caso não seja comentario e nenhum argumento seja sido achado no arquivo é salvo o valor das dimensões
			{
				leitor >> Dimensoes[0];
				leitor >> Dimensoes[1];
				saida ++;
			}
			else if (saida == 1){	//Caso não seja comentario e já tenha sido salvo o primeiro argumento é salvo o valor da profundidade
				int Numeros;
				leitor >> Numeros;
				setProfundidade(Numeros);
				saida++;
			}
		} // Fechando laço de repetição

		auxiliar = leitor.peek();	//'Espiando' a proxima letra do arquivo
		if (auxiliar == '\n')	//Caso proxima letra seja um espaço para saltar linhas é ignorado isso
		{
			leitor.seekg (1, leitor.cur);
		}
	} //Fechando escopo para destruir variaveis locais
	//Alocação Dinamica das camadas
	faixa = new char ** [Dimensoes[0]];
	for (int i = 0; i < Dimensoes[0]; ++i)
	{
		faixa[i] = new char * [Dimensoes[1]];
		for (int j = 0; j < Dimensoes[1]; ++j)
		{
		faixa[i][j] = new char ;
		}
	}
	//Copiando o valor do arquivo para a memoria
	for (int i = 0; i < Dimensoes[0]; ++i)
	{
		for (int j = 0; j < Dimensoes[1]; ++j)
		{
			leitor.get(faixa[i][j][0]);
		}
	}
	leitor.close();
};

imagemCinza::~imagemCinza(){
};