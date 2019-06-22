#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
使用链表时，当前节点用上一个节点的next表示 

给定学生的志愿和分数，招生时始终以分数优先的原则录取各个志愿
但是当前学生，当前志愿专业已满时，需要降分后，重新排序再录取
并且还有调剂等操作
客户要求先按成绩排序，再建立链表，每当当前学生需要降分时，向链表后寻找合适位置插入 
*/

int sNum;//投档学生总数
FILE * input, *output;//输入和输出文件指针

typedef struct S_Student//保存学生信息
{
    char name[20];//学生姓名
    unsigned long long sId;//学号
    int preScore,nowScore;//原始分数，和当前分数
    int trans;//是否同意调剂
    int wish[4];//wish[i]代表第i志愿的专业编号，0号不用
    int nowWish;//录取过程中所到的志愿级别，大于3表示未被录取或被调剂
    int admittedMajor;//最终被录取的专业编号，-1表示未被录取

}Student;

typedef struct S_Node//链表节点
{
    Student data;
    struct S_Node *next;
}Node;

Student students[10001];//保存投档的学生
Node *head=NULL;//链表头节点指针
int planNum[11];//planNum[i]表示i专业计划招生数
int nowNum[11];//nowNum[i]表示i专业当前已招生数

void printFile(char path[])//打印文件内容
{
    FILE *fp=fopen(path,"r");
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
    fclose(fp);
}

char filePath[100];//文件路径

void getInfo()//从文件中读入学生信息
{
    sNum=0;
    while(fscanf(input,"%s%llu%d%d%d%d%d",students[sNum].name,&students[sNum].sId,&students[sNum].preScore,&students[sNum].trans,&students[sNum].wish[1],&students[sNum].wish[2],&students[sNum].wish[3])!=EOF)
    {
        students[sNum].admittedMajor=-1;
        students[sNum].nowScore=students[sNum].preScore;
        students[sNum].nowWish=1;
        ++sNum;
    }
    printf("\n读入完成，共%d名学生\n",sNum);
}

int findMajor()//寻找当前为招满，且招生数最接近计划数的专业，返回专业编号，找不到返回-1
{
    int i,ans=-1,MIN=0x3f3f3f3f,temp;
    for(i=1;i<=10;i++)
    {
        temp=planNum[i]-nowNum[i];//剩余招生指标
        if(temp>0&&temp<MIN)//找剩余招生指标最少的专业
        {
            MIN=temp;
            ans=i;//更新专业编号
        }
    }
    return ans;
}

void Qsort(int be,int ed)//快速排序
{
    if(ed>be)
    {
        int i=be,j=ed;
        Student temp=students[be];
        while(j>i)
        {
            while(j>i&&students[j].preScore<=temp.preScore) j--;
            students[i]=students[j];
            while(j>i&&students[i].preScore>=temp.preScore) i++;
            students[j]=students[i];
        }
        students[i]=temp;//此时i==j
        Qsort(be,i-1);
        Qsort(i+1,ed);
    }
}

Node *getNewNode(Student data)//创建一个信息域为data的链表节点，返回地址
{
    Node *ans=(Node *)malloc(sizeof(Node));
    ans->data=data;
    return ans;
}

void pushFront(Node *nd)//向链表头部插入一个节点
{
    nd->next=head->next;
    head->next=nd;
}

Node* cutOut(Node *pre)//将pre节点指向的节点从链表截取出来，返回该节点指针
{
    Node *ans=pre->next;
    pre->next=ans->next;
    return ans;
}

//向pre后插入节点nd，该节点寻找pre后第一个nowScore小于等于它的节点并插入在前面，以保持链表有序
void findAndInsert(Node *pre,Node *nd)
{
    while(pre->next!=NULL)
    {
        if(pre->next->data.nowScore<=nd->data.nowScore)//可以插入在pre后
        {
            nd->next=pre->next;
            pre->next=nd;
            return;
        }
        pre=pre->next;//不能插入，继续向后找位置
    }
    //此时pre->next==NULL，是链表最后一个节点，说明nd应该插入到末位
    nd->next=NULL;
    pre->next=nd;
}

