#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdlib>
#include"user_interface.h"
#include"handle_data.h"
#include"account_setting.h"
#include"front_office.h"

using std::cout;

int end_exec=0;
extern int room_con;

_user::_user()
{
    init();
}

void _user::init()
{
    int i;
    char menu[4][20]={"log in","account setting","add account","exit"};
    for(i=0;i<4;i++)
        strcpy(this->menu[i],menu[i]);

    arrow="->";
    arrow2="<-";
}

void _user::display()
{
    char stop;
    int acc_indeks;
    while(1)
    {
        int res=show_menu();
        if(res==0)// fo login(),0 fo_log in is dont have account and dont make account, 1 is succes to log in
        {
            if(fo_login(acc_indeks))
            {
                std::cout<<"succes to log in\n";
                room_con=display_room();
                break;
            }
            else
                std::cout<<"failed log in";
        }

        else if(res==1)
            m_con(acc_indeks);

        else if(res==2)
            add_acc();
        else
        {
            end_exec=3;
            break;
        }
       std::cin.get();
    }

}

int _user::show_menu()
{
    char con;
    int i;
    int chose=0;
    while(con!=0x0D)
    {
        cout<<"(  ____ \\\__   __/(       )(  ____ )( \\      (  ____ \\  (  ____ )(  ____ )(  ___  )(  ____ \\(  ____ )(  ___  )(       )\n";
        cout<<"| (    \\/  ) (   | () () || (    )|| (      | (    \\/  | (    )|| (    )|| (   ) || (    \\/| (    )|| (   ) || () () |\n";
        cout<<"| (_____   | |   | || || || (____)|| |      | (__      | (____)|| (____)|| |   | || |      | (____)|| (___) || || || | \n";
        cout<<"(_____  )  | |   | |(_)| ||  _____)| |      |  __)     |  _____)|     __)| |   | || | ____ |     __)|  ___  || |(_)| | \n";
        cout<<"      | |  | |   | |   | || (      | |      | (        | (      | (\\ (   | |   | || | \\_  )| (\\ (   | (   ) || |   | | \n";
        cout<<"/\\____) |__) (___| )   ( || )      | (____/\\| (____/\\  | )      | ) \\ \\__| (___) || (___) || ) \\ \\__| )   ( || )   ( | \n";
        cout<<"\\_______)\\_______/|/    \\||/       (_______/(_______/  |/       |/   \\__/(_______)(_______)|/   \\__/|/     \\||/     \\|  \n\n";

        cout<<"          _______ _________ _______  _\n";
        cout<<"|\\     /|(  ___  )\\_   __/(  ____ \\( \\\n";
        cout<<"| )   ( || (   ) |  ) (   | (    \\/| ( \n";
        cout<<"| (___) || |   | |  | |   | (__    | | \n";
        cout<<"|  ___  || |   | |  | |   |  __)   | |  \n";
        cout<<"| (   ) || |   | |  | |   | (      | |\n";
        cout<<"| )   ( || (___) |  | |   | (____/\\| (____/\\\n";
        cout<<"|/     \\|(_______)  )_(   (_______/(_______/\n";

        std::cout<<"\n\n\n";
        for(i=0;i<4;i++)
        {
            std::cout<<"\t\t";
            if(chose==i)
                std::cout<<arrow<<menu[i]<<arrow2<<std::endl<<std::endl;
            else
                std::cout<<menu[i]<<std::endl<<std::endl;
        }

        con=getch();
        if(con=='s' && (chose<3 && chose>=0))
            chose+=1;
        else if(con=='w' && (chose>0 && chose<=3))
            chose-=1;

        system("cls");
    }
    return chose;
}












