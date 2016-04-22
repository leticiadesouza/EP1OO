
#include "gerenciador.hpp"

// metodo que retira o texto da imagem e salva em um arquivo.txt
void Gerenciador::obter_segredo(imagemCinza * imagem) {
	ofstream arquivo;
	processaCinza Texto(imagem->get_faixa(), imagem->get_medidas(),imagem->get_parte_segredo());
	arquivo.open ("doc/segredoImagem.txt", fstream::out | fstream::trunc); //abrindo arquivo na pasta doc com o nome segredoImagem.txt
	if (arquivo.is_open()) { //o arquivo esta aberto?
		cout << "AQUIIIII> " << Texto.getSegredoCinza() << endl;
		arquivo << Texto.getSegredoCinza(); 
		arquivo.close();//fechando arquivo
		cout << "Segredo registrado em: doc/segredoImagem.txt" << endl << "Enter para retornar ao menu" << endl;
		//cin.clear();	//limpando o buffer
		//cin.ignore(10000,'\n');
		getchar();//Esperando qualquer entrada do usuario
    }
	else {//em caso de falha ao abrir o arquivo
		cout << "ERRO!!\n Falha ao abrir o arquivo" << endl;
		cout << "Enter para retornar ao menu" << endl;
		cin.clear();	//limpando o buffer
		cin.ignore(10000,'\n');
		delete(imagem);
	}
}

int menu_cor(){
	int numero_cor;
	//Menu de selecão de cor
	do {
		cout << "          Entre com a cor de sua preferencia\n" << endl;
		cout << "                  1 -> Vermelho" << endl;
		cout << "                  2 -> Verde" << endl;
		cout << "                  3 -> Azul" << endl;
		cin >> numero_cor;
		if(numero_cor != 1 && numero_cor != 2 && numero_cor != 3){
			cout << "ERRO!! Entrada invalida" << endl;
		}
	}while (numero_cor != 1 && numero_cor != 2 && numero_cor != 3);
	return numero_cor;
}
// obtendo o caminho e nome da imagem
string Gerenciador::obter_info_imagem(){
	string nome;
	string caminho;
	cout << "insira o caminho da imagem: " << endl;
	cin.clear();//limpando o buffer
	cin.ignore(10000, '\n');
	getline(cin, caminho);
	cout << "insira o nome da imagem: " << endl;
	cin.clear();//limpando o buffer
	getline(cin, nome);
	return caminho + "/" + nome;//construindo string para achar o arquivo
} 
void Gerenciador::tratar_imagem_cinza(){
	
	imagemCinza * imagem;//armazenar imagem em buffer
	string caminho_arquivo;//local + nome do arquivo
	caminho_arquivo = obter_info_imagem();
	// Abrindo o Arquivo
	std::fstream arquivo;
	arquivo.open (caminho_arquivo, fstream::in);
	//Testando se o Arquivo foi aberto
	if (!arquivo.is_open()) {
		//erro ao abrir
		cout << "ERRO!!\n o arquivo nao pode ser aberto"<< endl;
		cout << "Enter para retornar ao menu"<< endl;
		cin.clear();	//limpando o buffer
		cin.ignore(10000,'\n');
    }
	else {
		//nada a fazer
	}
	//Apos verificar a abertura do arquivo, verifica-se o formato
	{//definindo escopo
		char numero_magico[3];
		
		arquivo.getline(numero_magico,3);
		arquivo.close();

		if ((numero_magico[0] == 'P') && (numero_magico[1] == '5')){
			imagem = new imagemCinza(caminho_arquivo.c_str());
		}
		else{
			//formato errado
			cout << "Formato invalido" << endl;
			cout << "Enter para retornar ao menu"<< endl;
			cin.clear();	//limpando o buffer
			cin.ignore(10000,'\n');
		}
	}

	//obtem o segredo
	obter_segredo(imagem);
}

void Gerenciador::tratar_imagem_colorida() {
	imagemRGB * imagem;
	string caminho_arquivo;
	caminho_arquivo = obter_info_imagem();
	std::fstream arquivo; //abrindo arquivo
	arquivo.open (caminho_arquivo, fstream::in);
	if (arquivo.is_open()) {
    }
	else {
		cout << "ERRO!! O arquivo nao pode ser aberto"<< endl;
		cout << "Enter para retornar ao menu"<< endl;
		cin.clear();	//limpando buffer
			cin.ignore(10000,'\n');
		cin.ignore(1);
	}
	//escopo
	{
		//arquivo aberto no formato correto
		char numero_magico[3];

		arquivo.getline(numero_magico,3);
		arquivo.close();

		if ((numero_magico[0] == 'P') && (numero_magico[1] == '6')) {
			imagem = new imagemRGB(caminho_arquivo.c_str());
		}
		else{
			cout << "Erro no formato de arquivo" << endl;
			cout << "Enter para retornar ao menu"<< endl;
			cin.clear();	//limpando buffer
			cin.ignore(10000,'\n');
			cin.ignore(1);
			delete(imagem);

		}
	}
	system("clear"); // limpar tela
	
	int numero_cor;	//Variavel cor selecionada
	numero_cor = menu_cor();
	
	switch(numero_cor){
		case 1:
			cout << endl << "Cor vermelha escolhida" << endl;
			break;
		case 2:
			cout << endl << "Cor Verde escolhida" << endl;
			break;
		case 3:
			cout << endl << "Cor Azul escolhida" << endl;		
	}

	//Remove a cores nao desejadas
	processaRGB Texto(imagem->get_faixa(), imagem->get_medidas(), numero_cor - 1);
	arquivo.open ("doc/segredoImagem.ppm", fstream::out | fstream::trunc);
	//arquivo aberto com sucesso?
	if (arquivo.is_open()) {

		arquivo << imagem->getMagicNumber() << endl;
		arquivo << *(imagem->get_medidas()) << " " << *(imagem->get_medidas()+1) << endl;
		arquivo << imagem->getProfundidade() << endl;

		char *** intensidade = Texto.getFaixaRGB();
			for (int i = 0; i < *(imagem->get_medidas()); ++i) {
				for (int j = 0; j < *(imagem->get_medidas()+1) ; ++j) {
					for (int k = 0; k < 3; ++k) {
						arquivo << intensidade[i][j][k] << flush;;
					}
				}
			}

		arquivo.close();
		cout << "Segredo salvo em ./doc/segredoImagem.ppm" << endl;
		cout << "Enter para retornar ao menu" << endl;
		cin.clear();	//limpando buffer
		cin.ignore(10000,'\n');
		cin.ignore(1);
		delete[](intensidade);
    }
	else {
		//erro ao abrir
		cout << "ERRO!! Falha na criacao do arquivo" << endl << "Enter para retornar ao menu" << endl;
		cin.clear();	//limpando buffer
		cin.ignore(10000,'\n');
		cin.ignore(1);
	}
	delete(imagem);
}
