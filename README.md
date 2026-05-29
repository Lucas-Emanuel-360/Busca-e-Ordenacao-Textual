# 🔍 Busca e Ordenação Textual

Projeto prático desenvolvido para a disciplina de **Busca e Ordenação** do curso de Ciência da Computação do Instituto Federal do Norte de Minas Gerais (IFNMG) - Campus Montes Claros. 

Orientação: Prof. Tadeu Zubaran.

Alunos : Estevão Ribeiro Santos & Lucas Emanuel Rodrigues Silva Maia

## 🎯 Sobre o Projeto

Este repositório contém implementações de algoritmos clássicos de busca e ordenação aplicados à manipulação e análise de textos. O objetivo principal é resolver desafios reais de processamento de strings garantindo eficiência computacional.

## 🚀 Funcionalidades Implementadas

A arquitetura do projeto foi desenhada de forma modular, atacando os seguintes desafios propostos:

* **1. Busca Exata (Algoritmo KMP):** Permite encontrar todas as ocorrências de uma palavra específica dentro de um texto, retornando suas posições exatas. (Tarefa Obrigatória).
* **2. Busca com Curinga (KMP Adaptado):** Suporte ao caractere curinga `*`, permitindo buscar padrões onde o curinga substitui qualquer caractere no texto.
* **3. Verificação Ortográfica (Tabela Hash):** Algoritmo que cruza as palavras do texto com um dicionário carregado em memória para apontar termos incorretos ou inexistentes.
* **4. Sugestão de Correção (Distância de Levenshtein):** Para cada erro ortográfico encontrado, o sistema calcula a distância de edição e sugere as palavras válidas mais próximas.
* **5. Nuvem de Palavras e Frequência (QuickSort):** Contagem de frequência das palavras em um conjunto de textos, utilizando ordenação para elencar os termos mais recorrentes.

## 📂 Estrutura do Repositório

```text
BUSCA-E-ORDENACAO-TEXTUAL/
├── bin/                # Executável final gerado após compilação
├── data/               # Arquivos de texto e dicionários de referência
├── docs/               # Documentação e edital do projeto
├── include/            # Arquivos de cabeçalho (.hpp)
│   ├── hash.hpp
│   ├── kmp.hpp
│   └── levenshtein.hpp
├── src/                # Código-fonte principal (.cpp)
│   ├── hash.cpp
│   ├── kmp.cpp
│   ├── levenshtein.cpp
│   ├── main.cpp
│   └── utils.cpp
└── README.md