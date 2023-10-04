#include <string>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

struct Passageiro_onibus
{
    string nome, cpf;
    int idade;
};

struct Poltrona
{
    Passageiro_onibus passageiro;
    bool disponivel = true;
};
struct Data_viagem
{
    int dia;
    int mes;
    int ano;
    string hora;
};

struct Viagem
{
    Poltrona poltrona[40];
    Data_viagem data;
    string destino_viagem;      // ida ou volta
    double valor_viagem = 80.0; // valor_viagem = 80 para cada
};

bool pedi_data(Viagem &viagens, string data_string);

void add_viagem(vector<Viagem> &viagens);
string busca_passageiro(vector <Viagem> &viagens);
string total_arrecadado_por_mes(vector <Viagem> &viagens);
string busca_passageiro_poltrona(vector <Viagem> &viagens);
int media_idade(vector <Viagem> &viagens);

int main(){
    vector<Viagem> viagens;
    add_viagem(viagens);
    busca_passageiro(viagens);
    total_arrecadado_por_mes(viagens);
    busca_passageiro_poltrona(viagens);
    cout << media_idade(viagens) <<endl;


    return 0;
}

bool pedi_data(Viagem &viagem, string data_string)
{
    string dia, mes, ano;
    cout << "Digite a data(dd/mm/yyyy)" << endl;
    cin >> data_string;

    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    if (!regex_match(data_string, datePattern))
    {
        return false;
    }
    else
    {

        dia = data_string.substr(0, 2);
        mes = data_string.substr(3, 2);
        ano = data_string.substr(6, 10);

        viagem.data.dia = atol(dia.c_str());
        viagem.data.mes = atoi(mes.c_str());
        viagem.data.ano = atoi(ano.c_str());

        if ((viagem.data.dia >= 1 && viagem.data.dia <= 30) && (viagem.data.mes == 4 || viagem.data.mes == 6 || viagem.data.mes == 9 || viagem.data.mes == 7 || viagem.data.mes == 11))
        {
        }
        else if ((viagem.data.dia >= 1 && viagem.data.dia <= 31) && (viagem.data.mes == 1 || viagem.data.mes == 3 || viagem.data.mes == 5 || viagem.data.mes == 7 || viagem.data.mes == 8 || viagem.data.mes == 10 || viagem.data.mes == 12))
        {
        }
        else if ((viagem.data.dia >= 1 && viagem.data.dia <= 28) && (viagem.data.mes == 2))
        {
        }
        else if (viagem.data.dia >= 29 && viagem.data.mes == 2 && (viagem.data.ano % 400 == 0 || viagem.data.ano % 4 == 0 && viagem.data.ano % 100 != 0))
        {
        }
        else
        {
            return false;
        }
        return true;
    }
}

void add_viagem(vector <Viagem> &viagens){
    int poltrona_numero = 0;
    int j = 0;
    int ida = 0;
    int volta = 0;
    bool salva_poltrona = false;
    char resposta;
    string data_string;

    Viagem nova_viagem;

    cout << "Distino, ida  ou volta da viagem ?" << endl;
    cin >> nova_viagem.destino_viagem;

    if (pedi_data(nova_viagem, data_string)){
        if (nova_viagem.destino_viagem == "ida" && ida <= 5){
            cout << "Para a Volta escolha o horario, 6:00, 7:00, 10:00, 11:00, 12:00, " << endl;
            cin >> nova_viagem.data.hora;
            ida++;
        }else if (nova_viagem.destino_viagem == "volta" && volta <= 5){
            cout << "Para a Volta escolha o horario, 14:00, 15:00, 16:00, 17:00, 18:00, " << endl;
            cin >> nova_viagem.data.hora;
            volta++;
        };

        do{

            cout << "Digite o nome do passageiro:"  << "da viagem " << endl;
            cin >> nova_viagem.poltrona[j].passageiro.nome;

            cout << "Digite o cpf do passageiro;" << "da viagem " << endl;
            cin >> nova_viagem.poltrona[j].passageiro.cpf;

            cout << "Digite a idade do passageiro;" << endl;
            cin >> nova_viagem.poltrona[j].passageiro.idade;

            do{

                cout << "Digite a poltrona (0 -> 39)" << endl;
                cin >> poltrona_numero;

                if (nova_viagem.poltrona[poltrona_numero].disponivel == true)
                {
                    nova_viagem.poltrona[poltrona_numero].disponivel = false;
                    salva_poltrona = true;
                }
                else if (nova_viagem.poltrona[poltrona_numero].disponivel == false)
                {
                    cout << "a poltrona está ocupada, escolha outra diferente de " << poltrona_numero << endl;
                    salva_poltrona = false;
                };
            } while (salva_poltrona == false);

            j++;
            if(j < 40){
                cout << "Deseja Adicionar outro passageiro para a data e horario escolhido (s/n)?" << endl;
                cin >> resposta;
            }else{
                break;
            }
        } while ((resposta == 's' || resposta == 'S'));

        viagens.push_back(nova_viagem);
    } 

}

