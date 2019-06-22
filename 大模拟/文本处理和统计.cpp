#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
给定一段英文文本
需要将其规范化，即每段首行要空2个空格，段间不要有空行，每个句子首字母小写
标点符号后保留一个空格（句末标点不用）等等诸多要求
还有将各种缩写展开等
然后统计各个单词、标点、空格的频率，排序后输出 
*/

#define isSep(c) (c=='.'||c==','||c=='?'||c=='!'||c==';')//判断句子分隔符，可以自己再加
char filePath[101];//中间过程保存文件路径
char buf[1000001];//字符缓冲区
char Str[21];//中间过程用来存单词
FILE *normFile;//整理好的文档的文件指针
FILE *resultFile;//统计结果文件指针
typedef struct S_Word//存单词和其出现次数
{
    char s[21];
    int num;//出现次数
}Word;

struct R_Result//分析结果
{
    int praNum,sentNum,charNum,wordNum;//分别为段落、句子、字符、单词总数
    Word Dic[1001];//字典，存所有单词和其出现次数
    int dicNum;//字典长度
}Result;

int readFileToBuf()//将filePath所指文件内容读入到缓冲区，成功返回文件字符个数，否则返回-1
{
    int len=0;
    FILE *fp=NULL;//文件指针
    if((fp=fopen(filePath,"r"))==NULL)//防止打开失败
    {
        return -1;
    }
    else
    {
        char c;
        while((c=fgetc(fp))!=EOF)//将文件内容读入缓冲区
        {
            buf[len++]=c;
        }
        buf[len]='\0';//字符串末尾添加'\0'
        fclose(fp);
        return len;
    }
}

void printFile(char path[])//打印文件内容
{
    FILE *fp=fopen(path,"r");
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
}

void readWordsByPos(int L,int R)//根据buf中单词的起始和末位置提取单词到Str
{
	int i; 
    for(i=L;i<=R;i++)
    {
        Str[i-L]=buf[i];
    }
    Str[R-L+1]='\0';
}

//展开前的字符串和展开后的
char From[15][20]={"let's","we'll","we'd","what's","where's","that's","there's","here's","i'm","i'd","i'll","you're","they're","we're"};
char To[15][20]={"let us","we will","we would","what is","where is","that is","there is","here is","i am","i would","i will","you are","they are","we are"};

int replaceWord()//缩写展开，若需展开返回1，否则返回0
{
    int i,ans=0,isU=isupper(Str[0]);//先记录是否大写，因为判断时要统一小写首字母查询
    Str[0]=tolower(Str[0]);
    for(i=0;i<14;i++)
    {
        if(strcmp(From[i],Str)==0)//寻找匹配的缩写
        {
            strcpy(Str,To[i]);//用展开替换
            ans=1;
            break;
        }
    }
    if(isU)
    {
        Str[0]=toupper(Str[0]);//若首字母大写，恢复
    }
    return ans;
}

int Strip(int start)//除去start位置开始的空白符，返回第一个非空字符位置
{
    while(buf[start]!='\0'&&isspace(buf[start]))//向后找非空字符，直到找到或者到达尾部
    {
        ++start;
    }
    return start;
}

void getWords(int Start,int End,char lastPunc)//分割句子中的单词，lastPunc为本句前的符号
{
    int L=Start,R,fir=1;
    while(L<=End)
    {
        L=Strip(L);
        if(L<=End)
        {
            R=L+1;
            while(R<=End&&(!isspace(buf[R])))//空白符为单词的分隔符
            {
                ++R;
            }
            readWordsByPos(L,R-1);//buf[L]-buf[R-1]为单词位置
            if(fir)//判断是否为句子中第一个单词
            {
                if((islower(Str[0])&&lastPunc!=',')||Str[0]=='i')//逗号后句子，除了I，不必大写字母开头
                {
                    Str[0]=toupper(Str[0]);//第一个单词首字符大写
                }
                fir=0;
            }
            else
            {
                fprintf(normFile," ");//非第一个，单词前加一个空格隔开
            }
            ++Result.wordNum;
            if(replaceWord())//展开后单词数变为2个
            {
                ++Result.wordNum;
            }
            fprintf(normFile,"%s",Str);//第一个，单词前无需空格
            L=R+1;
        }
    }
}

void getSentences(int Start,int End)//分割段落中的句子，逐句处理。Start、End为段落起始位置和结束位置
{
    int L=Start,R,fir=1;
    char lastPunc=-1;
    while(L<=End)
    {
    	L=Strip(L);
    	if(L<=End)
    	{
	    	R=L+1;
	        while(R<=End&&(!isSep(buf[R])))//略过非分隔符
	        {
	            ++R;
	        }
	        if(!fir)//非第一句，前面输出空格空开
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
	            fprintf(normFile,"%c",buf[R]);//此时buf[R]为句子结束标点
	            lastPunc=buf[R];
	        }
	        L=R+1;
		}
    }
}

void getParagraphs()//分割段落，逐段处理文档
{
    int L=0,R,fir=1;//段落的起始和末尾位置
    while(buf[L]!='\0')
    {
        L=Strip(L);//先除去起始的空白符，避免干扰
        if(buf[L]!='\0')
        {
            R=L+1;
            while(buf[R]!='\0'&&buf[R]!='\n')//寻找该段的末位置，换行或文件尾为段的结束标志
            {
                ++R;
            }
            if(!fir)//段落间换行
            {
                fprintf(normFile,"\n");
            }
            else
            {
                fir=0;
            }
            ++Result.praNum;
            fprintf(normFile,"  ");//段落前的缩进
            getSentences(L,R-1);
			L=R;
        }
        else//已经分析完
        {
            break;
        }
    }

}

