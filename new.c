

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
///FOR HIDING CURSOR.
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
///FOR ARROW CURSOR.
// realPosition is the position arrow is at.
//arrowPosito is the position where the user want the arrow to be.
void arrowHere(int realPosition, int arrowPosition)
{
    char arrow = 16;

    if(realPosition == arrowPosition)
    {
        printf("%c ", arrow);
    }

    else
        printf("  ");
}


/// for animation
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct transaction_info
{
    char name[100];
    int amount;
    char date[10];
};
struct transaction_info t_user[100];


struct st
{
    char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];

};
struct st user[15];


struct transaction
{
    char userID[20]; /// user name for each id
    int id_balance; /// balance for each id
    int tran_num;  ///transaction number for each id
};
struct transaction id[15]; /// for multiple transaction

struct note
{
    char note_name[30];
    int num_note;
};
struct note note_user[15];


int id_num = 0;   /// number of  id  curently saved
int balance;   /// total balance;
int n_num,num;        ///tran ending point for each id
int id_pos;   /// id position
int tran_add;
int id_point;
char my_note[200][200];
char name[20];
char password[20];
int n_last,n_pos,n_start;


void login();
void signup();
void main_page();
void add_money();
void read_tran();
void write_tran();
void show_tran();
void remove_tran();
void remove_money();
void search_id();
void read_note();
void write_note();
void show_note();
void note_page();
void add_notes();
void remove_note();


int t_num;   ///how many transaction done

int number; /// for remove_tran function


void read_tran()  ///to read  transactions1
{
    FILE* ch;

    ch=fopen("transaction.txt","r");
    // if(ch==0)
    // printf("file doesnot exixit");
    fscanf(ch,"%d",&id_num);

    int i,j;

    num=0;

    for( i=0; i<id_num; i++)
    {
        int start=0;

        fscanf(ch,"%s",&id[i].userID);
        fscanf(ch,"%d",&id[i].id_balance);
        fscanf(ch,"%d",&id[i].tran_num);

        if(strcmp(name,id[i].userID)==0) /// id balance check
            balance = id[i].id_balance;


        num += id[i].tran_num ; ///tran ending point for each id

        start = num - id[i].tran_num;

        for( j=start; j<num; j++)
        {
            fscanf(ch,"%s",&t_user[j].name);
            fscanf(ch,"%d",&t_user[j].amount);
            fscanf(ch,"%s",&t_user[j].date);
        }

    }

    fclose(ch);
}

void write_tran() /// to write transaction1
{
    FILE* ch;
    ch=fopen("transaction.txt","w");

    if(ch==0)
        printf("file doesnot exixit");

    num=0;

    fprintf(ch,"%d\n",id_num);

    int i,j;

    for(i=0; i<id_num; i++)
    {
        int start = 0;

        fprintf(ch,"%s\n",id[i].userID);
        fprintf(ch,"%d\n",id[i].id_balance);
        fprintf(ch,"%d\n",id[i].tran_num);

        num += id[i].tran_num;  ///tran ending point for each id

        start = num - id[i].tran_num;

        for( j=start; j<num; j++ )
        {
            fprintf(ch,"%s\n",t_user[j].name);
            fprintf(ch,"%d\n",t_user[j].amount);
            fprintf(ch,"%s\n",t_user[j].date);
        }

    }

    fclose(ch);

}

