#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fir
{
    char noa[100],desc[1000],place[100],add[1000],noc[100],witn[100],noofficer[100],remark[1000];
    int day,month,year,hour,min;
}fir;

void addnewfir();
void display();
void sortbydate();
void deletefir();
void search();
void solvefir();

int main()
{
    int ch;

    while(ch!=7)
    {
        printf("\n1.New FIR\n2.Display\n3.Sort By Date\n4.Delete FIR\n5.Search\n6.Total FIR\n\n");
        printf("\nEnter your choice::\n");
        scanf("%d",&ch);
        system("cls");

        switch(ch)
        {
            case 1: newfir();
                    break;
            case 2: display();
                    break;
            case 3: sortbydate();
                    break;
            case 4: deletefir();
                    break;
            case 5: search();
                    break;
            case 6: totalfir();
                    break;
            default: printf("\nEnter correct choice\n");
        }

    }

}
void newfir()
{
    fir*p;
    int i,n;
    FILE*fp=NULL;

    p = (fir*) calloc (n,sizeof(fir));

    fp=fopen("fir1.bin","a");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }

    printf("\nEnter record do you want to add::");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    fflush(stdin);
    printf("\n%d.Name of The accuse :: ",i+1);
    gets(p[i].noa);
    printf("\nDescription :: ");
    gets(p[i].desc);
    printf("\nPlace :: ");
    gets(p[i].place);
    printf("\nAddress :: ");
    gets(p[i].add);
    printf("\nDate :: ");
    scanf("%d%d%d",&p[i].day,&p[i].month,&p[i].year);
    printf("\nTime::");
    scanf("%d%d",&p[i].hour,&p[i].min);
    fflush(stdin);
    printf("\nName of criminal :: ");
    gets(p[i].noc);
    printf("\nWitness :: ");
    printf("\nName :: ");
    gets(p[i].witn);
    printf("\nName of officer who register the case :: ");
    gets(p[i].noofficer);
    printf("\nRemark :: ");
    gets(p[i].remark);
    fflush(stdin);

    fwrite(&p[i],sizeof(fir),1,fp);
    }

    fclose(fp);
}
void display()
{
    fir p1;
    int n;
    FILE*fp;

    fp=fopen("fir1.bin","r");

    while(fread(&p1,sizeof(fir),1,fp));
    {

    printf("\nName of The accuse :: %s",p1.noa);

    printf("\nDescription :: %s",p1.desc);

    printf("\nPlace :: %s",p1.place);

    printf("\nAddress :: %s",p1.add);

    printf("\nDate :: %d/%d/%d",p1.day,p1.month,p1.year);

    printf("\nTime:: %d::%d",p1.hour,p1.min);

    printf("\nName of criminal :: %s",p1.noc);

    printf("\nWitness :: ");
    printf("\n Name :: %s",p1.witn);

    printf("\nName of officer who register the case :: %s",p1.noofficer);

    printf("\nRemark :: %s\n",p1.remark);
    }

    fclose(fp);
}

void sortbydate()
{

}
void deletefir()
{

}
void search()
{
    fir p;
    int i,n,date,found=0;
    FILE*fp=NULL;

    fp=fopen("fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }
    printf("\n Enter the date do you want to search::");
    scanf("%d",&date);

    while(fread(&p,sizeof(fir),1,fp));
    {
        if(p.day==date)
        {
            found=1;

            printf("\nName of The accuse :: %s",p.noa);

            printf("\nDescription :: %s",p.desc);

            printf("\nPlace :: %s",p.place);

            printf("\nAddress :: %s",p.add);

            printf("\nDate :: %d/%d/%d",p.day,p.month,p.year);

            printf("\nTime:: %d::%d",p.hour,p.min);

            printf("\nName of criminal :: %s",p.noc);

            printf("\nWitness :: ");
            printf("\n Name :: %s",p.witn);

            printf("\nName of officer who register the case :: %s",p.noofficer);

            printf("\nRemark :: %s\n",p.remark);
        }

    }
    if(found==0)
    {
        printf("\n The record is not found\n");
    }
}
void totalfir()
{
    fir p1;
    FILE*fp;

    fp=fopen("fir1.txt","r");

    if(fp==NULL)
    {
        printf("\nFile does not exist\n");
        exit(1);
    }

    fseek(fp,0,SEEK_END);

    int n=ftell(fp)/sizeof(fir);

    printf("\n The total FIR records are %d ",n);

    fclose(fp);

}
