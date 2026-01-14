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
//  Auther        : Aditya Vijay Mali
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
//  Entry Point Function of The Project
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    StartAuxillaryDataInitilisation();

    return 0;
}