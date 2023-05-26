#include<bits/stdc++.h>
#include<windows.h>
using namespace std;


class information{
    public:
    char NID[15];
    char fName[30];
    char lName [30];
    char address[50];
    char phone_no[15];
    char email[50] ;
    char blood_group[5]; 
}C;

//----------------------------Login & Registration---------------------------------------------
void login();
void registerUser();
void regAndLogin() ;
void loginAsAdmin() ;
void loginAsUser() ; 

//----------------------------console Management Functions--------------------------------------
void SetColor(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground();
void gotoxy(int x, int y);
void boxBorder();
void window();
void print_heading(const char title[]);
void clearWindow();



//----------------------------Main Window Functions--------------------------------------------
void main_window();
void UserMainWindow() ;
void add_info();
void find_info();
void display();
void edit_info();
void delete_info();
//----------------------------Main Function-----------------------------------------------------
int main(){
    ClearConsoleToColors(0,1023) ;
    window();
    regAndLogin() ;
    return 0 ; 


}
void regAndLogin(){

    int choice;
    SetColor(10);
    gotoxy(1,7 );
    cout<<"________________________Main Menu______________________\n" ;
    gotoxy(1,8 );
    cout<<"1. Login As Editor"<<endl;
    gotoxy(1,9 );
    cout<<"2.Login as Public User"<<endl;
    gotoxy(1,10 );
    cout<<"3. Register(Applicable for public User only)"<<endl;
    gotoxy(1,11 );
    cout<<"4. Exit"<<endl;
    gotoxy(1,13 );
    SetColor(1024);
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            system("cls");
            window(); 
            loginAsAdmin();
            break;
        case 2:
            system("cls");
            window();
            loginAsUser();
            break;
        case 3:
            system("cls");
            window();
            registerUser();
            gotoxy(1,12);
            cout<<"Thank you for Registering"<<endl;
            regAndLogin(); 
            break;
        case 4:
            cout<<"Thank You"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            system("cls");
            window(); 
            gotoxy(1,12);
            regAndLogin();
    }
}
void loginAsAdmin(){

    SetColor(10);
    gotoxy(25,7 );
    cout<<"Editor Login Page\n" ;
    gotoxy(15,8 );
    cout<<"This is the login page for the editor"<<endl;
    gotoxy(15,9 );
    cout<<"This Page is password Protected"<<endl;
    gotoxy(15,10 );
    cout<<"Enter Valid administrator Password to Enter"<<endl;
    
    int count  ;
    string username,password,id , pass;
    SetColor(17);
    gotoxy(20,15);
    cout<<"USERNAME: ";
    cin>>username;
    gotoxy(20,16);
    cout<<"PASSWORD: ";
    cin>>password;
    ifstream input("AdminsDataBase.txt");
    while(input>>id>>pass){
        if(id==username && pass==password){
            count=1;
        }
    }
    input.close();
    if(count==1){
        cout<<"Hello "<<username<<"\n";
        cout<<"Login Successful\n";
        system("cls");
        window() ;
        main_window(); 
    }
    else{
        system("cls");
        window();
        gotoxy(15,11) ;
        cout<<"Login Failed\n";
        gotoxy(15,12) ;
        cout<<"Please Try Again\n"; 
        loginAsAdmin();
    }
}


