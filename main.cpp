#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int currentMedicineCount = 0;


void addMedicine(string medicineNames[], double medicinePrices[], int medicineQuantities[], int n) {
   
    cin.ignore();

    for (int i = 0; i < n; i++) {
      
        int index = currentMedicineCount;

        cout << "Enter the Name of medicine " << i + 1 << ": ";
        getline(cin, medicineNames[index]);

        cout << "Enter the Price of medicine " << i + 1 << ": ";
        cin >> medicinePrices[index];

        cout << "Enter the Quantities of medicine " << i + 1 << ": ";
        cin >> medicineQuantities[index];

        cin.ignore(); 
        currentMedicineCount++; 
    }
    cout << " Registered successfully!\n";
}


void displayMedicines(string medicineNames[], double medicinePrices[], int medicineQuantities[]) {
    if (currentMedicineCount == 0) {
        cout << " الصيدلية فارغة حالياً!\n";
        return;
    }

   
    for (int i = 0; i < currentMedicineCount; i++) {
        cout << i + 1 << ". Name: " << medicineNames[i] << endl;
        cout << "  Price: " << fixed << setprecision(2) << medicinePrices[i] << " $" << endl;;
        cout << "  Quantity: "<< medicineQuantities[i] << endl;
    }
    cout << "======================================================" << endl;
}


void searchMedicine(string medicineNames[], double medicinePrices[], int medicineQuantities[]) {
    if (currentMedicineCount == 0) {
        cout << "⚠️ الصيدلية فارغة!\n";
        return;
    }

    string name;
    cout << "Enter the name of medicine to search: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < currentMedicineCount; i++) {
        if (medicineNames[i] == name) {
            cout << "the Price of medicine : " << medicinePrices[i] << " $" << endl;
             cout << " Available Quantity: " << medicineQuantities[i] << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << " هذا الدواء غير متوفر في الصيدلية.\n";
    }
}


void sellMedicine(string medicineNames[], double medicinePrices[], int medicineQuantities[]) {
    if (currentMedicineCount == 0) {
        cout << " الصيدلية فارغة، لا يوجد ما يمكن بيعه!\n";
        return;
    }

    string name;
    int quantities;
    cout << "Enter the name of medicine to buy: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < currentMedicineCount; i++) {
        if (medicineNames[i] == name) {
            found = true;
            cout << "Enter the Quantity to buy: ";
            cin >> quantities;

            if (medicineQuantities[i] >= quantities) {
                cout << " Total Price:" << quantities * medicinePrices[i] <<" $" << endl;
                medicineQuantities[i] -= quantities; 
                cout << " Purchase completed successfully!\n";
            }
            else {
                cout << " الكمية المتاحة لا تكفي، المتوفر فقط هو: " << medicineQuantities[i] << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << " هذا الدواء غير متوفر لإتمام عملية البيع.\n";
    }
}

int main() {
    string medicineNames[100];
    double medicinePrices[100];
    int medicineQuantities[100];

    int x = 0; 

    while (x != 5) {
        cout << "\nChoose an Option " << endl;
        cout << "1. Add New Medicine." << endl;
        cout << "2. Display All Medicines." << endl;
        cout << "3. Search for Medicine." << endl;
        cout << "4. Sell Medicine / Update Quantity." << endl;
        cout << "5. Exit." << endl;
        cout << "Your Choice: ";
        cin >> x;

        switch (x) {
        case 1: {
            int n;
            cout << "How many medicines do you want to add now? ";
            cin >> n;
            addMedicine(medicineNames, medicinePrices, medicineQuantities, n);
            break;
        }
        case 2:
            displayMedicines(medicineNames, medicinePrices, medicineQuantities);
            break;
        case 3:
            searchMedicine(medicineNames, medicinePrices, medicineQuantities);
            break;
        case 4:
            sellMedicine(medicineNames, medicinePrices, medicineQuantities);
            break;
        case 5:
            cout << " Exiting program... Thank you!" << endl;
            break;
        default:
            cout << " Invalid Choice! Please choose between 1 and 5." << endl;
        }
    }
    return 0;
}