void add_money()//1
{

    read_tran();
    search_id();

    for(int i=tran_add; i>id_point; i--)
    {
        t_user[i]=t_user[i-1];
    }

    gotoxy(17,5);

         printf("..................................................................................");
                 gotoxy(17,18);

         printf("..................................................................................");
         for(int i=5;i<=18;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=18;i++)
         {gotoxy(98,i);
            printf(".");
         }
     gotoxy(48,7);
    printf("...............................");
    gotoxy(52,6);
    printf("-----Add money------");

    gotoxy(19,9);
    printf("Enter name : ");
    scanf("%s",&t_user[id_point].name);
 gotoxy(19,10);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    gotoxy(19,11);
    printf("Enter amount : +");
    scanf("%d",&t_user[id_point].amount);
 gotoxy(19,12);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(19,13);
    printf("Enter date (dd/mm/yy) format: ");
    scanf("%s",&t_user[id_point].date);
 gotoxy(19,14);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    //gotoxy(18,14);
    // printf("  => %d ",id_point);

    id[id_pos].id_balance += t_user[id_point].amount;

    id[id_pos].tran_num++;

    write_tran();

    gotoxy(57,15);
    printf("***Transaction successfull***");

    gotoxy(57,17);
    printf("=>Press any key to get back<=");

    getch();
    system("CLS");

    main_page();
}

void remove_money()//1
{
    read_tran();
    search_id();

    for(int i=tran_add; i>id_point; i--)
    {
        t_user[i]=t_user[i-1];
    }


  gotoxy(17,5);

         printf("..................................................................................");
                 gotoxy(17,21);

         printf("..................................................................................");
         for(int i=5;i<=21;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=21;i++)
         {gotoxy(98,i);
            printf(".");
         }

    gotoxy(52,6);
       printf("-----Remove money------");
    gotoxy(48,7);
    printf("...............................");
         gotoxy(19,9);
   printf("Enter name : ");
   scanf("%s",&t_user[id_point].name);
 gotoxy(19,10);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(19,11);
   printf("Enter amount : -");
   scanf("%d",&t_user[id_point].amount);
 gotoxy(19,12);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(19,13);
   printf("Enter date (dd/mm/yy) format: ");
    scanf("%s",&t_user[id_point].date);
 gotoxy(19,14);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    ///to check if enough balance is available to remove

    if( id[id_pos].id_balance >= t_user[id_point].amount )
    {

        id[id_pos].id_balance -= t_user[id_point].amount;

        id[id_pos].tran_num++;

        write_tran();

        gotoxy(43,17);
        printf("**Transaction successfull**");

    }
    else
    {
        gotoxy(43,17);
        printf("**Insufficient balance**");
    }


    gotoxy(43,19);
    printf("=>Press any key to get back<=");

    getch();
    system("CLS");


    main_page();
}

void remove_tran()//1
{
    read_tran();

  num = 0;
    int start;

    int k=0;

    for(int j=0;j<id_num;j++)
        {
             num += id[j].tran_num;


       if(strcmp(name,id[j].userID)==0){

            //printf("done");

            start = num - id[j].tran_num;
             gotoxy(24,6);
    printf("SI.");
       gotoxy(35,6);
    printf("Name");
      gotoxy(54,6);
    printf("Amount");
         gotoxy(72,6);
    printf("Date");
    gotoxy(23,7);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        gotoxy(23,5);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for(int i=5;i<=19;i++)
         {gotoxy(23,i);
            printf(".");
         }
          for(int i=5;i<=19;i++)
         {gotoxy(79,i);
            printf(".");
         }
          for(int i=5;i<=19;i++)
         {gotoxy(28,i);
            printf(".");
         } for(int i=5;i<=19;i++)
         {gotoxy(45,i);
            printf(".");
         } for(int i=5;i<=19;i++)
         {gotoxy(66,i);
            printf(".");
         }
          gotoxy(23,19);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    int f =1 ;

    for(int i=start;i<num;i++)
    {

    gotoxy(25,f+7);
    printf("%d . ",f);
    gotoxy(29,f+7);
    printf("%s",t_user[i].name);
    gotoxy(47,f+7);
    printf("%d  ",t_user[i].amount);
    gotoxy(68,f+7);
    printf("%s",t_user[i].date);

    f++;


         }
          //k=f+10;

       }
     //k=f+10;
     }
 gotoxy(25,2);
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
   gotoxy(28,1);

    printf("Enter ther transaction number you want to remove : ");

    scanf("%d",&number); /// number declared globally

    id[id_pos].tran_num--;

    for(int f=start+number;f<num;f++)
    {
        t_user[f-1]=t_user[f];
    }


    write_tran();

    gotoxy(40,22);
    printf("Press any key to get back");
     gotoxy(37,23);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    getch();
    system("CLS");

    main_page();




}

