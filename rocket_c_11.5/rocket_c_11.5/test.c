//1.实现strcpy
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


//2.实现strcat
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


//3.实现strstr
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

//4.实现strchr
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


//5.实现strcmp

//这个很特殊，一定要多看！！！！
//这个很特殊，一定要多看！！！！
//这个很特殊，一定要多看！！！！

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#pragma warning(disable:4996)

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	int sub;
	while (!(sub = (*str1 - *str2)) && *str1)//两个字符相等且都不为'\0'就继续循环
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


//6.实现memcpy
//此函数对于内存覆盖的问题没有定义，所以对于内存覆盖问题的拷贝，要用memmove函数来处理
//memcpy是内存拷贝函数，以字节为单位进行拷贝，所以不管什么类型都能进行拷贝
//遇到'\0'不会停止
#include <stdio.h>
#include <windows.h>
#include <assert.h>
//#include <string.h>
#pragma warning(disable:4996)

void *my_memcpy(void* dest, const void* src, int num)//mem系列以字节为单位进行操作
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

//7.实现memmove
//内存出现覆盖的时候调用此函数，此函数与memcpy不同之处就是当出现 dest > src 或 dest < src + strlen时，从后往前拷贝就好
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)

void *my_memmove(void* dest, const void* src, int num)//mem系列以字节为单位进行操作
{
	assert(dest);
	assert(src);
	assert(num > 0);
	char *pdest = (char *)dest;
	const char *psrc = (char *)src;
	if (pdest > psrc && pdest < psrc + num)
	{
		while (num--)//num == 1时，判断可以进入循环，随后立即num-- 变为0，进入循环进行操作
		{
			*(pdest + num) = *(psrc + num);
			//num--;  如果把--放在这里，那么num等于0就不会进入循环操作，那么*(pdest + 0) = *(psrc + 0)就不会进行，结果会出错！
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