void loginAsUser(){

    SetColor(10);
    gotoxy(25,7 );
    cout<<"Public User Login Page\n" ;
    gotoxy(15,8 );
    cout<<"This is the login page for Public User"<<endl;
    gotoxy(15,9 );
    cout<<"This Page is  Protected"<<endl;
    gotoxy(15,10 );
    cout<<"Enter Valid NID Serial No to Enter"<<endl;
    
    int count  ;
    string username,password,id , pass;
    SetColor(17);
    gotoxy(20,15);
    cout<<"Your NAME: ";
    cin>>username;
    gotoxy(20,16);
    cout<<"YOUR NID: ";
    cin>>password;
    ifstream input("UserDataBase.txt");
    while(input>>id>>pass){
        if(id==username && pass==password){
            count=1;
        }
    }
    input.close();
    if(count==1){
        cout<<"Hello "<<username<<"\n";
        cout<<"Login Successful\n";
        system("cls");
        window() ;
        UserMainWindow(); 
    }
    else{
        system("cls");
        window();
        gotoxy(15,11) ;
        cout<<"Login Failed\n";
        gotoxy(15,12) ;
        cout<<"Please Try Again\n"; 
        loginAsUser();
    }
}
void registerUser(){
    SetColor(10);
    gotoxy(25,7 );
    cout<<"Public User Registration Page\n" ;
    gotoxy(15,8 );
    cout<<"This is the Registration page for Public User"<<endl;
    gotoxy(15,9 );
    cout<<"Enter name & Valid NID Serial No"<<endl;
    
    int count  ;
    string username,NID,id , pass;
    SetColor(17);
    gotoxy(20,15);
    cout<<"Your NAME: ";
    cin>>username;
    gotoxy(20,16);
    cout<<"YOUR NID: ";
    cin>>NID;
    ofstream reg("UserDataBase.txt",ios::app);
    reg<<username<<' '<<NID<<endl;
    reg.close();
    cout<<"Registration Sucessful.Now add Your information\n";
    system("cls");
    window();
    regAndLogin();
}

void main_window(){
    SetColor(28);
    int choice;
    int x = 2;
    while(1){
        gotoxy(x,8);
            cout << "1. Add Information";
        gotoxy(x,10);
            cout << "2. Find Information";
        gotoxy(x,12);
            cout << "3. Display Information";
        gotoxy(x,14);
            cout << "4. Edit Information";
        gotoxy(x,16);
            cout << "5. Delete Information";
        gotoxy(x,18);
            cout << "6. Sign Out";
        gotoxy(x,20);
            cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add_info();
                break;
            case 2:
                find_info();
                break;
            case 3:
                display();
                break;
            case 4:
                edit_info();
                break;
            case 5:
                delete_info();
                break;
            case 6:
                clearWindow();
                system("cls");
                window();
                regAndLogin();
                break;
            default:
                break;
        }
    }
}
void UserMainWindow(){
    SetColor(28);
    int choice;
    int x = 2;
    while(1){
        gotoxy(x,8);
            cout << "1. Add Information";
        gotoxy(x,10);
            cout << "2. Find Information";
        gotoxy(x,12);
            cout << "3. Display Information";
        gotoxy(x,14);
            cout << "4. Edit Information";
        gotoxy(x,18);
            cout << "5. Sign Out";
        gotoxy(x,20);
            cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add_info();
                break;
            case 2:
                find_info();
                break;
            case 3:
                display();
                break;
            case 4:
                edit_info();
                break;
            case 5:
                clearWindow();
                system("cls");
                window();
                regAndLogin();
                break;
            default:
                break;
        }
    }
}
//----------------------menu------------------------
void add_info(){
    
    clearWindow();
    SetColor(10);
    print_heading(" -- Add Information -- ");
    int print = 37;
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "Correct NID: ";
        fflush(stdin);
        gets(n_id);
    FILE *data;
    data = fopen("publicInfo.txt","a+");
    if(strlen(n_id) <= 8){
        gotoxy(37,12);
            cout << "ID must be greater than 8 characters";
    }
    else{
        while(fread(&C,sizeof(C),1,data) == 1){
            if(strcmp(n_id,C.NID) == 0){
                isFound = 1;
                gotoxy(37,12);
                    cout << "Information already exist.";
                break;
            }
        }
        if(isFound == 0){
            if(data == NULL){
                gotoxy(37,12);
                    cout << "Unable to Open File.";

            }
            else{
                fflush(stdin);
                    strcpy(C.NID,n_id);
                gotoxy(print,12);
                    cout << "First Name: ";
                    gets(C.fName);
                gotoxy(print,14);
                    cout << "Last Name: ";
                    gets(C.lName);
                gotoxy(print,16);
                    cout << "Address: ";
                    gets(C.address);
                gotoxy(print,18);
                    cout << "Phone Number: ";
                    gets(C.phone_no);
                gotoxy(print,20);
                    cout << "Email: ";
                    gets(C.email);
                gotoxy(print,22);
                    cout << "Blood Group: ";
                    gets(C.blood_group);
                fwrite(&C,sizeof(C),1,data);
                gotoxy(40,20);
                    cout << "Information is added successfully.";
            }
        }
    }
    SetColor(28);
    fclose(data);
    return;
}