void show_tran()    /// to print and show trasantions1
{

    read_tran();


    num = 0;

   // write_tran();

    int k=0;

    for(int j=0;j<id_num;j++)
        {
             num += id[j].tran_num;


       if(strcmp(name,id[j].userID)==0){

            //printf("done");

              int start = num - id[j].tran_num;
               gotoxy(24,3);
    printf("SI.");
       gotoxy(35,3);
    printf("Name");
      gotoxy(54,3);
    printf("Amount");
         gotoxy(72,3);
    printf("Date");
    gotoxy(23,4);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        gotoxy(23,2);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for(int i=2;i<=15;i++)
         {gotoxy(23,i);
            printf(".");
         }
          for(int i=2;i<=15;i++)
         {gotoxy(79,i);
            printf(".");
         }
          for(int i=2;i<=15;i++)
         {gotoxy(28,i);
            printf(".");
         } for(int i=2;i<=15;i++)
         {gotoxy(45,i);
            printf(".");
         } for(int i=2;i<=15;i++)
         {gotoxy(66,i);
            printf(".");
         }
          gotoxy(23,15);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    int f =1 ;

    for(int i=start;i<num;i++)
    {

    gotoxy(25,f+4);
    printf("%d ",f);
    gotoxy(29,f+4);
    printf("%s",t_user[i].name);
    gotoxy(47,f+4);
    printf("%d  ",t_user[i].amount);
    gotoxy(68,f+4);
    printf("%s",t_user[i].date);

    f++;


         }
         int k = f+10;
       }

     }

    gotoxy(40,k);
   printf("Press any key to get back");
gotoxy(37,k+1);
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    getch();
    system("CLS");

    main_page();


}








void read_note()
{
    FILE *ch;
    ch = fopen("notes.txt","r");

    num = 0;

    fscanf(ch,"%d",&id_num);


    int start = 0;

    for(int i=0; i<id_num; i++)
    {

        fscanf(ch,"%s",note_user[i].note_name);
        fscanf(ch,"%d",&note_user[i].num_note);


        num += note_user[i].num_note ;
        start = num - note_user[i].num_note ;

        if(strcmp(name,note_user[i].note_name)==0)
        {
            n_last=num;
            n_pos = i;
            n_start = start;
            //start = num - note_user[i].num_note ;

        }


        for(int j=start; j<num; j++)
        {

            fscanf(ch," %[^\n]",my_note[j]);

        }

    }



    fclose(ch);


}

void write_note()
{
    FILE *ch;
    ch = fopen("notes.txt","w");

    fprintf(ch,"%d\n",id_num);

    int  start = 0,num = 0;

    for(int i=0; i<id_num; i++)
    {
        fprintf(ch,"%s\n",note_user[i].note_name);
        fprintf(ch,"%d\n",note_user[i].num_note);

        num += note_user[i].num_note;
        start = num -  note_user[i].num_note;

        for(int j=start; j<num; j++)
        {
            fprintf(ch,"%s\n",my_note[j]);
        }
    }

    fclose(ch);
}

void show_note()
{

    read_note();

    num=0;

    int start = 0,k=8;


    for(int i=0; i<id_num; i++)
    {
        num += note_user[i].num_note;

        if(strcmp(name,note_user[i].note_name)==0)
        {
            n_last=num;
            n_pos = i;
            start = num - note_user[i].num_note ;
            //  printf("%d",note_user[i].num_note);

            int s = 1;  /// for serial
 gotoxy(17,5);

         printf("..................................................................................");
             gotoxy(17,7);

         printf("..................................................................................");
     gotoxy(17,18);

         printf("..................................................................................");
              for(int i=5;i<=18;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=18;i++)
         {gotoxy(98,i);
            printf(".");
         }
            gotoxy(54,6);

            printf("|| My notes ||");

            for(int j=start; j<num; j++)
            {
                gotoxy(20,k);
                k++;
                printf("%d . %s\n",s,my_note[j]);
                s++;
            }

        }

    }


    gotoxy(46,k+5);
    printf("=> Press any key to get back <=");
  gotoxy(43,k+6);

         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    getch();

    system("CLS");



    note_page();

}

