/*Hospital Management System
        Created By
FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)*/
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>
//-------------------------------------------Structure Function---------------------------------
struct Patients
{
    int id;
    char fname[20];
    char lname[20];
    char gender[2];
    int age;
    char address[20];
    char c_no[20];
    char mail[20];
    char problem[20];
    char doc[20];
};

//---------------------------------------------ADD function--------------------------------------------
void add(struct Patients bk[])
{
    int i,demo;
    char male[2]="M";
    char female[2]="F";
    char more;
    static int n=11;
    header();
    printf("\n\t\t\t\t\t***********************************ADD PATIENTS RECORD***********************************\n\n");
    for (i=n-1; i<100; i++)
    {
        bk[i].id=n;
        n+=1;
A:
        fflush(stdin);
        printf("\t\t\t\tFirst name :");
        gets(bk[i].fname);
        fflush(stdin);
        if(strlen(bk[i].fname)>20)
        {
            printf("\n\t\t\t\t Invalid :( \t The max range for first name is 20\n");
            goto A;
        }
B:
        printf("\t\t\t\tLast Name :");
        gets(bk[i].lname);
        fflush(stdin);
        if(strlen(bk[i].lname)>20)
        {
            printf("\n\t\t\t\t Invalid :( \t The max range for last name is 20\n");
            goto B;
        }
C:
        printf("\t\t\t\tGender [M/F] :");
        gets(bk[i].gender);
        fflush(stdin);
        if(strcmp(bk[i].gender,male)==0 || strcmp(bk[i].gender,female)==0)
        {

        }
        else
        {
            printf("\n\t\t\t\tInvalid gender,Please enter again\n");
            goto C;
        }

        printf("\t\t\t\tAge :");
        scanf("%d",&bk[i].age);
        fflush(stdin);
D:
        printf("\t\t\t\tAddress :");
        gets(bk[i].address);
        fflush(stdin);
        if(strlen(bk[i].address)>20||strlen(bk[i].address)<2)
        {
            printf("\n\t\t\t\t Invalid :( \t The max range for address is 20 and min range is 2 :)\n");
            goto D;
        }
E:
        printf("\t\t\t\tPhone no.(923001234567):");
        gets(bk[i].c_no);
        fflush(stdin);

        printf("\t\t\t\tEmail :");
        gets(bk[i].mail);
        fflush(stdin);

        printf("\t\t\t\tDisease :");
        gets(bk[i].problem);
        fflush(stdin);

        printf("\t\t\t\tPrescribed Doctor :");
        gets(bk[i].doc);
        fflush(stdin);

        printf("\n\n\t\t\t\t\t **************************( PATIENT RECORD ADDED SUCCESSFULY )**************************\n\n");

        printf("\t\t\t\t\t\t    **************************(PATIENT ID :%d)**************************",bk[i].id);

        printf("\nYou want to more Record (Y/N) :");
        scanf("%c",&more);
        system("cls");
        if(more =='n' || more == 'N')
        {
            break;
        }
    }
    printf("\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");

}
//---------------------------------------------Display Function--------------------------------------------
void display(struct Patients bk[])
{

    int i;
    header();
    printf("\n\t\t\t\t\t***********************************DISPLAY PATIENTS RECORD***********************************\n\n");
    recordhead();
    for(i=0; i<100; i++)
    {

        if(bk[i].id!=0)
        {
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10s | %10s   |\n",bk[i].id,bk[i].fname,bk[i].lname,bk[i].gender,bk[i].age,bk[i].address,bk[i].c_no,bk[i].mail,bk[i].problem,bk[i].doc);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
        }
    }
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}
//-------------------------------------------------Delete Function-------------------------------------------------

