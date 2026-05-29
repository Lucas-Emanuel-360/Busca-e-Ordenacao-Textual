#include <iostream>
#include <string>
#include "../include/utils.hpp"

// Aqui incluir os .hpp das tarefas quando forem criando
 #include "../include/kmp.hpp"
// #include "../include/hash.hpp"

using namespace std;

void exibirMenu() {
    cout << "\n=========================================\n";
    cout << "     SISTEMA DE BUSCA E ORDENACAO\n";
    cout << "=========================================\n";
    cout << "1. Buscar ocorrencias de palavra (KMP)\n";
    cout << "2. Buscar palavra com Curinga (*) (KMP)\n";
    cout << "3. Varredura de erros ortograficos (Hash)\n";
    cout << "4. Sugerir correcao de palavra (Levenshtein)\n";
    cout << "5. Sair\n";
    cout << "=========================================\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    int opcao = 0;
    string caminhoTexto = "data/texto_teste.txt";
    string caminhoDicionario = "data/lexico.txt";

    cout << "[SISTEMA] Carregando arquivos...\n";
    
    // 1. Carrega o texto onde a busca (KMP) vai acontecer
    string textoSanitizado = lerArquivoESanitizar(caminhoTexto);
    if(textoSanitizado == "") {
        cout << "[AVISO] Iniciando sem arquivo de texto de teste.\n";
    } else {
        cout << "[SISTEMA] Texto de teste carregado com sucesso!\n";
    }
    
    // 2. Carrega o lexico.txt (O dicionario para a Hash)
    string dicionarioSanitizado = lerArquivoESanitizar(caminhoDicionario);
    if(dicionarioSanitizado == "") {
        cout << "[AVISO] Iniciando sem dicionario. A verificacao ortografica nao vai funcionar.\n";
    } else {
        cout << "[SISTEMA] Dicionario (lexico.txt) carregado com sucesso!\n";
    }

    while (opcao != 5) {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
    cout << "\n[Tarefa 1] Iniciando modulo KMP...\n";
    cout << "Digite a palavra que deseja buscar: ";
    string palavra;
    cin >> palavra;
    
    // Converte a palavra buscada para minúsculo para garantir o match com o texto sanitizado
    for(int i = 0; i < palavra.length(); i++){
        palavra[i] = tolower(palavra[i]);
    }
    
    buscarKMP(textoSanitizado, palavra);
    break;
}
            case 2:
                cout << "\n[Tarefa 2] Iniciando modulo KMP Curinga...\n";
                break;
            case 3:
                cout << "\n[Tarefa 5] Iniciando Tabela Hash...\n";
                // verificarOrtografia(textoSanitizado, dicionarioSanitizado);
                break;
            case 4:
                cout << "\n[Tarefa 6] Iniciando Distancia de Levenshtein...\n";
                break;
            case 5:
                cout << "\nEncerrando o sistema. Ate logo!\n";
                break;
            default:
                cout << "\nOpcao invalida! Tente novamente.\n";
                break;
        }
    }

    return 0;
}