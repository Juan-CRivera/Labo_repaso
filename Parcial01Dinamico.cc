#include <algorithm>
#include <iostream>
#include <list>

struct Member {
  std::string first_name;
  std::string last_name;
  int age;
};

struct Club {
  std::string name;
  std::string date;
  int max_capacity;
  std::list<Member> members;
};

void CreateClub(std::list<Club>&);
void ListClubs(const std::list<Club>);
void ListClubsJustName(const std::list<Club>);
void RegisterMember(std::list<Club>&, const std::string&);
void ListMembers(std::list<Club>&, const std::string&);
void TotalMembers(const std::list<Club>);

int main() {
  std::list<Club> clubes;
  int opcion;
  std::string club_selection;
  while (true) {
    std::cout << "    -- Sistema de clubes --  \n";
    std::cout << "1. Agregar un club \n";
    std::cout << "2. Ver clubes \n";
    std::cout << "3. Agregar un miembro a un club \n";
    std::cout << "4. Ver miembros de un club \n";
    std::cout << "5. Ver numero de miembros de clubes \n";
    std::cout << "6. Salir \n";
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        CreateClub(clubes);
        break;
      case 2:
        ListClubs(clubes);
        break;
      case 3:
        ListClubsJustName(clubes);
        std::cout << "\nIngresa el nombre de un club para agregar un miembro: ";
        std::cin >> club_selection;
        RegisterMember(clubes, club_selection);
        break;
      case 4:
        ListClubsJustName(clubes);
        std::cout << "\nIngresa el nombre de un club para ver sus miembros: ";
        std::cin >> club_selection;
        ListMembers(clubes, club_selection);
        break;
      case 5:
        TotalMembers(clubes);
        break;
      case 6:
        return 0;
        break;

      default:
        break;
    }
  }
  return 0;
}

// Funcion para crear clubes
void CreateClub(std::list<Club>& clubes) {
  Club club1;
  std::cout << "Ingresa el nombre del club: ";
  std::cin >> club1.name;
  std::cout << "Ingresa la fecha de fundacion del club DDMMYY: ";
  std::cin >> club1.date;
  std::cout << "Ingresa capacidad maxima de miembros del club: ";
  std::cin >> club1.max_capacity;
  clubes.push_front(club1);
  std::cout << "Club agregado. \n";
}

// Funcion para mostrar clubes en listas
void ListClubs(const std::list<Club> clubes) {
  std::cout << "    -- Listado de clubes --  \n";
  // Muestra los clubs del mas recinte agregado al mas antiguo
  for (const auto& clubes : clubes) {
    std::cout << "Nombre : " << clubes.name << "\n"
              << "fecha de fundacion: " << clubes.date << "\n"
              << "Capacidad maxima de miembros: " << clubes.max_capacity
              << "\n\n";
  }
}

void ListClubsJustName(const std::list<Club> clubes) {
  std::cout << "    -- Listado de clubes --  \n";
  // Muestra los clubs del mas recinte agregado al mas antiguo
  for (const auto& clubes : clubes) {
    std::cout << "Nombre : " << clubes.name << "\n";
  }
}

void RegisterMember(std::list<Club>& clubes, const std::string& name) {
  Member members;
  auto it =
      std::find_if(clubes.begin(), clubes.end(), [&name](const Club& club) {
        return club.name == name;  // este return se usa para saber si el nombre
                                   // del club es igual al que se busca
      });
  if (it != clubes.end()) {
    if (it->members.size() + 1 <= it->max_capacity) {
      std::cout << "Ingrese nombre del miembro: ";
      std::cin >> members.first_name;
      std::cout << "Ingrese el apellido del miembro: ";
      std::cin >> members.last_name;
      std::cout << "Ingrese la edad del miembro: ";
      std::cin >> members.age;
      // agregar un miembro a la lista members del club
      it->members.push_front(members);
      std::cout << "El miembro se ingreso correctamente a " << it->name << "\n";
    } else {
      std::cout << "El club se encuentra lleno \n";
    }
  } else {
    std::cout << "El club con nombre '" << name << "' no se encontró.\n";
  }
}

void ListMembers(std::list<Club>& clubes, const std::string& name) {
  Member members;
  auto it =
      std::find_if(clubes.begin(), clubes.end(), [&name](const Club& club) {
        return club.name == name;  // este return se usa para saber si el nombre
                                   // del club es igual al que se busca
      });
  if (it != clubes.end()) {
    std::list<Member> members;
    members = it->members;
    std::cout << "    -- Listado de miembros del club --  \n";
    for (const auto& members : members) {
      std::cout << "Nombre : " << members.first_name << "\n"
                << "Apellido: " << members.last_name << "\n"
                << "Edad: " << members.age << "\n\n";
    }
  } else {
    std::cout << "El club con nombre '" << name << "' no se encontró.\n";
  }
}

void TotalMembers(const std::list<Club> clubes) {
  std::cout << "    -- Numero de miembros por club --  \n";
  for (const auto& clubes : clubes) {
    std::cout << "Nombre : " << clubes.name << "--------- "
              << clubes.members.size() << " miembros \n";
  }
}