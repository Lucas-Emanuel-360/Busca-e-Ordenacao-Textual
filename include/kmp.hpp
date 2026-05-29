#ifndef KMP_HPP
#define KMP_HPP

#include <string>
#include <vector>

void computarLPS(const std::string& padrao, int M, std::vector<int>& lps);
void buscarKMP(const std::string& texto, const std::string& padrao);

#endif