/*************************************************************
Title : 학교 자판기 프로그램

자판기를 사용하는 학생들의 정보, 자판기 안의 음료, 동전 수 등을
관리자 로그인을 통해 확인할 수 있는 자판기 프로그램!
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 자판기 음료 가격 매크로 상수
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

#define MAX_SIZE 200 // 입력할 수 있는 최대 학생 수

// 자판기 정보 구조체
struct DRINK_INFO{
    // 자판기 음료개수
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
    int coin[2]; // 자판기에 남아있는 동전 개수 coin[0] -> 500원, coin[1] -> 100원
    int coin_count[2]; // 거슬러주는 동전 개수 coin_count[0] -> 500원 coin_count[1] -> 100원
};

typedef struct DRINK_INFO dri;

// 학생 정보 구조체
struct STUDENT_INFO{
    char sname[20]; // 학생 이름
    int stu_number; // 학생 학번
    int stu_money; // 학생 초기 금액
    // 학생이 쓴 돈
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

// 관리자 구조체
struct MANAGER_INFO{
    char mname[20]; // 관리자 이름
    char cmp_mname[20]; // 로그인시 이름이 맞는지 비교
    int password; // 관리자 비밀번호
    int cmp_password; // 로그인시 비밀번호가 맞는지 비교
};

typedef struct MANAGER_INFO man;

int start_menu=0; // 시작화면 메뉴선택
int menu=0; // 메뉴선택
int m_menu=0;
int money=0; // 입력한 돈, 남은 돈을 저장
int change_money=0; // 거스름돈
int add_money=0; // 추가로 입력하는 돈
int count=0; // 학생들이 자판기를 사용한 횟수

// 자판기 함수
void select_drink(dri *drink, stu *student); // 음료 고르는 함수
void fadd_money(stu *student); // 돈을 더 넣는 함수
void print_drink(dri *drink); // 남은 음료 출력 함수
void give_money(dri *drink, stu *student); // 남은 돈 출력 함수
void count_coin(dri *drink); // 자판기에 남은 동전 개수 출력 함수

// 관리자 함수
void use_student(stu *student); // 관리자 모드로 사용한 학생 출력 함수
void total_money(stu *student); // 관리자 모드로 매출 출력 함수


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

    while(1){ // 초기 화면
        flag=0;
        m_menu_flag=0;

        system("cls");
        printf(" ------------------------------------------------------------------------------\n");
        printf("|                        프로그래밍 언어 학교 자판기                           |\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("|              1. 학생                |               2. 관리자                |\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("메뉴선택 : ");
        scanf("%d", &start_menu);

        switch(start_menu){
        case 1: // 학생 선택
            while(!flag){
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        프로그래밍 언어 학교 자판기                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                               학생 정보 입력                                 |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("이름 : ");
                scanf("%s", student[count].sname);
                printf("학번 : ");
                scanf("%d", &student[count].stu_number);
                printf("현금 : ");
                scanf("%d", &student[count].stu_money);
                while(!flag){ // 자판기 사용 화면
                    system("cls");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|                        프로그래밍 언어 학교 자판기                           |\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|1.콜라        \t");
                    printf("|2.사이다      \t");
                    printf("|3.식혜        \t");
                    printf("|4.맥콜        \t");
                    printf("|5.파워에이드  |\n");
                    printf("|%d원        \t", COLA);
                    printf("|%d원        \t", SIDER);
                    printf("|%d원         \t", SIKHYE);
                    printf("|%d원        \t", MAKOL);
                    printf("|%d원        |\n", POWERAID);
                    printf(" ------------------------------------------------------------------------------\n");

                    printf("|6.포카리      \t");
                    printf("|7.게토레이    \t");
                    printf("|8.핫식스      \t");
                    printf("|9.커피        \t");
                    printf("|10.홍차       |\n");
                    printf("|%d원        \t", POKARI);
                    printf("|%d원        \t", GETOREI);
                    printf("|%d원        \t", HOTSIX);
                    printf("|%d원        \t", COFFEE);
                    printf("|%d원        |\n", HONGCHA);
                    printf(" ------------------------------------------------------------------------------\n");

                    printf(" ------------------------------------------------------------------------------\n");
                    printf("|11.돈 넣기   \t");
                    printf("|12.남은 음료 \t");
                    printf("|13.잔돈 반환 \t");
                    printf("|14.남은 동전 \t");
                    printf("|15.나가기     |\n");
                    printf(" ------------------------------------------------------------------------------\n");
                    printf("남은 돈 : %-d \t", student[count].stu_money);
                    printf("넣은 돈 : %-d \t", money);
                    printf("학생이름 : %-s \t", student[count].sname);
                    printf("학생번호 : %-3d \n \n", student[count].stu_number);

                    printf("메뉴 선택 : ");
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
                            printf("돈이 남아있습니다.");
                            getchar();
                            getchar();
                            break;
                        }else{
                            flag=1;
                            count++;
                            break;
                        }
                    default :
                        printf("다시 눌러주세요! \n");
                        getchar();
                        getchar();
                    }
                }
            }
            break;
        case 2: // 관리자 선택
            // 관리자 선택 초기화면에서 이름, 비밀번호 설정
            if(!m_flag){
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        프로그래밍 언어 학교 자판기                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        관리자 이름과 비밀번호 설정                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("관리자 이름 설정 : ");
                scanf("%s", manager.mname);
                printf("관리자 비밀번호 설정 : ");
                scanf("%d", &manager.password);
                m_flag=1;
                break;
            //
            }else{
                system("cls");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                        프로그래밍 언어 학교 자판기                           |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("|                                관리자 로그인                                 |\n");
                printf(" ------------------------------------------------------------------------------\n");
                printf("관리자 이름 : ");
                scanf("%s", manager.cmp_mname);
                printf("관리자 비밀번호 : ");
                scanf("%d", &manager.cmp_password);

                // 로그인성공
                while(!m_menu_flag){
                    if(!strcmp(manager.cmp_mname, manager.mname) && manager.cmp_password==manager.password){
                        system("cls");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|                        프로그래밍 언어 학교 자판기                           |\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|                        관리자 이름 : %-10s                              |\n", manager.mname);
                        printf(" ------------------------------------------------------------------------------\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("|1.남은 음료   \t");
                        printf("|2.남은 동전   \t");
                        printf("|3.사용학생    \t");
                        printf("|4.매출        \t");
                        printf("|5.나가기      |\n");
                        printf(" ------------------------------------------------------------------------------\n");
                        printf("메뉴 선택 : ");
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

                // 로그인실패
                }else{
                    printf("잘못입력하셨습니다.");
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

void select_drink(dri *drink, stu *student){ // 음료선택 함수
    int minus_money=0; // 거스름돈 구하기 위한 음료수 가격

    switch(menu){
    case 1: minus_money=COLA; strcpy(&drink->name[0], "콜라"); break;
    case 2: minus_money=SIDER; strcpy(&drink->name[0], "사이다"); break;
    case 3: minus_money=SIKHYE; strcpy(&drink->name[0], "식혜"); break;
    case 4: minus_money=MAKOL; strcpy(&drink->name[0], "맥콜"); break;
    case 5: minus_money=POWERAID; strcpy(&drink->name[0], "파워에이드"); break;
    case 6: minus_money=POKARI; strcpy(&drink->name[0], "포카리"); break;
    case 7: minus_money=GETOREI; strcpy(&drink->name[0], "게토레이"); break;
    case 8: minus_money=HOTSIX; strcpy(&drink->name[0], "핫식스"); break;
    case 9: minus_money=COFFEE; strcpy(&drink->name[0], "커피"); break;
    case 10: minus_money=HONGCHA; strcpy(&drink->name[0], "홍차"); break;
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

        printf("%s가 나왔습니다. \n", drink->name);
        money=change_money;
        student[count].spent_money+=minus_money;
    }else{
        printf("돈을 더 넣어주세요 \n");
    }
    getchar();
}

void fadd_money(stu *student){ // 자판기에 돈을 넣는 함수
    printf("돈을 넣어주세요 : ");
    scanf("%d", &add_money);

    if(student[count].stu_money < add_money){
        printf("돈이 부족합니다. \n");
        getchar();
        return;
    }

    if(student[count].stu_money<0){
        printf("금액이 부족합니다. \n");
        student[count].stu_money+=add_money;
        money-=add_money;
    }else{
        money+=add_money;
        student[count].stu_money-=add_money;
    }
}

void print_drink(dri *drink){ // 음료 재고 출력함수
    printf(" -----------------------------------------------------------------------------------------------------------------\n");
    printf("|콜라개수 : %-3d        ", drink->cola_count);
    printf("|사이다개수 : %-3d      ", drink->sider_count);
    printf("|식혜개수 : %-3d        ", drink->sikhye_count);
    printf("|맥콜개수 : %-3d        ", drink->makol_count);
    printf("|파워에이드개수 : %-3d |\n", drink->poweraid_count);
    printf("|포카리개수 : %-3d      ", drink->pokari_count);
    printf("|게토레이개수 : %-3d    ", drink->getorei_count);
    printf("|핫식스개수 : %-3d      ", drink->hotsix_count);
    printf("|커피개수 : %-3d        ", drink->coffee_count);
    printf("|홍차개수 : %-3d       |\n", drink->hongcha_count);
    printf(" -----------------------------------------------------------------------------------------------------------------\n");
    getchar();
}

void give_money(dri *drink, stu *student){ // 자판기에 넣어져 있는 돈 반환함수

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
        printf("500원 %3d개 100원 %3d개 나왔습니다. \n", drink->coin_count[0], drink->coin_count[1]);
        student[count].stu_money+=(drink->coin_count[0]*500)+(drink->coin_count[1]*100);
        money=0;
    }else if(drink->coin_count[0]==0 && drink->coin_count[1]!=0){
        printf("100원 %3d개 나왔습니다. \n", drink->coin_count[1]);
        student[count].stu_money+=drink->coin_count[1]*100;
        money=0;
    }else if(drink->coin_count[0]!=0 && drink->coin_count[1]==0){
        printf("500원 %3d개 나왔습니다. \n", drink->coin_count[0]);
        student[count].stu_money+=drink->coin_count[0]*500;
        money=0;
    }else if(drink->coin_count[0]==0 && drink->coin_count[1]==0){
        printf("잔돈이 없습니다. \n");
    }
    getchar();
}

void count_coin(dri *drink){ // 자판기에 보관돼 있는 동전 수 출력함수
    printf(" ----------------------\n");
    printf("|500원 동전 개수 : %-3d |\n", drink->coin[0]);
    printf("|100원 동전 개수 : %-3d |\n", drink->coin[1]);
    printf(" ----------------------\n");
    getchar();
}

void use_student(stu *student){ // 사용한 학생 정보 출력함수
    int i=0;

    for(i=0; i<count; i++){
        printf("\n");
        printf("%3d. 이름 : %-s 학번 : %-d \n", i+1, student[i].sname, student[i].stu_number);
        printf(" ------------------------------------------------------------------------------\n");
        printf("|1.콜라        \t");
        printf("|2.사이다      \t");
        printf("|3.식혜        \t");
        printf("|4.맥콜        \t");
        printf("|5.파워에이드  |\n");
        printf("|%-d개          \t", student[i].scola_count);
        printf("|%-d개          \t", student[i].ssider_count);
        printf("|%-d개          \t", student[i].ssikhye_count);
        printf("|%-d개          \t", student[i].smakcol_count);
        printf("|%-d개           |\n", student[i].spoweraid_count);
        printf(" ------------------------------------------------------------------------------\n");

        printf("|6.포카리      \t");
        printf("|7.게토레이    \t");
        printf("|8.핫식스      \t");
        printf("|9.커피        \t");
        printf("|10.홍차       |\n");
        printf("|%-d개          \t", student[i].spokari_count);
        printf("|%-d개          \t", student[i].sgetorei_count);
        printf("|%-d개          \t", student[i].shotsix_count);
        printf("|%-d개          \t", student[i].scoffee_count);
        printf("|%-d개           |\n", student[i].shongcha_count);
        printf(" ------------------------------------------------------------------------------\n");
        printf("사용금액 : %d원 \n\n", student[i].spent_money);
    }
    getchar();
}

void total_money(stu *student){ // 총 매출 출력함수
    int sum_money=0;
    int i=0;

    for(i=0; i<count; i++){
        sum_money+=student[i].spent_money;
    }
    for(i=0; i<count; i++){
        printf(" ------------------------------------------------------------------------------\n");
        printf("|%d. 이름 : %-10s 학번 : %-5d 사용 금액 : %-5d원                         |\n", i+1, student[i].sname, student[i].stu_number, student[i].spent_money);
        printf(" ------------------------------------------------------------------------------\n");
    }
    printf("\n");
    printf("매출 : %-d원 \n", sum_money);
    getchar();
}
