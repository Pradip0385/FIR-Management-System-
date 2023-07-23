#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct fir
{
    char noa[100],desc[1000],mobile[10],place[100],add[1000],noc[100],witn[100],noofficer[100],status[1000],crmdesc[1000];
    int day,month,year,hour,min,id;
};
struct fir f;

void addnewfir();
void display();
void sortbydate();
void search1();
void totalfir();
void update();
void Exit();
int main()
{
    int ch;

        while(ch!=7)
        {
                system("color B4");
                system("cls");
                printf("\n\t\t\t**** F.I.R. RECORDS MANAGEMENT SYSTEM ****\t\t\t\n");
                printf("\t\t\t___________________________________________________\n");
                printf("\n\t\t\t1.New FIR\n\t\t\t2.Display\n\t\t\t3.Sort By Date(dd/mm/yy)\n\t\t\t4.Search\n\t\t\t5.Total FIR\n\t\t\t6.Update Of FIR's\n\t\t\t\n7.Exit()");
                printf("\t\t\t___________________________________________________");
                printf("\n\t\t\tEnter your choice::");
                scanf("\t\t\t%d",&ch);
                system("cls");

                switch(ch)
                {
                    case 1: addnewfir();
                            break;
                    case 2: display();
                            break;
                    case 3: sortbydate();
                            break;
                    case 4: search1();
                            break;
                    case 5: totalfir();
                            break;
                    case 6:update();
                            break;
                    case 7:Exit();
                            break;
                    default: printf("\nEnter correct choice\n");
                }
                printf("\n Press any key to continue\n");
                getch();

        }

}
void addnewfir()
{
    FILE*fp=NULL;

    fp=fopen("E:\\Mini Project\\fir1.txt","a+");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }

    fflush(stdin);
    printf("\nName of The accuser:: ");
    gets(f.noa);
    printf("\nDescription about incident:: ");
    gets(f.desc);
    printf("\nPlace of incident:: ");
    gets(f.place);
    printf("\nAddress of accuser:: ");
    gets(f.add);
    printf("\nMobile number::");
    gets(f.mobile);
    printf("\nDate(dd/mm/yy) :: ");
    scanf("%d%d%d",&f.day,&f.month,&f.year);
    fflush(stdin);
    printf("\nTime::");
    scanf("%d%d",&f.hour,&f.min);
    fflush(stdin);
    printf("\nName of criminal:: ");
    gets(f.noc);
    printf("\nCriminal Description :: ");
    gets(f.crmdesc);
    printf("\nWitness Name:: ");
    gets(f.witn);
    printf("\nName of officer who register the case :: ");
    gets(f.noofficer);
    printf("\nstatus(Newly added,pending,solved FIR's) :: ");
    gets(f.status);
    fflush(stdin);

    fwrite(&f,sizeof(f),1,fp);

    fclose(fp);
    system("cls");


}
void display()
{
    FILE*fp;

    int i=0;

    fp=fopen("E:\\Mini Project\\fir1.txt","r");

     if(fp==NULL)
    {
        printf("\n No Previous records \n");
        exit(1);
    }

    system("cls");
    while(fread(&f,sizeof(f),1,fp)==1)
        {
            printf("\t\t\t___________________________________________________\n");

            printf("\n\t\t\tName of The accuse :: %s",f.noa);

            printf("\n\t\t\tDescription :: %s",f.desc);

            printf("\n\t\t\tPlace :: %s",f.place);

            printf("\n\t\t\tAddress :: %s",f.add);

            printf("\n\t\t\tMobile Number :: %s",f.mobile);

            printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

            printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

            printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
            i++;

            printf("\n\t\t\tName of criminal :: %s",f.noc);

            printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

            printf("\n\t\t\tWitness Name :: %s",f.witn);

            printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

            printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

            printf("\t\t\t___________________________________________________\n");
        }

    fclose(fp);

}

