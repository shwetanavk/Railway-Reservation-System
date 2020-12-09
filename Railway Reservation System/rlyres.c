//error 1. Isn't checking the seats available in the class

#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
int enterchoice()     //To enter choice from the admin
{   int choise,i, a;
    textcolor(YELLOW);

    gotoxy(48,2);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=120;i++)
       printf("_");

    printf("\nSelect an option\n");
    printf("1. View Trains \n2. Book Tickets\n3. View Ticket\n4. Search Ticket No\n5. View All Bookings\n");
    printf("6. View Train Bookings\n7. Cancel Ticket\n8. Cancel Train\n9. Quit\n");

    printf("Enter Choice\t");
    scanf("%d",&a);
    return a;
}

 void add_trains()                    //to add all details of trains in file
 {
    FILE *fp;
    fp=fopen("d:\\MyProject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"346","HBJ","MUM",4500,3360} // same ticket no aa gaya hai
        };
        fp=fopen("d:\\MyProject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        //printf("File saved sucessfully");
        fclose(fp);
    }
    else
       {
      // printf(" ALREADY PRESENT");
        fclose(fp);
       }
}

void view_trains()                            //to view trains details
{   FILE *fp;
    clrscr();
    Train t;
    int i;
    textcolor(YELLOW);

    printf("Train no");
    gotoxy(24,1);
    printf("From");
    gotoxy(50,1);
    printf("to");
    gotoxy(74,1);
    printf("First AC Fare");
    gotoxy(106,1);
    printf("Second AC Fare\n");
    for(i=0;i<120;i++)
        printf("_");
        printf("\n");
    fp=fopen("d:\\MyProject\\alltrains.dat","rb");
    while(fread(&t,sizeof(Train),1,fp)==1)
    printf("  %s                   %s                      %s                          %d                            %d \n",t.train_no,t.from,t.to,t.fac_fare,t.sac_fare);
    fclose(fp);
    textcolor(WHITE);
    printf("Press any key to go back to main screen");
    getch();
    clrscr();

}


 int check_train_no(char *trainno)                 //to check wheather the following train no is present in database or not
 {
     FILE *fp;
     fp=fopen("d:\\MyProject\\alltrains.dat","rb");
     Train tr;
     while(fread(&tr,sizeof(tr),1,fp)==1)   //size of Train try it!   this also works hear
     {
        if( strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
     }

     fclose(fp);
     return 0;
 }


 Passenger* get_passenger_details()                //To get details of passenger
 {   clrscr();
     gotoxy(100,1);
     textcolor(LIGHTGREEN);
     printf("Press 0 to Exit");
     gotoxy(1,1);
     textcolor(YELLOW);
     //talking input for name
     printf("Enter Your Name: ");
     fflush(stdin);
     static Passenger psn;
     fgets(psn.p_name,20,stdin);
     char *pos;
     pos=strchr(psn.p_name,'\n');
     *pos ='\0';
     if(strcmp(psn.p_name,"0")==0)
     {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("Reservation Cancel");
         getch();
         clrscr();
         textcolor(YELLOW);
         return NULL ;

     }

      //talking input for gender
      int valid;
      printf("Enter Gender(M/F): ");
      do
      {
          valid=1;
          fflush(stdin);
          scanf("%c",&psn.gender);
      if(psn.gender=='0')
      {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("Reservation Cancel");
         getch();
         //clrscr();
         textcolor(YELLOW);
         return NULL ;
      }

      if(psn.gender!='M'&&psn.gender!='F')
      {

         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("Error! Gender should be male(M) or female(F).(IN UPPERCASE)");
         valid=0;
         getch();
         //printf("\r                                                                   ");
         textcolor(YELLOW);
         gotoxy(20,2);
         printf("    \b\b\b\b");

         //exit(0);
         //return NULL ;
      }
      }while(valid==0);
      gotoxy(1,25);
      printf("\t\t\t\t\t\t\t\t\t\t\t");

     //taiking input for train no

      gotoxy(1,3);
      printf("Enter Train Number: ");
      do
      {
       fflush(stdin);
      scanf("%s",&psn.train_no);
      if(strcmp(psn.train_no,"0")==0)
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("Reservation Cancel");
         getch();
         //clrscr();
         textcolor(YELLOW);
         return NULL ;
      }


            valid= check_train_no(psn.train_no);
            if(valid==0)
              {
                  gotoxy(1,25);
                  textcolor(LIGHTRED);
                  printf("Error! Following Train Number does not exist. Try Again!");
                  getch();
                  //gotoxy(20,3);
                  gotoxy(21,3);
                  printf("\t\t\t\t\t\t              ");
                  //clrscr();
                  textcolor(YELLOW);
                  gotoxy(21,3);
                  //printf("     \b\b \b\b\b\b");
                 // exit(0) ;

              }
      }while(valid==0);
      gotoxy(1,25);
      printf("\t\t\t\t\t\t\t");


      gotoxy(1,4);
      //talking input for travelling class;
      printf("Enter Travelling Class(First AC-F,Second AC-S): ");
      do
      { valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("\t\t\t\t\t\t\t");
           gotoxy(1,25);
           printf("Reservation Cancel");
           getch();
           //clrscr();
           textcolor(YELLOW);
           return NULL ;
       }
        if(psn.p_class!='F'&&psn.p_class!='S')
       {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("Class should be First AC(F) or Second AC(S).(In UPPERCASE(F/S)");
         valid=0;
         getch();
        // printf("\r                                                                      ");
         textcolor(YELLOW);
         gotoxy(49,4);
         printf("    \b\b\b\b");
      }
      }while(valid==0);

      gotoxy(1,25);
      printf("\t\t\t\t\t\t\t\t\t\t\t\t");



      //input for address
      gotoxy(1,5);
      printf("Enter address: ");
      fflush(stdin);
      fgets(psn.address,20,stdin);
      pos=strchr(psn.address,'\n');
      *pos='\0';
      if(strcmp(psn.address,"0")==0)
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("Reservation Cancel");
         getch();
         clrscr();
         textcolor(YELLOW);
         return NULL ;
      }

      //input for age
      printf("Enter age: ");
      do
      { valid=1;
      fflush(stdin);
      scanf("%d",&psn.age);
      if(psn.age=='0')
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("Reservation Cancel");
         getch();
         //clrscr();
         textcolor(YELLOW);
         return NULL ;
      }

      if(psn.age<0)
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("Age can't be negative.");
         valid=0;
         getch();
         printf("\r                                        ");
         textcolor(YELLOW);
         gotoxy(12,6);
         printf("    \b\b\b\b");
      }
      }while(valid==0);
      gotoxy(1,25);
      printf("\t\t\t\t\t\t\t");




      //input for mobile no
      gotoxy(1,7);
      printf("Enter Mobile no: ");
