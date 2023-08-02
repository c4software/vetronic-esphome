#include <vector>
#include <string>
#include <regex>

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}

int getInteger(const std::string& value) {
    // Définition de la regex pour un entier
    std::regex reg("^[0-9]{1,20}$");

    // Vérification si la chaîne correspond à l'expression régulière pour un entier
    if (std::regex_match(value, reg)) {
        // Conversion de la chaîne en entier et retour de la valeur
        return std::stoi(value);
    } else {
        // Retour de 1 si la chaîne n'est pas un entier
        return 1;
    }
}