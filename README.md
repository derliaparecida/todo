# Projeto de Gestão de Tarefas

Este projeto implementa um software de gestão de tarefas com técnica Pomodoro, utilizando C++ e orientação a objetos.

## Funcionalidades principais

- Cadastro e login de usuário
- Cadastro, edição, exclusão e organização de tarefas
- Definição e execução de Pomodoros

## Diagramas

- Acesso aqui [mermaidchart.com](https://www.mermaidchart.com/app/projects/db63fd40-5427-4689-8831-a26a74493861/diagrams/f018b86e-a4e7-4e2f-81bf-9975a67b1085/share/invite/eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJkb2N1bWVudElEIjoiZjAxOGI4NmUtYTRlNy00ZTJmLTgxYmYtOTk3NWE2N2IxMDg1IiwiYWNjZXNzIjoiRWRpdCIsImlhdCI6MTc1ODIxNTcwNn0.NppGDnSck9rLZptqJffmny5NcWXhoUdsOaIOkqBINqM)

```mermaid
classDiagram
direction TB
    class Usuario {
	    - std::string id
	    - std::string nome
	    - std::string senha
	    - std::string email
	    + Usuario(id: std::string, nome: std::string, senha: std::string, email: std::string)
	    + std::string getNome() const
	    + std::string getEmail() const
	    + bool autenticar(senha: string) const
	    + bool salvar(db: Database&)
	    + static bool login(db: Database&, email: string, senha: string)
    }
    class Tarefa {
	    - std::string titulo
	    - std::string grupo
	    - std::string status
	    - int pomodoro
	    - std::string prazo
	    - std::string notas
	    + Tarefa(titulo: std::string)
	    + void setGroup()
	    + void setStatus()
	    + void setPomodoros()
	    + void setPrazo()
	    + void setNotas()
	    + std::string getTitulo()
    }
    class Database {
	    - sqlite3* db
	    - std::string dbName
	    + Database(filename: string)
	    + ~Database()
	    + bool open()
	    + void close()
	    + bool execute(sql: string)
	    + bool executeWithCallback(sql: string, callback, data)
	    + sqlite3* getDB()
    }
    class Pomodoro {
	    - int duracao
	    - int pausaCurta
	    - int pausaLonga
	    + Pomodoro(duracao: int, int: pausaCurta, int: pausaLonga)
	    + int getDuracao()
	    + int getPausaCurta()
	    + int getPausaLonga()
	    + void configurar(int duracao, int pausaCurta, int pausaLonga)
    }
    class Grupo {
	    - std::string nome
	    - std::vector tarefas
	    + Grupo(const std::string& nome)
	    + void adicionarTarefa(string: tarefa)
	    + void removerTarefa(string: tarefa)
	    + std::string getNome()
    }
    class PomodoroTotal {
	    - date data_conclusao
	    - int duracao
    }
    Usuario "1" --> "1" Database : utiliza
    Usuario "1" --> "n" Tarefa : utiliza
    Tarefa "1" --> "1" Pomodoro : contem
    Grupo "1" --> "n" Tarefa : contem
    Tarefa "1" --> "n" PomodoroTotal : contem

	style Usuario stroke:#FBB35A,fill:#FFEFDB,color:#8F632D
	style Database stroke:#FBB35A,fill:#FFEFDB,color:#8F632D

	class Usuario:::Peach
	class Usuario:::Sky
	class Tarefa:::Sky
	class Database:::Peach
	class Database:::Sky
	class Pomodoro:::Sky
	class Grupo:::Sky
	class PomodoroTotal:::Sky

	classDef Sky :,stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
```

## Guia rápido para desenvolvedores

### 1. Preparação do ambiente

- Instalar compilador C++ instalado (ex: g++, etc).
- Instalar extensão "C/C++" da Microsoft.

### 2. Compilação manual

- Criar pasta `build` na raiz do projeto:
- mkdir build
- cd build
- cmake ..
- make
- ./todo

### Compilar e execução usando VSCode

- no menu: "Run and Debug":
- clique em "Run" ou "Start Debugging" e configure os arquivos: `launch.json` e `tasks.json`

### Rodar projeto usando console

-

## Autores

Bruna Oenning Amador, Derli Aparecida Machado

## Conceitos de POO utilizados:

- Herança/Abstração: ITarefaDAO fornece uma interface (contrato) que permite substituir a implementação concreta (mais fácil p/ implementar testes).
- Polimorfismo/Dependency Inversion: TarefaController depende da abstração, isso reduz acoplamento e melhora testabilidade.
- Composição: Tarefa contém um Pomodoro — modelo de uma tarefa “tem um” Pomodoro, permite reutilizar a lógica de Pomodoro e manter limpa a classe Tarefa.
