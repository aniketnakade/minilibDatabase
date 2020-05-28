#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<fstream>

using namespace std;



struct Person
{
    string name;
    string surname;
    short age;
    string telephone;
};
short peopleInDatabase;
Person people[50];

void requireEnter();

void addPerson();

void showPerson();

void savePeopleToFile();

void loadPeopleFromTheFile();

void searchDatabase();

void removePersonFromDatabase();
int main()
{

    char test;
loadPeopleFromTheFile();
    do{
            cout<<"Number Of People in Database: "<<peopleInDatabase<<endl;
cout<<"MENU:"<<endl;
cout<<"1.Add Person"<<endl;
cout<<"2.Show all people"<<endl;
cout<<"3.Save People To File"<<endl;
cout<<"4.Load People From The File"<<endl;
cout<<"5.Search From Database"<<endl;
cout<<"6.Remove Person From Database"<<endl;
cout<<endl;

test=getch();

switch(test)
{
case '1':
   addPerson();
    break;
case '2':
    showPerson();
    break;
case '3':
    savePeopleToFile();
    break;
case '4':
    loadPeopleFromTheFile();
    break;
case '5':
    searchDatabase();
    break;
case '6':
    removePersonFromDatabase();

}

requireEnter();
system("cls");


}while(test!=27);

    return 0;
}
void requireEnter()
{
    cout<<"Click Enter To Continue...."<<endl;
    while(getch()!=13);
}
void addPerson()
{
    cout<<"Type Name: "<<endl;
    cin>>people[peopleInDatabase].name;

    cout<<"Type Surname: "<<endl;
    cin>>people[peopleInDatabase].surname;

    cout<<"Type Age: "<<endl;
    cin>>people[peopleInDatabase].age;

    cout<<"Type Mobile Number: "<<endl;
    cin>>people[peopleInDatabase].telephone;

    peopleInDatabase++;

}
void showPerson()
{
    if(peopleInDatabase>0)
    {
        for(int i=0;i<peopleInDatabase;i++)
        {
            cout<<"Person Index "<<i+1<<endl;
            cout<<"Name: "<<people[i].name<<endl;
            cout<<"Surname: "<<people[i].surname<<endl;
            cout<<"Age: "<<people[i].age<<endl;
            cout<<"Mobile Number: "<<people[i].telephone<<endl<<endl<<endl;


        }

    }
    else
        cout<<"Nobody is in the Database"<<endl;
}
void savePeopleToFile()
{
    ofstream file("database.txt");
    if(file.is_open())
    {
     file<<peopleInDatabase<<endl;
        for(int i=0;i<peopleInDatabase;i++)
        {

            file<<people[i].name<<endl;
            file<<people[i].surname<<endl;
            file<<people[i].age<<endl;
            file<<people[i].telephone<<endl;


        }

        file.close();
        cout<<"Saved Successfully.."<<endl;
    }
    else
        cout<<"Could Not Save To File"<<endl;
}
void loadPeopleFromTheFile()
{
    ifstream file("database.txt");

    if(file.is_open())
    {
        file>>peopleInDatabase;

        if(peopleInDatabase>0)
        {
for(int i=0;i<peopleInDatabase;i++)
        {
            file>>people[i].name;
            file>>people[i].surname;
            file>>people[i].age;
            file>>people[i].telephone;
        }
        cout<<"All peoples were loaded fine."<<endl;
        }
        else
            cout<<"Database is Empty"<<endl;
    }
    else
        cout<<"This File Does Not Exist"<<endl;
}
void searchDatabase()
{
    if(peopleInDatabase>0)
    {
        string name;
        cout<<"Type a name of person you want to look for"<<endl;
        cin>>name;
        for(int i=0;i<peopleInDatabase;i++)
        {
            if(name==people[i].name)
            {

            cout<<"Person Index "<<i+1<<endl;
            cout<<"Name: "<<people[i].name<<endl;
            cout<<"Surname: "<<people[i].surname<<endl;
            cout<<"Age: "<<people[i].age<<endl;
            cout<<"Mobile Number: "<<people[i].telephone<<endl<<endl<<endl;

            }
        }
    }
    else
        cout<<"Nothing in the database to search for"<<endl;
}
void removePersonFromDatabase()
{
if(peopleInDatabase>0)
{
    short index;
cout<<"Who do you want to remove type index:"<<endl;
cin>>index;
if(peopleInDatabase>=index)
{
        for(short k=index;k<peopleInDatabase;k++)
        {
            people[k-1].name=people[k].name;
            people[k-1].surname=people[k].surname;
            people[k-1].age=people[k].age;
            people[k-1].telephone=people[k].telephone;
        }
        peopleInDatabase--;
        cout<<"Removed Successfully...."<<endl;
        savePeopleToFile();
}
else
cout<<"There is nobody like that"<<endl;


}
else
    cout<<"There is nothing to remove"<<endl;
}
