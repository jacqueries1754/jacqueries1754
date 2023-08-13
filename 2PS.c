
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void displayWelcomeScreen();
void selectLanguage();
void displayMainMenu();
void checkBalance();
void withdrawMoney();
void depositMoney();
void displayExitScreen();
void displayend();

// Global variables
float balance = 5000.00;
char language[10] = "English";


int main() {
    displayWelcomeScreen();
    selectLanguage();
    displayMainMenu();
    displayend();
    return 0;
}

void displayWelcomeScreen() {
    printf("Welcome to the ATM Banking Machine\n");
}

void selectLanguage() {
    printf("Please select your preferred language:\n");
    printf("1. English\n");
    printf("2. ພາສາລາວ\n");
    int choice;
    
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("CLS");
            strcpy(language, "English");
            break;
        case 2:
            system("CLS");
            strcpy(language, "Lao");
            break;
        default:
            printf("Invalid choice, please try again\n");
            selectLanguage();
    }
       
}

void displayMainMenu() {
    printf("\n%s\n", strcmp(language, "English") == 0 ? "Main Menu" : "ລາຍການ");
    printf("%s\n", strcmp(language, "English") == 0 ? "1. Check Balance" : "1. ກອດຍອດເງິນໃນບັນຊີ");
    printf("%s\n", strcmp(language, "English") == 0 ? "2. Withdraw Money" : "2. ຖອນເງິນໃນບັນຊິ");
    printf("%s\n", strcmp(language, "English") == 0 ? "3. Deposit Money" : "3. ຝາກເງິນເຂົ້າບັນຊີ");
    printf("%s\n", strcmp(language, "English") == 0 ? "4. Exit" : "4. ອອກຈາກລະບົບ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            checkBalance();
            break;
        case 2:
            withdrawMoney();
            break;
        case 3:
            depositMoney();
            break;
        case 4:
            displayExitScreen();
            break;
        default:
            printf("%s\n", strcmp(language, "English") == 0 ? "Invalid choice, please try again" : "ກາລຸນາປ້ອນໃຫ້ຖືກຕ້ອງ");
            displayMainMenu();
            break;
    }

}

void checkBalance() {
    printf("\n%s $%.2f\n", strcmp(language, "English") == 0 ? "Your current balance is:" : "ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ:", balance);
    displayend();
}

void withdrawMoney() {
    printf("\n%s\n", strcmp(language, "English") == 0 ? "Withdraw Money" : "ຖອນເງິນ");
    float withdrawAmount;
    printf("%s", strcmp(language, "English") == 0 ? "Please enter the amount to withdraw: " : "ກະລຸນາປ້ອນຈຳນວນເງິນທີ່ຕ້ອງຖອນ: ");
    scanf("%f", &withdrawAmount);
    if (withdrawAmount <= 0) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Invalid amount, please try again" : "ຈຳນວນເງິນບໍ່ຖືກຕ້ອງ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ");
        withdrawMoney();
    }
    else if (withdrawAmount > balance) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Insufficient funds, please try again" : "ມູນຄ່າເງິນຂອງທ່ານບໍ່ພຽງພໍ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ");
        withdrawMoney();
    }
    else {
        balance -= withdrawAmount;
        printf("%s $%.2f\n", strcmp(language, "English") == 0 ? "Please collect your cash. Your new balance is:" : "ກະລຸນານັບເງິນຂອງທ່ານ. ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ:", balance);
        displayend();
    }
}

void depositMoney() {
    printf("\n%s\n", strcmp(language, "English") == 0 ? "Deposit Money" : "ຝາກເງິນ");
    float depositAmount;
    printf("%s", strcmp(language, "English") == 0 ? "Please enter the amount to deposit: " : "ກະລຸນາປ້ອນຈຳນວນເງິນທີ່ຕ້ອງການຝາກ: ");
    scanf("%f", &depositAmount);
    if (depositAmount <= 0) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Invalid amount, please try again" : "ຈຳນວນເງິນບໍ່ຖືກຕ້ອງ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ");
        depositMoney();
    }
    else {
        balance += depositAmount;
        printf("%s $%.2f\n", strcmp(language, "English") == 0 ? "Deposit successful. Your new balance is:" : "ການຝາກເງິນຂອງທ່ານສຳເລັດ. ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ:", balance);
        displayend();
    }
}
void displayend(){    
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n%s\n", strcmp(language, "English") == 0 ? "Would you like to do another transaction" : "ທ່ານຕ້ອງການບໍລິການອື່ນເສີມບໍ່");
        printf("%s\n", strcmp(language, "English") == 0 ? "< 1 > Yes" : "< 1 > ຕ້ອງການ");
        printf("%s\n", strcmp(language, "English") == 0 ? "< 2 > No" : "< 2 > ບໍ່ຕ້ອງການ");
        int choice;
        bool again = true;
        scanf("%d", &choice);
    
        system("CLS");
        
        if (choice == 1) {
            again = false;
            displayMainMenu();
        }    
        else{
            again = false;
            displayExitScreen();
        }
}
void displayExitScreen() {
    printf("\n%s\n", strcmp(language, "English") == 0 ? "Thank you for using the ATM Banking Machine" : "ຂໍຂອບໃຈທ່ານທີ່ໃຊ້ບໍລິການທາງເຄື່ອງ ATM ຂອງເຮົາ");
    printf("%s\n", strcmp(language, "English") == 0 ? "Have a nice day!" : "ຂໍໃຫ້ມື້ນີ້ເປັນມື້ທີ່ດີຂອງທ່ານ!");
    exit(0);
}


