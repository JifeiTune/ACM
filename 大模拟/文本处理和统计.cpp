#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
����һ��Ӣ���ı�
��Ҫ����淶������ÿ������Ҫ��2���ո񣬶μ䲻Ҫ�п��У�ÿ����������ĸСд
�����ź���һ���ո񣨾�ĩ��㲻�ã��ȵ����Ҫ��
���н�������дչ����
Ȼ��ͳ�Ƹ������ʡ���㡢�ո��Ƶ�ʣ��������� 
*/

#define isSep(c) (c=='.'||c==','||c=='?'||c=='!'||c==';')//�жϾ��ӷָ����������Լ��ټ�
char filePath[101];//�м���̱����ļ�·��
char buf[1000001];//�ַ�������
char Str[21];//�м���������浥��
FILE *normFile;//����õ��ĵ����ļ�ָ��
FILE *resultFile;//ͳ�ƽ���ļ�ָ��
typedef struct S_Word//�浥�ʺ�����ִ���
{
    char s[21];
    int num;//���ִ���
}Word;

struct R_Result//�������
{
    int praNum,sentNum,charNum,wordNum;//�ֱ�Ϊ���䡢���ӡ��ַ�����������
    Word Dic[1001];//�ֵ䣬�����е��ʺ�����ִ���
    int dicNum;//�ֵ䳤��
}Result;

int readFileToBuf()//��filePath��ָ�ļ����ݶ��뵽���������ɹ������ļ��ַ����������򷵻�-1
{
    int len=0;
    FILE *fp=NULL;//�ļ�ָ��
    if((fp=fopen(filePath,"r"))==NULL)//��ֹ��ʧ��
    {
        return -1;
    }
    else
    {
        char c;
        while((c=fgetc(fp))!=EOF)//���ļ����ݶ��뻺����
        {
            buf[len++]=c;
        }
        buf[len]='\0';//�ַ���ĩβ���'\0'
        fclose(fp);
        return len;
    }
}

void printFile(char path[])//��ӡ�ļ�����
{
    FILE *fp=fopen(path,"r");
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
}

void readWordsByPos(int L,int R)//����buf�е��ʵ���ʼ��ĩλ����ȡ���ʵ�Str
{
	int i; 
    for(i=L;i<=R;i++)
    {
        Str[i-L]=buf[i];
    }
    Str[R-L+1]='\0';
}

//չ��ǰ���ַ�����չ�����
char From[15][20]={"let's","we'll","we'd","what's","where's","that's","there's","here's","i'm","i'd","i'll","you're","they're","we're"};
char To[15][20]={"let us","we will","we would","what is","where is","that is","there is","here is","i am","i would","i will","you are","they are","we are"};

int replaceWord()//��дչ��������չ������1�����򷵻�0
{
    int i,ans=0,isU=isupper(Str[0]);//�ȼ�¼�Ƿ��д����Ϊ�ж�ʱҪͳһСд����ĸ��ѯ
    Str[0]=tolower(Str[0]);
    for(i=0;i<14;i++)
    {
        if(strcmp(From[i],Str)==0)//Ѱ��ƥ�����д
        {
            strcpy(Str,To[i]);//��չ���滻
            ans=1;
            break;
        }
    }
    if(isU)
    {
        Str[0]=toupper(Str[0]);//������ĸ��д���ָ�
    }
    return ans;
}

int Strip(int start)//��ȥstartλ�ÿ�ʼ�Ŀհ׷������ص�һ���ǿ��ַ�λ��
{
    while(buf[start]!='\0'&&isspace(buf[start]))//����ҷǿ��ַ���ֱ���ҵ����ߵ���β��
    {
        ++start;
    }
    return start;
}

void getWords(int Start,int End,char lastPunc)//�ָ�����еĵ��ʣ�lastPuncΪ����ǰ�ķ���
{
    int L=Start,R,fir=1;
    while(L<=End)
    {
        L=Strip(L);
        if(L<=End)
        {
            R=L+1;
            while(R<=End&&(!isspace(buf[R])))//�հ׷�Ϊ���ʵķָ���
            {
                ++R;
            }
            readWordsByPos(L,R-1);//buf[L]-buf[R-1]Ϊ����λ��
            if(fir)//�ж��Ƿ�Ϊ�����е�һ������
            {
                if((islower(Str[0])&&lastPunc!=',')||Str[0]=='i')//���ź���ӣ�����I�����ش�д��ĸ��ͷ
                {
                    Str[0]=toupper(Str[0]);//��һ���������ַ���д
                }
                fir=0;
            }
            else
            {
                fprintf(normFile," ");//�ǵ�һ��������ǰ��һ���ո����
            }
            ++Result.wordNum;
            if(replaceWord())//չ���󵥴�����Ϊ2��
            {
                ++Result.wordNum;
            }
            fprintf(normFile,"%s",Str);//��һ��������ǰ����ո�
            L=R+1;
        }
    }
}

