#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
ʹ������ʱ����ǰ�ڵ�����һ���ڵ��next��ʾ 

����ѧ����־Ը�ͷ���������ʱʼ���Է������ȵ�ԭ��¼ȡ����־Ը
���ǵ�ǰѧ������ǰ־Ըרҵ����ʱ����Ҫ���ֺ�����������¼ȡ
���һ��е����Ȳ���
�ͻ�Ҫ���Ȱ��ɼ������ٽ�������ÿ����ǰѧ����Ҫ����ʱ���������Ѱ�Һ���λ�ò��� 
*/

int sNum;//Ͷ��ѧ������
FILE * input, *output;//���������ļ�ָ��

typedef struct S_Student//����ѧ����Ϣ
{
    char name[20];//ѧ������
    unsigned long long sId;//ѧ��
    int preScore,nowScore;//ԭʼ�������͵�ǰ����
    int trans;//�Ƿ�ͬ�����
    int wish[4];//wish[i]�����i־Ը��רҵ��ţ�0�Ų���
    int nowWish;//¼ȡ������������־Ը���𣬴���3��ʾδ��¼ȡ�򱻵���
    int admittedMajor;//���ձ�¼ȡ��רҵ��ţ�-1��ʾδ��¼ȡ

}Student;

typedef struct S_Node//����ڵ�
{
    Student data;
    struct S_Node *next;
}Node;

Student students[10001];//����Ͷ����ѧ��
Node *head=NULL;//����ͷ�ڵ�ָ��
int planNum[11];//planNum[i]��ʾiרҵ�ƻ�������
int nowNum[11];//nowNum[i]��ʾiרҵ��ǰ��������

void printFile(char path[])//��ӡ�ļ�����
{
    FILE *fp=fopen(path,"r");
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
    fclose(fp);
}

char filePath[100];//�ļ�·��

void getInfo()//���ļ��ж���ѧ����Ϣ
{
    sNum=0;
    while(fscanf(input,"%s%llu%d%d%d%d%d",students[sNum].name,&students[sNum].sId,&students[sNum].preScore,&students[sNum].trans,&students[sNum].wish[1],&students[sNum].wish[2],&students[sNum].wish[3])!=EOF)
    {
        students[sNum].admittedMajor=-1;
        students[sNum].nowScore=students[sNum].preScore;
        students[sNum].nowWish=1;
        ++sNum;
    }
    printf("\n������ɣ���%d��ѧ��\n",sNum);
}

int findMajor()//Ѱ�ҵ�ǰΪ����������������ӽ��ƻ�����רҵ������רҵ��ţ��Ҳ�������-1
{
    int i,ans=-1,MIN=0x3f3f3f3f,temp;
    for(i=1;i<=10;i++)
    {
        temp=planNum[i]-nowNum[i];//ʣ������ָ��
        if(temp>0&&temp<MIN)//��ʣ������ָ�����ٵ�רҵ
        {
            MIN=temp;
            ans=i;//����רҵ���
        }
    }
    return ans;
}

void Qsort(int be,int ed)//��������
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
        students[i]=temp;//��ʱi==j
        Qsort(be,i-1);
        Qsort(i+1,ed);
    }
}

Node *getNewNode(Student data)//����һ����Ϣ��Ϊdata������ڵ㣬���ص�ַ
{
    Node *ans=(Node *)malloc(sizeof(Node));
    ans->data=data;
    return ans;
}

void pushFront(Node *nd)//������ͷ������һ���ڵ�
{
    nd->next=head->next;
    head->next=nd;
}

Node* cutOut(Node *pre)//��pre�ڵ�ָ��Ľڵ�������ȡ���������ظýڵ�ָ��
{
    Node *ans=pre->next;
    pre->next=ans->next;
    return ans;
}

//��pre�����ڵ�nd���ýڵ�Ѱ��pre���һ��nowScoreС�ڵ������Ľڵ㲢������ǰ�棬�Ա�����������
void findAndInsert(Node *pre,Node *nd)
{
    while(pre->next!=NULL)
    {
        if(pre->next->data.nowScore<=nd->data.nowScore)//���Բ�����pre��
        {
            nd->next=pre->next;
            pre->next=nd;
            return;
        }
        pre=pre->next;//���ܲ��룬���������λ��
    }
    //��ʱpre->next==NULL�����������һ���ڵ㣬˵��ndӦ�ò��뵽ĩλ
    nd->next=NULL;
    pre->next=nd;
}

