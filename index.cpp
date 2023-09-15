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
    
    vector<Viagem> viagens;

    string total_arrecadado(Viagem viagens){
        double valor_total =0;
        string data_escolhida, hora_escolhida;

        cout << "Digite a data da viagem" << endl;
        cin >> data_escolhida;

        cout << "Digite o horario da viagem" <<endl;
        cin >> hora_escolhida;

        for(int i=0; i< 40; i ++){
            if(viagens.data.dia[i] == data_escolhida && viagens.hora_viagem[i] == hora_escolhida){
                for(int i=0; i< 40; i ++){
                    if(viagens.poltrona[i].disponivel == false){
                        valor_total += viagens.valor_viagem;
                    }; 
                };
            };
        }; 

         cout <<"total: " << valor_total <<endl;

    };

int main(void){

    vector<Viagem> viagens;


    return 0;


}