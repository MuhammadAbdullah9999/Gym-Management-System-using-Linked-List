#include<stdio.h>
#include<windows.h>
#include<conio.h>
//#include<stdin.h>

struct user{
    int fee;
    int id;
    char subType[10];
    char name[100];
    char cnic[100];
    char phoneNumber[100];
    char password[100];
    char feeStatus[10];
    struct user *prev;
    struct user *next;
};
struct user *start=NULL;

struct user *user;

int subType;

void Registration(){

    SYSTEMTIME t;
    GetLocalTime(&t);

    int time,feeStatus;


    user=malloc(sizeof(struct user));

    if(start==NULL){
        start=user;
        start->next=NULL;
    }

    else{

    struct user *p;
    p=start;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=user;
    user->next=NULL;

    }

    printf("Enter the name:\n");
    fflush(stdin);
    gets(user->name);

    fflush(stdin);
    printf("\nEnter the phone number\n");
    gets(user->phoneNumber);

    printf("\nEnter the CNIC\n");
    gets(user->cnic);

    printf("\nEnter the password\n");
    gets(user->password);

    printf("\nSelect the subscription type\n1.montly\t\t2000\n2.yearly\t\t24000\n");
    scanf("%d",&subType);

    if(subType==1){
        user->fee=2000;
        strcpy(user->subType,"Monthly");
        fflush(stdin);
    }
    else if(subType==2){
        user->fee=24000;
         strcpy(user->subType,"Yearly");
    }
    printf("\n1.Pay fee now\n2.Later\n");
    scanf("%d",&feeStatus);

    if(feeStatus==1){
        printf("\nFee paid successfully!!!\n\n");
        strcpy(user->feeStatus,"Paid");
         //user->feeStatus[100]="paid";
    }
    else if(feeStatus==2){
        printf("\nFee not paid!!!\n\n");
        strcpy(user->feeStatus,"Not Paid");
        //user->feeStatus[100]="{Not paid}";
    }

 
    printf("-----------------------------------------------------------------------------------------------------\n");
         printf("Name: %s\n",user->name);
         printf("Phone number: %s\n",user->phoneNumber);
         printf("CNIC: %s\n",user->cnic);
         printf("Password: %s\n",user->password);
         printf("Fee: %d\n",user->fee);
         printf("Fee status: %s\n",user->feeStatus);
         printf("Subscription type: %s\n",user->subType);
         printf("-----------------------------------------------------------------------------------------------------");

      if(subType==1){
 
    printf("\nMembership Start Date %d-%d-%d\n",t.wDay,t.wMonth,t.wYear);
    printf("Membership End Date %d-%d-%d\n",t.wDay,t.wMonth+1,t.wYear);
    }
    else if(subType==2){
      printf("\nMembership Start Date%d-%d-%d\n",t.wDay,t.wMonth,t.wYear);
      printf("Membership End Date%d-%d-%d\n",t.wDay,t.wMonth,t.wYear+1);
   
    }
    printf("\n");

}