void sortbydate()
{
   struct fir a[100];

    int i,j,k,r=0,m=0;
    FILE*fp;

    fp=fopen("E:\\Mini Project\\fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }
    i=0;

     fseek(fp,0,SEEK_END);

    int n=ftell(fp)/sizeof(f);

    rewind(fp);

    while(fread(&a[i],sizeof(a[i]),1,fp)==1)
    {
        i++;
        r++;
    }

   for(i=0; i<r; i++)
    {
            for(j=0; j<=i; j++)
            {
                if(a[j].year>a[i].year)
                {
                    k=a[j].year;
                    a[j].year=a[i].year;  //swap(a[j].year,a[i].year)
                    a[i].year=k;
                    k=a[j].month;
                    a[j].month=a[i].month;//swap(a[j].month,a[i].month)
                    a[i].month=k;
                    k=a[j].day;
                    a[j].day=a[i].day;
                    a[i].day=k;
                }
                else
                {
                    if(a[j].year==a[i].year)
                    {
                        if(a[j].month>a[i].month)
                        {
                            k=a[j].year;
                            a[j].year=a[i].year;
                            a[i].year=k;
                            k=a[j].month;
                            a[j].month=a[i].month;
                            a[i].month=k;
                            k=a[j].day;
                            a[j].day=a[i].day;
                            a[i].day=k;
                        }
                        else
                        {
                            if(a[j].month==a[i].month)
                            {
                                if(a[j].day>a[i].day)
                                {
                                    k=a[j].year;
                                    a[j].year=a[i].year;
                                    a[i].year=k;
                                    k=a[j].month;
                                    a[j].month=a[i].month;
                                    a[i].month=k;
                                    k=a[j].day;
                                    a[j].day=a[i].day;
                                    a[i].day=k;
                                }
                            }
                        }
                    }
                 }
            }
    }

    for(i=0;i<n;i++)
    {
            printf("\t\t\t___________________________________________________\n");

            printf("\n\t\t\tName of The accuse :: %s",a[i].noa);

            printf("\n\t\t\tDescription :: %s",a[i].desc);

            printf("\n\t\t\tPlace :: %s",a[i].place);

            printf("\n\t\t\tAddress :: %s",a[i].add);

            printf("\n\t\t\tMobile Number :: %s",a[i].mobile);

            printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",a[i].day,a[i].month,a[i].year);

            printf("\n\t\t\tTime:: %d::%d",a[i].hour,a[i].min);

            printf("\n\t\t\tCriminal ID:: FIR%d%d",a[i].year,i+1);
            i++;

            printf("\n\t\t\tName of criminal :: %s",a[i].noc);

            printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);


            printf("\n\t\t\tWitness Name :: %s",a[i].witn);

            printf("\n\t\t\tName of officer who register the case :: %s",a[i].noofficer);

            printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",a[i].status);

            printf("\t\t\t___________________________________________________\n");
    }
     fclose(fp);


}
void search1()
{
     int i,date,mon,year,flag=0;
    char stat[200];
    char crname[30];

    FILE*fp=NULL;

    fp=fopen("E:\\Mini Project\\fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }

    int ch;

            printf("\n\t\t\t1.By Date(dd/mm/yy)\n\t\t\t2.By Status\n\t\t\t3.By Criminal Name\n");
            printf("\t\t\tEnter your choice search by date or status:-");
            scanf("\t\t\t%d",&ch);
            system("cls");

            switch(ch)
            {
                case 1:  system("cls");
                        printf("\n Enter the date do you want to search(dd/mm/yy)::");
                         scanf("%d%d%d",&date,&mon,&year);


                           while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(f.day==date&&f.month==mon&&f.year==year)
                                {

                                            flag=1;

                                    printf("\t\t\t___________________________________________________\n");

                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");


                                }

                            }
                            if(flag==0)
                            {
                                printf("\n\t\t\t The record is not found\n");
                            }
                            break;
                case 2:  fflush(stdin);
                         printf("\n Enter the status of FIR do you want search(pending,solved,newly)::");
                         gets(stat);

                            while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(strcmp(stat,f.status)==0)
                                {
                                            flag=1;

                                    printf("\t\t\t___________________________________________________\n");

                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");

                                }

                            }
                            if(flag==0)
                            {
                                printf("\n\t\t\t The record is not found\n");
                            }
                            break;
                case 3:   fflush(stdin);
                          printf("\n Enter the criminal name do you want search::");
                          gets(crname);

                            while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(strcmp(crname,f.noc)==0)
                                {
                                            flag=1;

                                    printf("\t\t\t___________________________________________________\n");

                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");

                                }

                            }
                            if(flag==0)
                            {
                                printf("\n\t\t\t The record is not found\n");
                            }
                            break;
                default:printf("\n\t\t\tEnter the correct option\n");
            }

        fclose(fp);
}

