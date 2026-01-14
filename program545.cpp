///////////////////////////////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

///////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////////////

// Maximum file size that we allow in the projexct
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 5

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

///////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Structures
//
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    BootBlock 
//  Discription    :    Holds the information to boot the OS
//
///////////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    SuperBlock 
//  Discription    :    Holds the information About the File System
//
///////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    Inode 
//  Discription    :    Holds the Information About The File
//
///////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int ReferenceCount;
    int Permission;
    char *Buffer;           // Actual file Allocation Address
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode * PINODE;
typedef struct Inode ** PPINODE;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    FileTable 
//  Discription    :    Holds the information About opened file
//
///////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    UAREA 
//  Discription    :    Holds the information about Process
//
///////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Global variables or objects used in the Project
//
///////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uaraobj;

PINODE head = NULL;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseUAREA
//  Description   : It is used to initialise UAREA members
//  Auther        : Sanyam BhupendraKumar Ravne      
//  Date          : 13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uaraobj.ProcessName,"Myexe");

    int i = 0;
    for (i = 0; i < MAXOPENFILES; i++)
    {
        uaraobj.UFDT[i] = NULL;
    } 
    
    printf("Marvellous CVFS : UAREA gets initialised succesfully \n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseSuperBlock
//  Description   : It is used to initialise Super Block members
//  Auther        : Sanyam BhupendraKumar Ravne
//  Date          : 13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Marvellous CVFS : Super block gets initialised succesfully \n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CreateDILB
//  Description   : It is used to creat LinkedList of inodes
//  Auther        : Sanyam BhupendraKumar Ravne
//  Date          : 13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    for (i = 0; i <= MAXINODE; i++)
    {
        newn = (PINODE) malloc(sizeof(INODE));

        strcpy(newn -> FileName,"\0");
        newn -> InodeNumber = i;
        newn -> FileSize = 0;
        newn -> ActualFileSize = 0;
        newn -> ReferenceCount = 0;
        newn -> Permission = 0;
        newn -> Buffer = NULL;
        newn -> next = NULL;

        if (temp == NULL)   // LL is Empty
        {
            head = newn;
            temp = head;
        }
        else                // LL contains atlist one node
        {
            temp -> next = newn;
            temp = temp -> next;
        }        
    }
    
    printf("Marvellous CVFS : DILB created succesfully \n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : StartAuxillaryDataInitilisation
//  Description   : It is used to call all such function which are used to initialise
//                  Auxillary data
//  Auther        : Sanyam BhupendraKumar Ravne
//  Date          : 13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitilisation()
{
    strcpy(bootobj.Information,"Booting processs of Marvellous CVFS is done");

    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();

    CreateDILB();
    
    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialised succesfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayHelp
//  Description   : It is used to Display help page
//  Auther        : Sanyam BhupendraKumar Ravne
//  Date          : 14/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    printf("-----------------------------------------------------------------\n");
    printf("----------------- Marvellous CVFS Help page ---------------------\n");
    printf("-----------------------------------------------------------------\n");

    printf("man     : It is use to Display Manual page\n");
    printf("clear   : It is use to clear the terminal\n");
    printf("creat   : It is used to create new file\n");
    printf("write   : It is used to write the data into the file\n");
    printf("read    : It is used to read the data from the file\n");
    printf("stat    : It is used to Display Statistical information\n");
    printf("unlink  : It is used to Delete file\n");
    printf("exit    : It is use to terminate Marvellous CVFS\n");

    printf("-----------------------------------------------------------------\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function of The Project
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};
    char Command[5][20] = {{'\0'}};
    int iCount = 0;
    StartAuxillaryDataInitilisation();

    printf("-----------------------------------------------------------------\n");
    printf("-------------- Marvellous CVFS started succesfully --------------\n");
    printf("-----------------------------------------------------------------\n");

    // Infinite Listening Shell
    while (1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\n Marvellous CVFS : > ");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s,%s,%s,%s,%s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        fflush(stdin);

        if(iCount == 1)
        {
            if(strcmp("exit",Command[0]) == 0)
            {
                printf("Thank you for Using Marvellous CVFS\n");
                printf("Deallocating All the Resources\n");

                break;
            }
            else if(strcmp("ls",Command[0]) == 0)
            {
                printf("Inside ls");
            }
            else if(strcmp("help",Command[0]) == 0)
            {
                DisplayHelp();
            }
        }// End of else if 1
        else if(iCount ==2)
        {

        }// End of else if 2
        else if(iCount == 3)
        {

        }// End of else if 3
        else if(iCount == 4)
        {

        }// End of else if 4
        else
        {
            printf("Command not found\n");
            printf("Please refer -help option to get more information\n");
        }// End of else
    }// End of while
    
    return 0;
}// End of Main