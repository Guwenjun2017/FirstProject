#include "../inc/stu.h"

//初始学生数为0
int num_of_students = 0;

/*求平均值*/  
float Average(student stu){  
    return (stu.math + stu.engl + stu.phys + stu.elec + stu.CII) / 5;  
}  
  
/*通过学号返回数组下标*/  
int Student_SearchByID(int id){  
    int i;  
    for(i=0;i<num_of_students;i++){  
	if (students[i].ID == id)  
        {  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*通过姓名返回数组下标*/  
int Student_SearchByName(char name[]){  
    int i;  
    for(i=0;i<num_of_students;i++){  
        if (strcmp(students[i].Name, name) == 0){  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*显示单条学生记录*/  
void Student_DisplaySingle(int index){  
    printf("%5s %9s %9s %9s %9s %9s %9s \t%9s  \n","ID","Name","math","engl","phys","elec","CII","平均成绩");
    printf("------------------------------------------------------------------------------------------\n");
    printf("%7d %7s %10.2f %9.2f %9.2f %9.2f %10.2f %10.2f\n",students[index].ID,students[index].Name,  
              students[index].math, students[index].engl, students[index].phys, students[index].elec, \
	      students[index].CII, students[index].Average);  

    return;
}  
  
/*插入学生信息*/  
void Student_Insert(){  
    //IO_ReadInfo();
    int  a = 0;
    while(1){  
	system("clear");
	printf("Input_ID:");  
        scanf("%d",&students[num_of_students].ID);  
        getchar();  
	for(int i = 0; i < num_of_students; i++){
	    if(students[num_of_students].ID == students[i].ID){
		printf("\e[31m\e[1m%s\e[0m","add error!This student is existed.");
		a = 1;
	    }
	}
	if(a == 1){
	    break;
	}
	
        printf("Input_Name:");  
        scanf("%s",&students[num_of_students].Name);  
        getchar();  

        printf("Input_math:");  
	do{
	    scanf("%f",&students[num_of_students].math);  
	    if(students[num_of_students].math >= 0 && students[num_of_students].math <= 100){
		break;
	    }else
		printf(RED_COLOR,"Grade not in the limit!please input again.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("Input_engl:");  
	do{
	    scanf("%f",&students[num_of_students].engl);  
	    if(students[num_of_students].engl >= 0 && students[num_of_students].engl <= 100){
		break;
	    }else
		printf(RED_COLOR,"Grade not in the limit!please input again.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("Input_phys:");  
	do{
	    scanf("%f",&students[num_of_students].phys);  
	    if(students[num_of_students].phys >= 0 && students[num_of_students].phys <= 100){
		break;
	    }else
		printf(RED_COLOR,"Grade not in the limit!please input again.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("Input_elec:");  
	do{
	    scanf("%f",&students[num_of_students].elec);  
	    if(students[num_of_students].elec >= 0 && students[num_of_students].elec <= 100){
		break;
	    }else
		printf(RED_COLOR,"Grade not in the limit!please input again.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("Input_CII:");  
	do{
	    scanf("%f",&students[num_of_students].CII);  
	    if(students[num_of_students].CII >= 0 && students[num_of_students].CII <= 100){
		break;
	    }else
		printf(RED_COLOR,"Grade not in the limit!please input again.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  
  
        students[num_of_students].Average=Average(students[num_of_students]);  
        num_of_students++;  
  
        printf("\e[31m\e[1m%s\e[0m","Continue?(y/n)");  
  
        if (getchar()=='n'){  
             break;  
        } 
    }  

    //IO_WriteInfo();
    return;
}  
  
/*修改学生信息*/  
void Student_Modify(){  
    while(1){  
	int id;  
        int index;  
  
        printf("Please input the student's ID, the one you want to modify:");  
        scanf("%d",&id);  
        getchar();  
        index=Student_SearchByID(id);  
        if(index==-1){  
            printf(GREEN_COLOR,"Not exist!\n");  
        }  
        else{  
            printf("The infomation of the student you want to modify is:\n");  
            Student_DisplaySingle(index);  
	    int choice;
		printf("please choose the information you want to modify:\n");
		printf("-1.math\n");
		printf("-2.engl\n");
		printf("-3.phys\n");
		printf("-4.elec\n");
		printf("-5.CII\n");
		printf("-6.all information\n");
		printf("-0.break\n");
		printf(">>>>:");
		scanf("%d", &choice);
		if(1 == choice){
		    printf("please input the new math score:");
		    scanf("%f",&students[index].math);  
		    students[index].Average=Average(students[index]);  
		}
		if(2 == choice){
		    printf("please input the new english score:");
		    scanf("%f",&students[index].engl);  
		    students[index].Average=Average(students[index]);  
		}
		if(3 == choice){
		    printf("please input the new physics score:");
		    scanf("%f",&students[index].phys);  
		    students[index].Average=Average(students[index]);  
		}
		if(4 == choice){
		    printf("please input the new electric score:");
		    scanf("%f",&students[index].elec);  
		    students[index].Average=Average(students[index]);  
		}
		if(5 == choice){
		    printf("please input the new CII score:");
		    scanf("%f",&students[index].CII);  
		    students[index].Average=Average(students[index]);  
		}
		if(6 == choice){
		    printf("-- please input the all new information--\n");  
		    printf("Input_ID:");  
		    scanf("%d",&students[index].ID);  
		    getchar();  

		    printf("Input_Name:");  
		    scanf("%s",&students[index].Name);  
		    getchar();  

		    printf("Input_math:");  
		    scanf("%f",&students[index].math);  
		    getchar();  

		    printf("Input_engl:");  
		    scanf("%f",&students[index].engl);  
		    getchar();  

		    printf("Input_phys:");  
		    scanf("%f",&students[index].phys);  
		    getchar();  

		    printf("Input_elec:");  
		    scanf("%f",&students[index].elec);  
		    getchar();  

		    printf("Input_CII:");  
		    scanf("%f",&students[index].CII);  
		    getchar();  

		    students[index].Average=Average(students[index]);  
		}
} 
	getchar();
        printf(GREEN_COLOR,"Continue?(y/n)");  
        if(getchar()=='n'){  
	    break;  
        }  
    }  

    return;
}  

/*删除学生信息*/  
void Student_Delete(){  
    int i;  
    while(1){  
	int id;  
        int index;  
        printf("Please input ID of student which you want to delete:");  
        scanf("%d",&id);  
        getchar();  
        index=Student_SearchByID(id);  

        if(index==-1){  
             printf("Not exist!\n");  
        }  
        else{  
            printf("The infomation of the student you want to delete is:\n");  
            Student_DisplaySingle(index);  
            printf(GREEN_COLOR,"Sure delete?(y/n)");  
            if(getchar()=='y'){  
                for(i=index;i<num_of_students-1;i++){  
		    //把后边的对象都向前移动  
		    students[i]=students[i+1];
                }  
                num_of_students--;  
            }  
            getchar();  
        }  

        printf(GREEN_COLOR,"Continue?(Enter/n)");  
        if(getchar()=='n'){  
             break;  
        }  
    } 

    //IO_WriteInfo();
    return;
}  
  
/*按学号查询*/  
void Student_SelectByID(){  
    while(1){  
	int a;
        int index;  
        printf("Please input the student's ID, the one you want to search:");  
        scanf("%d",&a);  
        getchar();  
        index=Student_SearchByID(a);  

        if (index==-1){  
             printf(GREEN_COLOR,"Not exist!\n");  
        }else{  
             printf("The infomation of the student you want to search is:\n");  
             Student_DisplaySingle(index);  
        }  

        printf(GREEN_COLOR,"Continue?(y/n)");  
        if (getchar()=='n'){  
             break;  
        }  
    }  

    return;
}  

/*按姓名查询*/  
void Student_SelectByName(){  
    while(1){  
        char name[20];  
        int index;  
        printf("Please input the student's Name, the one you want to search:");  
        scanf("%s",&name);  
        getchar();  
        index=Student_SearchByName(name);  

        if (index==-1){  
             printf(GREEN_COLOR,"Not exist!\n");  
        }else{  
             printf("The infomation of the student you want to search is:\n");  
             Student_DisplaySingle(index);  
        }  

        printf(GREEN_COLOR,"Continue?(y/n)");  
        if (getchar()=='n'){  
             break;  
        }  
    }  

    return;
}  
  
/********************************************成绩统计模块**************************************************/
/*按平均值排序*/  
void Student_SortByAverage(){  
    //IO_ReadInfo();
    system("clear");
    int i, j;  
    student tmp;  

    for(i = 0; i < num_of_students; i++){  
	for (j = 1; j < num_of_students - i; j++){  
	    if(students[j - 1].Average < students[j].Average){  
		tmp = students[j - 1];  
                students[j - 1] = students[j];  
                students[j] = tmp;  
             }  
        }  
    }  
    Student_Display();

    return;
}  
   
/*按学号排序*/
void Student_SortByID(){
    //IO_ReadInfo();
    system("clear");
    int i, j;
    student tmp;

    for(j = 0; j < num_of_students - 1; j++){
	for(i = 0; i < num_of_students - 1; i++){
	    if(students[i].ID > students[i + 1].ID){
		tmp = students[i];
		students[i] = students[i + 1];
		students[i + 1] = tmp;
	    }
        }
    }
    Student_Display();

    return;
}

//各门课各分数段学生人数统计并打印
void Student_Sort_EachSubject(){
//    IO_ReadInfo();
    system("clear");
    //IO_ReadInfo();
    int math1 = 0, math2 = 0, math3 = 0, math4 = 0, math5 = 0;
    int engl1 = 0, engl2 = 0, engl3 = 0, engl4 = 0, engl5 = 0;
    int phys1 = 0, phys2 = 0, phys3 = 0, phys4 = 0, phys5 = 0;
    int elec1 = 0, elec2 = 0, elec3 = 0, elec4 = 0, elec5 = 0;
    int CII1 = 0, CII2 = 0, CII3 = 0, CII4 = 0, CII5 = 0;

    //math
    for(int i = 0; i < num_of_students; i++){
	if(students[i].math >= 90)
	    math1++;
	else if(students[i].math >= 80)
	    math2++;
	else if(students[i].math >= 70)
	    math3++;
	else if(students[i].math >= 60)
	    math4++;
	else 
	    math5++;
    }

    //engl
    for(int i = 0; i < num_of_students; i++){
	if(students[i].engl >= 90)
	    engl1++;
	else if(students[i].engl >= 80)
	    engl2++;
	else if(students[i].engl >= 70)
	    engl3++;
	else if(students[i].engl >= 60)
	    engl4++;
	else 
	    engl5++;
    }

    //phys
    for(int i = 0; i < num_of_students; i++){
	if(students[i].phys >= 90)
	    phys1++;
	else if(students[i].phys >= 80)
	    phys2++;
	else if(students[i].phys >= 70)
	    phys3++;
	else if(students[i].phys >= 60)
	    phys4++;
	else 
	    phys5++;
    }

    //elec
    for(int i = 0; i < num_of_students; i++){
	if(students[i].elec >= 90)
	    elec1++;
	else if(students[i].elec >= 80)
	    elec2++;
	else if(students[i].elec >= 70)
	    elec3++;
	else if(students[i].elec >= 60)
	    elec4++;
	else 
	    elec5++;
    }

    //CII
    for(int i = 0; i < num_of_students; i++){
	if(students[i].CII >= 90)
	    CII1++;
	else if(students[i].CII >= 80)
	    CII2++;
	else if(students[i].CII >= 70)
	    CII3++;
	else if(students[i].CII >= 60)
	    CII4++;
	else 
	    CII5++;
    }
 
    printf(GREEN_COLOR,"\t\t90分以上\t80 ~ 89\t\t70~79\t\t60~69\t\t60以下\t(单位:人)\n");
    printf("--------------------------------------------------------------------------------------\n");  
    printf("math:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",math1, math2, math3, math4, math5);
    printf("engl:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",engl1, engl2, engl3, engl4, engl5);
    printf("phys:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",phys1, phys2, phys3, phys4, phys5);
    printf("elec:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",elec1, elec2, elec3, elec4, elec5);
    printf("CII: \t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",CII1, CII2, CII3, CII4, CII5);
    printf("--------------------------------------------------------------------------------------\n");  

    return;
}
/*显示学生信息*/  
void Student_Display()  
{  
    int i;  
    int Ranking = 0;

    printf("%10s| %10s| %10s| %10s| %10s| %10s| %10s| %10s| %10s| \n","ID","Name","math","engl","phys","elec","CII","Average","Ranking");  
    printf("-----------------------------------------------------------------------------------------------------------------\n");  
    for (i=0;i<num_of_students;i++){  
	Ranking++;
        printf("   %7d| %10s| %10.2f| %10.2f| %10.2f| %10.2f| %10.2f| %10.2f| %10d|\n", students[i].ID, students[i].Name,  
             students[i].math, students[i].engl, students[i].phys, students[i].elec, students[i].CII, students[i].Average, Ranking);  
    }  

    return;
}  
  
/******************************************学籍处理模块****************************************************/
//补考通知
void print_information_bukao(){
    system("clear");
    //初始挂科数为0
    int num_of_students_of_fail = 0;
    //初始补考人数设为-1,因计数从0开始
    int num_of_students_of_studentbukao = -1;
    for(int i = 0; i < num_of_students; i++){
	if(students[i].math < 60)
	    num_of_students_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_of_fail++; 
	if(students[i].CII < 60)
	    num_of_students_of_fail++;
	if(num_of_students_of_fail > 0){
	    num_of_students_of_studentbukao++;
	}
	if(num_of_students_of_studentbukao != -1){
	    students_bukao[num_of_students_of_studentbukao] = students[i];
	}
    } 

    if(num_of_students_of_studentbukao == -1){
	printf(GREEN_COLOR,"No students need to bukao.\n");
    }

    printf(GREEN_COLOR,"\n-----------补考通知(学生ID Name和挂科科目成绩)-------------\n");  
    for(int j = 0; j < num_of_students_of_studentbukao; j++){
        printf("%d\t", students_bukao[j].ID);
        printf("%s\t", students_bukao[j].Name);
        if(students_bukao[j].math < 60){
            printf("math:  %5.2f|", students_bukao[j].math);
        }
        if(students_bukao[j].engl < 60){
            printf("engl:  %5.2f|", students_bukao[j].engl);
        }
        if(students_bukao[j].phys < 60){
            printf("phys:  %5.2f|", students_bukao[j].phys);
        }
        if(students_bukao[j].elec < 60){
            printf("elec:  %5.2f|", students_bukao[j].elec);
        }
        if(students_bukao[j].CII < 60){
            printf("CII:  %5.2f|", students_bukao[j].CII);
        }
        printf("\n");
    }  

    return;
}
//退学通知
void print_information_tuixue(){
    system("clear");
    //初始挂科数为0
    int num_of_students_of_fail = 0;
    //初始退学人数设为-1,因计数从0开始
    int num_of_students_of_studentfail = -1; 
    for(int i = 0; i < num_of_students; i++){
	if(students[i].math < 60)
	    num_of_students_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_of_fail++;
	if(students[i].CII < 60)
	    num_of_students_of_fail++;
	if(num_of_students_of_fail >= 3){
	    num_of_students_of_studentfail++;
	    students_fail[num_of_students_of_studentfail] = students[i];
	}
    }
    if(num_of_students_of_studentfail == -1){
	printf("No students need to fail.\n");
    }
    printf(GREEN_COLOR,"\n-----------退学通知(学生ID Name和挂科科目成绩)-------------\n");  
    for(int j = 0; j < num_of_students_of_studentfail; j++){
        printf("%d\t", students_fail[j].ID);
        printf("%s\t", students_fail[j].Name);
        if(students_fail[j].math < 60){
            printf("math:  %5.2f|", students_fail[j].math);
        }
        if(students_fail[j].engl < 60){
            printf("engl:  %5.2f|", students_fail[j].engl);
        }
        if(students_fail[j].phys < 60){
            printf("phys:  %5.2f|", students_fail[j].phys);
        }
        if(students_fail[j].elec < 60){
            printf("elec:  %5.2f|", students_fail[j].elec);
        }
        if(students_fail[j].CII < 60){
            printf("CII:  %5.2f|", students_fail[j].CII);
        }
        printf("\n");
    }  

    return;
} 

//升学学生
void print_information_up() {
   system("clear");
    //初始挂科数为0
    int num_of_students_of_fail = 0;
    //初始升学人数设为-1,因计数从0开始
    int num_of_students_of_up = -1; 
    for(int i = 0; i < num_of_students; i++){
	if(students[i].math < 60)
	    num_of_students_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_of_fail++;
	if(students[i].CII < 60)
	    num_of_students_of_fail++;
	if(num_of_students_of_fail <= 2){
	    num_of_students_of_up++;
	    next[num_of_students_of_up] = students[i];
	}
    }
    printf(GREEN_COLOR,"\nthe ID and name of students entering senior class:\n");
    for(int j = 0; j < num_of_students_of_up; j++){
	printf("ID: %d\t", next[j].ID);
	printf("Name: %s\n", next[j].Name);
    }

    return;
}

/*********************************************文件读写模块*************************************************/
void IO_ReadInfo()
{
    FILE *fp;
    int i;
    if((fp=fopen("record.txt", "rb")) == NULL)
    {
	printf("open failed!\n");
	return;
    }
    if(fread(&num_of_students, sizeof(int), 1, fp) != 1)
    {
	num_of_students = -1;
    }
    else
    {
	for(i = 0; i < num_of_students; i++)
	{
	    fread(&students[i], sizeof(struct Student), 1, fp);
	}
    }

    fclose(fp);
}
void IO_WriteInfo()
{
    FILE *fp;
    int i;
    if((fp = fopen("record.txt", "wb")) == NULL)
    {
	printf("open failed!\n");
	return;
    }
    if(fwrite(&num_of_students, sizeof(int), 1, fp) !=  1)
    {
	printf("writeIn failed!\n");
    }
    for(i = 0; i < num_of_students; i++)
    {
	if(fwrite(&students[i], sizeof(struct Student), 1, fp) != 1){
	    printf("writeIn failed!\n");
	}
    }

    fclose(fp);
}
