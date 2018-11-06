//1.ʵ��strcpy
#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *my_strcpy(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	char *pstr = dest;
	while (*pstr++ = *src++)
	{
		;
	}
	return dest;
}

int main()
{
	char str1[] = "abcdefg";
	char str2[10] = {0};
	char *str = my_strcpy(str2, str1);
	printf("%s\n", str);
	system("pause");
	return 0;
}


//2.ʵ��strcat
#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *my_strcat(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	char *pstr = dest;
	while (*pstr)
	{
		pstr++;
	}
	while (*pstr++ = *src++)
	{
		;
	}
	return dest;
}

int main()
{
	char str1[20] = "abcdefg";
	char str2[] = "abcdefg";
	char *str = my_strcat(str1, str2);
	printf("%s\n", str);
	system("pause");
	return 0;
}


//3.ʵ��strstr
#include <stdio.h>
#include <windows.h>
#include <assert.h>

const char *my_strstr(const char *dest, const char *src)
{
	assert(dest);
	assert(src);
	const char *pstr = dest;
    const char *pdest = pstr;
	while (*pstr)
	{
		pdest = pstr;
		while (*pstr == *src && *src)
		{
			pstr++;
			src++;
		}
		if (*src == '\0')
		{
			return pdest;
		}
		pstr++;
	}
	return NULL;
}

int main()
{
	char str1[20] = "abcdefg1234defg";
	const char *str = my_strstr(str1, "defg");
	printf("%s\n", str);
	system("pause");
	return 0;
}

//4.ʵ��strchr
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#pragma warning(disable:4996)

const char *my_strchr(const char* str, char ch)
{
	assert(str);
	const char *pdest = str;
	while (*pdest != ch && *pdest)
	{
		pdest++;
	}
	if (*pdest == ch)
	{
		return pdest;
	}
	else
	{
		return NULL;
	}
}

int main()
{
	char str[] = "abcdefg1234";
	char ch = 0;
	scanf("%c", &ch);
	const char *pstr = my_strchr(str, ch);
	if (pstr == NULL)
	{
		printf("<NULL>\n");
	}
	else
	{
		int result = pstr - str + 1;
		printf("%d\n", result);
	}
	system("pause");
	return 0;
}


//5.ʵ��strcmp

//��������⣬һ��Ҫ�࿴��������
//��������⣬һ��Ҫ�࿴��������
//��������⣬һ��Ҫ�࿴��������

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#pragma warning(disable:4996)

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	int sub;
	while (!(sub = (*str1 - *str2)) && *str1)//�����ַ�����Ҷ���Ϊ'\0'�ͼ���ѭ��
	{
		str1++;
		str2++;
	}
	if (sub > 0)
	{
		return 1;
	}
	else if (sub < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str1[] = "abcdEfg123";
	char str2[] = "abcdEfg123";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}


//6.ʵ��memcpy
//�˺��������ڴ渲�ǵ�����û�ж��壬���Զ����ڴ渲������Ŀ�����Ҫ��memmove����������
//memcpy���ڴ濽�����������ֽ�Ϊ��λ���п��������Բ���ʲô���Ͷ��ܽ��п���
//����'\0'����ֹͣ
#include <stdio.h>
#include <windows.h>
#include <assert.h>
//#include <string.h>
#pragma warning(disable:4996)

void *my_memcpy(void* dest, const void* src, int num)//memϵ�����ֽ�Ϊ��λ���в���
{
	assert(dest);
	assert(src);
	assert(num > 0);
	char *pdest = (char *)dest;
	const char *psrc = (char *)src;
	while (num--)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}

int main()
{
	char str1[] = "abcdefg123";
	char str2[20];
	my_memcpy(str2, str1, sizeof(str1));
	printf("%s\n", str2);
	system("pause");
	return 0;
}

//7.ʵ��memmove
//�ڴ���ָ��ǵ�ʱ����ô˺������˺�����memcpy��֮ͬ�����ǵ����� dest > src �� dest < src + strlenʱ���Ӻ���ǰ�����ͺ�
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)

void *my_memmove(void* dest, const void* src, int num)//memϵ�����ֽ�Ϊ��λ���в���
{
	assert(dest);
	assert(src);
	assert(num > 0);
	char *pdest = (char *)dest;
	const char *psrc = (char *)src;
	if (pdest > psrc && pdest < psrc + num)
	{
		while (num--)//num == 1ʱ���жϿ��Խ���ѭ�����������num-- ��Ϊ0������ѭ�����в���
		{
			*(pdest + num) = *(psrc + num);
			//num--;  �����--���������ônum����0�Ͳ������ѭ����������ô*(pdest + 0) = *(psrc + 0)�Ͳ�����У���������
		}
		return dest;
	}
	else
	{
		while (num--)
		{
			*pdest++ = *psrc++;
		}
		return dest;
	}
}

int main()
{
	char str[20] = "abcdefg123";
	my_memmove(str + 1, str, 10);
	printf("%s\n", str);
	system("pause");
	return 0;
}