#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h""

int main()
{   add_trains();

    int choice,result;
    int ticket_no;
    Passenger *ptr;
    char *ptrain_no;
    char *pmob_no;
    int *pticktet_no;



    int train_no;

while(1)
{
     choice= enterchoice();
        if(choice==9)
       {
           exit(0);
       }
    switch(choice)
    {
          case 1:
               view_trains();
               break;

          case 2:
               ptr=get_passenger_details();
               clrscr();
               if(ptr!=NULL)
               {
                   ticket_no=book_ticket(*ptr); //value at ptr
                   if(ticket_no==-1)
                   {
                       textcolor(LIGHTRED);
                       printf("Booking Failed");
                   }
                   else
                   {
                      textcolor(LIGHTGREEN);
                       printf("Ticket Sucessfully Booked.\n Your Ticket no is %d ",ticket_no);
                   }

               }

               getch();
               clrscr();
               break;

          case 3:
               clrscr();
               gotoxy(100,1);
               textcolor(LIGHTGREEN);
               printf("Press 0 to Exit");
               gotoxy(1,1);
               textcolor(YELLOW);
               ticket_no=accept_ticket_no();
               if(ticket_no!=0)
                   view_ticket(ticket_no);
               textcolor(WHITE);
               printf("\nPress any key to go back to the main screen");
               getch();
               clrscr();
               break;

          case 4:
               clrscr();
               int *pticket_no;
               pmob_no=accept_mob_no();
               if(pmob_no!=NULL)
               {
                   pticket_no=get_ticket_no(pmob_no);
                   view_all_tickets(pmob_no,pticket_no);
               }
            clrscr();

               break;
          case 5:
               clrscr();
              view_all_bookings();
               break;
          case 6:
               clrscr();
               gotoxy(100,1);
               textcolor(LIGHTGREEN);
               printf("Press 0 to Exit");
               gotoxy(1,1);
               textcolor(YELLOW);
               ptrain_no=accept_train_no();
               if(ptrain_no!='0')
                   view_booking(ptrain_no);
               textcolor(WHITE);
               printf("\nPress any key to go back to the main screen");
               getch();
               clrscr();

               break;
          case 7:
            clrscr();
            gotoxy(100,1);
            textcolor(LIGHTGREEN);
            printf("Press 0 to Exit");
            gotoxy(1,1);
            textcolor(YELLOW);
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                {
                    result=cancel_ticket(ticket_no);
                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked against ticket no %d",ticket_no);

                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Ticket no %d successfully cancelled!",ticket_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");

             }

            getch();
            clrscr();
            break;

          case 8:
            clrscr();
             gotoxy(100,1);
            textcolor(LIGHTGREEN);
            printf("Press 0 to Exit");
            gotoxy(1,1);
            textcolor(YELLOW);
            train_no=accept_train_no();
            if(train_no!=NULL)
            {
                result=cancel_train(train_no);
                if(result==0)
                  {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked in train no. %s",ptrain_no);

                    }
                    else
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no %s successfully cancelled!",ptrain_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");

            }


            getch();
            clrscr();
            break;

          default:
               textcolor(LIGHTRED);
               printf("Wrong choice! Try again\n");
               getch();
               clrscr();
    }
}


return 0;
}
