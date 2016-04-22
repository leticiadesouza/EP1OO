//___________________________________________________________________
//---------Trabalho de Programação 1----------01/2016----------------
//---------Materia de Orientação a Objetos // Codigo: 195341---------
//---------Professor: Ranato Coral Sampario--------------------------
//---------Aluno: Vinicius Guimarães Hass // Matricula 10/0021751----
//___________________________________________________________________
#include "imagemRGB.hpp"
//Declaração por causa do ifstream
using namespace std;

imagemRGB::imagemRGB(const char * Arquivo){
	MagicNumber = new char[3];
	Dimensoes = new int[2];

	ifstream Leitor;

	Leitor.open (Arquivo, ifstream::in | ifstream::binary);
	Leitor.getline(MagicNumber,3);	//Por padrão o numero magico é sempre o primeiro valor do arquivo
		
	{	//Abrindo escopo para uso de variaveis locais
		int saida = 0;	//Variavel para contar se todos os parametros foram achados
		char auxiliar;	//Variavel auziliar para ver o proximo argumento sem mover o ponteiro do arquivo
		while (saida < 2){

			auxiliar = Leitor.peek();	//'Espiando' a proxima letra do arquivo
			if (auxiliar == '#'){	//Caso seja comentario salva o valor em comentario
				getline (Leitor,Comentario);
				Comentario = Comentario + " ";
				setComentario(Comentario);
			}
			else if (saida == 0)	//Caso não seja comentario e nenhum argumento seja sido achado no arquivo é salvo o valor das dimensões
			{
				Leitor >> Dimensoes[0];
				Leitor >> Dimensoes[1];
				saida ++;
			}
			else if (saida == 1){	//Caso não seja comentario e já tenha sido salvo o primeiro argumento é salvo o valor da profundidade
				int Numeros;
				Leitor >> Numeros;
				setProfundidade(Numeros);
				saida++;
			}
		} // Fechando laço de repetição

		auxiliar = Leitor.peek();	//'Espiando' a proxima letra do arquivo
		if (auxiliar == '\n')	//Caso proxima letra seja um espaço para saltar linhas é ignorado isso
		{
			Leitor.seekg (1, Leitor.cur);
		}

	} //Fechando escopo para destruir variaveis locais
	//Alocação Dinamica das camadas
	faixa = new char ** [Dimensoes[0]];
	for (int i = 0; i < Dimensoes[0]; ++i)
	{
		faixa[i] = new char * [Dimensoes[1]];
		for (int j = 0; j < Dimensoes[1]; ++j)
		{
		faixa[i][j] = new char[3] ;
		}
	}
	//Copiando o valor do arquivo para a memoria
	for (int i = 0; i < Dimensoes[0]; ++i)
	{
		for (int j = 0; j < Dimensoes[1]; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				Leitor.get(faixa[i][j][k]);
			}
		}
	}
	Leitor.close();
};

imagemRGB::~imagemRGB(){
};