void delList()//清空链表
{
    if(head!=NULL)
    {
        Node *now=head,*temp;
        while(now!=NULL)
        {
            temp=head->next;//保存下一个节点指针
            free(now);//释放本节点内存
            now=temp;
        }
    }
}

void buildList()//根据排好序的数组，建立链表
{
    delList();//先释放原链表内存
    Node *temp;
    head=getNewNode(students[0]);//头结点信息域无意义，随便搞
    head->next=NULL;
    int i;
    for(i=sNum-1;i>=0;i--)//不断向链表头部插入节点，为了保持分数降序，要倒着插入
    {
        temp=getNewNode(students[i]);
        pushFront(temp);
        //printf("%s %d %d\n",students[i].name,students[i].preScore,students[i].wish[1]);
	}
}

void simulate()//模拟招生
{
    Node *p=head,*temp;
    Student stu;
    int major;
    while(p->next!=NULL)//链表从头向后遍历
    {
        stu=p->next->data;
        if(stu.nowWish<=3)//志愿降级未完，无需调剂
        {
            major=stu.wish[stu.nowWish];//获取当前志愿专业
            if(nowNum[major]<planNum[major])//该专业未录满
            {
                ++nowNum[major];
                p->next->data.admittedMajor=major;//置为已录取
                p=p->next;//该学生处理完，向后移位处理下一个
            }
            else//录满了，需要志愿降级、减分后重新排序
            {
                p->next->data.nowScore-=5;//分数减5分
                p->next->data.nowWish+=1;//志愿级别降低
                temp=cutOut(p);//把该节点截取出来
                findAndInsert(p,temp);//寻找合适位置重新插入
            }
        }
        else//需要调剂
        {
            if(stu.trans)//同意调剂，都同意调剂时，原来分数高的也是肯定先遍历到
            {
                major=findMajor();
                if(major!=-1)//调剂成功
                {
                    p->next->data.admittedMajor=major;
                }
            }
            p=p->next;
        }
    }
}

void outputResult()//遍历链表2遍，分别输出录取成功名单和未录取名单
{
    Node *p=head;
    Student stu;
    fprintf(output,"录取成功名单：\n");
    fprintf(output,"姓名\t\t录取专业\t录取志愿\n");
    while(p->next!=NULL)
    {
        stu=p->next->data;
        if(stu.admittedMajor!=-1)
        {
            if(stu.nowWish>3)//被调剂
            {
                fprintf(output,"%s\t\t%d\t\t调剂\n",stu.name,stu.admittedMajor);
            }
            else
            {
                fprintf(output,"%s\t\t%d\t\t第%d志愿\n",stu.name,stu.admittedMajor,stu.nowWish);
            }
        }
        p=p->next;
    }
    p=head;//指针回到头结点
    fprintf(output,"\n未录取名单：\n");
    fprintf(output,"姓名\n");
    while(p->next!=NULL)
    {
        stu=p->next->data;
        if(stu.admittedMajor==-1)
        {
            fprintf(output,"%s\n",stu.name);
        }
        p=p->next;
    }
}

void findStudent(unsigned long long sId)//查询某个学生录取结果
{
    Node *p=head;
    Student stu;
    while(p->next!=NULL)//遍历结果链表，查找学号为sId的学生
    {
        stu=p->next->data;
        if(stu.sId==sId)
        {
            printf("查询成功，学生录取信息如下：\n");
            if(stu.admittedMajor!=-1)//被录取
            {
                printf("成功录取！\n");
                printf("录取专业\t录取志愿\n");
                if(stu.nowWish>3)//被调剂
                {
                    printf("%d\t\t调剂\n",stu.admittedMajor);
                }
                else
                {
                    printf("%d\t\t第%d志愿\n",stu.admittedMajor,stu.nowWish);
                }
            }
            else
            {
                printf("未录取！\n");
            }
            return;//及时退出
        }
        p=p->next;
    }
    printf("查询失败！不存在该学生！\n");
}

