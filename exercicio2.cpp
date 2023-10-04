#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Empregado{
    string nome;
    string sobrenome;
    string ano_nascimento;
    string RG;
    string ano_adimissao;
    float salario;
};

void add_empregado( vector <Empregado> &empregado, int tamanho);
void lista_empregado( vector <Empregado> &empregado);
void reajusta_Dez_porcento( vector <Empregado> &empregado);

int main(){
    int tamanho = 50;
    vector <Empregado> empregado;

    add_empregado(empregado, tamanho);
    lista_empregado(empregado);
    reajusta_Dez_porcento(empregado);
    lista_empregado(empregado);

    return 0;
}

void add_empregado( vector <Empregado> &empregado, int tamanho){
    
    Empregado novo_empregado;
    char resposta;
    int i = 0;

    do {

        cout << "Digite o nome do funcionario " << endl;
        cin >> novo_empregado.nome;

        cout << "Digite o sobrenome do funcionario " << endl;
        cin >> novo_empregado.sobrenome;

        cout << "Digite o ano de nascimento do funcionario" << endl;
        cin >> novo_empregado.ano_nascimento;

        cout << "Digite o RG do funcionario" << endl;
        cin >> novo_empregado.RG;

        cout << "Digite o ano de admissão do funcionario" << endl;
        cin >> novo_empregado.ano_adimissao;

        cout << "Digite o salario do funcionario" << endl;
        cin >> novo_empregado.salario;

        if( i < tamanho){
            cout << "Deseja Adicionar outro funcionario (s/n)?" << endl;
            cin >> resposta;
        }else{
            cout << "A lista de empregados está cheia" << endl;
            break;
        }
        empregado.push_back(novo_empregado);
        i++;
    }while(resposta == 's');

}


void lista_empregado( vector <Empregado> &empregado){
cout << "------------LISTA DE EMPREGADOS------------" << endl;
    for(Empregado empregado : empregado){
        cout << "Nome: " <<empregado.nome <<
        "\nSobrenome: " << empregado.sobrenome <<
        "\nData de Nascimento: "<< empregado.ano_nascimento <<
        "\nRG: " << empregado.RG<<
        "\nAno de admissão: " << empregado.ano_adimissao<<
        "\nSalario: "<< empregado.salario <<endl;
        cout << "------------------------" << endl;

    }
}


void reajusta_Dez_porcento(vector <Empregado> &empregado){
    int tamanho = empregado.size();

    for(int i=0; i< tamanho; i ++){
        empregado[i].salario = empregado[i].salario + (0.10 * empregado[i].salario);
    }
    cout << "Reajuste de salario realizado com sucesso!!!" << endl;

}