void note_page()  /// note page
{
    int position =1;
    int keyPressed = 0;

    while(keyPressed != 13)
    {

        system("cls");

   gotoxy(15,3);
    printf("::::::::::::::::::::::::::::::::::::::");
     gotoxy(15,22);
    printf("::::::::::::::::::::::::::::::::::::::");
   for(int i=3;i<=22;i++)
   {

    gotoxy(15,i);
    printf("..");

   }
for(int i=3;i<=22;i++)
   {

    gotoxy(52,i);
    printf("..");
   }
        gotoxy(18,7);
        arrowHere(1, position);
        printf(" Show notes");


        gotoxy(18,9);
        arrowHere(2, position);
        printf(" Add note");

        gotoxy(18,11);
        arrowHere(3, position);
        printf(" Remove note");

        gotoxy(18,13);
        arrowHere(4, position);
        printf(" Back to Main menu.");

        keyPressed = getch();

        if(keyPressed == 80 && position != 4)
            position++;

        else if(keyPressed == 72 && position !=1)
            position--;

        else position = position;


        ///Operations.

        if(position == 1 && keyPressed == 13)
        {
            system("cls");
            show_note();
        }



        if(position == 2 && keyPressed == 13)
        {
            system("cls");
            add_notes();
        }


        if(position == 3 && keyPressed == 13)
        {
            system("cls");
            remove_note();
        }


        else if(position == 4 && keyPressed == 13)
        {
            system("cls");
            main_page();
        }

    }
}

void add_notes()//1
{
    read_note();
     gotoxy(17,5);

         printf("..................................................................................");
             gotoxy(17,7);

         printf("..................................................................................");
     gotoxy(17,18);

         printf("..................................................................................");
              for(int i=5;i<=18;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=18;i++)
         {gotoxy(98,i);
            printf(".");
         }

    gotoxy(50,6);
    printf("|| start from below || ");

    gotoxy(22,8);
    printf("=>");

    scanf(" %[^\n]",my_note[n_last]);  /// n last from read note


    note_user[n_pos].num_note++;


    for(int i=num; i>n_last; i--)
        strcpy(my_note[i],my_note[i-1]);



    write_note();

    gotoxy(45,13);

    printf(">> Note added successfully <<");

    gotoxy(45,16);
    printf("=>Press any key to get back<=");

    getch();
    system("CLS");

    note_page();


}

void remove_note()//1
{
    read_note();
    num=0;

    int start = 0,k=4,s,n;


    for(int i=0; i<id_num; i++)
    {
        num += note_user[i].num_note;

        if(strcmp(name,note_user[i].note_name)==0)
        {
            n_last=num;
            n_pos = i;
            start = num - note_user[i].num_note ;
            //  printf("%d",note_user[i].num_note);

            s = 1;  /// for serial

            for(int j=start; j<num; j++)
            {
                gotoxy(10,k);
                k++;
                printf("%d . %s\n",s,my_note[j]);
                s++;
            }

        }

    }
  gotoxy(10,s+4);

         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(10,s+5);
    printf("      ** Enter the serial of the note u want to remove **");
       gotoxy(10,s+6);

         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");


        gotoxy(10,s+7);
       printf("Enter :");
   // scanf("%d",&n);

 gotoxy(10,s+8);

         printf("~~~~~~~~~~");
scanf("%d",&n);



    note_user[n_pos].num_note--;


    for(int i=n_start+n-1; i<num; i++)
        strcpy(my_note[i],my_note[i+1]);


    write_note();


    gotoxy(50,s+10);
    printf(">> Note removed successfully <<");
    gotoxy(52,s+12);
    printf("PRESS ANY KEY TO GET BACK");

    getch();
    system("CLS");

    note_page();


}





