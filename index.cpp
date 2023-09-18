#include <string>
#include <iostream>
#include <vector>

using namespace std;

    struct Passageiro_onibus
    {
        string nome, cpf, idade;

    };

    struct Poltrona
    {
        Passageiro_onibus passageiro;
        bool disponivel = true;
    };
    struct Data_viagem {
        string dia, mes, ano, hora;

    };

    struct Viagem
    {
        Poltrona poltrona[40]; 
        Data_viagem data;
        string destino_viagem; // ida ou volta
        bool tipo_viagem;
        double valor_viagem = 80.0; // valor_viagem = 80 para cada
    };

    int Menu()
        {
            cout << "========================================\n";
            cout << "1 - Adicionar Viagem\n";
            cout << "2 - Total arrecadado\n";
            cout << "3 - Total arrecadado por mês \n";
            cout << "4 - Buscar passageiro\n";
            cout << "0 - Sair\n";

            int opcao;
            wcout << L"\nEscolha uma opção: ";
            cin >> opcao;

            return opcao;
        };
   

    void add_viagem(Viagem nova_viagem [], int cont_passagens){
        int poltrona_numero = 0;
        int tamanho = 2;
        bool salva_poltrona = false;
        
        for(int i=0; i<tamanho; i++) {  
  
            cout << "Distino, ida  ou volta da viagem ?"<< i << endl;
            cin >> nova_viagem[i].destino_viagem;

            cout << "Digite a dia" <<endl;
            cin >> nova_viagem[i].data.dia;

            cout << "Digite mês;" <<endl;
            cin >> nova_viagem[i].data.mes;

            if(nova_viagem[i].destino_viagem == "ida"){
                cout << "Para a Ida escolha o horario, 6:00, 7:00, 8:00, 9:00, 11:00, " <<endl;
                cin >> nova_viagem[i].data.hora;
            }else if(nova_viagem[i].destino_viagem == "volta"){
                cout << "para a Volta escolha o horario, 14:00, 15:00, 16:00, 17:00, 18:00, " <<endl;
                cin >>nova_viagem[i].data.hora;
            };

            for(int j = 0; j <= tamanho; j++){
                cout << "Digite o nome do passageiro:" << j <<"da viagem "<< i <<endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.nome;

                cout << "Digite o cpf do passageiro;"  << j <<"da viagem "<< i << endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.cpf;

                cout << "Digite a idade do passageiro;" <<endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.cpf;

                do{
                    cout << "Digite a poltrona (1 -> 40)" <<endl;
                    cin >> poltrona_numero;

                    if(nova_viagem[i].poltrona[poltrona_numero].disponivel == true){
                        nova_viagem[i].poltrona[poltrona_numero].disponivel = false;
                        cont_passagens ++;
                        salva_poltrona = true;

                    }else if(nova_viagem[i].poltrona[poltrona_numero].disponivel == false){
                            cout << "a poltrona está ocupada, escolha outra diferente de "<< poltrona_numero <<endl;
                            salva_poltrona = false;
                    };

                }while (salva_poltrona == false);
        
            };


        }; 

    };

    string total_arrecadado(Viagem nova_viagem [], int cont_passagens){
        int valor_total=0;  

        valor_total  = cont_passagens * 80;
        cout << "======================================" <<endl;
        cout << "Total arrecadado" <<endl;

        cout <<"Total de passagens: "<< valor_total << endl; 
    };


    string total_arrecadado_por_mes(Viagem nova_viagem []){
        int cont_=0;
        string mes_escolhido;

        cout << "Digite o mes da viagem" << endl;
        cin >> mes_escolhido;

        for(int i=0; i< 10; i++){
            for(int j=0; j< 40; j++){
                if(nova_viagem [i].data.mes == mes_escolhido && nova_viagem[i].poltrona[j].disponivel == false){
                        cont_ ++;
                };
            };
        };

        cout <<"Total de passagens \n"
        "Mês: "<< mes_escolhido <<
        "\nAno: 2023"
        "\nTotal: "<< cont_*80 <<endl;
    };



    string busca_passageiro(Viagem nova_viagem[]){
        string nome_passageiro;

        cout << "Digite o nome do passageiro" << endl;
        cin >> nome_passageiro;

        for(int i=0; i< 10; i ++){
            for(int j=0; j< 40; j ++){
                if(nova_viagem[i].poltrona[j].passageiro.nome == nome_passageiro){
                    cout << "Nome: " << nova_viagem[i].poltrona[j].passageiro.nome <<
                    "\n Cpf: " << nova_viagem[i].poltrona[j].passageiro.cpf <<
                    "\n Idade: "<< nova_viagem[i].poltrona[j].passageiro.idade <<
                    "\n Destino: " << nova_viagem[i].destino_viagem<<
                    "\n Data: "<< nova_viagem[i].data.dia <<"/"<< nova_viagem[i].data.mes << "/" << nova_viagem[i].data.ano <<endl;
                };
            };     
        };

    };


int main(void){

    Viagem viagens[2];
    int cont_passagens =0;

    add_viagem(viagens, cont_passagens);

    total_arrecadado(viagens);

    total_arrecadado_por_mes(viagens);

    busca_passageiro(viagens);
 
        
    return 0;


}