void del(struct Patients bk[])
{
    int i,flag,del;
    char more;
    header();
    printf("\n\t\t\t\t\t***********************************DELETE PATIENT RECORD***********************************\n\n");
    printf("\t\t\t\tEnter the book ID you want to delete:");
    scanf("%d",&del);
    for(i=0; i<100; i++)
    {
        if(del==bk[i].id && del!=0)
        {
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10s | %10s   |\n",bk[i].id,bk[i].fname,bk[i].lname,bk[i].gender,bk[i].age,bk[i].address,bk[i].c_no,bk[i].mail,bk[i].problem,bk[i].doc);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
            printf("\nAre you sure you want to delete Book ID =%d (Y/N) :",del);
            scanf(" %c",&more);
            if(more =='y' || more == 'Y')
            {
                bk[i].id=NULL;
                printf("\n\n\t\t\t\t\t\t**********************( THIS DATA IS DELETED )***********************\n\n");
            }
            flag=0;
            break;
        }
        else
            flag=1;
    }
    if(flag==1)
    {
        printf("\n\n\t\t\t\t\t      **********************************************************************\n\n");
        printf("\t\t\t\t\t**************************( DATA IS NOT AVAILABLE )*******************************\n\n");
        printf("\t\t\t\t\t      **********************************************************************\n\n");
    }
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//------------------------------------------------Search Function----------------------------------------
void search(struct Patients bk[])
{
    int i,flag,srch;
    header();
    printf("\n\t\t\t\t\t***********************************SEARCH PATIENT RECORD***********************************\n\n");
    printf("\t\t\t\tEnter the Patient ID you want to Search:");
    scanf("%d",&srch);
    for(i=0; i<100; i++)
    {
        if(srch==bk[i].id && srch!=0)
        {
            printf("\n\t\t\t\t\t***********************************( RECORD FOUND )***********************************\n\n");
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10s | %10s   |\n",bk[i].id,bk[i].fname,bk[i].lname,bk[i].gender,bk[i].age,bk[i].address,bk[i].c_no,bk[i].mail,bk[i].problem,bk[i].doc);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n\n\n\n\n\n");
            flag=0;
            break;
        }
        else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
        recordhead();
        printf("\n\t\t   **           ****           ****            **    **          ******         *****             ******           ****          ***\n\n\n\n\n");
    }
    printf("\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}


//-------------------------------------------Edit Function------------------------------------------------------
void edit(struct Patients bk[])
{
    header();
    printf("\n\t\t\t\t\t***********************************EDIT PATIENTS RECORD***********************************\n\n");
    int i,flag,edt,select;
    char male[2]="M";
    char female[2]="F";
    printf("\t\t\t\tEnter the Patient ID you want to edit:");
    scanf("%d",&edt);
    for(i=0; i<100; i++)
    {
        if(edt==bk[i].id && edt!=0)
        {
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10s | %10s   |\n",bk[i].id,bk[i].fname,bk[i].lname,bk[i].gender,bk[i].age,bk[i].address,bk[i].c_no,bk[i].mail,bk[i].problem,bk[i].doc);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\n\n\n\t\t\t1- First name\n");
        printf("\t\t\t2- Last Name\n");
        printf("\t\t\t3- Gender\n");
        printf("\t\t\t4- Age\n");
        printf("\t\t\t5- Address\n");
        printf("\t\t\t6- Phone no.\n");
        printf("\t\t\t7- Email\n ");
        printf("\t\t\t8- Disease\n");
        printf("\t\t\t9- Prescribed Doctor\n\n");
        printf("\t\t\tSelect any one:");
        scanf("%d",&select);
        switch(select)
        {
        case 1:
Ac:
            fflush(stdin);
            printf("\t\t\t\tFirst name :");
            gets(bk[i].fname);
            fflush(stdin);
            if(strlen(bk[i].fname)>20)
            {
                printf("\n\t\t\t\t Invalid :( \t The max range for first name is 20\n");
                goto Ac;
            }
            printf("\n\n\t\t\t\t\t*************************( FIRST NAME UPDATED )***************************\n\n");
            break;
        case 2:
Bc:
            fflush(stdin);
            printf("\t\t\t\tLast Name :");
            gets(bk[i].lname);
            fflush(stdin);
            if(strlen(bk[i].lname)>20)
            {
                printf("\n\t\t\t\t Invalid :( \t The max range for Last name is 20\n");
                goto Bc;
            }
            printf("\n\n\t\t\t\t\t*************************( LAST NAME UPDATED )***************************\n\n");
            break;
        case 3:
Ab:
            fflush(stdin);
            printf("\t\t\t\tGender [M/F] :");
            gets(bk[i].gender);
            fflush(stdin);
            if(strcmp(bk[i].gender,male)==0 || strcmp(bk[i].gender,female)==0)
            {

            }
            else
            {
                printf("\n\t\t\t\tInvalid gender,Please enter again\n");
                goto Ab;
            }

            printf("\n\n\t\t\t\t\t*************************( GENDER UPDATED )***************************\n\n");
            break;
        case 4:

            fflush(stdin);
            printf("\t\t\t\tAge :");
            scanf("%d",&bk[i].age);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*************************( AGE UPDATED )***************************\n\n");
            break;
        case 5:
cd:
            fflush(stdin);
            printf("\t\t\t\tAddress :");
            gets(bk[i].address);
            fflush(stdin);
            if(strlen(bk[i].address)>20 || strlen(bk[i].address)<2)
            {
                printf("\n\t\t\t\t Invalid :( \t The max range for address is 20 and min range is 2 :)\n");
                goto cd;
            }
            printf("\n\n\t\t\t\t\t*************************( ADDRESS UPDATED )***************************\n\n");
            break;
        case 6:
            fflush(stdin);
            printf("\t\t\t\tPhone no. :");
            gets(bk[i].c_no);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*************************( PHONE NO. UPDATED )***************************\n\n");
            break;
        case 7:
            fflush(stdin);
            printf("\t\t\t\tEmail :");
            gets(bk[i].mail);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*************************( EMAIL UPDATED )***************************\n\n");
            break;
        case 8:
            fflush(stdin);
            printf("\t\t\t\tDisease :");
            gets(bk[i].problem);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*************************( DISEASE INFO UPDATED )***************************\n\n");
            break;
        case 9:
            fflush(stdin);
            printf("\t\t\t\tPrescribed Doctor :");
            gets(bk[i].doc);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t*************************( DOCTOR'S INFO UPDATED )***************************\n\n");
            break;
        default:
            printf("\n\n\t\t\t\t\t************************Invalid selection has been made************************\n\n");
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t*********( RECORD NOT FOUND )*********\n\n");
        recordhead();
        printf("\n\t\t   **           ****           ****            **    **          ******         *****             ******           ****          ***\n\n\n\n\n\n");

    }
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}
//-------------------------------------------main menu--------------------------------------------
void menu()
{
    //Menu which Display first
    header();
    printf("\n\n\n               ");
    printf("\t\t\t                                    _______**********_______\n\n               ");
    printf("\t\t\t                                    1 - Add Patient Record\n\n               ");
    printf("\t\t\t                                    2 - Show Pateints Record\n\n               ");
    printf("\t\t\t                                    3 - Delete Patient Record\n\n               ");
    printf("\t\t\t                                    4 - Search Patient Record\n\n               ");
    printf("\t\t\t                                    5 - Edit Patient Record\n\n               ");
    printf("\t\t\t                                    6 - Exit\n\n               ");
    printf("\t\t\t                                    _______**********_______\n\n\n               ");
}

//-----------------------------------------record head------------------------------------------------
void recordhead()
{
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|  Id       First Name       Last Name      Gender   Age        Address         Contact        Email           Desease         Doctor       |\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
//-----------------------------------------program head------------------------------------------------
void header()
{
    printf("\t\t ___________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|                                                       THE KARF HOSPITAL                                                                   |\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|___________________________________________________________________________________________________________________________________________|\n\n\n");
}

//---------------------------------------login function------------------------------------------------
int login()
{
    int flag,i;
    char id[20];
    char password[20];
    char org_id[20]="1";
    char org_password[20]="1";
    header();
    printf("\t\t\t\t\t\t\t\tEnter Username & Password to log in\n\n\n");
    printf("\t\t\t\t\t\t\tUsername :");
    scanf("%s",&id);
    printf("\t\t\t\t\t\t\tPassword :");
    scanf("%s",&password);
    if(strcmp(id,org_id)==0 && strcmp(password,org_password)==0)
    {
        printf("\n\n\n\t\t         ----------------------------------------------------Login successful----------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\tPress Any key to continue....................");
        getch();
        system("cls");
        flag=0;
        return 1;

    }
    else
    {
        flag=1;
        printf("\n\n\t\t\t\t\t\t\t\tSorry! Wrong username & password\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\tPress Any to continue....................");
        getch();
        system("cls");
    }
    if(flag==1)
    {
        for(i=3; i>=0; i--)
        {
            header();
            printf("\t\t\t\t\t\t\t\tEnter Username & Password to log in\n\n\n");
            printf("\t\t\t\t\t\t\tUsername :");
            scanf("%s",&id);
            printf("\t\t\t\t\t\t\tPassword :");
            scanf("%s",&password);
            if(strcmp(id,org_id)==0 && strcmp(password,org_password)==0)
            {
                printf("\n\n----------------------------------------------------Login successful----------------------------------------------------\n\n\n\n");
                printf("\t\t\t\t\t\t\tPress Any key to continue....................");
                getch();
                system("cls");
                return 1;
                break;
            }
            else
            {
                if(i!=0)
                {
                    printf("\n\n\t\t\t\t\t\t\t\tSorry! Wrong username & password\n");
                    printf("\t\t\t\t\t\tYou have (%d) chances. Otherwise you will be out of program\n\n\n",i);

                }
                else
                {
                    printf("\n\n\n\t\t\t\t\t\t\t!!You Have entered wrong Username & Password Many times!!");
                    printf("\n\n\n\t\t\t\t\t\t\tPress Any key to exit....................");
                    getch();
                    flag=2;
                    break;
                }
                printf("\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
                getch();
                flag=2;
                system("cls");
            }
        }
    }
    if(flag==2)
    {
        system("cls");
        return 0;
    }
}
//----------------------------------------------starting page-------------------------------------------------------
void start()
{
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t###################################################################################################################\n");
    printf("\t\t\t\t#  _____________________________________________________________________________________________________________  #\n");
    printf("\t\t\t\t# | ___________________________________________________________________________________________________________ | #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                               WELCOME TO                                 ::                || #\n");
    printf("\t\t\t\t# ||             ::                   THE HOSPITAL MANAGEMENT SYSTEM                         ::                || #\n");
    printf("\t\t\t\t# ||             ::                          MADE BY: KUNWAR AHMAD                           ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||___________________________________________________________________________________________________________|| #\n");
    printf("\t\t\t\t# |_____________________________________________________________________________________________________________| #\n");
    printf("\t\t\t\t#                                                                                                                 #\n");
    printf("\t\t\t\t###################################################################################################################\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}
//--------------------------------------------- Exit Function----------------------------------------------------------
void ex_it()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t  _____________________________________________________________________________________________________________  \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                              THANK YOU                                                      | \n");
    printf("\t\t\t\t |                                            MADE BY: KUNWAR                                                  | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to exit....................");
    getch();
}
//---------------------------------------------------Main function-----------------------------------------------------
int main()
{
    struct Patients bk[100]= {{1,"Kunwar","Ahmad","M",20,"A1 LHR","923000123","xyz@mail.com","Fever","Dr Bravo"},
        {2,"Rana","Adeel","M",27,"A2 LHR","923000123","xyz@mail.com","Fever","Dr Khaled"},
        {3,"Fahad","Asif","M",18,"DHA LHR","923000123","xyz@mail.com","Flue","Dr Kamran"},
        {4,"Asif","Iqbal","M",20,"MT LHR","923000123","xyz@mail.com","Fever","Dr Khalil"},
        {5,"Alina","Ali","F",17,"DHA LHR","923000123","xyz@mail.com","Headache","Dr Khalil"},
        {6,"Tazeem","Ahmad","M",20,"JT LHR","923000123","xyz@mail.com","Fever","Dr Najma"},
        {7,"Bilal","Saeed","M",20,"TS LHR","923000123","xyz@mail.com","Fever","Dr Sumaira"},
        {8,"Rao","Asad","M",20,"GT LHR","923000123","xyz@mail.com","Fever","Dr Shahzad"},
        {9,"Agha","Khaan","M",20,"BT LHR","923000123","xyz@mail.com","Fever","Dr Bialwal"},
        {10,"Saleem","Ahmad","M",20,"GT LHR","923000123","xyz@mail.com","Fever","Dr Bhatti"},{0," "," "," ",0," "," "," "," "," "}
    };
    int select,log;
    char more;
    start();
    log=login();
    if(log==1)
    {
        do
        {
            menu();
            printf("Select any one =");
            scanf("%d",&select);
            system("cls");
            switch(select)
            {
            //Add
            case 1:
            {
                add(bk);
            }
            break;
            //display
            case 2:
            {
                display(bk);
            }
            break;

            //Delete
            case 3:
            {

                del(bk);
            }
            break;
            //Search
            case 4:
            {

                search(bk);
            }
            break;
            case 5:
                edit(bk);
                break;
            case 6:
                ex_it();
                break;
            //In case of wrong selection
            default:
            {
                system("cls");
                header();
                printf("\n\nt\t\t\t\t\t************************Invalid selection has been made************************\n\n");
                printf("\t\t\t\t\t\t\tPress Any to continue....................");
                getch();
                system("cls");

            }
            }
        }
        //condition to check how many times program run
        while(select!=6);
    }
    return 0;
}

