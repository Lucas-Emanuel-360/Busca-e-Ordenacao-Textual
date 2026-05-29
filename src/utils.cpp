#include "../include/utils.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string lerArquivoESanitizar(const string& caminho) {
    ifstream arquivo(caminho);
    
    // Verifica se o arquivo existe na pasta data/
    if (!arquivo.is_open()) {
        cout << "[ERRO] Nao foi possivel abrir o arquivo: " << caminho << "\n";
        cout << "Verifique se ele esta na pasta correta!\n";
        return "";
    }

    string conteudo = "";
    string linha;
    
    // Lê linha por linha
    while (getline(arquivo, linha)) {
        for (int i = 0; i < linha.length(); i++) {
            char c = linha[i];
            
            // Converte maiúsculas para minúsculas usando ASCII (soma 32)
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            
            // Aceita apenas letras minúsculas, números e espaços
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == ' ') {
                conteudo += c;
            } 
            // Transforma pontuações (vírgulas, pontos) em espaço para separar palavras
            else if (c == ',' || c == '.' || c == ';' || c == '!' || c == '?') {
                conteudo += ' ';
            }
        }
        // Adiciona um espaço ao final de cada linha para as palavras não grudarem
        conteudo += " "; 
    }
    
    arquivo.close();
    return conteudo;
}