void read_data()//1
{

    FILE* ch;
    ch = fopen("sign_up.txt","r");
    fscanf(ch,"%d",&id_num);
    for(int i=0; i<id_num; i++)
    {
        fscanf(ch,"%s",&user[i].first_name);
        fscanf(ch,"%s",&user[i].last_name);
        fscanf(ch,"%s",&user[i].user_name);
        fscanf(ch,"%s",&user[i].password);
    }

    fclose(ch);

}

void write_data()//1
{
    FILE* ch;
    ch = fopen("sign_up.txt","w");

    //  id_num++;
    fprintf(ch,"%d\n",id_num);
    for(int i=0; i<id_num; i++)
    {
        fprintf(ch,"%s\n",user[i].first_name);
        fprintf(ch,"%s\n",user[i].last_name);
        fprintf(ch,"%s\n",user[i].user_name);
        fprintf(ch,"%s\n",user[i].password);
    }

    fclose(ch);



}

void search_id()//1
{
    read_tran();

    int i;

    id_point = 0;

    tran_add = 0;

    for(i=0; i<id_num; i++)
    {
        tran_add += id[i].tran_num;


        if(strcmp(name,id[i].userID)==0)
        {

            id_pos = i;
            id_point = tran_add;

        }

    }


}

void main_page()  /// account main page1
{

    read_tran();


    int position = 1;
    int keyPressed = 0;

    while(keyPressed != 13)
    {
        system("cls");

    /// from read_tran
 gotoxy(15,3);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
     gotoxy(15,22);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
   for(int i=3;i<=22;i++)
   {

    gotoxy(15,i);
    printf("..");

   }
for(int i=3;i<=22;i++)
   {

    gotoxy(85,i);
    printf("..");

   }

    gotoxy(18,5);
    printf("|| Balance : %d",balance); /// from read_tran
      gotoxy(18,6);
    printf("~~~~~~~~~~~~~~~~~");
      gotoxy(18,8);
    printf("-------------------------------");
      gotoxy(18,10);
    printf("-------------------------------");
      gotoxy(18,12);
    printf("-------------------------------");
      gotoxy(18,14);
    printf("-------------------------------");
      gotoxy(18,16);
    printf("-------------------------------");
    gotoxy(18,18);
    printf("-------------------------------");
    gotoxy(18,20);
    printf("-------------------------------");
        ///gotoxy(18,6);
        ///printf("WELCOME Ekhane naam ta show kora user er", )!!


        gotoxy(18,7);
        printf("What do you want do today!");

        gotoxy(18,9);
        arrowHere(1, position);
        printf("1. Add money");

        gotoxy(18,11);
        arrowHere(2, position);
        printf("2. Remove money");

        gotoxy(18,13);
        arrowHere(3, position);
        printf("3. View Transaction History");

        gotoxy(18,15);
        arrowHere(4, position);
        printf("4.Delete Transaction ");

        gotoxy(18,17);
        arrowHere(5,position);
        printf("5. My Diary ");

        gotoxy(18,19);
        arrowHere(6,position);
        printf("6. Exit");

        keyPressed = getch();


        if(keyPressed == 80 && position != 6)
            position++;

        else if(keyPressed == 72 && position != 1)
            position--;

        else position = position;


        ///Operations.
        if(position == 1 && keyPressed == 13)
        {
            system("cls");
            add_money();
        }

        else if(position ==2 && keyPressed == 13)
        {
            system("cls");
            remove_money();
        }

        else if(position ==3 && keyPressed == 13)
        {
            system("cls");
            show_tran();
        }

        else if(position ==4 && keyPressed == 13)
        {
            system("cls");
            remove_tran();
        }

        else if(position ==5 && keyPressed == 13)
        {
            system("cls");
            note_page();    ///work from here
        }

        else if(position ==6 && keyPressed == 13)
        {
            system("cls");
            EXIT();
        }

    }
}