string busca_passageiro(vector <Viagem> &viagens){
    string nome_passageiro;
    cout << "------------BUSCA PASSAGEIRO------------" << endl;

    cout << "Digite o nome do passageiro, para que realizar a busca" << endl;
    cin >> nome_passageiro;

    for(Viagem v : viagens){
        for(int i=0; i< 40; i ++){
            if(v.poltrona[i].passageiro.nome == nome_passageiro){
                cout << "Nome: " << v.poltrona[i].passageiro.nome <<
                "\nCpf: " << v.poltrona[i].passageiro.cpf <<
                "\nIdade: "<< v.poltrona[i].passageiro.idade <<
                "\nDestino: " << v.destino_viagem<<
                "\nHorario: " << v.data.hora<<
                "\nData: "<< v.data.dia <<"/"<< v.data.mes << "/" << v.data.ano <<endl;
            }
        }
    }
}


string total_arrecadado_por_mes(vector <Viagem> &viagens){
    int cont_=0;
    int mes_escolhido;
    int tamanho =40;

    cout << "Digite o mes da viagem, com 2 digitos:" << endl;
    cin >> mes_escolhido;

    for(Viagem v : viagens){
        for(int i=0; i< tamanho; i ++){
            if(v.data.mes == mes_escolhido && v.poltrona[i].disponivel == false){
               cont_ ++;
            }
        }
    }
    cout << "------------TOTAL DE ARRECADADO------------" << endl;
    cout <<"Mes: "<< mes_escolhido <<
    "\nAno: 2023"
    "\nTotal: R$"<< (cont_*80)<<endl;
};

string busca_passageiro_poltrona(vector<Viagem> &viagens) {
    string nome_passageiro;
    int poltrona, dia, mes, ano;

    cout << "------------BUSCA PASSAGEIRO POLTRONA------------" << endl;

    cout << "Digite o nome do passageiro, para que realizar a busca" << endl;
    cin >> nome_passageiro;

    cout << "Digite o numero da poltrona para realizar a busca do passageiro" << endl;
    cin >> poltrona;

    cout << "Digite o dia, para que realizar a busca" << endl;
    cin >> dia;

    cout << "Digite o mes, para realizar a busca do passageiro" << endl;
    cin >> mes;

    cout << "Digite o ano, para realizar a busca do passageiro" << endl;
    cin >> ano;

    for (Viagem v : viagens) {
        if (v.data.dia == dia && v.data.mes == mes && v.data.ano == ano) {
            for (int i = 0; i < 40; i++) {
                if (!v.poltrona[i].disponivel && v.poltrona[i].passageiro.nome == nome_passageiro) {
                    cout << "Nome: " << v.poltrona[i].passageiro.nome <<
                        "\nCpf: " << v.poltrona[i].passageiro.cpf <<
                        "\nIdade: " << v.poltrona[i].passageiro.idade <<
                        "\nDestino: " << v.destino_viagem <<
                        "\nHorario: " << v.data.hora <<
                        "\nData: " << v.data.dia << "/" << v.data.mes << "/" << v.data.ano << endl;
                    return "Passageiro encontrado!";
                }
            }
        }
    }
    return "Passageiro não encontrado.";
}


int media_idade(vector<Viagem> &viagens) {
    int soma = 0;
    int cont = 0;
    int resultado = 0;

    cout << "------------MEDIA DA IDADE DOS PASSAGEIROS------------" << endl;

    for (Viagem v : viagens) {
        for (int i = 0; i < 40; i++) {
            if (!v.poltrona[i].disponivel) {
                soma += v.poltrona[i].passageiro.idade;
                cont++;
            }
        }
    }
    resultado = soma / cont;
    return resultado;

}