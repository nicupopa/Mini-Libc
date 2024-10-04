// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	if (destination == NULL)
	{
        return NULL;
    }

	for (size_t i = 0; i < strlen(source) + 1; i++)
	{
		destination[i] = source[i];

		if (destination[i] == '\0')
			break;
	}

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (destination == NULL)
	{
		return NULL;
	}

	for (size_t i = 0; i < len; i++)
	{
		destination[i] = source[i];

		if (destination[i] == '\0')
			break;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	if (destination == NULL)
		return NULL;

	char *aux = destination;
	aux = aux + strlen(aux);

	while (*source != '\0')
	{
		*aux = *source;
		aux++;
		source++;
	}

	*aux = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	if (destination == NULL)
		return NULL;

	size_t count = 0;
	char *aux = destination;
	aux = aux + strlen(aux);

	while (*source != '\0')
	{
		*aux = *source;
		aux++;
		source++;
		count++;
		if (count == len)
			break;
	}

	*aux = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (1)
	{
		if (*str1 != *str2)
			break;

		str1++;
		str2++;

		if (*str1 == '\0' || *str2 == '\0')
			break;
	}

	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t count = 0;

	while (1)
	{
		if (*str1 != *str2)
			break;

		str1++;
		str2++;
		count++;

		if (*str1 == '\0' || *str2 == '\0')
			break;

		if (count == len)
		{
			return 0;
		}
	}

	if (count == len)
		{
			return 0;
		}

	return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	const char *aux = str;

	for (size_t i = 0; i < strlen(str); i++, aux++)
	{
		if (*aux == c)
			return (char *)aux;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *aux = str + strlen(str);

	for (size_t i = 0; i < strlen(str); i++, aux--)
	{
		if (*aux == c)
			return (char *)aux;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
		return NULL;

	const char *aux = haystack;

	for (size_t i = 0; i < strlen(haystack); i++, aux++)
	{
		if (strncmp(aux, needle, strlen(needle)) == 0)
		{
			return (char *)aux;
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
		return NULL;

	const char *aux = haystack + strlen(haystack);

	for (size_t i = 0; i < strlen(haystack); i++, aux--)
	{
		if (strncmp(aux, needle, strlen(needle)) == 0)
		{
			return (char *)aux;
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	if (destination == NULL || source == NULL)
	{
		return NULL;
	}

	// Source: https://www.geeksforgeeks.org/write-memcpy/
	char *dest = (char *)destination;
	char *src = (char *)source;

	for (size_t i = 0; i < num; i++)
	{
		dest[i] = src[i];
	}

	return dest;
}

void *memmove(void *destination, const void *source, size_t num)
{
	if (destination == NULL || source == NULL)
	{
		return NULL;
	}

	char *dest = (char *)destination;
	char *src = (char *)source;

	if (dest == src || num == 0)
		return dest;

	if (dest < src)
	{
		for (size_t i = 0; i < num; i++)
		{
			dest[i] = src[i];
		}
	} else {
		for (int i = num-1; i >= 0; i--)
		{
			dest[i] = src[i];
		}
	}

	return dest;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;

	for (size_t i = 0; i < num; i++)
	{
		if (p1[i] != p2[i])
			break;
	}
	return *p1 - *p2;
}

void *memset(void *source, int value, size_t num)
{
	if (source == NULL)
	{
		return NULL;
	}

	char *src = (char *)source;

	for (size_t i = 0; i < num; i++)
	{
		src[i] = value;
	}

	return src;
}
