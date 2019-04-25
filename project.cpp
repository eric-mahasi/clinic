#include <iostream>
#include <fstream>

using namespace std;

class clinic{

private:
  // Used to determine which option is chosen from a list of menu items.
  int doctor_choice, reception_choice;
	string first_name, last_name, gender, age, id_number, insurance, status,
  app_date;
  // app_date is short for appointment date

public:
  int choice;
  void main_menu();
  void doctor_menu();
  void reception_menu();
  void write_to_file();
  void display_records();
  void get_report();
  void view_apps();
  void edit_file();
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
  // Stores the patient details to the file.
  int number;
  ofstream ofile("clinic records.xls", ios::app);

  cout << "Enter First Name: ";
  cin >> first_name;
  first_name[0] = toupper(first_name[0]);

  cout << "Enter Last Name: ";
  cin >> last_name;
  last_name[0] = toupper(last_name[0]);

  cout << "Enter Gender(M/F): ";
  cin >> gender;
  gender[0] = toupper(gender[0]);

  cout << "Enter Age: ";
  cin >> age;

  cout << "Enter ID Number: ";
  cin >> id_number;

  cout << "Enter Insurance Company: ";
  cin >> insurance;
  insurance[0] = toupper(insurance[0]);

  cout << "Enter Status(Routine/Urgent): ";
  cin >> status;
  status[0] = toupper(status[0]);

  system("cls");
  ofile << first_name << "\t" << last_name << "\t" << gender << "\t" << age <<
  "\t" << id_number << "\t" << insurance << "\t" << status << endl;

 ofile.close();
}

void clinic::display_records(){
  // Displays all the patient details stored in the file.
  ifstream ifile("clinic records.xls");
  string title = "First Name\tLast Name \t\tGender \t\tAge  \t\tID Number"
  "\t\tInsurance \t\tStatus \n";

  cout << title;
  while(ifile >> first_name >> last_name >> gender >> age >> id_number >> insurance >> status){
    cout << first_name << "\t\t" << last_name << "\t\t\t" << gender << "\t\t"
    << age << "\t\t" << id_number << "\t\t\t" << insurance << "\t\t\t" <<
    status;
    cout << endl;
  }
  ifile.close();
}

void clinic::get_report(){
  // Determines when a patient's appointment is due depending on their status.
  ifstream ifile("clinic records.xls");
  ofstream ofile("appointments.xls", ios::app);

  while(ifile >> first_name >> last_name >> gender >> age >> id_number >> insurance >> status){
    if(status == "Urgent"){
      app_date = "Today";
      ofile << first_name << "\t" << last_name << "\t" << gender << "\t" << age
       << "\t" << id_number << "\t" << insurance << "\t" << app_date << endl;
    }else if(status == "Routine"){
      app_date = "Tomorrow";
    }else{
      cout << "Please confirm status";
    }
  }
  ifile.close();
  ofile.close();
}

void clinic::view_apps(){
  // Displays the due appointments.
  ifstream ifile("appointments.xls");
  string title = "First Name\tLast Name \t\tGender \t\tAge  \t\tID Number"
  "\t\tInsurance \t\tAppointment Date\n";

  cout << title;
  while (ifile >> first_name >> last_name >> gender >> age >> id_number >> insurance >> app_date){
    cout << first_name << "\t\t" << last_name << "\t\t\t" << gender << "\t\t" <<
     age << "\t\t" << id_number << "\t\t\t" << insurance << "\t\t\t" << app_date
      << endl;
  }
  ifile.close();
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
