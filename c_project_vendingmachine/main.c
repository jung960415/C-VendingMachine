/*************************************************************
Title : �б� ���Ǳ� ���α׷�

���Ǳ⸦ ����ϴ� �л����� ����, ���Ǳ� ���� ����, ���� �� ����
������ �α����� ���� Ȯ���� �� �ִ� ���Ǳ� ���α׷�!
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ǳ� ���� ���� ��ũ�� ���
#define COLA 1200
#define SIDER 1200
#define SIKHYE 800
#define MAKOL 1000
#define POWERAID 2000
#define POKARI 2000
#define GETOREI 2000
#define HOTSIX 1500
#define COFFEE 1000
#define HONGCHA 1000

#define MAX_SIZE 200 // �Է��� �� �ִ� �ִ� �л� ��

// ���Ǳ� ���� ����ü
struct DRINK_INFO{
    // ���Ǳ� ���ᰳ��
    int cola_count;
    int sider_count;
    int sikhye_count;
    int makol_count;
    int poweraid_count;
    int pokari_count;
    int getorei_count;
    int hotsix_count;
    int coffee_count;
    int hongcha_count;
    char name[20];
    int coin[2]; // ���Ǳ⿡ �����ִ� ���� ���� coin[0] -> 500��, coin[1] -> 100��
    int coin_count[2]; // �Ž����ִ� ���� ���� coin_count[0] -> 500�� coin_count[1] -> 100��
};

typedef struct DRINK_INFO dri;

// �л� ���� ����ü
struct STUDENT_INFO{
    char sname[20]; // �л� �̸�
    int stu_number; // �л� �й�
    int stu_money; // �л� �ʱ� �ݾ�
    // �л��� �� ��
    int spent_money;
    int scola_count;
    int ssider_count;
    int ssikhye_count;
    int smakcol_count;
    int spoweraid_count;
    int spokari_count;
    int sgetorei_count;
    int shotsix_count;
    int scoffee_count;
    int shongcha_count;
};

typedef struct STUDENT_INFO stu;

// ������ ����ü
struct MANAGER_INFO{
    char mname[20]; // ������ �̸�
    char cmp_mname[20]; // �α��ν� �̸��� �´��� ��
    int password; // ������ ��й�ȣ
    int cmp_password; // �α��ν� ��й�ȣ�� �´��� ��
};

typedef struct MANAGER_INFO man;

int start_menu=0; // ����ȭ�� �޴�����
int menu=0; // �޴�����
int m_menu=0;
int money=0; // �Է��� ��, ���� ���� ����
int change_money=0; // �Ž�����
int add_money=0; // �߰��� �Է��ϴ� ��
int count=0; // �л����� ���Ǳ⸦ ����� Ƚ��

// ���Ǳ� �Լ�
void select_drink(dri *drink, stu *student); // ���� ���� �Լ�
void fadd_money(stu *student); // ���� �� �ִ� �Լ�
void print_drink(dri *drink); // ���� ���� ��� �Լ�
void give_money(dri *drink, stu *student); // ���� �� ��� �Լ�
void count_coin(dri *drink); // ���Ǳ⿡ ���� ���� ���� ��� �Լ�

// ������ �Լ�
void use_student(stu *student); // ������ ���� ����� �л� ��� �Լ�
void total_money(stu *student); // ������ ���� ���� ��� �Լ�


int main()
{
    int flag=0;
    int m_flag=0;
    int m_menu_flag=0;

    dri drink={10,10,10,10,10,10,10,10,10,10};

    drink.coin[0]=50;
    drink.coin[1]=50;

    drink.coin_count[0]=0;
    drink.coin_count[1]=0;

    stu student[MAX_SIZE];

    man manager;

    while(1){ // �ʱ� ȭ��
        flag=0;
        m_menu_flag=0;

        system("cls");
        printf(" ------------------------------------------------------------------------------\n");
        printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("|              1. �л�                |               2. ������                |\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("�޴����� : ");
        scanf("%d", &start_menu);

        switch(start_menu){
        case 1: // �л� ����
            while(!flag){
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                               �л� ���� �Է�                                 |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("�̸� : ");
                scanf("%s", student[count].sname);
                printf("�й� : ");
                scanf("%d", &student[count].stu_number);
                printf("���� : ");
                scanf("%d", &student[count].stu_money);
                while(!flag){ // ���Ǳ� ��� ȭ��
                    system("cls");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|1.�ݶ�        \t");
                    printf("|2.���̴�      \t");
                    printf("|3.����        \t");
                    printf("|4.����        \t");
                    printf("|5.�Ŀ����̵�  |\n");
                    printf("|%d��        \t", COLA);
                    printf("|%d��        \t", SIDER);
                    printf("|%d��         \t", SIKHYE);
                    printf("|%d��        \t", MAKOL);
                    printf("|%d��        |\n", POWERAID);
                    printf(" ------------------------------------------------------------------------------\n");

                    printf("|6.��ī��      \t");
                    printf("|7.���䷹��    \t");
                    printf("|8.�ֽĽ�      \t");
                    printf("|9.Ŀ��        \t");
                    printf("|10.ȫ��       |\n");
                    printf("|%d��        \t", POKARI);
                    printf("|%d��        \t", GETOREI);
                    printf("|%d��        \t", HOTSIX);
                    printf("|%d��        \t", COFFEE);
                    printf("|%d��        |\n", HONGCHA);
                    printf(" ------------------------------------------------------------------------------\n");

                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|11.�� �ֱ�   \t");
                    printf("|12.���� ���� \t");
                    printf("|13.�ܵ� ��ȯ \t");
                    printf("|14.���� ���� \t");
                    printf("|15.������     |\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("���� �� : %-d \t", student[count].stu_money);
                    printf("���� �� : %-d \t", money);
                    printf("�л��̸� : %-s \t", student[count].sname);
                    printf("�л���ȣ : %-3d \n \n", student[count].stu_number);

                    printf("�޴� ���� : ");
                    scanf("%d", &menu);

                    switch(menu){
                    case 0:
                    case 1:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 2:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 3:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 4:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 5:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 6:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 7:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 8:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 9:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 10:
                        select_drink(&drink, student);
                        getchar();
                        break;
                    case 11:
                        fadd_money(student);
                        getchar();
                        break;
                    case 12:
                        print_drink(&drink);
                        getchar();
                        break;
                    case 13:
                        give_money(&drink, student);
                        getchar();
                        break;
                    case 14:
                        count_coin(&drink);
                        getchar();
                        break;
                    case 15:
                        if(money>0){
                            printf("���� �����ֽ��ϴ�.");
                            getchar();
                            getchar();
                            break;
                        }else{
                            flag=1;
                            count++;
                            break;
                        }
                    default :
                        printf("�ٽ� �����ּ���! \n");
                        getchar();
                        getchar();
                    }
                }
            }
            break;
        case 2: // ������ ����
            // ������ ���� �ʱ�ȭ�鿡�� �̸�, ��й�ȣ ����
            if(!m_flag){
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        ������ �̸��� ��й�ȣ ����                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("������ �̸� ���� : ");
                scanf("%s", manager.mname);
                printf("������ ��й�ȣ ���� : ");
                scanf("%d", &manager.password);
                m_flag=1;
                break;
            //
            }else{
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                                ������ �α���                                 |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("������ �̸� : ");
                scanf("%s", manager.cmp_mname);
                printf("������ ��й�ȣ : ");
                scanf("%d", &manager.cmp_password);

                // �α��μ���
                while(!m_menu_flag){
                    if(!strcmp(manager.cmp_mname, manager.mname) && manager.cmp_password==manager.password){
                        system("cls");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|                        ���α׷��� ��� �б� ���Ǳ�                           |\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|                        ������ �̸� : %-10s                              |\n", manager.mname);
                        printf(" ------------------------------------------------------------------------------\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|1.���� ����   \t");
                        printf("|2.���� ����   \t");
                        printf("|3.����л�    \t");
                        printf("|4.����        \t");
                        printf("|5.������      |\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("�޴� ���� : ");
                        scanf("%d", &m_menu);
                        switch(m_menu){
                        case 1:
                            print_drink(&drink);
                            getchar();
                            break;
                        case 2:
                            count_coin(&drink);
                            getchar();
                            break;
                        case 3:
                            use_student(student);
                            getchar();
                            break;
                        case 4:
                            total_money(student);
                            getchar();
                            break;
                        case 5:
                            m_menu_flag=1;
                            break;
                        default :
                            break;
                        }

                // �α��ν���
                }else{
                    printf("�߸��Է��ϼ̽��ϴ�.");
                    getchar();
                    getchar();
                    break;
                }
            }
        default :
            break;
            }
        }
    }

    return 0;
}

void select_drink(dri *drink, stu *student){ // ���ἱ�� �Լ�
    int minus_money=0; // �Ž����� ���ϱ� ���� ����� ����

    switch(menu){
    case 1: minus_money=COLA; strcpy(&drink->name[0], "�ݶ�"); break;
    case 2: minus_money=SIDER; strcpy(&drink->name[0], "���̴�"); break;
    case 3: minus_money=SIKHYE; strcpy(&drink->name[0], "����"); break;
    case 4: minus_money=MAKOL; strcpy(&drink->name[0], "����"); break;
    case 5: minus_money=POWERAID; strcpy(&drink->name[0], "�Ŀ����̵�"); break;
    case 6: minus_money=POKARI; strcpy(&drink->name[0], "��ī��"); break;
    case 7: minus_money=GETOREI; strcpy(&drink->name[0], "���䷹��"); break;
    case 8: minus_money=HOTSIX; strcpy(&drink->name[0], "�ֽĽ�"); break;
    case 9: minus_money=COFFEE; strcpy(&drink->name[0], "Ŀ��"); break;
    case 10: minus_money=HONGCHA; strcpy(&drink->name[0], "ȫ��"); break;
    default : break;
    }

    change_money = money - minus_money;

    if(money>minus_money){
        switch(menu){
        case 1: drink->cola_count--; student[count].scola_count++; break;
        case 2: drink->sider_count--; student[count].ssider_count++; break;
        case 3: drink->sikhye_count--; student[count].ssikhye_count++;break;
        case 4: drink->makol_count--; student[count].smakcol_count++; break;
        case 5: drink->poweraid_count--; student[count].spoweraid_count++; break;
        case 6: drink->pokari_count--; student[count].spokari_count++; break;
        case 7: drink->getorei_count--; student[count].sgetorei_count++; break;
        case 8: drink->hotsix_count--; student[count].shotsix_count++; break;
        case 9: drink->coffee_count--; student[count].scoffee_count++; break;
        case 10: drink->hongcha_count--; student[count].shongcha_count++; break;
        default : break;
        }

        printf("%s�� ���Խ��ϴ�. \n", drink->name);
        money=change_money;
        student[count].spent_money+=minus_money;
    }else{
        printf("���� �� �־��ּ��� \n");
    }
    getchar();
}

void fadd_money(stu *student){ // ���Ǳ⿡ ���� �ִ� �Լ�
    printf("���� �־��ּ��� : ");
    scanf("%d", &add_money);

    if(student[count].stu_money < add_money){
        printf("���� �����մϴ�. \n");
        getchar();
        return;
    }

    if(student[count].stu_money<0){
        printf("�ݾ��� �����մϴ�. \n");
        student[count].stu_money+=add_money;
        money-=add_money;
    }else{
        money+=add_money;
        student[count].stu_money-=add_money;
    }
}

void print_drink(dri *drink){ // ���� ��� ����Լ�
    printf(" -----------------------------------------------------------------------------------------------------------------\n");
    printf("|�ݶ󰳼� : %-3d        ", drink->cola_count);
    printf("|���̴ٰ��� : %-3d      ", drink->sider_count);
    printf("|�������� : %-3d        ", drink->sikhye_count);
    printf("|���ݰ��� : %-3d        ", drink->makol_count);
    printf("|�Ŀ����̵尳�� : %-3d |\n", drink->poweraid_count);
    printf("|��ī������ : %-3d      ", drink->pokari_count);
    printf("|���䷹�̰��� : %-3d    ", drink->getorei_count);
    printf("|�ֽĽ����� : %-3d      ", drink->hotsix_count);
    printf("|Ŀ�ǰ��� : %-3d        ", drink->coffee_count);
    printf("|ȫ������ : %-3d       |\n", drink->hongcha_count);
    printf(" -----------------------------------------------------------------------------------------------------------------\n");
    getchar();
}

void give_money(dri *drink, stu *student){ // ���Ǳ⿡ �־��� �ִ� �� ��ȯ�Լ�

    drink->coin_count[0]=money/500;
        drink->coin_count[1]=(money%500)/100;
        if(drink->coin_count[0]>drink->coin[0]){
            drink->coin_count[0]=0;
            drink->coin_count[1]=(money-(drink->coin[0]*500))/100;
                if(drink->coin_count[1]>drink->coin[1]){
                    drink->coin_count[1]=0;
                }
        }else{
        drink->coin[0]-=drink->coin_count[0];
        drink->coin[1]-=drink->coin_count[1];
        }

    if(drink->coin_count[0]!=0 && drink->coin_count[1]!=0){
        printf("500�� %3d�� 100�� %3d�� ���Խ��ϴ�. \n", drink->coin_count[0], drink->coin_count[1]);
        student[count].stu_money+=(drink->coin_count[0]*500)+(drink->coin_count[1]*100);
        money=0;
    }else if(drink->coin_count[0]==0 && drink->coin_count[1]!=0){
        printf("100�� %3d�� ���Խ��ϴ�. \n", drink->coin_count[1]);
        student[count].stu_money+=drink->coin_count[1]*100;
        money=0;
    }else if(drink->coin_count[0]!=0 && drink->coin_count[1]==0){
        printf("500�� %3d�� ���Խ��ϴ�. \n", drink->coin_count[0]);
        student[count].stu_money+=drink->coin_count[0]*500;
        money=0;
    }else if(drink->coin_count[0]==0 && drink->coin_count[1]==0){
        printf("�ܵ��� �����ϴ�. \n");
    }
    getchar();
}

void count_coin(dri *drink){ // ���Ǳ⿡ ������ �ִ� ���� �� ����Լ�
    printf(" ----------------------\n");
    printf("|500�� ���� ���� : %-3d |\n", drink->coin[0]);
    printf("|100�� ���� ���� : %-3d |\n", drink->coin[1]);
    printf(" ----------------------\n");
    getchar();
}

void use_student(stu *student){ // ����� �л� ���� ����Լ�
    int i=0;

    for(i=0; i<count; i++){
        printf("\n");
        printf("%3d. �̸� : %-s �й� : %-d \n", i+1, student[i].sname, student[i].stu_number);
        printf(" ------------------------------------------------------------------------------\n");
        printf("|1.�ݶ�        \t");
        printf("|2.���̴�      \t");
        printf("|3.����        \t");
        printf("|4.����        \t");
        printf("|5.�Ŀ����̵�  |\n");
        printf("|%-d��          \t", student[i].scola_count);
        printf("|%-d��          \t", student[i].ssider_count);
        printf("|%-d��          \t", student[i].ssikhye_count);
        printf("|%-d��          \t", student[i].smakcol_count);
        printf("|%-d��           |\n", student[i].spoweraid_count);
        printf(" ------------------------------------------------------------------------------\n");

        printf("|6.��ī��      \t");
        printf("|7.���䷹��    \t");
        printf("|8.�ֽĽ�      \t");
        printf("|9.Ŀ��        \t");
        printf("|10.ȫ��       |\n");
        printf("|%-d��          \t", student[i].spokari_count);
        printf("|%-d��          \t", student[i].sgetorei_count);
        printf("|%-d��          \t", student[i].shotsix_count);
        printf("|%-d��          \t", student[i].scoffee_count);
        printf("|%-d��           |\n", student[i].shongcha_count);
        printf(" ------------------------------------------------------------------------------\n");
        printf("���ݾ� : %d�� \n\n", student[i].spent_money);
    }
    getchar();
}

void total_money(stu *student){ // �� ���� ����Լ�
    int sum_money=0;
    int i=0;

    for(i=0; i<count; i++){
        sum_money+=student[i].spent_money;
    }
    for(i=0; i<count; i++){
        printf(" ------------------------------------------------------------------------------\n");
        printf("|%d. �̸� : %-10s �й� : %-5d ��� �ݾ� : %-5d��                         |\n", i+1, student[i].sname, student[i].stu_number, student[i].spent_money);
        printf(" ------------------------------------------------------------------------------\n");
    }
    printf("\n");
    printf("���� : %-d�� \n", sum_money);
    getchar();
}