void getSentences(int Start,int End)//�ָ�����еľ��ӣ���䴦��Start��EndΪ������ʼλ�úͽ���λ��
{
    int L=Start,R,fir=1;
    char lastPunc=-1;
    while(L<=End)
    {
    	L=Strip(L);
    	if(L<=End)
    	{
	    	R=L+1;
	        while(R<=End&&(!isSep(buf[R])))//�Թ��Ƿָ���
	        {
	            ++R;
	        }
	        if(!fir)//�ǵ�һ�䣬ǰ������ո�տ�
	        {
	            fprintf(normFile," ");
	        }
	        else
	        {
	            fir=0;
	        }
	        ++Result.sentNum;
	        getWords(L,R-1,lastPunc);
	        if(R<=End)
	        {
	            fprintf(normFile,"%c",buf[R]);//��ʱbuf[R]Ϊ���ӽ������
	            lastPunc=buf[R];
	        }
	        L=R+1;
		}
    }
}

void getParagraphs()//�ָ���䣬��δ����ĵ�
{
    int L=0,R,fir=1;//�������ʼ��ĩβλ��
    while(buf[L]!='\0')
    {
        L=Strip(L);//�ȳ�ȥ��ʼ�Ŀհ׷����������
        if(buf[L]!='\0')
        {
            R=L+1;
            while(buf[R]!='\0'&&buf[R]!='\n')//Ѱ�Ҹöε�ĩλ�ã����л��ļ�βΪ�εĽ�����־
            {
                ++R;
            }
            if(!fir)//����任��
            {
                fprintf(normFile,"\n");
            }
            else
            {
                fir=0;
            }
            ++Result.praNum;
            fprintf(normFile,"  ");//����ǰ������
            getSentences(L,R-1);
			L=R;
        }
        else//�Ѿ�������
        {
            break;
        }
    }

}

void addWord(char s[])//��ͳ�ƽ����Dic�в��뵥��s
{
    int len=Result.dicNum,i;
    if(!(s[0]=='I'&&s[1]=='\0'))
    {
        s[0]=tolower(s[0]);//���˵���I������ĸͳһСд
    }
    for(i=0;i<len;i++)
    {
        if(strcmp(Result.Dic[i].s,s)==0)//�õ�����ǰ���ֹ�
        {
            ++Result.Dic[i].num;
            return;
        }
    }
    strcpy(Result.Dic[len].s,s);//δ���ֹ�������
    Result.Dic[len].num=1;
    ++Result.dicNum;
}

void swapWord(Word *a,Word *b)//���������ַ���
{
    char temp[21];
    int n;
    strcpy(temp,a->s);
    strcpy(a->s,b->s);
    strcpy(b->s,temp);
    n=a->num,a->num=b->num,b->num=n;
}

void sortByLex()//���ֵ�������
{
    int len=Result.dicNum,i,j;
    for(i=len-1;len>=1;len--)
    {
        for(j=0;j<i;j++)
        {
            if(strcmp(Result.Dic[j].s,Result.Dic[j+1].s)>0)
            {
                swapWord(&Result.Dic[j],&Result.Dic[j+1]);
            }
        }
    }
}

void sortByNum()//����Ƶ����
{
    int len=Result.dicNum,i,j;
    for(i=len-1;len>=1;len--)
    {
        for(j=0;j<i;j++)
        {
            if(Result.Dic[j].num<Result.Dic[j+1].num)
            {
                swapWord(&Result.Dic[j],&Result.Dic[j+1]);
            }
        }
    }
}

