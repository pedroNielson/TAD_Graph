#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class graph
{
private:
    int nVertices;
    int matrixGeradora[10][10];
    int verifica1, verifica2, pesoAresta, maiorGrau = 0, menorGrau = 0;

public:
    void leArquivo()
    {

        ifstream entradaTXT;
        string aux;

        entradaTXT.open("entrada.txt");

        if (entradaTXT.is_open())
        {
            while (entradaTXT.eof() == false)
            {
                getline(entradaTXT, aux); //le a primeira linha
                nVertices = stoi(aux);    //converte string para inteiro e armazena o nuemro de vertices
                
                for (int i = 0; i < nVertices; i++)
                {
                    for (int j = 0; j < nVertices; j++)
                    {
                        entradaTXT >> matrixGeradora[i][j];
                    }
                   
                }
            }
        }

        entradaTXT.close();
    }

    bool verificaVertice(int verifica1, int verifica2)
    {
        if (matrixGeradora[verifica1][verifica2] == 0)
            return true;
        else
            return false;
    }

    void inserir()
    {
        cout << "Insira o vertice de saida: ";
        cin >> verifica1;
        cout << endl
             << "Insira o vertice de chegada: ";
        cin >> verifica2;

        if (verificaVertice(verifica1, verifica2))
        {
            cout << "Insira o peso da nova aresta: ";
            cin >> pesoAresta;
            matrixGeradora[verifica1][verifica2] = pesoAresta;
        }
        else
            cout << "Esta aresta já existe ..." << endl;
    }
    void retirarAresta()
    {
        cout << "Insira o vertice de saida: ";
        cin >> verifica1;
        cout << endl << "Insira o vertice de chegada: ";
        cin >> verifica2;

        if(verificaVertice(verifica1, verifica2))
            cout << "Esta aresta não existe ... impossivel concluir tal tarefa" << endl;
        else
        {
            cout << "Aresta encontrada, excluindo ..." << endl;
            matrixGeradora[verifica1][verifica2] = 0;
        }
        
    }
    int verificaMaiorGrau()
    {
        int aux = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                aux = matrixGeradora[i][j];
                if(aux > maiorGrau)   
                    maiorGrau = aux;
                    
                
            }
            
        }

        return maiorGrau;

    }
    int verificaMenorGrau()
    {
        int aux = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                aux = matrixGeradora[i][j];
                if(aux <= menorGrau)   
                    menorGrau = aux;
            }
            
        }

        return menorGrau;

    }


    void imprimirGrafo()
    {
        cout << "Numero de vertices: " << nVertices << endl
             << endl
             << "GRAFO: " << endl;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                cout << matrixGeradora[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph A;
    
    A.leArquivo();
    A.imprimirGrafo();
    //A.inserir();
    //A.imprimirGrafo();
    cout << A.verificaMaiorGrau() << endl;
    cout << A.verificaMenorGrau() << endl;
}