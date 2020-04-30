#include <iostream>
#include <fstream>
#include <string>

class Employee {
private:
    std::string last_name;
    int experience{};
    double hourly_wage{};
    int hours_worked{};

public:
    Employee() = default;
    ~Employee() = default;

    friend std::istream& operator>>(std::istream&, Employee&);
    friend std::ostream& operator<<(std::ostream&, const Employee&);

    void read();
    void print() const;
    void write(const std::string&) const;

    double calculateSalary() const;
    double calculatePremium() const;
};

int main() {
    Employee numberone;
    numberone.read();
    numberone.print();
    numberone.write("output.txt");
    return 0;
}

std::istream& operator>>(std::istream& is, Employee& obj) {
    std::cout << "Enter last name: ";
    std::getline(is, obj.last_name);
    std::cout << '\n' << "Enter worker's experience: ";
    is >> obj.experience;
    std::cout << '\n' << "Enter worker's hourly tag: ";
    is >> obj.hourly_wage;
    std::cout << '\n' << "Enter how much worker had worked: ";
    is >> obj.hours_worked;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Employee& obj) {
    os << "......................." << '\n'
        << "Last Name: " << obj.last_name << '\n'
        << "Experience: " << obj.experience << '\n'
        << "Hourly wag: " << obj.hourly_wage << '\n'
        << "Hours worked: " << obj.hours_worked << '\n'
        << "Salary: " << obj.calculateSalary() << '\n'
        << "Premium: " << obj.calculatePremium();
    return os;
}

void Employee::read() {
    std::cin >> *this;
}

void Employee::print() const {
    std::cout << *this;
}

void Employee::write(const std::string& output_file_name) const {
    std::ofstream outfile("output.txt");
    outfile
        << "Last Name: " << this->last_name << '\n'
        << "Experience: " << this->experience << '\n'
        << "Hourly wage: " << this->hourly_wage << '\n'
        << "Hours worked: " << this->hours_worked << '\n'
        << "Salary: " << this->calculateSalary() << '\n'
        << "Premium: " << this->calculatePremium();
    outfile.close();
    std::cout << '\n' << "=======================" << '\n'
        << " SAVED IN '" << output_file_name << "'" << '\n'
        << "=======================";
}


double Employee::calculateSalary() const {
    return hourly_wage * hours_worked;
}

double Employee::calculatePremium() const {
    if (hours_worked <= 1)
        return 0;
    else if (hours_worked <= 3)
        return calculateSalary() * 0.05;
    else if (hours_worked <= 5)
        return calculateSalary() * 0.08;
    else
        return calculateSalary() * 0.15;
}
