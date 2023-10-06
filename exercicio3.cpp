#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Produto{
    int codigo;
    string nome;
    float preco;
};

void add_empregado( vector <Produto> &produto);
void lista_produtos(vector <Produto> &produto);
void buscar_produtos(vector <Produto> &produto);
bool remover_produto(vector <Produto> &produto);

int main(){
    vector <Produto> produto;

        add_empregado(produto);
        lista_produtos(produto);
        buscar_produtos(produto);


        if(remover_produto(produto)){
            cout << "Produto removido com sucesso."<< endl;

        }else{
            cout << "Erro ao remover produto."<< endl;
        }

        lista_produtos(produto);

    return 0;
}

void add_empregado(vector <Produto> &produto){
    
    char resposta;
    Produto novo_produto;
    do {

        cout << "Digite o nome do funcionario " << endl;
        cin >> novo_produto.nome;

        cout << "Digite o codigo do produto " << endl;
        cin >> novo_produto.codigo;


        cout << "Digite o preco do produto" << endl;
        cin >>novo_produto.preco;

        produto.push_back(novo_produto);

        cout << "deseja adicionar outro produto" << endl;
        cin >> resposta;

    }while(resposta == 's');

}


void lista_produtos(vector <Produto> &produto){
cout << "------------LISTA DE PRODUTOS------------" << endl;
    for(Produto p : produto){
        cout << "Nome: " <<p.nome <<
        "\nCodigo: " << p.codigo <<
        "\nPreco: "<< p.preco<< endl;
        cout << "------------------------" << endl;

    }
}

void buscar_produtos(vector <Produto> &produto){
    int codigo;
    cout << "Digite o codigo, para pesquisa de produto." << endl;
    cin >> codigo;

    for(Produto p : produto){
        if(p.codigo == codigo){
            cout << "Nome: " <<p.nome <<
            "\nPreco: "<< p.preco << endl;
            cout << "------------------------" << endl;

        }

    }
}

bool remover_produto(vector <Produto> &produto)
{
    int opcao;
    int codigo;

    cout << "Digite o codigo, para remocao de produto." << endl;
    cin >> codigo;

    for (int i = 0; i < produto.size(); i++){
        if (produto[i].codigo == codigo){
            cout << "======================================\n\n";
            cout << "Deseja realmente remover o produto?\n";
            cout << "1 - Sim\n";
            cout << "2 - Nao\n";
            cout << "OBS: Digite 1 ou 2, caso contrario sera considerado como Nao!\n";
            cin >> opcao;

            if (opcao == 1)
            {
                produto.erase(produto.begin() + i);
                return true;
            }
        }
    }
    return false;
}