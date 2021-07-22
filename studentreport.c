#include<stdio.h>
struct student
{
int rollno;
char name[80];
int math,eng,chem,phy,comp,dob;
char gender;
char fname[20],mname[20];
};
void accept(struct student[],int);
void display(struct student[],int);
void search(struct student[],int,int);
int maxNumber(struct student[],int);
int calculate(struct student[],int);
int maxPercentage(struct student[],int);
void topper(struct student[],int);
void PF(struct student[],int,int);
void Grade(struct student[],int);
void Modify(struct student[],int);
void delete(struct student[],int);
void personal(struct student[],int);

int main()
{
struct student data[20];
int n ,choice,rollno,math,eng,chem,phy,comp;
printf("\t\t\t\t\tSTUDENT REPORT CARD HANDELING SYSTEM\n");
printf("\t\t\t\t\t\tMINI PROJECT\n");
printf("SUBMITTED BY : DARSHITA GUPTA\t\t\t\t\t\t\tB.TECH CSE(2019-2023)\n\n");
printf("*********************************************************************************************************************\n");
printf("NUMBER OF RECORDS TO BE ENTER    ");
scanf("%d",&n);
accept(data,n);

do
{
printf("\nRESULT MENU \n");
printf("PRESS 1 TO DISPLAY ALL RECORDS\n");
printf("PRESS 2 TO SEARCH A RECORD \n");
printf("PRESS 3 TO KNOW THE MAXIMUM NUMBER \n");
printf("PRESS 4 TO FIND AND DISPLAY THE TOTAL AND PERCENTAGE OF THE STUDENT\n ");
printf("PRESS 5 TO KNOW WHO TOPPED THE CLASS\n");
printf("PRESS 6 TO KNOW THE HIGHEST PERCENTAGE\n");
printf("PRESS 7 TO KNOW THE STUDENT IS PASSED 0R FAILED\n");
printf("PRESS 8 TO KNOW GRADE OF ALL STUDENTS\n");
printf("PRESS 9 TO MODIFY ANY DETAIL\n");
printf("PRESS 10 TO DELETE A RECORD\n");
printf("PRESS 11 TO SAVE AND DISPLAY PERSONAL INFORMATION\n");
printf("PRESS 0 TO EXIT\n");
printf("*********************************************************************************************************************\n");
printf("ENTER YOUR CHOICE PLEASE\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
    display(data,n);
    printf("*********************************************************************************************************\n");
    break;
case 2:
    printf("ENTER ROLL NUMBER TO SEARCH");
    scanf("%d",&rollno);
    search(data,n,rollno);
    printf("**********************************************************************************************************\n");
    break;
case 3 :
    maxNumber(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 4 :
    calculate(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 5 :
    topper(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 6 :
    maxPercentage(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 7 :
    printf("ENTER ROLL NUMBER TO FIND OUT WHETHER THE STUDENT IS PASSED OR FAILED\n");
    scanf("%d",&rollno);
    PF(data,n,rollno);
    printf("**********************************************************************************************************\n");
    break;
case 8 :
    Grade(data,n);
    break;
    printf("**********************************************************************************************************\n");
case 9 :
    Modify(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 10 :
    delete(data,n);
    printf("**********************************************************************************************************\n");
    break;
case 11 :
    personal(data,n);
    printf("**********************************************************************************************************\n");
    break;
}
}
while(choice != 0);
return 0;
}

void accept(struct student list[80],int s)
{
int i;
for(i=0;i<s;i++)
{
printf("\nENTER DATA TO RECORD #%d",i+1);
printf("\nENTER ROLL NO.:  ");
scanf("%d", &list[i].rollno);
fflush(stdin);
printf("ENTER NAME:   ");
gets(list[i].name);
printf("ENTER MARKS OF MATHS:  ");
scanf("%d",&list[i].math);
printf("ENTER MARKS OF ENGLISH:   ");
scanf("%d",&list[i].eng);
printf("ENTER MARKS OF CHEMISTRY:   ");
scanf("%d",&list[i].chem);
printf("ENTER MARKS OF PHYSICS:   ");
scanf("%d",&list[i].phy);
printf("ENTER THE MARKS OF COMPUTER SCIENCE:    ");
scanf("%d",&list[i].comp);
}
}

int calculate(struct student list[80],int s)
{
int i,total=0;
float percentage;
printf("\n\nRollno\tName\tTotal\tPercentage\n");
for(i=0;i<s;i++)
{
total=list[i].math+list[i].eng+list[i].chem+list[i].phy+list[i].comp;
percentage=total/5;
printf("%d\t%s\t%d\t%f\n",list[i].rollno,list[i].name,total,percentage);
}
return total;
}

void display(struct student list[80],int s)
{
int i;
printf("\n\nRollno\tName\tMaths\tEnglish\tChemistry\tPhysics\tComputer\n");
for(i=0;i<s;i++)
{
printf("%d\t %s\t  %d\t %d\t %d\t          %d\t  %d\n",
list[i].rollno,list[i].name,list[i].math,list[i].eng,list[i].chem,list[i].phy,list[i].comp);


}
}

void search(struct student list[80],int s,int number)
{
int i;
for(i=0;i<s;i++)
{
if(list[i].rollno==number)
{
printf("Rollno : %d\nName : %s\nMaths : %d\nEnglish : %d\nChemistry : %d\nPhysics : %d\nComputer : %d\n",
list[i].rollno, list[i].name,list[i].math, list[i].eng, list[i].chem, list[i].phy, list[i].comp);
return;
}
}
printf("RECORD NOT FOUND\n");
}

int maxNumber(struct student list[80],int s)
{
int i,t=0;
int max=0;
for(i=0;i<s;i++)
{
t=list[i].math+list[i].eng+list[i].chem+list[i].phy+list[i].comp;
if(t>max)
{
max=t;
}
}
printf("THE MAXIMUM NUMBER IS :  %d\n",max);
return max;
}

int maxPercentage(struct student list[80],int s)
{
    int i,t=0;
    float maxp=0;
    float p;
    for(i=0;i<s;i++)
    {
        t=list[i].math+list[i].eng+list[i].chem+list[i].phy+list[i].comp;
        p=t/5;

    if(p>maxp)
    {
        maxp=p;
    }
    }
    printf("THE HIGHEST PERCENTAGE IS :   %f\n",maxp);
return maxp;
}

void topper(struct student list[80],int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        if((list[i].math+list[i].eng+list[i].chem+list[i].phy+list[i].comp)==maxNumber(list,s))
        {
        printf("THE PROUD TOPPER IS  %s\n",list[i].name);

    }
    }
}

void PF(struct student list[80],int s,int number)
{
    printf("TO PASS THE EXAM THE STUDENT MUST PASS ALL THE SUBJECTS \n");
    int i;
    for(i=0;i<s;i++)
    {
        if(list[i].rollno==number)
        {
            if((list[i].math>=33)&&(list[i].eng>=33)&&(list[i].chem>=33)&&(list[i].phy>=33)&&(list[i].comp>=33))
            {
                printf("PASSED\n");
                printf("CONGRATULATIONS,IT SEEMS LIKE U REALLY WORED HARD,KEEP WORKING HARD.\n ALL THE BEST\n");
            }
            else
                {
                printf("FAILED\n");
            printf("DONT LOOSE HOPE AT ALL WORK MORE HARD AND YOU WILL DEFINITELY BE SUCCESSFUL IN LIFE\n ALL THE BEST");
            }
        }
    }
}

void Grade(struct student list[],int s)
{
    int i,t=0;
    float p;
    char grade;
    for(i=0;i<s;i++)
    {
       t=list[i].math+list[i].eng+list[i].chem+list[i].phy+list[i].comp;
       p=t/5;
        if(p<50)
        {
            grade='F';
        }
        else if((p>=50)&&(p<60))
        {
            grade='D';
        }
        else if((p>=60)&&(p<70))
        {
            grade='C';
        }
        else if((p>=70)&&(p<80))
        {
            grade='B';
        }
        else if((p>=80)&&(p<90))
        {
            grade='A';
        }
        else if((p>=90)&&(p<100))
        {
            grade='+';
        }
        printf("Rollno : %d\nName : %s\nGrade   :%c\n",list[i].rollno, list[i].name,grade);
}
}

void Modify(struct student list[],int s)
{
int i,n,rn,new;
printf("ENTER WHAT YOU WANT TO MODIFY\n PRESS 1 FOR MATHS MARKS\n2 FOR ENGLISH MARKS\n3 FOR CHEMISTRY MARKS\n4 FOR PHYSICS MARKS\n5 FOR COMPUTER MARKS\n");
scanf("%d",&n);
if(n==1)
{
printf("ENTER ROLL NO OF THAT STUDENT\n");
scanf("%d",&rn);
for(i=0;i<s;i++)
{
if(rn==list[i].rollno)
{
printf("ENTER THE NEW MARKS OF MATHS\n");
scanf("%d",&new);
list[i].math=new;
}
}
}
else if(n==2)
{
    printf("ENTER ROLL NO OF THAT STUDENT\n");
scanf("%d",&rn);
for(i=0;i<s;i++)
{
if(rn==list[i].rollno)
{
printf("ENTER THE NEW MARKS OF ENGLISH\n");
scanf("%d",&new);
list[i].eng=new;
}
}
}
else if(n==3)
{
    printf("ENTER ROLL NO OF THAT STUDENT\n");
scanf("%d",&rn);
for(i=0;i<s;i++)
{
if(rn==list[i].rollno)
{
printf("ENTER THE NEW MARKS OF CHEMISTRY\n");
scanf("%d",&new);
list[i].chem=new;
}
}
}
else if(n==4)
{
   printf("ENTER ROLL NO OF THAT STUDENT\n");
scanf("%d",&rn);
for(i=0;i<s;i++)
{
if(rn==list[i].rollno)
{
printf("ENTER THE NEW MARKS OF PHYSICS\n");
scanf("%d",&new);
list[i].phy=new;
}
}
}
else if(n==5)
{
    printf("ENTER ROLL NO OF THAT STUDENT\n");
scanf("%d",&rn);
for(i=0;i<s;i++)
{
if(rn==list[i].rollno)
{
printf("ENTER THE NEW MARKS OF COMPUTER\n");
scanf("%d",&new);
list[i].comp=new;
}
}
}
}

void delete(struct student list[80],int s)
{
    int i,rn;
    printf("ENTER THE ROLL NO TO DELETE A RECORD \n");
    scanf("%d",&rn);
    for(i=0;i<s;i++)
    {
        if(list[i].rollno==rn)
        {
            list[i]=list[i+1];
            }
        }
        display(list,s-1);
    }

    void personal(struct student list[],int s)
    {
        char gender,fname[60],mname[60];
        int i,dob=0,n;
        for(i=0;i<s;i++)
        {fflush(stdin);

        printf("ENTER FATHER'S NAME\n");
        gets(list[i].fname);
        printf("ENTER MOTHER'S NAME\n");
        gets(list[i].mname);
        printf("ENTER GENDER OF THE STUDENT\n");
        scanf("%c",&list[i].gender);
        printf("ENTER DATE OF BIRTH OF STUDENT IN YYYYMMDD FORMAT\n");
        scanf("%d",&list[i].dob);
        }
        printf("DO YOU WANT TO SEE THE PERSONAL INFO, PRESS 1 FOR YES AND 2 FOR NO\n");
        scanf("%d",&n);
        if(n==1)
        {
            for(i=0;i<s;i++){
            printf("FATHER'S NAME\tMOTHER'S NAME\tGENDER\tDOB\n");
            printf("%s\t%s\t%c\t%d\t",list[i].fname,list[i].mname,list[i].gender,list[i].dob);
            printf("\n");
        }}
        else if(n==2)
        {
            printf("THANK YOU");
        }
    }
