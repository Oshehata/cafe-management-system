#include <iostream>
#include <string>
using namespace std;
//position of array
int counter=-1;
//structure  definition
struct client
{
    int id;
    string name;
    string time;
};

client num_of_clients[100];

// functions


bool search_id(int id)      //searching is this id exist or not
{

    for (int i=0;i<counter;i++)
    {
        if (num_of_clients[i].id==id)
        {
            return true;
            break;
        }
    }
    return 0;
}

int position_of_id(int id)    //searching for the position of founded id
{
    for (int i=0;i<=counter;i++)
    {
        if (num_of_clients[i].id==id)
        {
            return i;
            break;
        }
    }
    return -1;

}
bool error_choose(int choose)          //check if user enter (0 or 1 ) only
{
    if (choose==0 || choose ==1)
    {
        return true;
    }
    return false;
}


void add_client()       //adding client
{
    int flag=true;
    while (flag==true)
    {
        counter++;
        if(counter>99)                         //
        if(counter>99)                         //
        {
            cout<<"\n\nError you exceeded the maximum number of clients\n\n";
            break;
        }
        cout<<"\n\n\t\t\t\t\t\tWelcome user\n\n";
        cout<<"Please enter the id of the client entered the cafe: ";
        cin>>num_of_clients[counter].id;
        while (search_id(num_of_clients[counter].id)==1)
        {
            cout<<"\n\nError there is a client with this id, please enter another id: ";
            cin>>num_of_clients[counter].id;
        }
        cout<<"\n\nPlease enter the time the client entered the cafe: ";
        cin>>num_of_clients[counter].time;
        cout<<"\n\nPlease enter client name: ";
        cin>>num_of_clients[counter].name;
        cout<<"\n\nTo add other client, press 1 else to exit press 0.";
        cout<<"\n\nyour choose: ";
        cin>>flag;
        while (error_choose(flag)==false)
        {

            cout<<"\n\nWrong choice, your choose: ";
            cin>>flag;
        }
    }


}
void update_client()  // update client
{
    int flag=true;
    int id;
    int position;
    while (flag==true)
    {
        cout<<"\n\n\t\t\t\t\t\tWelcome user\n\n";
        cout<<"Please enter the id of the client to update: ";
        cin>>id;
        position=position_of_id(id);
        if(position!=-1)
        {
            cout<<"\n\nPlease enter the new time of the client: ";
            cin>>num_of_clients[position].time;
            cout<<"\n\nPlease enter the new name of the client : ";
            cin>>num_of_clients[position].name;
        }
        else
        {
            cout<<"\n\nError there is no client with this id";
        }
        cout<<"\n\nTo update other client, press 1 else to exit press 0.";
        cout<<"\n\nYour choose: ";
        cin>>flag;
        while (error_choose(flag)==false)
        {
            cout<<"\n\nWrong choose, your choose: ";
            cin>>flag;
        }
    }
}
void delete_client ()
{
    int flag=true;
    int id,position;
    while(flag==true)
    {
        cout<<"\n\n\t\t\t\t\t\tWelcome user\n\n";
        cout<<"Please enter the id of the client to delete: ";
        cin>>id;
        position=position_of_id(id);
        if(position!=-1)
        {
            for(int i=position;i<counter;i++)
            {
                num_of_clients[i]=num_of_clients[i+1];
            }
            counter--;
            cout<<"\n\nDeleted successfully";
        }
        else
        {
            cout<<"\n\nError there is no client with this id";
        }
        cout<<"\n\nTo delete other client, press 1 else to exit press 0.";
        cout<<"\n\nYour choose: ";
        cin>>flag;
        while (error_choose(flag)==false)
        {
            cout<<"\n\nWrong choose, your choose: ";
            cin>>flag;
        }
    }
}
void print_clients () //printing clients
{
    cout<<"\n\n\t\t\t\t\t\tWelcome user\n\n";
    cout<<"\n\nThe summary of clients visited the cafe today:\n\n";
    if (counter==-1)
    {
        cout<<"\n\nThere is no clients until now\n\n";
    }
    for (int i=0;i<=counter;i++)
    {
        cout<<i+1<<") At "<<num_of_clients[i].time<<" "<<num_of_clients[i].name<<" visited the cafe\n";
    }
    cout<<endl;
}
int main()
{
    bool flag =true;
    int choosen_number;
    while(flag==true)
     {

        cout<<"\t\t\t\tWelcome to the management system for a cafe\n\n";
        cout<<"1) Add new client.\n\n";
        cout<<"2) Update client.\n\n";
        cout<<"3) Delete client.\n\n";
        cout<<"4) Show all clients attended the cafe.\n\n";
        cout<<"Please choose one from above choices: ";
        cin>>choosen_number;
        while (choosen_number>4 || choosen_number<1)
        {
            cout<<"\nThis number is not valid please enter number again: ";
            cin>>choosen_number;
            cout<<endl;

        }

        if(choosen_number==1)
        {
            add_client();

        }
        else if (choosen_number==2)
        {
            update_client();

        }
        else if (choosen_number==3)
        {
            delete_client();

        }
        else
        {
            print_clients();
            cout<<"\n\nThanks for using this program\n\n";
            flag=false;
        }

     }
    return 0;
}