void update()
{
    char stat1[30]="pending";
    char stat2[30]="solved";
    char stat3[30]="newly";
    int i,j,k,l,flag,t,r;

    j=k=l=0;
    flag=t=r=0;

    FILE*fp=NULL;

    fp=fopen("E:\\Mini Project\\fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }
                   printf("\n\t\t__________________________________________________________\n");
                    printf("\n\t\t\t***The PENDING Records***\n");

                            while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(strcmp(stat1,f.status)==0)
                                {
                                            flag=1;

                                    printf("\t\t\t___________________________________________________\n");
                                    //printtf("\t\t\t%d",j+1);
                                    j++;
                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");


                                }


                            }
                              if(flag==0)
                            {
                                printf("\n\t\t\t Their is no record of Pending FIR's\n");
                            }
                     printf("\n\t\t__________________________________________________________\n");

                        printf("\n\t\t\t***The SOLVED Records***\n");

                        rewind(fp);

                            while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(strcmp(stat2,f.status)==0)
                                {
                                            t=1;

                                    printf("\t\t\t___________________________________________________\n");
                                   // printtf("\t\t\t%d",k+1);
                                    k++;

                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");

                                }

                            }

                              if(t==0)
                            {
                                printf("\n\t\t\t Their is no record of closed FIR's\n");
                            }

                      printf("\n\t\t__________________________________________________________\n");
                       printf("\n\t\t\t***The NEW Records***\n");

                       rewind(fp);

                            while(fread(&f,sizeof(f),1,fp)==1)
                            {
                                if(strcmp(stat3,f.status)==0)
                                {
                                            r=1;

                                    printf("\t\t\t___________________________________________________\n");
                                   // printtf("\t\t\t%d",l+1);
                                    l++;

                                    printf("\n\t\t\tName of The accuse :: %s",f.noa);

                                    printf("\n\t\t\tDescription :: %s",f.desc);

                                    printf("\n\t\t\tPlace :: %s",f.place);

                                    printf("\n\t\t\tAddress :: %s",f.add);

                                    printf("\n\t\t\tMobile Number :: %s",f.mobile);

                                    printf("\n\t\t\tDate(dd/mm/yy) :: %d/%d/%d",f.day,f.month,f.year);

                                    printf("\n\t\t\tTime:: %d::%d",f.hour,f.min);

                                    printf("\n\t\t\tCriminal ID:: FIR%d%d",f.year,i+1);
                                    i++;

                                    printf("\n\t\t\tName of criminal :: %s",f.noc);

                                    printf("\n\t\t\tCriminal Description :: %s",f.crmdesc);

                                    printf("\n\t\t\tWitness Name :: %s",f.witn);

                                    printf("\n\t\t\tName of officer who register the case :: %s",f.noofficer);

                                    printf("\n\t\t\tstatus(New added,pending,solved FIR's) :: %s\n",f.status);

                                    printf("\t\t\t___________________________________________________\n");

                                }

                            }
                              if(r==0)
                            {
                                printf("\n\t\t\t Their is no record of new FIR's\n");
                            }
                   printf("\n\t\t__________________________________________________________\n");

                     printf("\n\t\t\tTotal Pending FIR's are :%d",j);
                     printf("\n\t\t\tTotal Solved FIR's are :%d",k);
                     printf("\n\t\t\tTotal New FIR's are :%d",l);

                     printf("\n\t\t__________________________________________________________\n");

}

void totalfir()
{
    FILE*fp;

    fp=fopen("E:\\Mini Project\\fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }
    system("cls");
    fseek(fp,0,SEEK_END);

    int n=ftell(fp)/sizeof(f);

    printf("\n\t\t\tThe Total FIR Records are %d \n",n);

    fclose(fp);

}
void Exit()
{
    for(int i=0;i<=0;i++)
	break;
}