//      int valid;
      do
      {
          fflush(stdin);
          fgets(psn.mob_no,11,stdin);
          pos=strchr(psn.mob_no,'\n');
          if(pos!=NULL)
            *pos='\0';
     if(strcmp(psn.mob_no,"0")==0)
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("Reservation Cancel");
         getch();
         clrscr();
         textcolor(YELLOW);
         return NULL ;
      }
     // int valid;
      valid=check_mob_no(psn.mob_no);
      if(valid==0)
      {
         gotoxy(1,25);
         textcolor(LIGHTRED);
         printf("error wrong mob no!");
         getch();
         gotoxy(17,7);
         printf("\t\t\t\t\t\t\t\t\t\t       ");
         textcolor(YELLOW);
         gotoxy(17,7);
         printf("             \b\b\b\b\b\b\b\b\b\b\b\b");
      }
      }while(valid==0);
      return &psn;

 }



 int check_mob_no(char* p_mob)
 {
     if(strlen(p_mob)!=10)
        return 0;
     while(*p_mob!='\0')
     {
         if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
     }
     return 1;
 }


 int get_booked_ticket_count(char* train_no,char tc)
 {

    FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");
    if(fp==NULL)
    return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
     {
        if( strcmp(pr.train_no,train_no)==0 && pr.p_class==tc )
            ++count;
     }

    fclose(fp);
    return count;
}

int last_ticket_no()
{
   FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}


int book_ticket(Passenger p)
{
    int tickeet_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(tickeet_count==2)
    {
        textcolor(LIGHTRED);
        printf("All seats full in train no %s in %c class!\n",p.train_no,p.p_class);
        return -1;
    }

    int ticket_no= last_ticket_no() +1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("d:\\MyProject\\allbooking.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}


 int accept_ticket_no()              //for view train case 3
 {
       printf("Enter ticket no:  ");
       int valid;
       int ticket_no;
       do
       {
           valid=1;
           scanf("%d",&ticket_no);
           if(ticket_no==0)
           {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("\t\t\t\t\t\t\t");
               gotoxy(1,25);
               printf("Cancelling Input. . .!");
               textcolor(YELLOW);
               return 0;
           }
           if(ticket_no<0)
           {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error! Ticket number should be positive");
               valid=0;
               getch();
               gotoxy(19,1);
               printf("\t\t\t\t\t\t\t");
               gotoxy(19,1);
               textcolor(YELLOW);
           }
       } while(valid==0);
       return ticket_no;
}


void view_ticket(int ticket_no)
{
    FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");//d:\\MyProject\\allbooking.dat"
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }

    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
    if(pr.ticketno==ticket_no)
    {

       printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
       printf("\n\n");
      found=1;
      break;
    }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of ticket no %d found!",ticket_no);

    }
    fclose(fp);
    //return 0;
}