void getResult()//��ȡͳ�ƽ��
{
    char c,temp[3];
    int len,i;
    temp[0]=' ',temp[1]='\0';//����ͳ�ƿո�
    while((c=fgetc(normFile))!=EOF)//��ͳ���ַ���
    {
        if(c!='\n')
        {
            ++Result.charNum;//���в�ͳ��
        }
        if(c==' ')
        {
            addWord(temp);
        }
    }
    rewind(normFile);//ָ���λ
    //printf("�ַ���Ϊ%d\n",Result.charNum);
    while(fscanf(normFile,"%s",Str)!=EOF)//��ʼͳ�Ƶ���
    {
        len=strlen(Str);
        if(isSep(Str[len-1]))//���ַ�������ʱ�����ʺ�ĩβ�ı���һ����룬���б�㣬ȥ��
        {
            temp[0]=Str[len-1];
            temp[1]='\0';
            addWord(temp);//ͳ�Ʊ��
            Str[len-1]='\0';
        }
        addWord(Str);//����ǰ�����ĵ��ʴ�����
        //printf("%s\n",Str);
        //printf("%d\n",Result.dicNum);
    }
    //ͳ����ɣ���ʼ����ð���������ȶ��ģ������Ȱ��ֵ����ţ��źú��ٰ���Ƶ�ţ����ܵõ�������
    sortByLex();
    sortByNum();
    len=Result.dicNum;
    fprintf(resultFile,"��������%d\n��������%d\n��������%d\n�ַ�����%d\n",Result.praNum,Result.sentNum,Result.wordNum,Result.charNum);
    fprintf(resultFile,"��Ƶͳ�����£�\n");
    for(i=0;i<len;i++)
    {
        if(strcmp(Result.Dic[i].s," ")==0)
        {
            fprintf(resultFile,"%s %d\n","�ո�",Result.Dic[i].num);
        }
        else
        {
            fprintf(resultFile,"%s %d\n",Result.Dic[i].s,Result.Dic[i].num);
        }
    }
}

char path[100];//�����ļ������ļ��е�·�� 
char nfPath[100];//�������ļ�·�� 
char rfPath[100];//ͳ�ƽ���ļ�·�� 
void getPath()//����������ļ�·������ȡ�������ļ��� 
{
	int len=strlen(path),i,flag=1;
	for(i=len-1;i>=0;i--)
	{
		if(path[i]=='\\'||path[i]=='/')//���ֶ���·���ָ��� 
		{
			path[i+1]='\0'; //��ȥ�ļ���
			flag=0;
			break;
		}
	}
	if(flag)//ֻ���ļ������ 
	{
		path[0]='\0';
	}
	strcpy(nfPath,path);
	strcpy(rfPath,path);
	strcat(nfPath,"Normalized.txt");
	strcat(rfPath,"result.txt");//���ӵ���������ļ���·�� 
	//printf("[%s] [%s]\n",nfPath,rfPath);
}

int main(int argc, char* argv[])
{
    int len=0;//�ļ��ַ�����
    int op;//ѡ��Ĳ˵���
    int hasRead=0;//�Ƿ��Ѿ�����
    int hasNorm=0;//�Ƿ��ѹ淶��
    int hasSta=0;//�Ƿ���ͳ��
    while(1)
    {
        printf("��ѡ��˵��\n1�������ļ�\n2���ĵ������淶����\n3���ĵ�ͳ��\n4���˳�\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                hasNorm=hasSta=0;
                printf("�������������ĵ�·����\n");
                scanf("%s",filePath);
                strcpy(path,filePath);
                getPath();//��ȡ�ļ������ļ���·��
                if((len=readFileToBuf())==-1)
                {
                    printf("�ļ���ʧ�ܣ�\n");
                }
                else
                {
                    hasRead=1;
                    printf("����ɹ����ļ��������£�\n=========\n%s\n=========\n",buf);
                }
                break;
            }
        case 2:
            {
                if(!hasRead)
                {
                    printf("���ȶ����ļ���\n");
                }
                else
                {
                    Result.charNum=Result.praNum=Result.sentNum=Result.wordNum=Result.dicNum=0;//������Ĺ����п��Ա�ͳ��
                    normFile=fopen(nfPath,"w");//�����������ĵ�
                    getParagraphs();//��δ������������ļ�
                    fclose(normFile);
                    printf("������ɣ��������ѱ�����Normalized.txt��Ԥ������\n=========\n");
                    printFile(nfPath);
                    printf("\n=========\n");
                }
                hasNorm=1;
                break;
            }
        case 3:
            {
                if(!hasRead)
                {
                    printf("���ȶ����ļ���\n");
                }
                else if(!hasNorm)
                {
                    printf("���������ĵ���\n");
                }
                else
                {
                    Result.charNum=Result.dicNum=0;//������Ĺ����п��Ա�ͳ��
                    //������Ĺ������Ѿ�ͳ�ƺ��˶��䡢���Ӻ͵��ʵ���Ŀ
                    normFile=fopen(nfPath,"r");
                    resultFile=fopen(rfPath,"w");
                    getResult();
                    fclose(normFile);
                    fclose(resultFile);
                    printf("������ɣ��������ѱ�����result.txt��Ԥ������\n=========\n");
                    printFile(rfPath);
                    printf("\n=========\n");
                }
                break;
            }
        case 4:
            {
                return 0;
            }
        default:
            {
                puts("����������������룡");
            }
        }
    }
    return 0;
}