int main(int argc, char* argv[])
{
    int op,i,hasRead=0,hasSort=0,hasSim=0,num;
    unsigned long long sId;
    printf("程序初始化，请先输入10个专业分别的招生人数：\n");
    for(i=1;i<=10;i++)
    {
        scanf("%d",&planNum[i]);
        nowNum[i]=0;
    }
    printf("读入成功！\n");
    while(1)
    {
        printf("\n请选择菜单项：\n1、录入学生数据\n2、投档（学生成绩排序）\n3、模拟招生\n4、查询录取结果\n5、退出\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                printf("请输入学生数据，输入格式如下：\n第一行一个整数，表示要录入的学生数\n接下来每行一个学生信息，包括：姓名 学号 分数 是否同意调剂（1同意，0不同意） 第一志愿专业 第二志愿专业 第三志愿专业（专业为1-10的数字代码）\n");

                input=fopen("in.txt","w");//用来将录入信息保存到文件
                scanf("%d",&sNum);
                for(i=0;i<sNum;i++)
                {
                    scanf("%s%llu%d%d%d%d%d",students[i].name,&students[i].sId,&students[i].preScore,&students[i].trans,&students[i].wish[1],&students[i].wish[2],&students[i].wish[3]);
                    fprintf(input,"%s %llu %d %d %d %d %d\n",students[i].name,students[i].sId,students[i].preScore,students[i].trans,students[i].wish[1],students[i].wish[2],students[i].wish[3]);
                }
                fclose(input);
                printf("\n共%d名学生信息录入完成，并已保存至in.txt\n",sNum);
                hasRead=1,hasSort=0,hasSim=0;
                break;
            }
        case 2:
            {
                if(!hasRead)
                {
                    printf("请先录入学生信息！\n");
                }
                else if(hasSort)
                {
                    printf("已经投档啦！\n");
                }
                else
                {
                    input=fopen("in.txt","r");
                    getInfo();//从文件读入信息
                    fclose(input);

                    Qsort(0,sNum-1);//按成绩从高到低排序
                    int MAX=0;
                    for(i=1;i<=10;i++)
                    {
                        MAX+=planNum[i];//读入所有专业计划招生总数
                    }
                    MAX*=1.1;//按1.1倍投档
                    sNum=(sNum<=MAX?sNum:MAX);//人数不可超过MAX
                    printf("排序完成！共%d名学生投档成功，是否查看投档成功学生信息？(1是，其他数字否)\n",sNum);
                    scanf("%d",&op);
                    if(op==1)
                    {
                        printf("姓名\t学号\t\t成绩\t是否同意调剂\t第一志愿\t第二志愿\t第三志愿\n");
                        for(i=0;i<sNum;i++)
                        {
                            Student st=students[i];
                            printf("%s\t%llu\t%d\t%s\t\t%d\t\t%d\t\t%d\n",st.name,st.sId,st.preScore,st.trans==1?"是":"否",st.wish[1],st.wish[2],st.wish[3]);
                        }
                    }
                    hasSort=1;
                }
                break;
            }
        case 3:
            {
                if(!hasRead)
                {
                    printf("请先录入学生信息！\n");
                }
                else if(!hasSort)
                {
                    printf("请先给学生信息排序！\n");
                }
                else if(hasSim)
                {
                    printf("已经模拟过并保存结果啦!\n");
                }
                else
                {
                    output=fopen("result.txt","w");//保存结果文件
                    buildList();//根据排好序后的学生信息建立链表
                    simulate();//一切就绪，开始模拟招生
                    outputResult();//保存结果到文件，现在结果在链表里
                    fclose(output);
                    printf("模拟成功，结果已保存至result.txt，是否查看所有招生结果？(1是，其他数字否)\n");
                    scanf("%d",&op);
                    if(op==1)
                    {
                        printFile("result.txt");
                    }
                    hasSim=1;
                }
                break;
            }
        case 4:
            {
                if(!hasSim)
                {
                    printf("请先读入文件，排序，并模拟招生\n");
                }
                else
                {
                    printf("请输入要查询的学生学号：\n");
                    scanf("%llu",&sId);
					findStudent(sId);
                }
                break;
            }
        case 5:
            {
                return 0;
                break;
            }
        default:
            {
                printf("输入有误！\n");
                break;
            }
        }
    }
    return 0;
}
