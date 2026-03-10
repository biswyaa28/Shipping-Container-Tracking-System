// CONTAINER TRACKER v1.0 - RETRO EDITION
// Simple shipping container tracking system

#include <iostream>
#include <string>

using namespace std;

// === GLOBAL PARALLEL ARRAYS ===
string ids[100], types[100], sizes[100], locations[100], statuses[100];
string history[100][10];
int history_count[100] = {0};
int container_count = 0;

// === REGISTER CONTAINER ===
void register_container() {
    string id, type, size, loc, status;
    cout << "\n--- REGISTER CONTAINER ---\n";
    cout << "CONTAINER ID: "; cin >> id;
    
    for (int i = 0; i < container_count; i++) {
        if (ids[i] == id) { cout << "ERROR: ID ALREADY EXISTS\n"; return; }
    }
    
    cout << "TYPE (DRY/REEFER/TANK): "; cin >> type;
    cout << "SIZE (20FT/40FT): "; cin >> size;
    cout << "LOCATION: "; cin >> loc;
    cout << "STATUS (IN TRANSIT/DOCKED/DELIVERED): "; cin >> status;
    
    ids[container_count] = id;
    types[container_count] = type;
    sizes[container_count] = size;
    locations[container_count] = loc;
    statuses[container_count] = status;
    history[container_count][history_count[container_count]++] = "REGISTERED AT " + loc;
    container_count++;
    
    cout << "CONTAINER REGISTERED SUCCESSFULLY!\n";
    cout << "ID: " << id << " | TYPE: " << type << " | SIZE: " << size << "\n";
}

// === UPDATE LOCATION ===
void update_location() {
    string search_id, new_loc;
    cout << "\n--- UPDATE LOCATION ---\n";
    cout << "ENTER CONTAINER ID: "; cin >> search_id;
    
    for (int i = 0; i < container_count; i++) {
        if (ids[i] == search_id) {
            cout << "NEW LOCATION: "; cin >> new_loc;
            locations[i] = new_loc;
            history[i][history_count[i]++] = "MOVED TO " + new_loc;
            cout << "LOCATION UPDATED: " << search_id << " -> " << new_loc << "\n";
            return;
        }
    }
    cout << "ERROR: CONTAINER NOT FOUND\n";
}

// === UPDATE STATUS ===
void update_status() {
    string search_id, new_status;
    cout << "\n--- UPDATE STATUS ---\n";
    cout << "ENTER CONTAINER ID: "; cin >> search_id;
    
    for (int i = 0; i < container_count; i++) {
        if (ids[i] == search_id) {
            cout << "CURRENT STATUS: " << statuses[i] << "\n";
            cout << "NEW STATUS: "; cin >> new_status;
            statuses[i] = new_status;
            history[i][history_count[i]++] = "STATUS: " + new_status;
            cout << "STATUS UPDATED: " << search_id << " -> " << new_status << "\n";
            return;
        }
    }
    cout << "ERROR: CONTAINER NOT FOUND\n";
}

// === VIEW ALL CONTAINERS ===
void view_all() {
    cout << "\n========================================\n";
    cout << "  ID        TYPE      SIZE    LOCATION      STATUS\n";
    cout << "========================================\n";
    
    if (container_count == 0) { cout << "  NO CONTAINERS REGISTERED\n"; }
    
    for (int i = 0; i < container_count; i++) {
        printf("  %-10s%-10s%-8s%-14s%s\n", ids[i].c_str(), types[i].c_str(), 
               sizes[i].c_str(), locations[i].c_str(), statuses[i].c_str());
    }
    cout << "========================================\n";
    cout << "TOTAL: " << container_count << " CONTAINERS\n";
}

// === VIEW HISTORY ===
void view_history() {
    string search_id;
    cout << "\n--- VIEW HISTORY ---\n";
    cout << "ENTER CONTAINER ID: "; cin >> search_id;
    
    for (int i = 0; i < container_count; i++) {
        if (ids[i] == search_id) {
            cout << "HISTORY FOR " << search_id << ":\n";
            if (history_count[i] == 0) { cout << "  NO HISTORY FOUND\n"; return; }
            for (int j = 0; j < history_count[i]; j++)
                cout << "  " << (j + 1) << ". " << history[i][j] << "\n";
            return;
        }
    }
    cout << "ERROR: CONTAINER NOT FOUND\n";
}

// === GENERATE REPORT ===
void generate_report() {
    int transit = 0, docked = 0, delivered = 0, dry = 0, reefer = 0, tank = 0;
    
    for (int i = 0; i < container_count; i++) {
        if (statuses[i] == "IN TRANSIT") transit++;
        else if (statuses[i] == "DOCKED") docked++;
        else if (statuses[i] == "DELIVERED") delivered++;
        
        if (types[i] == "DRY") dry++;
        else if (types[i] == "REEFER") reefer++;
        else if (types[i] == "TANK") tank++;
    }
    
    cout << "\n================ REPORT ================\n";
    cout << "TOTAL CONTAINERS: " << container_count << "\n";
    cout << "----------------------------------------\n";
    cout << "BY STATUS:\n  IN TRANSIT: " << transit;
    cout << "\n  DOCKED: " << docked << "\n  DELIVERED: " << delivered << "\n";
    cout << "----------------------------------------\n";
    cout << "BY TYPE:\n  DRY: " << dry;
    cout << "\n  REEFER: " << reefer << "\n  TANK: " << tank << "\n";
    cout << "========================================\n";
}

// === SHOW MENU ===
void show_menu() {
    cout << "\033[32m";  // GREEN TEXT
    cout << "\n==============================\n";
    cout << "  CONTAINER TRACKER v1.0\n";
    cout << "==============================\n";
    cout << "1. REGISTER CONTAINER\n";
    cout << "2. UPDATE LOCATION\n";
    cout << "3. UPDATE STATUS\n";
    cout << "4. VIEW ALL\n";
    cout << "5. VIEW HISTORY\n";
    cout << "6. GENERATE REPORT\n";
    cout << "7. EXIT\n";
    cout << "==============================\n";
}

// === MAIN FUNCTION ===
int main() {
    int choice;
    
    while (true) {
        show_menu();
        cout << "CHOICE: ";
        cin >> choice;
        
        switch(choice) {
            case 1: register_container(); break;
            case 2: update_location(); break;
            case 3: update_status(); break;
            case 4: view_all(); break;
            case 5: view_history(); break;
            case 6: generate_report(); break;
            case 7: cout << "\nEXITING CONTAINER TRACKER...\n"; return 0;
            default: cout << "INVALID CHOICE!\n";
        }
        
        cout << "\nPRESS ENTER TO CONTINUE...";
        cin.ignore(); cin.get();
    }
}
