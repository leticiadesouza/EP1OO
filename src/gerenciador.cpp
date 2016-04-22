
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
	//Vavel para armazenar Arquivo em Buffer
	imagemRGB * imagem;
	// Pegando nome do arquivo
	char caminho_arquivo[256];
	cout << "Entre com o endereço e nome do arquivo do arquivo: (pasta/imagem)" << endl;
	cin.clear();	//Preparando cin para entrada do usuario
	cin.ignore(10000,'\n');
	std::cin.getline (caminho_arquivo,256);	//Pegando nome do arquivo
	// Abrindo o Arquivo
	std::fstream arquivo;
	arquivo.open (caminho_arquivo, fstream::in);
	//Testando se o Arquivo foi aberto
	if (arquivo.is_open()) {
    }
	else {
		//Caso o Arquivo não seja aberto corretamente o Usuario é avisado e o programa reinicia;
		cout << "Error ao abrir o arquivo"<< endl;
		cout << "Pressione qualquer tecla para voltar ao menu inicial"<< endl;
		cin.clear();	//Preparando cin para entrada do usuario
			cin.ignore(10000,'\n');
		cin.ignore(1);
	}
	//Caso o arquivo seja aberto corretamente, é verificado se o formato é o certo.
	{
		//Verifica se o arquivo aberto esta no formato correto esperado
		char numero_magico[3];

		arquivo.getline(numero_magico,3);
		arquivo.close();

		if ((numero_magico[0] == 'P') && (numero_magico[1] == '6'))
		{
			imagem = new imagemRGB(caminho_arquivo);
		}
		else{
			//Caso o formato seja errado é avisado para o usuario e o programa reinicia
			cout << "Tipo errado de arquivo" << endl;
			cout << "Pressione qualquer tecla para voltar ao menu inicial"<< endl;
			cin.clear();	//Preparando cin para entrada do usuario
			cin.ignore(10000,'\n');
			cin.ignore(1);
			delete(imagem);

		}
	}
	//Limpando a Tela
	system("clear");
	//Alocando Variaveis Locais
	int numero_cor;	//Variavel para selecionar a unica cor a permanecer na imagem
	//Menu de selecão de cor
	cout << "-------------------------------------------------------" << endl;
	cout << "------------Escola a camada a ser Mantida--------------" << endl;
	cout << "------------1 -> Vermelho------------------------------" << endl;
	cout << "------------2 -> Verde---------------------------------" << endl;
	cout << "------------3 -> Azul----------------------------------" << endl;
	cout << "Entre com a Opção: ";
	cin >> numero_cor;
	
	if (numero_cor == 1)
	{
		cout << endl << "Foi Selecionada a cor Vermelha" << endl;
	}
	else if (numero_cor == 2)
	{
		cout << endl << "Foi Selecionada a cor Verde" << endl;
	}else if (numero_cor == 3)
	{
		cout << endl << "Foi Selecionada a cor Azul" << endl;
	}else{
		cout << endl << "Opção Invalida" << endl;
		cout << "Pressione qualquer tecla para voltar ao menu inicial"<< endl;
		cin.clear();	//Preparando cin para entrada do usuario
			cin.ignore(10000,'\n');
		cin.ignore(1);
		delete(imagem);
	}

	//Remove a cor das camadas não desejadas
	processaRGB Texto(imagem->get_faixa(), imagem->get_medidas(), numero_cor - 1);
	arquivo.open ("doc/MensagemEscondida.ppm", fstream::out | fstream::trunc);
	//Verifica se o arquivo aonde vai ser salvo as imagem com o segredo revelado foi aberta corretamente
	if (arquivo.is_open()) {

		arquivo << imagem->getMagicNumber() << endl;
		arquivo << *(imagem->get_medidas()) << " " << *(imagem->get_medidas()+1) << endl;
		arquivo << imagem->getProfundidade() << endl;

		char *** Intensidade = Texto.getFaixaRGB();
			for (int i = 0; i < *(imagem->get_medidas()); ++i)
		{
			for (int j = 0; j < *(imagem->get_medidas()+1) ; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					arquivo << Intensidade[i][j][k] << flush;;
				}
			}
		}

		arquivo.close();
		cout << "A mensagem foi salva com sucesso em ./doc/MensagemEscondida.ppm" << endl;
		cout << "Pressione qualquer tecla para voltar ao menu inicial" << endl;
		cin.clear();	//Preparando cin para entrada do usuario
			cin.ignore(10000,'\n');
		cin.ignore(1);
		delete[](Intensidade);
    }
	else {
		//Caso o Arquivo não seja aberto corretamente o Usuario é avisado e o programa reinicia;
		cout << "Error ao abrir ao criar o arquivo para salva a imagem" << endl;
		cout << "Pressione qualquer tecla para voltar ao menu inicial" << endl;
		cin.clear();	//Preparando cin para entrada do usuario
			cin.ignore(10000,'\n');
		cin.ignore(1);
	}
	delete(imagem);
}
