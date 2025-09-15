#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>

class Usuario {
private:
    std::string nome;
    std::string senha;
public:
    Usuario(const std::string& nome, const std::string& senha);
    std::string getNome() const;
    bool autenticar(const std::string& senha) const;
};

#endif // USUARIO_HPP