void EXIT()
{
    int position = 1;
    int keyPressed = 0;

    while(keyPressed != 13)
    {
        system("cls");
       gotoxy(15,3);
    printf("::::::::::::::::::::::::::::::::::::::");
     gotoxy(15,22);
    printf("::::::::::::::::::::::::::::::::::::::");
   for(int i=3;i<=22;i++)
   {

    gotoxy(15,i);
    printf("..");

   }
for(int i=3;i<=22;i++)
   {

    gotoxy(52,i);
    printf("..");

   }

        gotoxy(25, 7);
        printf("Do you want to exit?!");

        gotoxy(25, 9);
        arrowHere(1, position);
        printf("YES.");

        gotoxy(25, 11);
        arrowHere(2, position);
        printf("NO.");

        keyPressed = getch();

        if(keyPressed == 80 && position != 2)
            position++;

        else if(keyPressed == 72 && position !=1)
            position--;

        else position = position;

        ///Operations.
        if(position == 1 && keyPressed == 13)
        {
            system("cls");
            //goto L1;
        }

        else if(position == 2 && keyPressed == 13)
        {
            system("cls");
            main_page();
        }
    }

}

void login()   ///login function
{
    hidecursor();
   gotoxy(42,1);

         printf("...............................");
         gotoxy(42,3);

         printf("..............................");
          gotoxy(42,2);
      printf(":");
           gotoxy(42,3);
      printf(":");
            gotoxy(72,2);
      printf(":");
           gotoxy(72,3);
      printf(":");
               gotoxy(17,5);

         printf("..................................................................................");
                 gotoxy(17,18);

         printf("..................................................................................");
         for(int i=5;i<=18;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=18;i++)
         {gotoxy(98,i);
            printf(".");
         }
   gotoxy(48,2);
      printf(" <<<<<LOGIN>>>>> ");

    char login_user_name[30],login_password[30];

    gotoxy(24,7);
    printf("1.Enter user name : ");
    scanf("%s",&login_user_name);
 gotoxy(24,8);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~");
   gotoxy(24,9);
    printf("2.Enter password  : ");
    scanf("%s",&login_password);

  gotoxy(24,10);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~");
    read_data();

    int k=0;  /// position of the userID
              ///initially kept 0

   for(int i=0;i<id_num;i++)
   {
       if(strcmp(login_user_name,user[i].user_name)==0)
        k=i;
   }



    /// comparing id password

  int a = strcmp(login_user_name,user[k].user_name);
  int b = strcmp(login_password,user[k].password);

  if(a == 0 && b == 0){

         strcpy(name,login_user_name);

    gotoxy(53,12);
    printf("**Succesful login**");
     gotoxy(51,14);
    printf("Press any key to continue");

    getch();
    system("CLS");

    main_page();

    }

  else{
    gotoxy(45,10);
    printf("**Incorrect user name or password**");

    gotoxy(53,11);
    printf("*please try again*");
     gotoxy(50,13);
    printf("Press any key to try again ");

    getch();
    system("CLS");
    login();

    }


    getch();
}

