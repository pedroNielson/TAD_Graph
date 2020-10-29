#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class graph
{
private:
    int nVertices; //numero de vertices
    int matrixGeradora[10][10]; //matriz principal
    int matrixTransposto[10][10]; //matriz transposta
    
    int verifica1, verifica2, pesoAresta, maiorPeso = 0, menorPeso = 0;

public:
    void leArquivo() //metodo que ira ler o arquivo txt
    {

        ifstream entradaTXT;
        string aux;

        entradaTXT.open("entrada.txt"); //comando para abrir o arquivo

        if (entradaTXT.is_open()) //Se o arquivo estiver aberto 
        {
            while (entradaTXT.eof() == false) //enquanto 
            {
                getline(entradaTXT, aux); //le a primeira linha
                nVertices = stoi(aux);    //converte string para inteiro e armazena o nuemro de vertices

                for (int i = 0; i < nVertices; i++) //Roda a matriz para ler item por item
                {
                    for (int j = 0; j < nVertices; j++)
                    {
                        entradaTXT >> matrixGeradora[i][j]; //Como a matriz esta separada por espacos, a leitura ocorre item por item
                    }
                }
            }
        }

        entradaTXT.close(); //fecha o arquivo 

    }

    bool verificaAresta() //metodo que verifica se aresta existe no grafo
    {
        if (matrixGeradora[verifica1][verifica2] == 0) //se o valor entre o vertice 1 e 2 for 0, entao a aresta nao existe 
            return true; //retorna verdadeiro, aresta nao existe
        else
            return false; //retorna falso, aresta existe 
    }

    void inserir() //metodo para inserir uma aresta no grafo
    {
        cout << "Insira o vertice de saida: ";
        cin >> verifica1; //inserir o vertice de saida
        cout << endl
             << "Insira o vertice de chegada: ";
        cin >> verifica2; //inserir o vertice de chegada

        if (verificaAresta())//verifica se a aresta ja existe
        {
            cout << "Insira o peso da nova aresta: ";
            cin >> pesoAresta;//caso exista, pede o peso da nova aresta
            matrixGeradora[verifica1][verifica2] = pesoAresta;//insere a nova aresta com o peso determinado 
        }
        else
            cout << "Esta aresta já existe ..." << endl; //caso a aresta ja exista, retorna ao usuario tal mensagem
    }
    void retirarAresta() //metodo para retirar uma aresta do grafo 
    {
        cout << "Insira o vertice de saida: ";
        cin >> verifica1; //inserir o vertice de saida
        cout << endl
             << "Insira o vertice de chegada: ";
        cin >> verifica2; //inserir o vertice de chegada

        if (verificaAresta()) //verifica se a aresta existe
            cout << "Esta aresta não existe ... impossivel concluir tal tarefa" << endl; //caso nao exista, impossivel de efetuar a tarefa
        else 
        {
            cout << "Aresta encontrada, excluindo ..." << endl;
            matrixGeradora[verifica1][verifica2] = 0; // caso exista, iguala a aresta a 0
        }
    }
    int verificaMaiorPeso() //metodo para verificar o maior peso das arestas do grafo
    {
        int aux = 0; //variavel auxiliar
        for (int i = 0; i < nVertices; i++)//roda a matriz para verificar todos as arestas 
        {
            for (int j = 0; j < nVertices; j++)
            {
                aux = matrixGeradora[i][j]; //armazena item por item 
                if (aux > maiorPeso)//verifica se o item atual eh maior q o de Maior peso
                    maiorPeso = aux; //se for atualiza a variavel de maior peso
            }
        }

        return maiorPeso; //retorno o maior peso do grafo 
    }
    int verificaMenorPeso()//metodo para verificar o menor peso das arestas do grafo
    {
        int aux = 0;//variavel auxiliar
        for (int i = 0; i < nVertices; i++)//roda a matriz para verificar todos as arestas
        {
            for (int j = 0; j < nVertices; j++)
            {
                aux = matrixGeradora[i][j];//armazena item por item 
                if (aux <= menorPeso)//verifica se o item atual eh menor ou igual q o de menor peso
                    menorPeso = aux;//se for atualiza a variavel de menor peso
            }
        }

        return menorPeso;//retorno o peso peso do grafo 
    }
    void grafoTransposto() //metodo para retornar o grafo transposto do grafo inserido
    {

        int aux = 0; //variavel auxiliar

        for (int i = 0; i < nVertices; i++)//pega todos os valores da matriz original, para nao mudar esta, mudar a transposta
        {
            for (int j = 0; j < nVertices; j++)
            {
                matrixTransposto[i][j] = matrixGeradora[i][j];
                
            }
        }

        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                if(i>j)//se a linha for maior q a coluna
                {   
                    aux = matrixTransposto[i][j];//armazena a aresta em aux
                    matrixTransposto[i][j] = matrixTransposto[j][i]; //transpoe a informacao 
                    matrixTransposto[j][i] = aux; // recebe a info original 
                }
            }
            
        }
        cout << "Grafo transposto: " << endl; //imprime o grafo transposto
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                cout << matrixTransposto[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }

    void verticesAdjacentes() //metodo que verifica vertices adjacentes a um desejado
    {
        cout << "Entre com o vertice a ser verificado: "; //pede o vertice inicial
        cin >> verifica1;
        cout << endl << "Vertices adjacentes ao vertice " << verifica1 << endl;
        for (int i = 0; i < nVertices; i++)//roda a matriz para verificar todos os intens 
        {
            if(matrixGeradora[verifica1][i] != 0) //verifica se as colunas da linha do vertice desejado sao diferentes de 0
            {
                cout << "-> " << i << endl; //caso seja ele mostra os vertices adjacentes 
            }
        }

    }

    void imprimirGrafo()//Metodo para imprimir o grafo 
    {
        cout << "Numero de vertices: " << nVertices << endl //imprime o numero de vertices
             << endl
             << "GRAFO: " << endl;
        for (int i = 0; i < nVertices; i++) //roda a matriz para imprimir o grafo
        {
            for (int j = 0; j < nVertices; j++)
            {
                cout << matrixGeradora[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void menu()//metodo para o menu exibido na saida 
    {

        int operador = 0;
        while (operador != 11) //enquanto operador for diferente de 10
        {

            cout << "------------- TAD_grafo ------------- \n\n\n";
            cout << "(1)  Iniciar grafo: \n";
            cout << "(2)  Inserir uma aresta no grafo: \n";
            cout << "(3)  Verificar se uma aresta existe: \n";
            cout << "(4)  Verificar vertices adjacentes: \n";
            cout << "(5)  Retirar uma aresta do grafo: \n";
            cout << "(6)  Imprimir o grafo: \n";
            cout << "(7)  Numero de vertices: \n";
            cout << "(8)  Grafo transposto: \n";
            cout << "(9)  Aresta de menor peso: \n";
            cout << "(10) Aresta de maior peso: \n";
            cout << "(11) Sair: \n\n";
            cout << "Escolha uma opcao: ";
            cin >> operador;
            cout << endl;

            switch (operador)
            {
            case 1:
                leArquivo();
                break;
            case 2:
                inserir();
                break;
            case 3:
                cout << "Insira o vertice de saida: ";
                cin >> verifica1;
                cout << endl
                     << "Insira o vertice de chegada: ";
                cin >> verifica2;

                if (verificaAresta())
                    cout << "Aresta nao existe ... " << endl;
                else
                    cout << "Aresta existe ... " << endl;

                break;
            case 4:
                verticesAdjacentes();
                break;
            case 5:
                retirarAresta();
                break;
            case 6:
                imprimirGrafo();
                break;
            case 7:
                cout << "Numero de vertices: " << nVertices << endl;
                break;
            case 8:
                grafoTransposto();
                break;
            case 9:
                cout << "Aresta de menor peso: " << verificaMenorPeso() << endl;
                break;
            case 10:
                cout << "Aresta de maior peso: " << verificaMaiorPeso() << endl;
                break;
            case 11:
                break;
            }
        }
    }
};

int main()
{
    graph A; //cria o objeto
    A.menu(); //chama o metodo menu que chamara todos os outros de acordo com a entrada do usuario 
}
