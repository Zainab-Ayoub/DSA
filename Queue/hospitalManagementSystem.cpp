#include <iostream>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrivalOrder;

    Patient(string n, int s, int o) {
        name = n;
        severity = s;
        arrivalOrder = o;
    }
};

class HospitalQueue {
private:
    vector<Patient> queue;
    int arrivalCounter = 0;

public:
    void addPatient(string name, int severity) {
        Patient newPatient(name, severity, arrivalCounter++);
        
        int index = 0;
        while (index < queue.size()) {
            if (severity > queue[index].severity) {
                break;
            } else if (severity == queue[index].severity && newPatient.arrivalOrder < queue[index].arrivalOrder) {
                break;
            }
            index++;
        }
        queue.insert(queue.begin() + index, newPatient);

        cout << "Patient '" << name << "' added with severity " << severity << ".\n";
    }

    void servePatient() {
        if (queue.empty()) {
            cout << "No patients in queue.\n";
            return;
        }
        Patient p = queue.front();
        queue.erase(queue.begin());
        cout << "Serving patient: " << p.name << " (Severity: " << p.severity << ")\n";
    }

    void showQueue() {
        if (queue.empty()) {
            cout << "No patients in the queue.\n";
            return;
        }

        cout << "\n Current Patient Queue:\n";
        for (int i = 0; i < queue.size(); ++i) {
            cout << "- " << queue[i].name << " (Severity: " << queue[i].severity << ")\n";
        }
        cout << endl;
    }
};

int main() {
    HospitalQueue hospital;
    int choice;
    string name;
    int severity;

    while (true) {
        cout << "\n Hospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Serve Next Patient\n";
        cout << "3. Show Patient Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter severity (1-10): ";
                cin >> severity;
                hospital.addPatient(name, severity);
                break;
            case 2:
                hospital.servePatient();
                break;
            case 3:
                hospital.showQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
