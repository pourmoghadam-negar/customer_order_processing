#include <iostream>
#include <string>
using namespace std;

struct Order {
    string name;
    string item;
    int status;
};

int main() {
    Order orders[10];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n1. Add Order\n2. View Orders\n3. Update Status\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Name: ";
            getline(cin, orders[count].name);
            cout << "Item: ";
            getline(cin, orders[count].item);
            orders[count].status = 1;
            count++;
            cout << "Order added.\n";
        }
        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". " << orders[i].name << " - " << orders[i].item << " (";
                if (orders[i].status == 1) cout << "Processing";
                else if (orders[i].status == 2) cout << "Sent";
                else cout << "Delivered";
                cout << ")\n";
            }       
        }
        else if (choice == 3) {
            int orderNum;
            cout << "Order number: ";
            cin >> orderNum;
            if (orderNum > 0 && orderNum <= count) {
                cout << "Status (1=Processing, 2=Sent, 3=Delivered): ";
                cin >> orders[orderNum - 1].status;
                cout << "Status updated.\n";
            }
        }
        else if (choice == 4) break;
    }

    return 0;
}