void delList()//�������
{
    if(head!=NULL)
    {
        Node *now=head,*temp;
        while(now!=NULL)
        {
            temp=head->next;//������һ���ڵ�ָ��
            free(now);//�ͷű��ڵ��ڴ�
            now=temp;
        }
    }
}

void buildList()//�����ź�������飬��������
{
    delList();//���ͷ�ԭ�����ڴ�
    Node *temp;
    head=getNewNode(students[0]);//ͷ�����Ϣ�������壬����
    head->next=NULL;
    int i;
    for(i=sNum-1;i>=0;i--)//����������ͷ������ڵ㣬Ϊ�˱��ַ�������Ҫ���Ų���
    {
        temp=getNewNode(students[i]);
        pushFront(temp);
        //printf("%s %d %d\n",students[i].name,students[i].preScore,students[i].wish[1]);
	}
}

void simulate()//ģ������
{
    Node *p=head,*temp;
    Student stu;
    int major;
    while(p->next!=NULL)//�����ͷ������
    {
        stu=p->next->data;
        if(stu.nowWish<=3)//־Ը����δ�꣬�������
        {
            major=stu.wish[stu.nowWish];//��ȡ��ǰ־Ըרҵ
            if(nowNum[major]<planNum[major])//��רҵδ¼��
            {
                ++nowNum[major];
                p->next->data.admittedMajor=major;//��Ϊ��¼ȡ
                p=p->next;//��ѧ�������꣬�����λ������һ��
            }
            else//¼���ˣ���Ҫ־Ը���������ֺ���������
            {
                p->next->data.nowScore-=5;//������5��
                p->next->data.nowWish+=1;//־Ը���𽵵�
                temp=cutOut(p);//�Ѹýڵ��ȡ����
                findAndInsert(p,temp);//Ѱ�Һ���λ�����²���
            }
        }
        else//��Ҫ����
        {
            if(stu.trans)//ͬ���������ͬ�����ʱ��ԭ�������ߵ�Ҳ�ǿ϶��ȱ�����
            {
                major=findMajor();
                if(major!=-1)//�����ɹ�
                {
                    p->next->data.admittedMajor=major;
                }
            }
            p=p->next;
        }
    }
}

