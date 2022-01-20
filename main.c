#include<stdio.h>

void encrypt(char* filename){

    FILE *fps, *fpt;
    char ch;

     // opening the file to be encrypted
    fps = fopen(filename, "r");
    if(fps == NULL)
        printf("%s %s", "Unable to open file: ", filename);

    // opening a temporary file 
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
        printf("%s", "Unable to open temporary file");

    // getting the first character of the file
    ch = fgetc(fps);

    // read each character until it reach the End Of File (EOF)
    while(ch != EOF)
    {
        ch = ch + 124; // encryption used - haracter number (ASCII) + 124
        fputc(ch, fpt); // storing the encrypted character on the temporary file
        ch = fgetc(fps); // go to the next character

    }

    // close the files
    fclose(fps);
    fclose(fpt);

    // opening both files again
    fps = fopen(filename, "w");
    if(fps == NULL)
        printf("%s %s", "Unable to open file: ", filename);

    fpt = fopen("temp.txt", "r");
    if(fpt == NULL)
        printf("%s", "Unable to open temporary file");

    // getting the first character of the temp file
    ch = fgetc(fpt);

    // read each character until it reach the End Of File (EOF)
    while(ch != EOF)
    {

        ch = fputc(ch, fps); // putting the characters from the temp file into the actual file
        ch = fgetc(fpt); // getting the next character

    }

    // closing both files
    fclose(fps);
    fclose(fpt);

    // end of program
    printf("\nFile %s Encrypted Successfully!", filename);
   
}

void decrypt(char* filename){

    FILE *fps, *fpt;
    char ch;

     // opening the file to be dencrypted
    fps = fopen(filename, "w");
    if(fps == NULL)
        printf("%s %s", "Unable to open file: ", filename);

    // opening a temporary file 
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
        printf("%s", "Unable to open temporary file");

    // getting the first character of the file
    ch = fgetc(fps);

    // read each character until it reach the End Of File (EOF)
    while(ch != EOF)
    {

        ch = ch - 124; // decryption used - character number (ASCII) - 124
        fputc(ch, fps); // storing the decrypted character on the temporary file
        ch = fgetc(fpt); // go to the next character

    }

    // closing both files
    fclose(fps);
    fclose(fpt);

    // end of program
    printf("\nFile %s Decrypted Successfully!", filename);
   
}

int main()
{
    char filename[20], ch;
    int opt;    

    printf("Welcome to this simple encryption software\n");
    printf("Encrypt[1] - Decrypt[2]: ");

    scanf("%d", &opt);

    // getting file name 
    printf("Enter Filename: ");
    scanf("%s", filename);

    if(opt == 1){

        encrypt(filename);

    }else if(opt == 2){

        decrypt(filename);

    }

    return 0;
}