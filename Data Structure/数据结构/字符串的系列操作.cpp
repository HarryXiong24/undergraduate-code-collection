#include<stdio.h>
#include<stdlib.h>

//字符串的系列操作

//字符串结构体定义
#define MaxSize 200                       //预估最大长度 
typedef struct{
	char v[MaxSize];
	int len;                              //字符串长度 
}MyString;


//判断字符串是否相等
int equals(MyString *pstr1, MyString *pstr2)
{
	int i = 0;
	if(pstr1->len == pstr2->len)          //先判断长度 
	{
		for(i = 0; i < pstr1->len; i++)
		{
			if(pstr1->v[i] != pstr2->v[i])
			{
				return 0;	
			}	
		}	
	}	
	
	return 1;
}

//求字符串长度
int getLength(MyString *pstr)
{
	return pstr->len;
} 

//连接两个字符串
MyString *concat(MyString *pstr1, MyString *pstr2)
{
	int i = 0;
	for(i = 0; i<pstr2->len; i++)
	{
		pstr1->v[pstr1->len] = pstr2->v[i];
		pstr1->len++;
	}
	return pstr1;
}

//求子串
MyString *concat(MyString *psub, MyString *pmain, int start, int end)
{
	int i = 0;
	psub->len = 0;
	if(start < 0)
	{
		start = 0;
	}
	if(end > pmain->len)
	{
		end = pmain->len;
	}
	for(i = start; i < end; i++)
	{
		psub->v[psub->len] = pmain->v[i];
		psub->len++;
	}
	
	return psub;
}

//子串定位(KMP匹配算法)
//求部分匹配串 
void partStringLen(MyString *pMode, int n[])
{
	int i = 1, j = 0;
	int m = pMode->len;
	n[0] = 0;	
	while(i < m)
	{
		if(pMode->v[i] == pMode->v[j])
		{
			n[i] = j + 1;
			i++;
			j++;
		}
		else if(j > 0)
		{
			j = n[j-1];
		}
		else
		{
			n[i++] = 0;
		}
	}
} 
//KMP算法
int kmpMatch(MyString *pDst, MyString *pMode)
{
	int n = pDst->len;
	int m = pMode->len;
	int i = 0, j = 0, nxt[MaxSize];
	partStringLen(pMode, nxt);
	while( i < n)
	{
		if(pDst->v[i] == pMode->v[j])
		{
			if(j == m-1)
			{
				return i-j;
			}	
			i++;
			j++;
		}
		else
		{
			if(j > 0)
			{
				j = nxt[j-1]; 
			}	
			else
			{
				i++;
			}
		}	
	}	
	return -1;
} 

//子串替换
MyString *replace(MyString *s, MyString *t, MyString *r)
{
	MyString tmp;
	int begin, i;
	while( (begin = kmpMatch(s, t)) >= 0 )
	{
		tmp.len = s->len - t->len - begin;
		for(i = 0; i< tmp.len; i++)                              //将子串t后面的字符保存到临时数组中 
		{
			tmp.v[i] = s->v[begin + t->len + i];
		}
		for(i = 0; i< r->len; i++)                              //将替换串复制到子串t所在的位置 
		{
			s->v[begin + i] = tmp.v[i];
		}
		for(i = 0; i< tmp.len; i++)                             //将临时串中的字符复制到字符串s中 
		{
			s->v[begin + r->len + i] = tmp.v[i];
		}
		s->len = s->len - t->len + r->len;                      //更新字符串长度 
	}
	return s;
} 














 
