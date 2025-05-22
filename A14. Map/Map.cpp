#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<string, int> mymap;
    mymap populationMap;

    populationMap["Maharashtra"] = 7062589;
    populationMap["Rajasthan"] = 603258;
    populationMap["Karnataka"] = 548978;
    populationMap["Punjab"] = 7498030;
    populationMap["West Bengal"] = 9075635;

    cout << "=========================== Population of States in India =============================\n";
    
    for (auto iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
        cout << iter->first << ": " << iter->second << " million\n";
    }
    
    cout << "\nSize of populationMap: " << populationMap.size() << "\n";

    string state_name;
    cout << "\nEnter the name of a state: ";
    cin >> state_name;

    auto iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        cout << state_name << "'s population is " << iter->second << " million.\n";
    } else {
        cout << "State not found in populationMap.\n";
        cout << "Enter the name of the state to be erased: ";
        cin >> state_name;

        if (populationMap.erase(state_name)) {
            cout << state_name << " has been removed from the map.\n";
        } else {
            cout << state_name << " was not found in the map to erase.\n";
        }
    }

    return 0;
}
