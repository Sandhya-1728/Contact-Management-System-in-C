#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<direct.h>

struct contact

{

    long ph;

    char name[100],add[100],email[100],group[20],dob[20],city[100];

} list;

char query[20],name[20],group[20],city[100];

FILE *fp, *ft;

int i,n,ch,l,found;

int main()

{

main:

    system("cls");    /* ******************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Search by group\n\t\t[5] Search by city\n\t\t[6] Edit a Contact\n\t\t[7] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new contacts****************************/

    case 1:

        system("cls");

        fp=fopen("contact.txt","a");

        for (;;)

        {
            fflush(stdin);
            printf("\n\n\t!!!ADD CONTACT!!!\n\t===========================\n\t");

            printf("To exit enter blank space in the name input\nName (Use identical):");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Phone:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("Address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("Email address:");

            gets(list.email);

            fflush(stdin);

            printf("Group:");

            gets(list.group);

            fflush(stdin);

            printf("Date of birth:");

            gets(list.dob);

            printf("City:");

            gets(list.city);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

        /* *********************list of contacts*************************  */

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\nGroup\t: %s\nDate Of Birth\t: %s\nCity\t: %s\n",list.name,

                           list.ph,list.add,list.email,list.group,list.dob,list.city);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* *******************search contacts**********************  */

    case 3:

        system("cls");

        found=0;

        printf("\n\n\t!!!CONTACT SEARCH!!!\n\t===========================\n\t>>>>Name of contact to search: ");

        fflush(stdin);

        scanf("%[^\n]",&query);

        l=strlen(query);

        fp=fopen("contact.txt","r");

        system("cls");

        printf("\n\n>>>>Search result for '%s' \n===================================================\n",query);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            for(i=0; i<=l; i++)

                name[i]=list.name[i];

            name[l]='\0';

            if(stricmp(name,query)==0)

            {

                printf("\n(1) Name\t: %s\n(2) Phone\t: %ld\n(3) Address\t: %s\n(4) Email\t: %s\n(5) Group\t: %s\n(6) Date Of Birth\t: %s\n(7) City\t: %s\n",list.name,list.ph,list.add,list.email,list.group,list.dob,list.city);

                found++;

                if (found%6==0)

                {

                    printf("Press any key to continue...");

                    getch();

                }

            }

        }    

        if(found==0)

            printf("\n :( No match found! :(");

        else

            printf("\n  :) %d match(s) found! :)",found);

        fclose(fp);

        printf("\n\n\n>>>>Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

        scanf("%d",&ch);

        switch (ch)

        {

            case 1:

                goto main;

            case 0:

                break;

            default:

                printf("Invalid choice");

                break;

        }

        

        break;

        /* *********************search by group************************/
    case 4:
        system("cls");
        
        found=0;
        printf("\n\n\t!!!SEARCH FOR A CONTACT BY GROUP!!!\n\t===========================\n\t>>>>Name of Group to search contact: ");

        fflush(stdin);

        scanf("%[^\n]",&query);

        l=strlen(query);

        fp=fopen("contact.txt","r");

        system("cls");

        printf("\n\n>>>>Search result for '%s' \n===================================================\n",query);

        while(fread(&list,sizeof(list),1,fp)==1)

        {
            for(i=0; i<=l; i++)

                group[i]=list.group[i];
            group[l]='\0';    

            if(stricmp(group,query)==0)

            {

                printf("\n(1) Name\t: %s\n(2) Phone\t: %ld\n(3) Address\t: %s\n(4) Email\t: %s\n(5) Group\t: %s\n(6) Date Of Birth\t: %s\n(7) City\t: %s\n",list.name,list.ph,list.add,list.email,list.group,list.dob,list.city);

                found++;

                if (found%6==0)

                {

                    printf("Press any key to continue...");

                    getch();

                }

            }

        }
        if(found==0)

            printf("\n :( No match found! :(");

        else

            printf("\n :) %d match(s) found! :)",found);

        fclose(fp);

        printf("\n\n\n>>>>Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

        scanf("%d",&ch);

        switch (ch)

        {

            case 1:

                goto main;

            case 0:

                break;

            default:

                printf("Invalid choice");

                break;

        }    

        
        

        break;
        
                /*****************search by city****************************/
    case 5:
        system("cls");
        found=0;
        printf("\n\n\t!!!SEARCH FOR A CONTACT BY CITY!!!\n\t===========================\n\t>>>>Name of City to search contact: ");
        fflush(stdin);

        scanf("%[^\n]",&query);

        l=strlen(query);

        fp=fopen("contact.txt","r");

        system("cls");

        printf("\n\n>>>>Search result for '%s' \n===================================================\n",query);

        while(fread(&list,sizeof(list),1,fp)==1)

        {
            for(i=0; i<=l; i++)

                city[i]=list.city[i];
            city[l]='\0';    

            if(stricmp(list.city,query)==0)

            {

                printf("\n(1) Name\t: %s\n(2) Phone\t: %ld\n(3) Address\t: %s\n(4) Email\t: %s\n(5) Group\t: %s\n(6) Date Of Birth\t: %s\n(7) City\t: %s\n",list.name,list.ph,list.add,list.email,list.group,list.dob,list.city);

                found++;

                if (found%6==0)

                {

                    printf("Press any key to continue...");

                    getch();

                }

            }

        }
        if(found==0)

            printf("\n :( No match found! :(");

        else

            printf("\n  :) %d match(s) found! :)",found);

        fclose(fp);
        printf("\n\n\n>>>>Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

        scanf("%d",&ch);

        switch (ch)

        {

            case 1:

                goto main;

            case 0:

                break;

            default:

                printf("Invalid choice");

                break;

        }
        break;
    

        /********************edit a contact*****************************/
    case 6:

        system("cls");

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        fflush(stdin);

        printf("\n\n\t!!!Edit contact!!!\n\t===============================\n\n\t>>>>Enter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\nEditing '%s'\n\n",name);

        printf("(1) Name(Use identical):");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("(2) Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("(3) Address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("(4) Email address:");

        gets(list.email);

        fflush(stdin);

        printf("(5) Group:");

        gets(list.group);

        fflush(stdin);

        printf("(6) Date of birth:");

        gets(list.dob);

        printf("(7) City:");
        gets(list.city);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");

        break;

        /* ********************delete contacts**********************/

    case 7:

        system("cls");

        fflush(stdin);

        printf("\n\n\t!!!DELETE A CONTACT!!!\n\t==========================\n\t>>>>Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n>>>>Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}