void signup()   ///sign up function
{
    hidecursor();
  char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];



    char any_key;

   read_data();
   read_tran();
   read_note();
         gotoxy(42,1);
         printf("...............................");
         gotoxy(42,3);

         printf("..............................");
          gotoxy(42,2);
      printf(":");
           gotoxy(42,3);
      printf(":");
            gotoxy(72,2);
      printf(":");
           gotoxy(72,3);
      printf(":");
         gotoxy(17,5);

         printf("..................................................................................");
     gotoxy(17,18);

         printf("..................................................................................");
              for(int i=5;i<=18;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=18;i++)
         {gotoxy(98,i);
            printf(".");
         }
   gotoxy(48,2);

   printf("<<<<<SIGN UP>>>>>");
   gotoxy(19,6);
   printf("1.Enter first name : ");
   scanf("%s",&user[id_num].first_name);
     gotoxy(19,7);
      printf("~~~~~~~~~~~~~~~~~~~~~~~");

   gotoxy(19,8);
    printf("2.Enter last name  : ");
    scanf("%s",&user[id_num].last_name);
  gotoxy(19,9);
      printf("~~~~~~~~~~~~~~~~~~~~~~~");
   gotoxy(19,10);
    printf("3.Enter user name  : ");
    scanf("%s",&user[id_num].user_name);
  gotoxy(19,11);
      printf("~~~~~~~~~~~~~~~~~~~~~~~");
   gotoxy(19,12);
   printf("4.Enter password   : ");
   scanf("%s",&user[id_num].password);
  gotoxy(19,13);
      printf("~~~~~~~~~~~~~~~~~~~~~~~");
      int i;

     for(i=0;i<id_num;i++)  ///to check if the userID is taken
   {



       if(strcmp(user[id_num].user_name,user[i].user_name)==0){

            system("CLS");
              gotoxy(17,4);
         printf("..................................................................................");
     gotoxy(17,20);

         printf("..................................................................................");
              for(int i=5;i<=20;i++)
         {gotoxy(17,i);
            printf(".");
         }
           for(int i=5;i<=20;i++)
         {gotoxy(98,i);
            printf(".");
         }
        gotoxy(45,6);
        printf("-----user name already taken-----");
         gotoxy(43,7);
        printf("***********************************");
        gotoxy(52,8);
        printf("Try another one >>>>");
         gotoxy(20,11);
    printf("--------------------");

        gotoxy(20,10);
    printf("3.Enter user name  : ");
    scanf("%s",&user[id_num].user_name);
     i=0;  /// to check if the new userID is taken
       }
   }

    strcpy(id[id_num].userID,user[id_num].user_name);
    id[id_num].id_balance = 0;
    id[id_num].tran_num = 0;

    id_num++;

  // strcpy(password,user[id_num].password);
    write_data();
   write_tran();
   read_note();


  gotoxy(48,14);
   printf("**sign up succesfull**");

    gotoxy(35,16);
   printf("Note : please login using your user name and password\n");

     gotoxy(45,18);
   printf("Press any key to continue : ");
     getch();


 //  gotoxy(48,12);
  // printf("**sign up succesfull**");
///
   // gotoxy(30,14);
   //printf("Note : please login using your user name and password\n");

   //  gotoxy(45,16);
  // printf("Press any key to continue : ");
  // getch();
 system("CLS");

   login();
}

void First_page()
{
   hidecursor();
    int position = 1;
    int keyPressed = 0;

    while(keyPressed != 13)
    {

        system("cls");
           gotoxy(33,3);
      printf(".......................................................");

       gotoxy(33,5);
      printf(".......................................................");
         gotoxy(33,14);
      printf(".......................................................");
      for(int i=4;i<15;i++)
         {
          gotoxy(33,i);
           printf(":");}
             for(int i=4;i<15;i++)
         {
          gotoxy(87,i);
           printf(":");}


        gotoxy(50,4);
        printf("Welcome to HALKHATA");
        gotoxy(35,8);
        arrowHere(1, position);
        printf("Login\n");
        gotoxy(35,10);
        arrowHere(2, position);
        printf("Sign up\n\n");
        gotoxy(50,15);

        keyPressed = getch();

        if(keyPressed == 80 && position != 2)
            position++;

        else if(keyPressed == 72 && position != 1)
            position--;

        else position = position;

        if(position == 2 && keyPressed == 13)
        {
            system("cls");
            signup();

        }
        else if(position == 1 && keyPressed == 13)
        {
            system("cls");
            login();

        }

    }


}

int main()
{
     system("color 0e");
    First_page();

    return 0;
}
