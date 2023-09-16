#include <string>
#include <iostream>
#include <vector>

using namespace std;

    struct Passageiro_onibus
    {
        // string id_passagem;
        string name, cpf, idade;

    };

    struct Poltrona
    {
        Passageiro_onibus passageiro;
        string numero_poltrona;
        bool disponivel = true;
    };
    struct Data_viagem {
        int dia, mes, ano;
        string hora;
    };

    struct Viagem
    {
        Poltrona poltrona[40]; 
        Data_viagem data;
        string destino_viagem; // ida ou volta
        bool tipo_viagem;
        double valor_viagem = 80.0; // valor_viagem = 80 para cada
    };


    string total_arrecadado(vector <Viagem> viagens){
        double valor_total =0;
        int dia_escolhido, mes_escolhido, ano_escolhido;
        string horario_escolhido;

        cout << "Digite o horario da viagem" <<endl;
        cin >> horario_escolhido;

        cout << "Digite a dia da viagem" << endl;
        cin >> dia_escolhido;

        cout << "Digite o mes da viagem" << endl;
        cin >> mes_escolhido;

        cout << "Digite o ano da viagem" <<endl;
        cin >> ano_escolhido;


        for(int i=0; i< 40; i ++){
            if(viagens[i].data.dia == dia_escolhido && viagens[i].data.mes == mes_escolhido && viagens[i].data.ano == ano_escolhido && viagens[i].data.hora == horario_escolhido){
                for(int i=0; i< 40; i ++){
                    if(viagens[i].poltrona[i].disponivel == false){
                        valor_total += viagens[i].valor_viagem;
                    }; 
                };
            };
        }; 
         cout <<"total: " << valor_total <<endl;
    };


    string total_arrecadado_por_mes(vector <Viagem> viagens){
        double valor_total =0;
        int mes_escolhido;

        cout << "Digite o mes da viagem" << endl;
        cin >> mes_escolhido;

        for(int i=0; i< 40; i ++){
            if(viagens[i].data.mes == mes_escolhido){
                for(int i=0; i< 40; i ++){
                    if(viagens[i].poltrona[i].disponivel == false){
                        valor_total += viagens[i].valor_viagem;
                    }; 
                };
            };
        }; 
         cout <<"total do mês: " << valor_total <<endl;
    };



    string busca_passageiro(vector <Viagem> viagens){
        double valor_total =0;
        string nome_passageiro;

        cout << "Digite o nome do passageiro" << endl;
        cin >> nome_passageiro;

        for(int i=0; i< 40; i ++){
            if(viagens[i].poltrona[i].passageiro.name == nome_passageiro){
                cout << "Nome: " << viagens[i].poltrona[i].passageiro.name <<
                "\n Cpf: " << viagens[i].poltrona[i].passageiro.cpf <<
                "\n Idade: "<< viagens[i].poltrona[i].passageiro.idade <<
                "\n Destino: " << viagens[i].destino_viagem<<
                "\n Data: "<< viagens[i].data.dia <<"/"<< viagens[i].data.mes << "/" << viagens[i].data.ano <<endl;
            }; 
        };

    };


int main(void){

    vector<Viagem> viagens;


    return 0;


}