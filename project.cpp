#include <iostream>
#include <fstream>

using namespace std;

class clinic{

private:
  int doctor_choice, reception_choice;
	string first_name, last_name, gender, age, id_number, insurance, status, app_time;

public:
  int choice;
  void main_menu();
  void doctor_menu();
  void reception_menu();
  void write_to_file();
  void display_records();
  void get_report();
  void output();
  void view_apps();
};

void clinic::main_menu(){
  cout << "Please make a choice from the options provided below.\n";
  cout << "1-----Doctor\n"
       << "2-----Receptionist\n"
       << "3-----Quit\n";
  cin >> choice;
  system("cls");
}

void clinic:: doctor_menu(){
  cout << "1-----View today's appointments\n"
       << "2-----Go back to main menu\n"
       << "3-----Quit\n";

  cin >> doctor_choice;
  system("cls");
  switch(doctor_choice){
    case 1:
      clinic::view_apps();
      break;
    case 2:
      clinic::main_menu();
      break;
    case 3:
      exit(0);
      break;
  }
}

void clinic::reception_menu() {
  cout << "1-----Edit patient details\n"
       << "2-----Enter new patient details\n"
       << "3-----Generate report\n"
       << "4-----View all records\n"
       << "5-----Go back to main menu\n"
       << "6-----Quit\n";

  cin >> reception_choice;
  system("cls");
  switch(reception_choice) {
    case 1:
      // edit_file();
      break;
    case 2:
      clinic::write_to_file();
      break;
    case 3:
      clinic::get_report();
      break;
    case 4:
      clinic::display_records();
      break;
    case 5:
      clinic::main_menu();
      break;
    case 6:
      exit(0);
      break;

  }
}

void clinic::write_to_file(){
  // Takes input from the keyboard and stores it to the file
  int number;
  ofstream write("clinic records.xls", ios::app);
  cout << "How many records would you like to add? ";
  cin >> number;

 for(int n = 0;n < number;n ++){

  cout << "Enter First Name: ";
	cin >> first_name;

	cout << "Enter Last Name: ";
	cin >> last_name;

	cout << "Enter Gender(M/F): ";
	cin >> gender;

	cout << "Enter Age: ";
	cin >> age;

	cout << "Enter ID Number: ";
	cin >> id_number;

	cout << "Enter Insurance Company: ";
	cin >> insurance;

  cout << "Enter Status: ";
  cin >> status;

  system("cls");
  write << first_name << "\t" << last_name << "\t" << gender << "\t" << age << "\t" << id_number << "\t" << insurance << "\t" << status << endl;
  }
  write.close();
}

void clinic::display_records(){
  // Displays all the user records stored in the file
	ifstream view("clinic records.xls");

  cout << "First Name" << "\t" << "Last Name" << "\t" << "Gender" << "\t" << "Age" << "\t" << "ID Number" << "\t" << "Insurance" << endl;
  while(view >> first_name >> last_name >> gender >> age >> id_number >> insurance){
    cout << first_name << "\t" << last_name << "\t" << gender << "\t" << age << "\t" << id_number << "\t" << insurance;
    cout << endl;
  }
  view.close();
}

void clinic::get_report(){
  // Determines when a patient's appointment is due
  ifstream read("clinic records.xls");
  ofstream output("appointments.xls", ios::app);

  while(read >> first_name >> last_name >> gender >> age >> id_number >> insurance >> status){
    if(status == "routine"){
      app_time = "Today";
      output << first_name << "\t" << last_name << "\t" << gender << "\t" << age << "\t" << id_number << "\t" << insurance << "\t" << app_time << endl;
    }else if(status == "urgent"){
      app_time = "Tomorrow";
    }else{
      cout << "Please confirm status";
    }
  }
  output.close();
  read.close();
}

void clinic::view_apps(){
  ifstream read("appointments.xls");
  cout << "First Name" << "\t" << "Last Name" << "\t" << "Gender" << "\t" << "Age" << "\t" << "ID Number" << "\t" << "Insurance" << "\t" << "Appointment Date" << endl;
  while (read >> first_name >> last_name >> gender >> age >> id_number >> insurance >> app_time){
    cout << first_name << "\t" << last_name << "\t" << gender << "\t" << age << "\t" << id_number << "\t" << insurance << "\t" << app_time;
  }
  read.close();
}

int main(){
  clinic uzima;
  cout << "Welcome.\n\n";

  while(true){
    uzima.main_menu();
    system("cls");
    switch(uzima.choice){
      case 1:
        uzima.doctor_menu();
        break;
      case 2:
        uzima.reception_menu();
        break;
      case 3:
        exit(0);
        break;
      default:
        cout << "Invalid choice. Try again \n";
        break;
    }
  }
  return 0;
}
