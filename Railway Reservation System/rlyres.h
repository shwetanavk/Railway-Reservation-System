#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;

};
struct Passenger
{
   char p_name[20];
   char gender;
   char address[20];
   int age;
   char train_no[20];
   char p_class;
   int ticketno;
   char mob_no[11];
};
 typedef struct Train Train;
 typedef struct Passenger Passenger;

int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
int* get_ticket_no(char*);
void view_ticket(int); //to view ticket
void view_all_bookings();
void view_booking(char*);
int cancel_ticket(int);
int cancel_train(char*);

int check_train_no(char *);
Passenger* get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
int accept_ticket_no();
char* accept_train_no();
char* accept_mob_no();
int* get_ticket_no(char *);
void view_all_tickets(char *,int *);




#endif // RLYRES_H_INCLUDED
