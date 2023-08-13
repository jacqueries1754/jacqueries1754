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
float balance = 5000.;
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
    printf("3. 中文\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(language, "English");
            break;
        case 2:
            strcpy(language, "Lao");
            break;
        case 3:
            strcpy(language, "Chinese");
            break;
        default:
            printf("Invalid choice, please try again\n");
            selectLanguage();
    }

}

void displayMainMenu() {
    
    printf("\n");
    if(strcmp(language, "English") == 0) {
        printf("Main Menu\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("ລາຍການ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("主菜单\n");
    }
    
    if(strcmp(language, "English") == 0) {
        printf("1. Check Balance\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("1. ກອດຍອດເງິນໃນບັນຊີ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("1. 查询余额\n");
    }
    
    if(strcmp(language, "English") == 0) {
        printf("2. Withdraw Money\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("2. ຖອນເງິນໃນບັນຊິ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("2. 取款\n");
    }
    
    if(strcmp(language, "English") == 0) {
        printf("3. Deposit Money\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("3. ຝາກເງິນເຂົ້າບັນຊີ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("3. 存款\n");
    }
    
    if(strcmp(language, "English") == 0) {
        printf("4. Exit\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("4. ອອກຈາກລະບົບ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("4. 退出\n");
    }
    
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
            printf("%s\n", strcmp(language, "English") == 0 ? "Invalid choice, please try again" : (strcmp(language, "Lao") == 0 ? "ກາລຸນາປ້ອນໃຫ້ຖືກຕ້ອງ" : "无效的选项，请重试"));
            displayMainMenu();
    }
}

void checkBalance() {
    printf("\n");
    if(strcmp(language, "English") == 0) {
        printf("Your current balance is: $%.2f\n", balance);
    } else if(strcmp(language, "Lao") == 0) {
        printf("ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ: $%.2f\n", balance);
    } else if(strcmp(language, "Chinese") == 0) {
        printf("您当前的余额为：$%.2f\n", balance);
    }
    displayend();
}

void withdrawMoney() {
    printf("\n");
    if(strcmp(language, "English") == 0) {
        printf("Withdraw Money\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("ຖອນເງິນ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("取款\n");
    }
    float withdrawAmount;
    printf("%s", strcmp(language, "English") == 0 ? "Please enter the amount to withdraw: " : (strcmp(language, "Lao") == 0 ? "ກະລຸນາປ້ອນຈຳນວນເງິນທີ່ຕ້ອງຖອນ: " : "请输入取款金额："));
    scanf("%f", &withdrawAmount);
    if (withdrawAmount <= 0) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Invalid amount, please try again" : (strcmp(language, "Lao") == 0 ? "ຈຳນວນເງິນບໍ່ຖືກຕ້ອງ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ" : "无效的金额，请重试"));
        withdrawMoney();
    }
    else if (withdrawAmount > balance) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Insufficient funds, please try again" : (strcmp(language, "Lao") == 0 ? "ຄ່າເງິນບໍ່ພຽງພໍ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ" : "余额不足，请重试"));
        withdrawMoney();
    }
    else {
        balance -= withdrawAmount;
        printf("%s $%.2f\n", strcmp(language, "English") == 0 ? "Please collect your cash. Your new balance is:" : (strcmp(language, "Lao") == 0 ? "ກະລຸນານັບເງິນຂອງທ່ານ. ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ:" : "请取走您的现金。 您的新余额为："), balance);
        displayend();
    }
}

void depositMoney() {
    printf("\n");
    if(strcmp(language, "English") == 0) {
        printf("Deposit Money\n");
    } else if(strcmp(language, "Lao") == 0) {
        printf("ລາຍການລາຍຈ່າຍເງິນ\n");
    } else if(strcmp(language, "Chinese") == 0) {
        printf("存款\n");
    }
    float depositAmount;
    printf("%s", strcmp(language, "English") == 0 ? "Please enter the amount to deposit: " : (strcmp(language, "Lao") == 0 ? "ກະລຸນາປ້ອນຈຳນວນເງິນທີ່ຕ້ອງການຝາກ: " : "请输入存款金额："));
    scanf("%f", &depositAmount);
    if (depositAmount <= 0) {
        printf("%s\n", strcmp(language, "English") == 0 ? "Invalid amount, please try again" : (strcmp(language, "Lao") == 0 ? "ຳນວນເງິນບໍ່ຖືກຕ້ອງ, ກະລຸນາລອງໃໝ່ອີກຄັ້ງ" : "无效的金额，请重试"));
        depositMoney();
    }
     else {
        balance += depositAmount;
        printf("%s $%.2f\n", strcmp(language, "English") == 0 ? "Deposit successful. Your new balance is:" : (strcmp(language, "Lao") == 0 ? "ການຝາກເງິນຂອງທ່ານສຳເລັດ. ຍອດເງິນໃນບັນຊີຂອງທ່ານແມ່ນ:" : "存款成功。您的新余额为："), balance);
        displayend();
    }
}
void displayend(){    
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"); 
       printf("\n%s\n", strcmp(language, "English") == 0 ? "Would you like to do another transaction?" : (strcmp(language, "Lao") == 0 ? "ທ່ານຕ້ອງການບໍລິການອື່ນເສີມບໍ່?" : "您是否要进行另一笔交易？"));    
       printf("%s\n", strcmp(language, "English") == 0 ? "< 1 > Yes" : (strcmp(language, "Lao") == 0 ? "< 1 > ຕ້ອງການ" : "< 1 > 是"));   
       printf("%s\n", strcmp(language, "English") == 0 ? "< 2 > No" : (strcmp(language, "Lao") == 0 ? "< 2 > ບໍ່ຕ້ອງການ" : "< 2 > 否"));
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
    printf("%s\n", strcmp(language, "English") == 0 ? "Thank you for using the ATM Banking Machine": (strcmp(language, "Lao") == 0 ? "ຂໍຂອບໃຈທ່ານທີ່ໃຊ້ບໍລິການທາງເຄື່ອງ ATM ຂອງເຮົາ" : "祝您有一个美好的一天！"));
    printf("%s\n", strcmp(language, "English") == 0 ? "Have a nice day!": (strcmp(language, "Lao") == 0 ? "ຂໍໃຫ້ມື້ນີ້ເປັນມື້ທີ່ດີຂອງທ່ານ!" : "感谢您使用ATM银行机"));
    exit(0);
}