void outputResult()//��������2�飬�ֱ����¼ȡ�ɹ�������δ¼ȡ����
{
    Node *p=head;
    Student stu;
    fprintf(output,"¼ȡ�ɹ�������\n");
    fprintf(output,"����\t\t¼ȡרҵ\t¼ȡ־Ը\n");
    while(p->next!=NULL)
    {
        stu=p->next->data;
        if(stu.admittedMajor!=-1)
        {
            if(stu.nowWish>3)//������
            {
                fprintf(output,"%s\t\t%d\t\t����\n",stu.name,stu.admittedMajor);
            }
            else
            {
                fprintf(output,"%s\t\t%d\t\t��%d־Ը\n",stu.name,stu.admittedMajor,stu.nowWish);
            }
        }
        p=p->next;
    }
    p=head;//ָ��ص�ͷ���
    fprintf(output,"\nδ¼ȡ������\n");
    fprintf(output,"����\n");
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

void findStudent(unsigned long long sId)//��ѯĳ��ѧ��¼ȡ���
{
    Node *p=head;
    Student stu;
    while(p->next!=NULL)//���������������ѧ��ΪsId��ѧ��
    {
        stu=p->next->data;
        if(stu.sId==sId)
        {
            printf("��ѯ�ɹ���ѧ��¼ȡ��Ϣ���£�\n");
            if(stu.admittedMajor!=-1)//��¼ȡ
            {
                printf("�ɹ�¼ȡ��\n");
                printf("¼ȡרҵ\t¼ȡ־Ը\n");
                if(stu.nowWish>3)//������
                {
                    printf("%d\t\t����\n",stu.admittedMajor);
                }
                else
                {
                    printf("%d\t\t��%d־Ը\n",stu.admittedMajor,stu.nowWish);
                }
            }
            else
            {
                printf("δ¼ȡ��\n");
            }
            return;//��ʱ�˳�
        }
        p=p->next;
    }
    printf("��ѯʧ�ܣ������ڸ�ѧ����\n");
}

int main(int argc, char* argv[])
{
    int op,i,hasRead=0,hasSort=0,hasSim=0,num;
    unsigned long long sId;
    printf("�����ʼ������������10��רҵ�ֱ������������\n");
    for(i=1;i<=10;i++)
    {
        scanf("%d",&planNum[i]);
        nowNum[i]=0;
    }
    printf("����ɹ���\n");
    while(1)
    {
        printf("\n��ѡ��˵��\n1��¼��ѧ������\n2��Ͷ����ѧ���ɼ�����\n3��ģ������\n4����ѯ¼ȡ���\n5���˳�\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                printf("������ѧ�����ݣ������ʽ���£�\n��һ��һ����������ʾҪ¼���ѧ����\n������ÿ��һ��ѧ����Ϣ������������ ѧ�� ���� �Ƿ�ͬ�������1ͬ�⣬0��ͬ�⣩ ��һ־Ըרҵ �ڶ�־Ըרҵ ����־Ըרҵ��רҵΪ1-10�����ִ��룩\n");

                input=fopen("in.txt","w");//������¼����Ϣ���浽�ļ�
                scanf("%d",&sNum);
                for(i=0;i<sNum;i++)
                {
                    scanf("%s%llu%d%d%d%d%d",students[i].name,&students[i].sId,&students[i].preScore,&students[i].trans,&students[i].wish[1],&students[i].wish[2],&students[i].wish[3]);
                    fprintf(input,"%s %llu %d %d %d %d %d\n",students[i].name,students[i].sId,students[i].preScore,students[i].trans,students[i].wish[1],students[i].wish[2],students[i].wish[3]);
                }
                fclose(input);
                printf("\n��%d��ѧ����Ϣ¼����ɣ����ѱ�����in.txt\n",sNum);
                hasRead=1,hasSort=0,hasSim=0;
                break;
            }
        case 2:
            {
                if(!hasRead)
                {
                    printf("����¼��ѧ����Ϣ��\n");
                }
                else if(hasSort)
                {
                    printf("�Ѿ�Ͷ������\n");
                }
                else
                {
                    input=fopen("in.txt","r");
                    getInfo();//���ļ�������Ϣ
                    fclose(input);

                    Qsort(0,sNum-1);//���ɼ��Ӹߵ�������
                    int MAX=0;
                    for(i=1;i<=10;i++)
                    {
                        MAX+=planNum[i];//��������רҵ�ƻ���������
                    }
                    MAX*=1.1;//��1.1��Ͷ��
                    sNum=(sNum<=MAX?sNum:MAX);//�������ɳ���MAX
                    printf("������ɣ���%d��ѧ��Ͷ���ɹ����Ƿ�鿴Ͷ���ɹ�ѧ����Ϣ��(1�ǣ��������ַ�)\n",sNum);
                    scanf("%d",&op);
                    if(op==1)
                    {
                        printf("����\tѧ��\t\t�ɼ�\t�Ƿ�ͬ�����\t��һ־Ը\t�ڶ�־Ը\t����־Ը\n");
                        for(i=0;i<sNum;i++)
                        {
                            Student st=students[i];
                            printf("%s\t%llu\t%d\t%s\t\t%d\t\t%d\t\t%d\n",st.name,st.sId,st.preScore,st.trans==1?"��":"��",st.wish[1],st.wish[2],st.wish[3]);
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
                    printf("����¼��ѧ����Ϣ��\n");
                }
                else if(!hasSort)
                {
                    printf("���ȸ�ѧ����Ϣ����\n");
                }
                else if(hasSim)
                {
                    printf("�Ѿ�ģ�������������!\n");
                }
                else
                {
                    output=fopen("result.txt","w");//�������ļ�
                    buildList();//�����ź�����ѧ����Ϣ��������
                    simulate();//һ�о�������ʼģ������
                    outputResult();//���������ļ������ڽ����������
                    fclose(output);
                    printf("ģ��ɹ�������ѱ�����result.txt���Ƿ�鿴�������������(1�ǣ��������ַ�)\n");
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
                    printf("���ȶ����ļ������򣬲�ģ������\n");
                }
                else
                {
                    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
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
                printf("��������\n");
                break;
            }
        }
    }
    return 0;
}