void ExistingUser(struct user *user){

    int flag=0;

        SYSTEMTIME t;
    GetLocalTime(&t);

    char pswd[100], cnic[100];
    int choice;
    char fee[100]="Paid";

    printf("Enter the password\n");
   fflush(stdin);
    gets(pswd);

    printf("Enter the CNIC\n");
    gets(cnic);


    struct user *q;
    int value , value1;

    q=start;
    while(q!=NULL){

            value =strcmp(pswd , q->password);
            value1= strcmp(cnic , q->cnic);
        if(value ==0 && value1==0){
 printf("-----------------------------------------------------------------------------------------------------\n");
         printf("Name: %s\n",user->name);
         printf("Phone number: %s\n",user->phoneNumber);
         printf("CNIC: %s\n",user->cnic);
         printf("Password: %s\n",user->password);
         printf("Fee: %d\n",user->fee);
         printf("Fee status: %s\n",user->feeStatus);
         printf("Subscription type: %s\n",user->subType);
         printf("-----------------------------------------------------------------------------------------------------");


    if(subType==1){
  printf("\nMembership Start Date %d-%d-%d\n",t.wDay,t.wMonth,t.wYear);
    printf("Membership End Date %d-%d-%d\n",t.wDay,t.wMonth+1,t.wYear);

    }
    else if(subType==2){
      printf("\nMembership Start Date%d-%d-%d\n",t.wDay,t.wMonth,t.wYear);
      printf("Membership End Date%d-%d-%d\n",t.wDay,t.wMonth,t.wYear+1);
    }
     flag=1;
do{
     printf("\nEnter the operation to perform\n");
     printf("1.Edit name");
     printf("\n2.Edit Phone Number");
     printf("\n3.Reset Password");
     printf("\n4.Pay fee");
     printf("\n0.Exit\n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
        printf("Enter the name\n");
        fflush(stdin);
        gets(q->name);
        break;

        case 2:
            printf("Enter the new Phone Number\n");
             fflush(stdin);
            gets(q->phoneNumber);
            break;

        case 3:
            printf("Enter the new Password\n");
            fflush(stdin);
            gets(q->password);
            break;

        case 4:
            value=strcmp(fee,q->feeStatus);
            if(value==0){
                printf("The fee is already paid\n");
            }
            else{
                printf("Fee paid Successfully\n");
                strcpy(q->feeStatus,"Paid");
            }
            break;

        case 0:
            return;

        default:
            printf("...Invalid Entry...\n");
    }
        }while(choice!=0);
        }
        q=q->next;
    }
    if (flag==0){
            printf("User Not found\n");
    }
}
void display(){
    struct user *q;

    if(start==NULL){
        printf("The list is Empty\n");
    }

    SYSTEMTIME t;
    GetLocalTime(&t);

    q = start;

    while(q != NULL){
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("Name: %s\n", q->name);
        printf("Phone number: %s\n", q->phoneNumber);
        printf("CNIC: %s\n", q->cnic);
        printf("Password: %s\n", q->password);
        printf("Fee: %d\n", q->fee);
        printf("Fee status: %s\n", q->feeStatus);
        printf("Subscription type: %s\n", q->subType);
        printf("-----------------------------------------------------------------------------------------------------");

        if(subType == 1){
            printf("\nMembership Start Date %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
            printf("Membership End Date %d-%d-%d\n", t.wDay, t.wMonth + 1, t.wYear);
        }
        else if(subType == 2){
            printf("\nMembership Start Date %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
            printf("Membership End Date %d-%d-%d\n", t.wDay, t.wMonth, t.wYear + 1);
        }

        q = q->next;
    }
}

void search_by_name(){
    SYSTEMTIME t;
    GetLocalTime(&t);

    char name[100];
    int flag = 0;

    printf("Enter the name of member to search\n");
    scanf("%s", name);

    struct user *p = start;

    while (p != NULL) {
        if (strcmp(name, p->name) == 0) {
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("Name: %s\n", p->name);
            printf("Phone number: %s\n", p->phoneNumber);
            printf("CNIC: %s\n", p->cnic);
            printf("Password: %s\n", p->password);
            printf("Fee: %d\n", p->fee);
            printf("Fee status: %s\n", p->feeStatus);
            printf("Subscription type: %s\n", p->subType);
            printf("-----------------------------------------------------------------------------------------------------");

            if (subType == 1) {
                printf("\nMembership Start Date %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
                printf("Membership End Date %d-%d-%d\n", t.wDay, t.wMonth + 1, t.wYear);
            } else if (subType == 2) {
                printf("\nMembership Start Date%d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
                printf("Membership End Date%d-%d-%d\n", t.wDay, t.wMonth, t.wYear + 1);
            }

            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag == 0) {
        printf("The member not found\n");
    }
}

void del(){
    struct user *p,*q;
    int count=1;
    int val;

    char name[100];


    printf("Enter the name to delete\n");
    fflush(stdin);
    scanf("%s",&name);

    p=start;
    q=p;
    while(p!=NULL){

        if(val=strcmp(name,p->name)==0){
            if(strcmp(start->name,name)==0)
            {
                start=start->next;
                free(p);
            }
            else
            {
                q->next=p->next;
                free(p);
            }
            printf("The user is Successfully Deleted\n\n");
            break;
        }
        q=p;
        p=p->next;

    }
}
void check_fee(){
    struct user *p;

    int value;
    int flag=0;
    p=start;

    while(p!=NULL){

        value=strcmp(p->feeStatus,"Not Paid");

        if(value==0){

            printf("\t%s\t\t%s","Name","CNIC");
            printf("\n\t%s\t%s",p->name,p->cnic);
            flag=1;
        }

        p=p->next;
    }
     if(flag==0){
            printf("No such Members found\n");
        }

}
void count_member()
{
    int count=0;
    struct user *p;
    p=start;
    while(p!=NULL){
        count=count+1;
        p=p->next;
    }
    printf("There are %d Members currently registered in this GYM\n",count);
}

void admin(){

    int choice;
    do{

        printf("\n\nEnter the operation to perform\n");
        printf("\n1.Display the list of members");
        printf("\n2.Search member by name");
        printf("\n3.Delete a User");
        printf("\n4.Check how many members of GYM");
        printf("\n5.Check which Member has not pay fee");
        printf("\n0.Exit\n\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                display();
            break;

            case 2:
                search_by_name();
            break;

            case 3:
                del();
                break;

            case 4:
                count_member();
                break;

            case 5:
                check_fee();
                break;

            case 0:
                return;

            default:
                printf("....Invalid Entry....");
                break;
    }
    }while(choice!=0);
}

int main(){

    int choice,choice1;

    printf("\t\t\t\t\t--------------GYM MANAGEMENT SYSTEM--------------\n\n\n");
    do{
    printf("\t\t\t\t\tEnter the choice\n\t\t\t\t\t");
    printf("1.SignUp as new User\n\t\t\t\t\t");
    printf("2.Login as a Existing user\n\t\t\t\t\t");
    printf("3.Login as a Admin\n\t\t\t\t\t");
    printf("0.Exit\n\n\n");
    scanf("%d",&choice);

    switch(choice){

case 1:
     Registration();
     break;
case 2:
    ExistingUser(user);
    break;
case 3:

    admin();
    break;
    default:
        printf("Invalid entry\n");

    }
}while(choice!=0);
}
