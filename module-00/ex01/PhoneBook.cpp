#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string &value) const {
    if (value.length() > 10)
        return (value.substr(0, 9) + ".");
    else
        return (value);
}

PhoneBook::PhoneBook() {
    index = 0;
    count = 0;
}

void PhoneBook::addContact() {
    Contact temp;
    std::string input;
    while (true)
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty\n";
        } else {
            break;
        }
    }
    temp.setFirstName(input);
    while (true)
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty\n";
        } else {
            break;
        }
    }
    temp.setLastName(input);
    while (true)
    {
        std::cout << "Enter Nick Name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty\n";
        } else {
            break;
        }
    }
    temp.setNickName(input);
    while (true)
    {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty\n";
        } else {
            break;
        }
    }
    temp.setPhoneNumber(input);
    while (true)
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty\n";
        } else {
            break;
        }
    }
    temp.setDarkestSecret(input);
    contacts[index % 8] = temp;
    index++;
    if (count < 8) { count++; }
}

void PhoneBook::search() const {
    std::string input;
    int index;

    if (count == 0) {
        std::cout << "PhoneBook empty\n";
        return;
    }
    std::cout << "Index | First Name | Last Name | Nickname\n";
    std::cout << "------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getNickName());
        std::cout << "\n";
    }
    std::cout << "------------------------------------------\n";
    std::cout << "enter index to view the contact: ";
    if (!std::getline(std::cin, input)) {
        std::cout << "\nError: No input\n";
        return;
    }
    index = atoi(input.c_str());
    if (index < 0 || index >= count) {
        std::cout << "Invalid index\n";
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickName() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}