int cancel_ticket(int ticket_no)
{

  FILE *fp1=fopen("d:\\MyProject\\allbooking.dat","rb+");
  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2=fopen("d:\\MyProject\\temp.dat","wb+");
  Passenger pr;
  int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(pr.ticketno!=ticket_no)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\MyProject\\temp.dat");
    }
    else
    {
        remove("d:\\MyProject\\allbooking.dat");
        rename("d:\\MyProject\\temp.dat","d:\\MyProject\\allbooking.dat");

    }

return found;
}



//cancel train

char * accept_train_no()
{
static char train_no[10];
int valid;
printf("Enter train number:");
            do
            {
            fflush(stdin);
            scanf("%s",train_no);
            if(strcmp(train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelling Input. . .!");
                textcolor(YELLOW);
                return NULL;
            }
            valid=check_train_no(train_no);
            if(valid==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);

            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);

            }
            }while(valid==0);
clrscr();
return train_no;
}


int cancel_train(char *ptrain_no)
{
  FILE *fp1=fopen("d:\\MyProject\\allbooking.dat","rb+");
  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2=fopen("d:\\MyProject\\temp.dat","wb+");
  Passenger pr;
  int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(strcmp(pr.train_no,ptrain_no)!=0)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\MyProject\\temp.dat");
    }
    else
    {
        remove("d:\\MyProject\\allbooking.dat");
        rename("d:\\MyProject\\temp.dat","d:\\MyProject\\allbooking.dat");

    }

return found;
}

char* accept_mob_no()
{
static char mob_no[11];
char *pos;
int valid;
printf("Enter mobile number:");
do
{
fflush(stdin);
fgets(mob_no,11,stdin);
pos=strchr(mob_no,'\n');
if(pos!=NULL)
   *pos='\0';
if(strcmp(mob_no,"0")==0)
{
  textcolor(LIGHTRED);
  gotoxy(1,25);
  printf("\t\t\t\t\t\t\t");
  gotoxy(1,25);
  printf("Cancelling Input. . .!");
  getch();
  textcolor(YELLOW);
  return NULL;
}
valid=check_mob_no(mob_no);
if(valid==0)
  {
   textcolor(LIGHTRED);
   gotoxy(1,25);
   printf("Error! Invalid Mobile No");
   getch();
   gotoxy(21,1);
   printf("\t\t\t\t\t\t");
   gotoxy(21,1);
   textcolor(YELLOW);
  }
 }while(valid==0);
clrscr();
return mob_no;
}


int* get_ticket_no(char *p_mob_no)
{
   int count=0;
   FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");
   if(fp==NULL)
    {
        return NULL;
    }
   Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticketno;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}

void view_all_tickets(char *pmob_no,int *pticket_no)
{    Passenger pr;
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO \n ");
    printf("-------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d ",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
getch();
}

//Assignment

void view_booking(char* train_no)
{  int j=0,i;
     FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");//d:\\MyProject\\allbooking.dat"
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }

    Passenger pr;
    int found=0;
    int n=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
    if(strcmp(pr.train_no,train_no)==0)
    {
        if(j==0)
        {printf("TICKET NO \t\t    CLASS\t\tNAME  \t\tGENDER\t\t  AGE\t\t MOBILE NO \n");
         for(i=1;i<=120;i++)
          printf("_");

        j++;
        };

        gotoxy(1,n);
        printf("%d",pr.ticketno);
        gotoxy(30,n);
        printf("%c",pr.p_class);
        gotoxy(47,n);
        printf("%s",pr.p_name);
         gotoxy(67,n);
        printf("%c",pr.gender);
         gotoxy(83,n);
        printf("%d",pr.age);
         gotoxy(98,n);
        printf("%s",pr.mob_no);
        printf("\n");
         found=1;
      n++;

    }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of train no %s found!",train_no);

    }
    fclose(fp);
    //return 0;
}


void view_all_bookings()
{
      int j=0,i;
     FILE *fp=fopen("d:\\MyProject\\allbooking.dat","rb");//d:\\MyProject\\allbooking.dat"
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }

    Passenger pr;
    int found=0;
    int n=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
  //  if(strcmp(pr.train_no,train_no)==0)
    {
        if(j==0)
        {printf("TICKET NO        TRAIN NO\t\tCLASS\t\tNAME  \t\t   GENDER\t    AGE\t\t MOBILE NO \n");
         for(i=1;i<=120;i++)
          printf("_");

        j++;
        };

        gotoxy(5,n);
        printf("%d",pr.ticketno);
        gotoxy(20,n);
        printf("%s",pr.train_no);
        gotoxy(43,n);
        printf("%c",pr.p_class);
        gotoxy(53,n);
        printf("%s",pr.p_name);
         gotoxy(77,n);
        printf("%c",pr.gender);
         gotoxy(93,n);
        printf("%d",pr.age);
         gotoxy(102,n);
        printf("%s",pr.mob_no);
        printf("\n");
         found=1;
      n++;

    }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of train no %s found!");

    }
    fclose(fp);
    getch();
    clrscr();
}