void addWord(char s[])//向统计结果的Dic中插入单词s
{
    int len=Result.dicNum,i;
    if(!(s[0]=='I'&&s[1]=='\0'))
    {
        s[0]=tolower(s[0]);//除了单词I，首字母统一小写
    }
    for(i=0;i<len;i++)
    {
        if(strcmp(Result.Dic[i].s,s)==0)//该单词以前出现过
        {
            ++Result.Dic[i].num;
            return;
        }
    }
    strcpy(Result.Dic[len].s,s);//未出现过，插入
    Result.Dic[len].num=1;
    ++Result.dicNum;
}

void swapWord(Word *a,Word *b)//交换两个字符串
{
    char temp[21];
    int n;
    strcpy(temp,a->s);
    strcpy(a->s,b->s);
    strcpy(b->s,temp);
    n=a->num,a->num=b->num,b->num=n;
}

void sortByLex()//按字典序排序
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

void sortByNum()//按词频排序
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

void getResult()//获取统计结果
{
    char c,temp[3];
    int len,i;
    temp[0]=' ',temp[1]='\0';//用来统计空格
    while((c=fgetc(normFile))!=EOF)//先统计字符数
    {
        if(c!='\n')
        {
            ++Result.charNum;//换行不统计
        }
        if(c==' ')
        {
            addWord(temp);
        }
    }
    rewind(normFile);//指针归位
    //printf("字符数为%d\n",Result.charNum);
    while(fscanf(normFile,"%s",Str)!=EOF)//开始统计单词
    {
        len=strlen(Str);
        if(isSep(Str[len-1]))//当字符串读入时，单词和末尾的标点会一起读入，若有标点，去掉
        {
            temp[0]=Str[len-1];
            temp[1]='\0';
            addWord(temp);//统计标点
            Str[len-1]='\0';
        }
        addWord(Str);//将当前读到的单词存入结果
        //printf("%s\n",Str);
        //printf("%d\n",Result.dicNum);
    }
    //统计完成，开始排序，冒泡排序是稳定的，所以先按字典序排，排好后再按词频排，就能得到所需结果
    sortByLex();
    sortByNum();
    len=Result.dicNum;
    fprintf(resultFile,"段落数：%d\n句子数：%d\n单词数：%d\n字符数：%d\n",Result.praNum,Result.sentNum,Result.wordNum,Result.charNum);
    fprintf(resultFile,"词频统计如下：\n");
    for(i=0;i<len;i++)
    {
        if(strcmp(Result.Dic[i].s," ")==0)
        {
            fprintf(resultFile,"%s %d\n","空格",Result.Dic[i].num);
        }
        else
        {
            fprintf(resultFile,"%s %d\n",Result.Dic[i].s,Result.Dic[i].num);
        }
    }
}

char path[100];//输入文件所在文件夹的路径 
char nfPath[100];//整理后的文件路径 
char rfPath[100];//统计结果文件路径 
void getPath()//根据输入的文件路径，获取其所在文件夹 
{
	int len=strlen(path),i,flag=1;
	for(i=len-1;i>=0;i--)
	{
		if(path[i]=='\\'||path[i]=='/')//两种都是路径分隔符 
		{
			path[i+1]='\0'; //滤去文件名
			flag=0;
			break;
		}
	}
	if(flag)//只含文件名情况 
	{
		path[0]='\0';
	}
	strcpy(nfPath,path);
	strcpy(rfPath,path);
	strcat(nfPath,"Normalized.txt");
	strcat(rfPath,"result.txt");//连接得两个输出文件的路径 
	//printf("[%s] [%s]\n",nfPath,rfPath);
}

int main(int argc, char* argv[])
{
    int len=0;//文件字符个数
    int op;//选择的菜单项
    int hasRead=0;//是否已经读入
    int hasNorm=0;//是否已规范化
    int hasSta=0;//是否已统计
    while(1)
    {
        printf("请选择菜单项：\n1、读入文件\n2、文档整理（规范化）\n3、文档统计\n4、退出\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                hasNorm=hasSta=0;
                printf("请输入待读入的文档路径：\n");
                scanf("%s",filePath);
                strcpy(path,filePath);
                getPath();//提取文件所在文件夹路径
                if((len=readFileToBuf())==-1)
                {
                    printf("文件打开失败！\n");
                }
                else
                {
                    hasRead=1;
                    printf("读入成功！文件内容如下：\n=========\n%s\n=========\n",buf);
                }
                break;
            }
        case 2:
            {
                if(!hasRead)
                {
                    printf("请先读入文件！\n");
                }
                else
                {
                    Result.charNum=Result.praNum=Result.sentNum=Result.wordNum=Result.dicNum=0;//在整理的过程中可以边统计
                    normFile=fopen(nfPath,"w");//保存整理后的文档
                    getParagraphs();//逐段处理，并保存至文件
                    fclose(normFile);
                    printf("整理完成，整理结果已保存至Normalized.txt，预览如下\n=========\n");
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
                    printf("请先读入文件！\n");
                }
                else if(!hasNorm)
                {
                    printf("请先整理文档！\n");
                }
                else
                {
                    Result.charNum=Result.dicNum=0;//在整理的过程中可以边统计
                    //在整理的过程中已经统计好了段落、句子和单词的数目
                    normFile=fopen(nfPath,"r");
                    resultFile=fopen(rfPath,"w");
                    getResult();
                    fclose(normFile);
                    fclose(resultFile);
                    printf("整理完成，整理结果已保存至result.txt，预览如下\n=========\n");
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
                puts("输入错误！请重新输入！");
            }
        }
    }
    return 0;
}
