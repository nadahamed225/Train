#include <iostream>
using namespace std;
#define endl '\n'
struct seat {
    int number;
    bool statue;
};
struct car {
    int id;
    int num_seats;
    seat seats;
};
struct train_element {
    car cars;
};
train_element t[11][31] = { 0 };
///////////////////////////////////////////////////////////
////////////////////////
void menu()
{
    cout << "Enter 1 to Reserve a ticket" << endl;
    cout << "Enter 2 to Cancel a reservation" << endl;
    cout << "Enter 3 to Check whether a specific car has available seat or not!" << endl;
    cout << "Enter 4 to Show avalibe seats in a specific car" << endl;
    cout << "Enter 5 to Check whether a specific seat is available or not!" << endl;
    cout << "Enter 0 to Exit." << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------" << endl;
}
/// ////////////////////////////////////////////////////////
void reserve() {
    int car_id, seat_id;
    cout << "Choose the [Car_id] You want to reserve your seat in from [1] to [10] " << endl;
    cin >> car_id;
    cout << "Choose the [Seat_id] You want to reserve your seat in from [1] to [30] " << endl;
    cin >> seat_id;
    if (car_id >= 1 && car_id <= 10 && seat_id >= 1 && seat_id <= 30) {
        if (t[car_id][seat_id].cars.seats.statue == 1) {
            cout << "Sorry, this seat is already Reserved and Not available :(( " << endl;
        }
        else {
            t[car_id][seat_id].cars.seats.statue = 1;
            cout << "Booking Successful :)) " << endl;
        }
    }
    else {
        cout << "Sorry, Please Try Again :((" << endl;
    }
}
/// ////////////////////////////////////////////////////////
void cancel_reserve() {
    int car_id, seat_id;
    cout << "Choose the [Car_id] You want to Cancel Your reserve seat from [1] to [10] " << endl;
    cin >> car_id;
    cout << "Choose the [seat_id] You want to Cancel Your reserve seat from [1] to [30] " << endl;
    cin >> seat_id;
    if (car_id >= 1 && car_id <= 10 && seat_id >= 1 && seat_id <= 30) {
        if (t[car_id][seat_id].cars.seats.statue == 0) {
            cout << "Sorry, but this seat is Not reserved and available :((" << endl;
        }
        else {
            t[car_id][seat_id].cars.seats.statue = 0;
            cout << "Booking Successful Canceled! :)) " << endl;
        }
    }
    else {
        cout << "Sorry, Please Try Again :((";
    }
}
/// ///////////////////////////////////////////////////////////////////////////////
void Check_specific_car() {
    int car_id;
    cout << "Enter the [car_id] that You want to check if has available seat or not" << endl;
    cin >> car_id;
    bool check = 0;
    if (car_id >= 1 && car_id <= 10) {
        for (int i = 1; i <= 30; i++) {
            if (t[car_id][i].cars.seats.statue == 0) {
                check = 1;
                break;
            }
        }
        if (check) {
            cout << "Congrats, this car have available seat :))" << endl;
        }
        else {
            cout << "Sorry, this car have NOT any available seat :((" << endl;
        }
    }
    else {
        cout << "Invalid car_id, Please Try Again :((" << endl;
    }
}
/// ///////////////////////////////////////////////////////////////////////////////
void Show() {
    int car_id;
    cout << "Enter the [car_id] that You want to show avalibe its seats" << endl;
    cin >> car_id;
    bool check = 1;
    if (car_id >= 1 && car_id <= 10) {
        for (int i = 1; i <= 30; i++) {
            if (t[car_id][i].cars.seats.statue == 0) {
                check = 0;
                cout << "the seat" << " " << i << " " << "of the Car" << " " << car_id << " " << "is be available" << endl;
                cout << "------------------------------------------------------------------------------------------" << endl;
            }
        }
        if (check) {
            cout << "Sorry, this car have NOT any available seat :((" << endl;
        }
    }
    else {
        cout << "Invalid car_id, Please Try Again :((" << endl;
    }


}
/// ///////////////////////////////////////////////////////////////////////////////
void Check_specific_seat() {
    int car_id, seat_id;
    cout << "Enter the [car_id] that you want check a specific seat of it" << endl;
    cin >> car_id;
    cout << "Enter the [seat_id] that you want check it" << endl;
    cin >> seat_id;
    if (car_id >= 1 && car_id <= 10 && seat_id >= 1 && seat_id <= 30) {
        if (t[car_id][seat_id].cars.seats.statue == 1) {
            cout << "Sorry, this seat in not available :((" << endl;
        }
        else
        {
            cout << "congrats, this seat is available and you can reserve it now :))" << endl;
        }
    }
    else {
        cout << "Invalid , Please Try Again :((" << endl;
    }
}

int main()
{
    bool first_time = true;
    while (1) {
        if (first_time) {
            cout << "------------------------- Welcome to Assiut Train Station ---------------------------" << endl;
            first_time = 0;
        }
        menu();
        int choose;
        cin >> choose;
        if (choose == 1)
            reserve();
        else if (choose == 2)
            cancel_reserve();
        else if (choose == 3)
            Check_specific_car();
        else if (choose == 4)
            Show();
        else if (choose == 5)
            Check_specific_seat();
        else {
            cout << "Bye.......Have a good day!" << endl;
            break;
        }
    }
}


