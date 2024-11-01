#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

struct Member {
    std::string first_name;
    std::string last_name;
    int age;
};

struct Club {
    std::string name;
    std::string creation_date;
    int max_capacity;
    std::list<Member> members;
};

void CreateClub(std::list<Club>& clubs);
void ListClubs(const std::list<Club>& clubs);
void RegisterMember(std::list<Club>& clubs);
void ListMembers(const Club& club);
void TotalMembers(const Club& club);
void SortClubsByName(std::list<Club>& clubs);
void InsertClubInMiddle(std::list<Club>& clubs);
void InsertMemberInMiddle(std::list<Member>& members);

int main() {
    std::list<Club> clubs;
    int option;

    do {
        std::cout << "\n1. Crear Club" << std::endl;
        std::cout << "2. Listar Clubs" << std::endl;
        std::cout << "3. Registrar Miembro en un Club" << std::endl;
        std::cout << "4. Listar Miembros de un Club" << std::endl;
        std::cout << "5. Total de Miembros en un Club" << std::endl;
        std::cout << "6. Ordenar Clubs por Nombre" << std::endl;
        std::cout << "7. Insertar Club en Medio" << std::endl;
        std::cout << "8. Insertar Miembro en Medio" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
            case 1:
                CreateClub(clubs);
                break;
            case 2:
                ListClubs(clubs);
                break;
            case 3:
                RegisterMember(clubs);
                break;
            case 4: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club& c) { return c.name == club_name; });
                if (it != clubs.end()) {
                    ListMembers(*it);
                } else {
                    std::cout << "Club no encontrado." << std::endl;
                }
                break;
            }
            case 5: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club& c) { return c.name == club_name; });
                if (it != clubs.end()) {
                    TotalMembers(*it);
                } else {
                    std::cout << "Club no encontrado." << std::endl;
                }
                break;
            }
            case 6:
                SortClubsByName(clubs);
                break;
            case 7:
                InsertClubInMiddle(clubs);
                break;
            case 8: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club& c) { return c.name == club_name; });
                if (it != clubs.end()) {
                    InsertMemberInMiddle(it->members);
                } else {
                    std::cout << "Club no encontrado." << std::endl;
                }
                break;
            }
            case 9:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (option != 9);

    return 0;
}

void CreateClub(std::list<Club>& clubs) {
    Club newClub;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> newClub.name;
    std::cout << "Ingrese la fecha de creación: ";
    std::cin >> newClub.creation_date;
    std::cout << "Ingrese la capacidad maxima del club: ";
    std::cin >> newClub.max_capacity;
    clubs.push_back(newClub);
    std::cout << "Club creado exitosamente." << std::endl;
}

void ListClubs(const std::list<Club>& clubs) {
    for (const auto& club : clubs) {
        std::cout << "Nombre: " << club.name << ", Fecha de Creación: " << club.creation_date 
                  << ", Capacidad Maxima: " << club.max_capacity << std::endl;
    }
}

void RegisterMember(std::list<Club>& clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club& c) { return c.name == club_name; });
    if (it != clubs.end()) {
        if (it->members.size() < it->max_capacity) {
            Member newMember;
            std::cout << "Ingrese el nombre del miembro: ";
            std::cin >> newMember.first_name;
            std::cout << "Ingrese el apellido del miembro: ";
            std::cin >> newMember.last_name;
            std::cout << "Ingrese la edad del miembro: ";
            std::cin >> newMember.age;
            it->members.push_back(newMember);
            std::cout << "Miembro registrado exitosamente." << std::endl;
        } else {
            std::cout << "El club ha alcanzado su capacidad maxima." << std::endl;
        }
    } else {
        std::cout << "Club no encontrado." << std::endl;
    }
}

void ListMembers(const Club& club) {
    for (const auto& member : club.members) {
        std::cout << "Nombre: " << member.first_name << ", Apellido: " << member.last_name 
                  << ", Edad: " << member.age << std::endl;
    }
}

void TotalMembers(const Club& club) {
    std::cout << "Total de miembros en el club " << club.name << ": " << club.members.size() << std::endl;
}

void SortClubsByName(std::list<Club>& clubs) {
    clubs.sort([](const Club& a, const Club& b) {
        return a.name < b.name;
    });
    std::cout << "Clubs ordenados por nombre:\n";
    ListClubs(clubs);
}

void InsertClubInMiddle(std::list<Club>& clubs) {
    Club newClub;
    std::cout << "Ingrese el nombre del nuevo club: ";
    std::cin >> newClub.name;
    std::cout << "Ingrese la fecha de creación: ";
    std::cin >> newClub.creation_date;
    std::cout << "Ingrese la capacidad máxima del club: ";
    std::cin >> newClub.max_capacity;

    auto it = clubs.begin();
    std::advance(it, clubs.size() / 2);
    clubs.insert(it, newClub);
    std::cout << "Club insertado en la posición media." << std::endl;
}

void InsertMemberInMiddle(std::list<Member>& members) {
    Member newMember;
    std::cout << "Ingrese el nombre del nuevo miembro: ";
    std::cin >> newMember.first_name;
    std::cout << "Ingrese el apellido del nuevo miembro: ";
    std::cin >> newMember.last_name;
    std::cout << "Ingrese la edad del nuevo miembro: ";
    std::cin >> newMember.age;

    auto it = members.begin();
    std::advance(it, members.size() / 2);
    members.insert(it, newMember);
    std::cout << "Miembro insertado en la posicion media." << std::endl;
}
