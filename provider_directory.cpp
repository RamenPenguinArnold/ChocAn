// This file contains the implementation for the provider_directory ADT

#include "provider_directory.h"

// constructor
provider::provider(void)
{
    address.street = "";
    address.city = "";
    address.state = "";
    address.zip_code = 0;
    name = "";
    id = 0;
}

// destrucutor
provider::~provider(void)
{
}

// Function to display provider status, name, and id
int provider::display(void)
{
    cout << "\n\tname: " << name;
    cout << "\n\tid: " << id;
    return 1;
}

int provider::compare(int to_compare)
{
    return 1;
}

int provider::create_provider(location_info set_adr, string set_name, int set_id)
{
    address.street = set_adr.street;
    address.city = set_adr.city;
    address.state = set_adr.state;
    address.zip_code = set_adr.zip_code;
    name = set_name;
    id = set_id;
    return 1;
}

/*******************/

// constructor
provider_directory::provider_directory(void)
{
}

// destructor
provider_directory::~provider_directory(void) {}

// wrapper function to insert a new provider into the vector of providers
int provider_directory::insert(const provider &to_add)
{
    provider_list.push_back(to_add);
    return 1;
}

// loads a list of providers from a .txt file, delimiter ',' comma
int provider_directory::load(string file_name)
{
    provider a_provider;
    location_info adr;

    char a_name[WORD_SIZE];
    char a_street[WORD_SIZE];
    char a_city[WORD_SIZE];
    char a_state[WORD_SIZE];
    int a_zip_code;
    int a_balance;
    int a_id;

    ifstream file_in;
    file_in.open(file_name);

    if (file_in)
    {
        cout << "File opened\n";

        file_in >> a_id;
        file_in.ignore(100, ',');

        while (file_in && !file_in.eof())
        {
            file_in.get(a_name, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in.get(a_street, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in >> a_zip_code;
            file_in.ignore(100, ',');

            file_in.get(a_city, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in.get(a_state, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            adr.street = a_street;
            adr.city = a_city;
            adr.state = a_state;
            adr.zip_code = a_zip_code;

            a_provider.create_provider(adr, a_name, a_id);
            insert(a_provider);

            file_in >> a_id;
            file_in.ignore(100, ',');
        }
        file_in.close();
    }
    return 1;
}

// iterates through the vector of providers and displays their information
int provider_directory::display(void)
{
    for (size_t i = 0; i < provider_list.size(); ++i)
    {
        provider_list[i].display();
    }
    return 1;
}