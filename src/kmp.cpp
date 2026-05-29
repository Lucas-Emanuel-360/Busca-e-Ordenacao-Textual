#include "../include/kmp.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Função para pré-processar o padrão e montar o array LPS (Longest Proper Prefix which is also Suffix)
void computarLPS(const string& padrao, int M, vector<int>& lps) {
    int len = 0; // Tamanho do maior prefixo que também é sufixo anterior
    lps[0] = 0;  // O primeiro elemento do LPS é sempre 0
    int i = 1;

    // O loop calcula o lps[i] para i de 1 até M-1
    while (i < M) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            // Se houver um erro de match (padrao[i] != padrao[len])
            if (len != 0) {
                // Volta o tamanho analisado sem zerar o 'i' (Essa é a mágica do KMP)
                len = lps[len - 1];
            } else {
                // Se não tem prefixo, lps[i] é 0 e avançamos o 'i'
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Função principal de busca KMP
void buscarKMP(const string& texto, const string& padrao) {
    int N = texto.length();
    int M = padrao.length();

    // Proteção contra buscas vazias
    if (M == 0 || N == 0) {
        cout << "[AVISO] Texto ou palavra buscada estao vazios." << endl;
        return;
    }

    // Cria o array LPS com o tamanho da palavra que estamos buscando
    vector<int> lps(M);
    computarLPS(padrao, M, lps);

    int i = 0; // Índice para percorrer o texto
    int j = 0; // Índice para percorrer o padrão (a palavra)
    int ocorrencias = 0;

    cout << "Buscando a palavra '" << padrao << "'...\n";

    while (i < N) {
        // Se as letras batem, avança os dois índices
        if (padrao[j] == texto[i]) {
            j++;
            i++;
        }

        // Se o índice 'j' chegou no final da palavra, achamos um match!
        if (j == M) {
            cout << "-> Encontrada na posicao (indice): " << i - j << endl;
            ocorrencias++;
            // Usa o LPS para saber onde continuar a busca, em vez de voltar pro inicio
            j = lps[j - 1];
        } 
        // Se houver divergência nas letras após alguns matches
        else if (i < N && padrao[j] != texto[i]) {
            // Não volta o 'i' do texto pra tras! Apenas ajusta o 'j' usando o LPS
            if (j != 0) {
                j = lps[j - 1];
            } else {
                // Se o 'j' é 0, a letra não bate em nada, então avança o texto
                i++;
            }
        }
    }

    if (ocorrencias == 0) {
        cout << "Nenhuma ocorrencia encontrada." << endl;
    } else {
        cout << "\nTotal de ocorrencias: " << ocorrencias << endl;
    }
}