void find_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Find Information -- ");
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "Enter NID: ";
        fflush(stdin);
        gets(n_id);
    FILE *data;
    data = fopen("publicInfo.txt","r");
    while(fread(&C,sizeof(C),1,data) == 1){
        if(strcmp(n_id,C.NID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);
            cout << "The Information is Found.";
        gotoxy(37,14);
            cout << "NID: " << C.NID;
        gotoxy(37,15);
            cout << "Name: " << C.fName << " " << C.lName;
        gotoxy(37,16);
            cout << "Address: " << C.address;
        gotoxy(37,17);
            cout << "Phone Number: " << C.phone_no;
        gotoxy(37,18);
            cout << "Email: " << C.email;
        gotoxy(37,19);
            cout << "Blood Group: " << C.blood_group;

    }
    else{
        gotoxy(37,12);
            cout << "Sorry,We don't have any information.";
    }
    SetColor(28);
    fclose(data);
    return;
}


void display(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Display Information -- ");
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "Enter NID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("info.txt","r");
    while(fread(&C,sizeof(C),1,data) == 1){
        if(strcmp(n_id,C.NID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);
            cout << "Information is Found.";
        gotoxy(37,14);
            cout << "NID: " << C.NID;
        gotoxy(37,15);
            cout << "Name: " << C.fName << " " << C.lName;
        gotoxy(37,16);
            cout << "Address: " << C.address;
        gotoxy(37,19);
            cout << "Phone No: " << C.phone_no;
    }else{
        gotoxy(37,12);
            cout << "Sorry,We don't have any information.";
    }
    SetColor(28);
    fclose(data);
    return;
}


void edit_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Edit Information -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
        cout << "Enter NID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("publicInfo.txt","r+");
    while(fread(&C, sizeof(C),1,data) == 1){
        if(strcmp(n_id, C.NID) == 0){
            fflush(stdin);
            gotoxy(print,12);
                cout << "NID: ";
                gets(C.NID);
            gotoxy(print,13);
                cout << "First Name: ";
                gets(C.fName);
            gotoxy(print,14);
                cout << "Name: ";
                gets(C.lName);
            gotoxy(print,15);
                cout << "Address: ";
                gets(C.address);
            gotoxy(print,16);
                cout << "Phone Number: ";
                gets(C.phone_no);
            fseek(data,-sizeof(C), SEEK_CUR);
            fwrite(&C,sizeof(C), 1, data);
            gotoxy(40,20);
                cout << "Information is updated successfully.";
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);
            cout << "Sorry, We don't have any information about U.";
    }
    fclose(data);
    SetColor(28);
    return;
}


void delete_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Delete Information -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
        cout << "Enter NID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data, *backup;
    data = fopen("publicInfo.txt","r");
    backup = fopen("temp.txt", "w");
    while(fread(&C, sizeof(C),1,data) == 1){
        if(strcmp(n_id, C.NID) == 0){
            fwrite(&C,sizeof(C),1,backup);
        }
    }
    fclose(data);
    fclose(backup);
    rename("info.txt","backup.txt");
    remove("temp.txt");
    gotoxy(37,12);
        cout << "Information is deleted successfully.";
    SetColor(28);
    return;
}



/*------- Clear Console Color Function (Source: Google) -------*/
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void ClearConsoleToColors(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


/*------- Console Coordinate Function -------*/
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/*------- Title -------*/
void window(){


    boxBorder();
    SetColor(12);
    gotoxy(10,1);
        cout << "People's Information Management System of Bangladesh(PIMS)";
    SetColor(10);
    gotoxy(1,2);
        cout << "==========================================================================";
    SetColor(1024);
    gotoxy(1,3);
        cout << "A secure System to manage, access and edit public data to assist\n" ;
        cout<<"Human Resource Management in the Government Republic of Bangladesh";
    SetColor(17);

}

void print_heading(const char title[]){
    SetColor(10);
    SetColorAndBackground(31,3);
    gotoxy(45,8);
        cout << title;
    SetColorAndBackground(17,15);
}


/*------- Clear Window -------*/
void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);
                cout << " ";
        }
    }
}

/*------- Box Border -------*/
void boxBorder(){
    // Box Side Border
    SetColor(8);
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",205);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",205);
        }else{
            printf("%c",205);
        }
    }

}






